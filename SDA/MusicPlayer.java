
import java.util.*;

public class MusicPlayer {

    // class data lagu
    static class lagu {

        String judul; // judul lagu
        String genre; // genre lagu
        int puter = 0;  // jumlah lagu diputar

        // constructor lagu
        lagu(String j, String g) {
            judul = j;
            genre = g;
        }

        // nambah jumlah play
        void putar() {
            puter++;
        }
    }

    // struktur data
    static List<lagu> listlagu = new ArrayList<>();  // list semua lagu
    static Stack<lagu> history = new Stack<>();// stack history lagu
    static Queue<lagu> antrian = new LinkedList<>(); // queue playlist
    static Set<String> noduplikat = new HashSet<>(); // set anti duplikat
    static Map<String, lagu> carilagu = new HashMap<>(); // map search cepat
    static Map<String, List<lagu>> genretree = new HashMap<>(); // genre -> list lagu

    // TREE GENRE
    // tree umum buat kategori genre
    static class genrenode {

        // nama genre
        String genre;

        // list lagu dalam genre
        List<lagu> daftarlagu = new ArrayList<>();

        // anak node genre
        List<genrenode> anak = new ArrayList<>();

        genrenode(String g) {
            genre = g;
        }
    }

    // root tree genre
    static genrenode rootgenre = new genrenode("music");

    // node bst
    static class node {

        // node nyimpen object lagu
        lagu data;

        // hubungan ke node lain
        node kiri, kanan;

        // constructor node
        node(lagu l) {

            // lagu yg dikirim disimpan ke node
            data = l;
        }
    }

    // root bst
    static node root;

    // insert bst diurut berdasarkan play count
    static node insert(node now, lagu baru) {

        // kalau kosong bikin node baru
        if (now == null) {
            return new node(baru);
        }

        // play lebih kecil ke kiri
        if (baru.puter < now.data.puter) {
            now.kiri = insert(now.kiri, baru); 
        }// selain itu ke kanan
        else {
            now.kanan = insert(now.kanan, baru);
        }

        return now;
    }

    // masukin lagu ke tree genre
    static void tambahgenre(lagu baru) {

        // cek genre sudah ada atau belum
        for (genrenode g : rootgenre.anak) {
            // kalau genre sama
            if (g.genre.equals(baru.genre)) {
                g.daftarlagu.add(baru);  // masukin lagu ke genre itu
                return;
            }
        }
        genrenode barugenre = new genrenode(baru.genre); // kalau genre belum ada bikin genre baru
        barugenre.daftarlagu.add(baru);// masukin lagu pertama
        rootgenre.anak.add(barugenre); // sambung ke root
    }

    // tambah lagu baru
    static void tambahlagu(String judul, String genre) {

        // cek duplikat
        if (noduplikat.contains(judul)) {
            System.out.println("lagu sudah ada!");
            return;
        }
        lagu baru = new lagu(judul, genre); // bikin object lagu baru

        listlagu.add(baru); // masuk list
        noduplikat.add(judul); // masuk set
        carilagu.put(judul, baru); // masuk map

        // kalau genre belum ada bikin list baru
        genretree.putIfAbsent(genre,new ArrayList<>()  );
        genretree.get(genre).add(baru); // masukin lagu ke genre

        tambahgenre(baru);  // masuk tree genre
        root = insert(root, baru);  // masuk bst

        System.out.println("tambah lagu: " + judul);
    }

    // tampil semua lagu
    static void tampilsemualagu() {
        int i = 1;

        // loop semua lagu
        for (lagu l : listlagu) {

            System.out.println( i++ + ". " + l.judul + " | " + l.genre + " | Played: " + l.puter);
        }
    }

    // muter lagu
    static void putarlagu(lagu l) {
        l.putar(); // play count naik
        history.push(l); // masuk history

        // bst dibikin ulang karena play count berubah
        root = null;

        // masukin ulang semua lagu
        for (lagu x : listlagu) {
            root = insert(root, x);
        }

        System.out.println("\nnow playing: " + l.judul);
    }

    // pilih lagu dari index
    static void putarbyindex(Scanner sc) {

        tampilsemualagu();

        System.out.print("pilih lagu: ");

        int idx = sc.nextInt();
        sc.nextLine();

        // cek index valid
        if (idx >= 1 && idx <= listlagu.size()) {
            putarlagu(listlagu.get(idx - 1)); 
        }else {
            System.out.println("index salah!");
        }
    }

  // bikin playlist input angka dipisah spasi
static void bikinplaylist(Scanner sc) {
    tampilsemualagu();
    System.out.print("input nomor lagu: ");

    String input = sc.nextLine();
    String[] arr = input.split(" ");

    boolean valid = true;

    // loop semua input
    for (String x : arr) {
        try {
            int idx = Integer.parseInt(x);
            // cek nomor lagu valid
            if (idx >= 1 && idx <= listlagu.size()) {
                antrian.offer(listlagu.get(idx - 1));
            }
            // kalau nomor gak ada
            else {
                valid = false;
                break;
            }
        }
        // kalau input bukan angka
        catch (Exception e) {

            valid = false;
            break;
        }
    }
    // hasil akhir
    if (valid)
        System.out.println("playlist dibuat!");

    else {
        // kalau ada input salah
        antrian.clear();

        System.out.println("input gak ada!");
    }
}

