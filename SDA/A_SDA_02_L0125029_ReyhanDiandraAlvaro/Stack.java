public class Stack {

    private final int[] mesin;
    private int itungan;

    // bikin object stack, ukurannya akan ditentukan saat nanti kodenya dipanggil
    public Stack(int kapasitas) {
        this.mesin = new int[kapasitas];
        this.itungan = -1; // mulai dari -1 karena array mulainya dari nol dan saat nol maka sudah berjalan
    }

    // fungsi buat masukin data ke stak
    public void push(int input) {
        // untuk mengecek apakah masih ada space di stack atau tidak
        if (this.itungan == this.mesin.length - 1) {
            System.out.println("storagenya audah full nih bro");
        } else {
            itungan++; // untuk menaikan data input ke array (naikin nomer slotnya)
            mesin[itungan] = input; // masukin datanya ke array
            System.out.println("stack masuk = " + input);
        }
    }

    // untuk mengambil nilai di stak
    public int pop() {
        if (kosong()) {
            System.out.println("Storage kosong");
            return -1;
        } else {
            int hasil = mesin[itungan]; // simpen data biar bisa di print nanti
            mesin[itungan] = 0; // jika data sudah di ambil maka nilainya di kosongin
            itungan--; // turunin posisi itunganya biar bisa dimasukin lagi
            return hasil; // datanya di return biar bisa dipanggil nnti print
        }
    }

    // peek untuk hanya mengecek data yang paling atas tampa diapa apain
    public int peek() {
        if (kosong()) {
            System.out.println("tidak ada data yang bisa dicek");
            return -1;
        } else {
            // mengembalikan nilai saat pemanggilan fungsi
            return mesin[itungan];
        }
    }

    // nah fungsi ini yang daritadi dipangggil yaitu buat cek apa stak ada isinya apa ga
    public boolean kosong() {
        return itungan == -1;
        //karena array mulainya dari nol maka digunakanlah -1 agar memastikan array kosong
    }

    // untuk mengeprint stack
    public void printstak() {
        if (kosong()) {
            System.out.println("Stak kosong");
        } else {
            // looping dari array tertinggi kebawah 
            for (int i = itungan; i >= 0; i--) {
                System.out.println("- " + mesin[i]);
            }
        }
    }

    public static void main(String[] args) {

        Stack tumpukan = new Stack(5); //ini untuk membuat berapa komponen maksimum yang bisa ditampung stadk

        tumpukan.push(11);
        tumpukan.push(22); //ini buat nginput data ke stack
        tumpukan.push(33);
        tumpukan.push(67);

        System.out.println("\n");
        System.out.println("isi stack = ");
        tumpukan.printstak(); //memanggil fungsi stak dan menampilkan angka angkanya

        //mau manggil peek
        System.out.println("\ncek fungsi peek");
        System.out.println("peek data paling atas: " + tumpukan.peek());

        //test poop
        System.out.println("\n");
        System.out.println("Ngambil(poop) data: " + tumpukan.pop());

        // tampilin lagi buat buktiin datanya beneran ilang abis di pop
        System.out.println("isi stack setelah dipoop yaitu = ");
        tumpukan.printstak();
    }
}
