    import java.util.HashMap;
    import java.util.HashSet;
    import java.util.Map;
    import java.util.Scanner;
    import java.util.Set;
    //import package java.util agar bisa menjalankan set dan map

    public class A_SDA_04_L0125029_ReyhanDiandraAlvaro {

        static Map<String, String> buku = new HashMap<>(); //deklarasi map dengan nama buku
        static Set<String> jenisbuku = new HashSet<>(); //deklarasi set dengan nama kategori

        public static void main(String[] args) {

            try (Scanner input = new Scanner(System.in)) {

                // untuk menentukan berapa banyak buku yang ingin diinput
                System.out.print("Masukkan jumlah buku: ");
                int jumlahBuku = input.nextInt();
                input.nextLine();

                /*  Tambah buku dengan method karena di method itu id, judul, kategori. Lalu id dan judul itu masuk untuk
                membuat map dan kategori untuk membuat set. Sehingga id dan judul bukunya otomatis masuk ke map dan 
                kategori otomatis masuk ke set 
                */
                for (int i = 0; i < jumlahBuku; i++) {
                    System.out.println("\nData buku ke-" + (i + 1));

                    System.out.print("Masukkan ID buku: ");
                    String id = input.nextLine();

                    System.out.print("Masukkan judul buku: ");
                    String judul = input.nextLine();

                    System.out.print("Masukkan kategori buku: ");
                    String kategori = input.nextLine();

                    tambahBuku(id, judul, kategori);
                }

                // untuk mengeprint semua yang sudah di input baik di map disini berarti untuk kode dan judul
                System.out.println("Daftar Buku:");
                System.out.println(buku);

                // mengeprint jenis bukunya disini berarti kita print setnya
                System.out.println("\nKategori Unik:");
                System.out.println(jenisbuku);

                // untuk mencari buku di map dengan command get
                System.out.print("\nCari buku dengan kode: ");
                String carikode = input.nextLine();
                
                //next.Line itu sendiri fungsinya agar bisa menerima spasi saat masukin 
                if (buku.containsKey(carikode)) {
                    System.out.println(buku.get(carikode));
                } else {
                    System.out.println("Buku tidak ada");
                }

                // menghapus data buku di map dengan cukup menghapus string idnya
                System.out.print("\nMasukkan kode buku yang ingin dihapus: ");
                String hapuskode = input.nextLine();

                if (buku.containsKey(hapuskode)) {
                    buku.remove(hapuskode);
                    System.out.println("\nSetelah buku " + hapuskode + " dihapus:");
                    System.out.println(buku);
                } else {
                    System.out.println("Buku gaada, jadi tidak tau hapus apa");
                }
            }
        }

        public static void tambahBuku(String id, String judul, String kategori) {
            buku.put(id, judul); // ini untuk memasukan map
            jenisbuku.add(kategori); //ini untuk memasukan set
        }
    }