    // muter playlist pake queue 
    static void putarplaylist() {

        // cek playlist kosong
        if (antrian.isEmpty()) {

            System.out.println("playlist kosong!");
            return;
        }

        // loop sampai playlist habis
        while (!antrian.isEmpty()) {
            // ambil depan queue
            lagu l = antrian.poll();

            // putar lagu
            putarlagu(l);
        }
    }

    // tampil history lagu
    static void tampilhistory() {

        // cek history kosong
        if (history.isEmpty()) {
            System.out.println("belum ada history!");
            return;
        }

        System.out.println("\nhistory lagu");

        // tampil dari atas stack
        for (int i = history.size() - 1; i >= 0; i--) {
            System.out.println("- " + history.get(i).judul);
        }
    }

    // cari lagu pake map search o(1)
    static void carilagu(String judul) {
        lagu l = carilagu.get(judul); // ambil lagu dari map

        // kalau gak ada
        if (l == null) {
            System.out.println("lagu gak ketemu!");
            return;
        }
        System.out.println("\nlagu ketemu"); // print data lagu
        System.out.println(l.judul+ " | "+ l.genre+ " | Played: " + l.puter);
    }

    // lagu paling populer node paling kanan bst
    static void topsong() {

        // cek bst kosong
        if (root == null) {
            System.out.println("belum ada lagu!");
            return;
        }
        node temp = root;

        // jalan terus ke kanan karena kanan lebih besar
        while (temp.kanan != null) {
            temp = temp.kanan;
        }

        System.out.println("\ntop song");// tampil lagu terbesar
        System.out.println(temp.data.judul+ " | Played: "+ temp.data.puter);
    }

    // rekomendasi lagu genre sama
    static void rekomendasi() {

        // cek history kosong
        if (history.isEmpty()) {
            System.out.println("belum ada lagu diputar!");
            return;
        }
        lagu terakhir = history.peek(); // ambil lagu terakhir diputar
        System.out.println("\nrekomendasi");

        List<lagu> rec = genretree.get(terakhir.genre); // ambil list genre sama

        // loop semua lagu genre sama
        for (lagu l : rec) {
            // jangan tampil lagu yg sama
            if (!l.judul.equals(terakhir.judul)) {
                System.out.println("- " + l.judul);
            }
        }
    }

    // cari lagu berdasarkan genre pake tree
    static void carigenre(Scanner sc) {
        System.out.print("input genre: ");
        String cari = sc.nextLine();

        // loop semua genre di tree
        for (genrenode g : rootgenre.anak) {

            // kalau genre ketemu
            if (g.genre.equalsIgnoreCase(cari)) {

                System.out.println("\nGenre: " + g.genre);
                // tampil semua lagu genre itu
                for (lagu l : g.daftarlagu) {
                    System.out.println("- " + l.judul+ " | Played: "+ l.puter);
                }
                return;
            }
        }
        System.out.println("genre gak ada!");
    }

    // main program
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // lagu default
        tambahlagu("Yellow", "Pop");
        tambahlagu("Fix You", "Pop");
        tambahlagu("Numb", "Rock");
        tambahlagu("Believer", "Rock");
        tambahlagu("Perfect", "Pop");
        tambahlagu("i love you so much", "Pop");
        tambahlagu("GOD", "R&B");
        tambahlagu("take me home", "Country");

        while (true) {

            System.out.println("\n===== MUSIC PLAYER =====");
            
            System.out.println("1. tambah lagu");
            System.out.println("2. tampil lagu");
            System.out.println("3. putar lagu");
            System.out.println("4. bikin playlist");
            System.out.println("5. putar playlist");
            System.out.println("6. history");
            System.out.println("7. cari lagu");
            System.out.println("8. top song");
            System.out.println("9. rekomendasi");
            System.out.println("10. cari genre");
            System.out.println("0. keluar");

            System.out.print("pilih: ");
            System.out.println(" ");

            int pilih = sc.nextInt();
            sc.nextLine();

            switch (pilih) {
                case 1:
                    System.out.print("judul: ");
                    String j = sc.nextLine();

                    System.out.print("genre: ");
                    String g = sc.nextLine();

                    tambahlagu(j, g);
                    break;

                case 2:
                    tampilsemualagu();
                    break;

                case 3:
                    putarbyindex(sc);
                    break;

                case 4:
                    bikinplaylist(sc);
                    break;

                case 5:
                    putarplaylist();
                    break;

                case 6:
                    tampilhistory();
                    break;

                case 7:
                    System.out.print("cari judul: ");
                    String s = sc.nextLine();

                    carilagu(s);
                    break;

                case 8:
                    topsong();
                    break;

                case 9:
                    rekomendasi();
                    break;

                case 10:

                    carigenre(sc);
                    break;

                case 0:

                    return;

                default:

                    System.out.println("pilihan gak ada!");
            }
        }
    }
}
