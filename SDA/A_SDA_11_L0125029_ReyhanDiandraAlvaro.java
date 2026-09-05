import java.util.*;

// ==========================================
// BAGIAN 1: ALGORITMA KRUSKAL & DISJOINT SET
// ==========================================
class KruskalMST {
    static class Edge implements Comparable<Edge> {
        int src, dest, weight;
        public Edge(int src, int dest, int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }
        @Override
        public int compareTo(Edge other) {
            return Integer.compare(this.weight, other.weight);
        }
    }

    static class DisjointSet {
        int[] parent, rank;
        public DisjointSet(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        public int find(int i) {
            if (parent[i] == i) return i;
            return parent[i] = find(parent[i]); // Path compression
        }

        public void union(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
                else if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
                else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        }
    }

    public static void findMST(List<Edge> edges, int V) {
        Collections.sort(edges); // Urutkan secara ascending (Greedy)
        DisjointSet ds = new DisjointSet(V);
        List<Edge> mst = new ArrayList<>();
        int totalWeight = 0;

        for (Edge edge : edges) {
            int rootSrc = ds.find(edge.src);
            int rootDest = ds.find(edge.dest);

            // Jika tidak membentuk siklus, masukkan ke dalam MST
            if (rootSrc != rootDest) {
                ds.union(rootSrc, rootDest);
                mst.add(edge);
                totalWeight += edge.weight;
            }
        }

        System.out.println("=== HASIL PERHITUNGAN MST (KRUSKAL) ===");
        System.out.println("Sisi yang terpilih dalam MST:");
        for (Edge e : mst) {
            System.out.println("Simpul " + e.src + " - " + e.dest + " | Bobot = " + e.weight);
        }
        System.out.println("Total Bobot Jaringan MST = " + totalWeight);
    }
}

// ==========================================
// BAGIAN 2: ALGORITMA DIJKSTRA (SHORTEST PATH)
// ==========================================
class DijkstraMatrix {
    public static void dijkstra(int[][] graph, int startNode) {
        int v = graph.length;
        int[] distances = new int[v];
        boolean[] visited = new boolean[v];
        int[] previousNodes = new int[v];

        for (int i = 0; i < v; i++) {
            distances[i] = Integer.MAX_VALUE;
            visited[i] = false;
            previousNodes[i] = -1;
        }
        distances[startNode] = 0;

        for (int count = 0; count < v - 1; count++) {
            int currentNode = findMinimumDistance(distances, visited);
            if (currentNode == -1) break;

            visited[currentNode] = true;

            for (int neighbor = 0; neighbor < v; neighbor++) {
                if (!visited[neighbor] && graph[currentNode][neighbor] != 0 && distances[currentNode] != Integer.MAX_VALUE) {
                    int distance = distances[currentNode] + graph[currentNode][neighbor];
                    if (distance < distances[neighbor]) { // Proses Relaxation
                        distances[neighbor] = distance;
                        previousNodes[neighbor] = currentNode;
                    }
                }
            }
        }
        printResult(startNode, distances, previousNodes);
    }

    private static int findMinimumDistance(int[] distances, boolean[] visited) {
        int min = Integer.MAX_VALUE;
        int minIndex = -1;
        for (int i = 0; i < distances.length; i++) {
            if (!visited[i] && distances[i] < min) {
                min = distances[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    private static void printResult(int startNode, int[] distances, int[] previousNodes) {
        System.out.println("\n=== HASIL PERHITUNGAN DIJKSTRA ===");
        System.out.println("Jarak terpendek dari Simpul Pusat [" + startNode + "] ke semua simpul:");
        for (int i = 0; i < distances.length; i++) {
            String jarakStr = (distances[i] == Integer.MAX_VALUE) ? "Infinity" : String.valueOf(distances[i]);
            List<Integer> path = new ArrayList<>();
            int current = i;
            while (current != -1) {
                path.add(current);
                current = previousNodes[current];
            }
            Collections.reverse(path);
            System.out.print("Ke Simpul " + i + " : Jarak = " + jarakStr + " | Rute = ");
            if (distances[i] == Integer.MAX_VALUE) {
                System.out.println("Tidak Terhubung");
            } else {
                for (int j = 0; j < path.size(); j++) {
                    System.out.print(path.get(j) + (j < path.size() - 1 ? " -> " : ""));
                }
                System.out.println();
            }
        }
    }
}

// ==========================================
// BAGIAN 3: EKSEKUSI UTAMA UTK PRAKTIKAN
// ==========================================
public class A_SDA_11_L0125029_ReyhanDiandraAlvaro {
    public static void main(String[] args) {
        
        // 1. INISIALISASI UNTUK KRUSKAL MST
        int V_Kruskal = 4; // Berisi jumlah simpul (0 sampai 3)
        List<KruskalMST.Edge> edges = new ArrayList<>();

        // TUGAS A: Kerjakan pengisian edges untuk Kruskal di sini berdasarkan instruksi soal!
        // Gunakan format: edges.add(new KruskalMST.Edge(source, destination, weight));
        // Tuliskan juga komentar penjelasan di setiap baris penambahan data.
        
        
        edges.add(new KruskalMST.Edge(0, 1, 10));// hubungin simpul 0 ke 1 buat jaringan kabel, biayanya 10
        edges.add(new KruskalMST.Edge(0, 2, 6));// sambungin simpul 0 ke 2, ini biayanya 6
        edges.add(new KruskalMST.Edge(0, 3, 5)); // hubungin simpul 0 ke 3, lumayan murah biayanya 5
        edges.add(new KruskalMST.Edge(1, 3, 15)); // rute simpul 1 ke 3 agak mahal, biayanya 15
        edges.add(new KruskalMST.Edge(2, 3, 4));// nah ini rute paling murah dari simpul 2 ke 3, cuma 4

        // Jalankan pencarian MST Kruskal
        KruskalMST.findMST(edges, V_Kruskal);
        
        // kasih spasi biar output di terminal nggak numpuk dan enak dibaca
        System.out.println();

        // 2. INISIALISASI UNTUK DIJKSTRA LINTASAN TERPENDEK
        int V_Dijkstra = 4; // Matriks berukuran 4x4 (Simpul 0 sampai 3)
        int[][] graph = new int[V_Dijkstra][V_Dijkstra];

        // TUGAS B: Kerjakan pengisian matriks ketetanggaan berbobot untuk Dijkstra di sini!
        // Gunakan format: graph[source][destination] = weight;
        // Ingat, isikan bobot 0 jika tidak ada hubungan langsung antar simpul.
        // Tuliskan juga komentar penjelasan di setiap baris penambahan data.
        
        graph[0][1] = 4; // bikin jalur pengiriman searah dari simpul 0 ke 1, bobot jaraknya 4
        graph[0][2] = 2;// dari simpul 0 ke 2 jaraknya lebih deket, cuma 2
        graph[1][2] = 1; // ini shortcut dari simpul 1 ke 2, jaraknya 1 doang
        graph[1][3] = 5; // jalur distribusi dari simpul 1 ke 3 butuh jarak 5
        graph[2][3] = 8;// kalau rute dari simpul 2 ke 3 lumayan jauh, jaraknya 8

        // Jalankan pencarian rute terpendek Dijkstra dengan simpul awal = 0
        DijkstraMatrix.dijkstra(graph, 0);
    }
}