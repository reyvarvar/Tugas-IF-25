import java.util.*;

class Graph {

    // Menyimpan pasangan nama mahasiswa dengan index matrix
    private HashMap<String, Integer> studentIndex;

    // Menyimpan daftar nama mahasiswa berdasarkan index
    private ArrayList<String> studentList;

    // Adjacency Matrix
    private int[][] matrix;

    // Jumlah mahasiswa
    private int size;

    Graph(int maxStudents) {
        matrix = new int[maxStudents][maxStudents];
        studentIndex = new HashMap<>();
        studentList = new ArrayList<>();
        size = 0;
    }

    // Menambahkan mahasiswa baru
    public void addStudent(String name) {
        studentIndex.put(name, size);
        studentList.add(name);
        size++;
    }

    // Menambahkan hubungan pertemanan
    public void addEdge(String source, String destination) {
        int src = studentIndex.get(source);
        int dest = studentIndex.get(destination);

        // Graph tidak berarah
        matrix[src][dest] = 1;
        matrix[dest][src] = 1;
    }

    // Menghapus hubungan pertemanan
    public void removeEdge(String source, String destination) {
        int src = studentIndex.get(source);
        int dest = studentIndex.get(destination);

        // Menghapus hubungan dua arah
        matrix[src][dest] = 0;
        matrix[dest][src] = 0;
    }

    // Menampilkan adjacency matrix
    public void displayGraph() {
        System.out.println("Adjacency Matrix:");

        // Header
        System.out.print("\t");
        for (String name : studentList) {
            System.out.print(name + "\t");
        }
        System.out.println();

        // Isi matrix
        for (int i = 0; i < size; i++) {
            System.out.print(studentList.get(i) + "\t");
            for (int j = 0; j < size; j++) {
                System.out.print(matrix[i][j] + "\t");
            }
            System.out.println();
        }
    }
}

class DisjointSet {

    private HashMap<String, String> parent = new HashMap<>();

    // Membuat kelompok baru
    public void makeSet(String name) {
        parent.put(name, name);
    }

    // Mencari representative
    public String find(String name) {
        // Jika parent dirinya sendiri
        if (parent.get(name).equals(name)) {
            return name;
        }
        // Rekursif mencari root
        return find(parent.get(name));
    }

    // Menggabungkan kelompok
    public void union(String a, String b) {
        String rootA = find(a);
        String rootB = find(b);

        // Jika berbeda maka digabung
        if (!rootA.equals(rootB)) {
            parent.put(rootB, rootA);
        }
    }

    // Mengecek apakah satu kelompok
    public boolean isSameGroup(String a, String b) {
        return find(a).equals(find(b));
    }
}

public class A_SDA_07_L0125029_ReyhanDiandraAlvaro {

    public static void main(String[] args) {

        Graph graph = new Graph(10);

        // Menambahkan mahasiswa
        graph.addStudent("Andi");
        graph.addStudent("Budi");
        graph.addStudent("Caca");
        graph.addStudent("Deni");
        graph.addStudent("Eka");
        graph.addStudent("Farah");

        // Kerjakan add edge disini beserta komentar
        graph.addEdge("Andi", "Budi"); //Menambahkan pertemanan antara Andi dan Budi
        graph.addEdge("Andi", "Caca"); // Menambahkan pertemanan antara Andi dan Caca
        graph.addEdge("Budi", "Deni"); // Menambahkan pertemanan antara Budi dan Deni
        graph.addEdge("Caca", "Eka"); // Menambahkan pertemanan antara Caca dan Eka
        graph.addEdge("Deni", "Farah"); // Menambahkan pertemanan antara Deni dan Farah

        System.out.println("Matrix Sebelum Deletion:");
        graph.displayGraph();
        System.out.println();

        // Kerjakan remove edge disini beserta komentar
        graph.removeEdge("Budi", "Deni"); // Menghapus pertemanan antara Budi dan Deni

        System.out.println("Matrix Setelah Deletion:");
        graph.displayGraph();
        System.out.println();

        DisjointSet ds = new DisjointSet();
        ds.makeSet("Andi");
        ds.makeSet("Budi");
        ds.makeSet("Caca");
        ds.makeSet("Deni");
        ds.makeSet("Eka");
        ds.makeSet("Farah");

        // Kerjakan union disini beserta komentar
        ds.union("Andi", "Budi"); //Menggabungkan kelompok andi dan budi
        ds.union("Budi", "Caca"); //Menggabungkan kelompok budi dan Caca
        ds.union("Deni", "Farah"); //Menggabungkan keompok Deni dan Farah

        // Kerjakan pengecekan grup disini
        // karena nanti hasil dari isSameGroup adalah true false atau boolean maka wajib di print dan agar mudah dikasih keterangan
        System.out.println("Apakah Andi dan Caca di grup yang sama " + ds.isSameGroup("Andi", "Caca")) ; //cek apa andi dan caca sekolompok
        System.out.print("Apakah Andi dan Farah di grup yang sama " + ds.isSameGroup("Andi", "Farah")) ; //cek apa andi dan farah sekelompok

        


    }
}