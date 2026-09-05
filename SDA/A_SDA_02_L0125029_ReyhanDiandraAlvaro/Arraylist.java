public class Arraylist {

    private int[] originalarr; // ini array aslinya
    private int isi; // cek brp data

// deklarasi peratma array list sebelum nanti datanya di ubah ubah
    public Arraylist(int bts) {
        this.originalarr = new int[bts];
        this.isi = 0; // awal jelas belum ada isinya
    }

    // untuk nginput data kedalam array 
    public void masukin(int angka) {
        // ngecek arraynya penuh ga
        if (isi == originalarr.length) {
            // jika penuh maka akan membuat array baru yg lebih panjang 2 kali lipat biar ga ribet
            System.out.println("array full (tambahakan panjang)");
            int[] baru = new int[originalarr.length * 2];

            // copy array lama ke baru 
            for (int i = 0; i < originalarr.length; i++) {
                baru[i] = originalarr[i]; //ini nge copy dari data nol sampe ke x pake for sehingga 1 1
            }

            this.originalarr = baru;
            /*  jadi disini array baru hanya sebagai storage semsntara saja nanti kalo sudah
            maka array tersebut akan diubah namanya lagi jadi orginalarr lagi biar sistemnya gabingung
            */
        }

        // masukin datanya ke posisi yg kosong
        originalarr[isi] = angka;
        isi++;
        System.out.println("masuk = " + angka);
    }

// buat nyetak arraynya 
    public void cetak() {
        if (isi == 0) {
            System.out.println("kosong");
        } else {
            System.out.print("isi array = ");
            for (int i = 0; i < isi; i++) {
                System.out.print(originalarr[i] + " "); //print array 1 1 lewat for 
            }
            System.out.println();
        }
    }

    // buat ngambil data 
    public int ambil(int idx) {
        //misal indenxnya yg mau diambil itu kurang dari nol atau lebih dari iis (kesalahan user)
        if (idx < 0 || idx >= isi) {
            System.out.println("input index salah");
            return -1;
        }
        return originalarr[idx]; //jika benar maka langsung saja dipanggil di di arr tsb
    }

    // ngubah salah satu data dalam array
    public void ganti(int idx, int angka) {
        if (idx < 0 || idx >= isi) {
            System.out.println("index error");//misal indenxnya yg mau diambil itu kurang dari nol atau lebih dari iis (kesalahan user)
        } else {
            originalarr[idx] = angka;
            System.out.println("index " + idx + " diganti jadi " + angka);
        }
    }

    // hapus salah 1 data dalam array
    public void hapus(int idx) {
        if (idx < 0 || idx >= isi) {
            System.out.println("index error"); // cek index
        } else {
            int buang = originalarr[idx]; // nyari index no brp yang mau dihapus

            // index yg sudah dihapus akan lansgung di tempati index yg sudah ada jika yg kosong bukan di akhir
            for (int i = idx; i < isi - 1; i++) {
                originalarr[i] = originalarr[i + 1]; // index yg diganti akan digantikan index +1 nyaa
            }

            isi--; // nandain bahwa slot ada sisa dibelakang
            System.out.println("data " + buang + " dihapus");
        }
    }

    public int size() {
        return isi; // buat cek panjang array yg ada isi saja
    }

    public static void main(String[] args) {

        Arraylist tes = new Arraylist(3); // set 3 aja biar cpet penuh

        tes.masukin(10);
        tes.masukin(20);
        tes.masukin(30);

        // tes masukin pas penuh
        tes.masukin(40);
        tes.masukin(50);

        //cek semua isi array
        System.out.println("\n");
        tes.cetak();
        //cek isi data yg di isi ada berapa
        System.out.println("total data: " + tes.size());

        System.out.println("\n");
        System.out.println("cek index 2 = " + tes.ambil(2));

        tes.ganti(2, 67); // ubah
        tes.cetak();

        System.out.println("\n");
        tes.hapus(1); // hapus index 1
        tes.cetak();

        System.out.println("total abis dihapus: " + tes.size());
    }
}
