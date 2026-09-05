public class Queue {

    private final int[] arr;
    private int belakang; // ini buat nandain posisi orang yg paling belakang

// bikin antrian baru, ukurannya ntar ditentuin di main
    public Queue(int bts) {
        this.arr = new int[bts];
        this.belakang = -1; // -1 soalnya belum ada yg antri sama sekali dan karena array mulai dri nol maka array kosong
    }

    // cek kosong ga antrianya
    public boolean kosong() {
        return belakang == -1;
    }

    // fungsi jika ada pelanggan baru masuk antrian (ENQUEUE)
    public void enqueue(int no) {
        // cek dulu tempat antrenya muat apa ngga
        if (belakang == arr.length - 1) {
            System.out.println("antrian full kepanjangan");
        } else {
            belakang++; // nambah total jumlah antrian belakang
            arr[belakang] = no; // pelanggan baru ditaruh di paling belakang
            System.out.println("masuk antrian = " + no);
        }
    }

// yang depan suruh beli sesuai urut barisan (DEQUEUE)
    public int dequeue() {
        if (kosong()) {
            System.out.println("antrian kosong ga ada yg beli");
            return -1;
        } else {
            // yg dilayanin yg index 0 (paling depan yg pertama beli)
            int hasil = arr[0];

            for (int i = 0; i < belakang; i++) {
                arr[i] = arr[i + 1]; //ini artinya index 0 dijadiin isi dari index 1 dst
                //jadi di for sehingga nilainya berubah 1 1 ya ibratanya di geser 
            }
            arr[belakang] = 0; // tempat paling belakang jadi kosong
            belakang--; // ngurangi data biar slot terakhir (index 4) kebuka lagi buat antrian baru

            return hasil;
        }
    }

// ngeliat antrian paling depan siapa dengan peek
    public int peek() {
        if (kosong()) {
            System.out.println("kosong");
            return -1;
        } else {
            return arr[0];
        }
    }

    // nampilin semua orang yg lagi antri 
    public void printq() {
        if (kosong()) {
            System.out.println("kosong");
        } else {
            System.out.print("isi queue = ");
            // ngeloop dari depan (0) sampe ke belakang 
            for (int i = 0; i <= belakang; i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {

        Queue antrian = new Queue(5); // bikin maks barisan lima

        antrian.enqueue(11);
        antrian.enqueue(22); //masukin orang yg antri
        antrian.enqueue(33);
        antrian.enqueue(67);
        antrian.enqueue(99);


        System.out.println("\n");
        antrian.printq(); //print display ataau semua orang yg lagi antri

        //nge peek orang yang paling depan
        System.out.println("\ncek depan = " + antrian.peek());

        //ngebuang antian paling depan karena sudah beli atau nge dequeue
        System.out.println("\n");
        System.out.println("yg dikeluarin = " + antrian.dequeue());

        //ini habis di deque di print lagi
        System.out.println("sisa antrian abis di dequeue:");
        antrian.printq();

        System.out.println("\n");
        // ngetes masukin lagi
        antrian.enqueue(78);
        antrian.printq();
    }
}
