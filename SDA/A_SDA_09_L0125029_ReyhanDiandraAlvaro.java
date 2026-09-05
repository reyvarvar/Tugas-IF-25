import java.util.Arrays;

// 1. Class Data
class PesertaEvent {
    int idPendaftaran;
    String nama;
    int poinPrioritas;

    public PesertaEvent(int idPendaftaran, String nama, int poinPrioritas) {
        this.idPendaftaran = idPendaftaran;
        this.nama = nama;
        this.poinPrioritas = poinPrioritas;
    }

    // Method untuk memudahkan pencetakan data ke layar
    @Override
    public String toString() {
        return String.format("[ID: %d | Nama: %-5s | Poin: %d]", idPendaftaran, nama, poinPrioritas);
    }
}

// 2. Class Utama
public class A_SDA_09_L0125029_ReyhanDiandraAlvaro {

    // --- BAGIAN 1: IMPLEMENTASI SORTING ---
    
    public static void bubbleSort(PesertaEvent[] arr) {
        int n = arr.length;
        boolean isswapped;

        for(int i = 0 ; i < n-1 ; i++) {
            isswapped = false ;

            // ngecek sebelahan, kalo yg kiri lebih kecil dari yg kanan, tuker posisinya (descending)
            for(int j = 0 ; j < n - i - 1 ; j++ ) {
                if( arr[j].poinPrioritas < arr[j+1].poinPrioritas) {
                    PesertaEvent temp = arr[j] ;
                    arr[j] = arr[j+1] ;
                    arr[j+1] = temp ;

                    isswapped = true ;
                }
            }
            // optimasi: kalo di loop ini ga ada yg ketuker sama sekali, brati udah urut, udahan aja
            if(!isswapped) {
                break ;
            }
        }
    }

    public static void selectionSort(PesertaEvent[] arr) {
        int n = arr.length;
        
        for(int i = 0 ; i < n -1 ; i++) {
            // nyimpen indeks yang poinnya paling gede
            int arrterkecil = i ;

            // cari di sisa array kanannya, ada ga yg poinnya lebih gede
            for(int j = i+1 ; j < n ; j++) {
                if( arr[j].poinPrioritas > arr[arrterkecil].poinPrioritas ){
                    arrterkecil = j ;
                }
            }

            // kalo ternyata ada yg lebih gede dari posisi awal i, baru dituker
            if(arrterkecil != i) {
                PesertaEvent temp = arr[i] ;
                arr[i] = arr[arrterkecil]  ;
                arr[arrterkecil] = temp ;
            }
        }
    }

    public static void insertionSort(PesertaEvent[] arr) {
        int n = arr.length;
        
        for (int i = 1; i < n; i++) {
            // ambil data yg mau diposisihin
            PesertaEvent tkr = arr[i]; 
            int j = i - 1;

            // selama data di kirinya lebih kecil, geser terus ke kanan buat ngasi ruang
            while (j >= 0 && arr[j].poinPrioritas < tkr.poinPrioritas) {
                arr[j + 1] = arr[j]; 
                j = j - 1;           
            }
            // taruh datanya di posisi yg bener
            arr[j + 1] = tkr; 
        }
    }

    // Method bantuan untuk mencetak isi array
    public static void printArray(PesertaEvent[] arr, String namaAlgoritma) {
        System.out.println("Hasil " + namaAlgoritma + ":");
        for (PesertaEvent p : arr) {
            System.out.println(p.toString());
        }
        System.out.println();
    }

    // --- MAIN METHOD ---
    public static void main(String[] args) {
        // Inisialisasi Data Awal (Sesuai instruksi soal)
        PesertaEvent[] dataAwal = {
            new PesertaEvent(1, "Andi", 85),
            new PesertaEvent(2, "Budi", 90),
            new PesertaEvent(3, "Caca", 75),
            new PesertaEvent(4, "Deni", 90),
            new PesertaEvent(5, "Euis", 85),
            new PesertaEvent(6, "Fajar", 60)
        };

        System.out.println("=== DATA AWAL SEBELUM DIURUTKAN ===");
        printArray(dataAwal, "Data Mentah");

        // Membuat salinan array agar setiap algoritma memproses data awal yang sama
        PesertaEvent[] arrBubble = Arrays.copyOf(dataAwal, dataAwal.length);
        PesertaEvent[] arrSelection = Arrays.copyOf(dataAwal, dataAwal.length);
        PesertaEvent[] arrInsertion = Arrays.copyOf(dataAwal, dataAwal.length);

        System.out.println("=== PENGUJIAN IMPLEMENTASI ===");
        
        // Menjalankan Bubble Sort
        bubbleSort(arrBubble);
        printArray(arrBubble, "Bubble Sort");

        // Menjalankan Selection Sort
        selectionSort(arrSelection);
        printArray(arrSelection, "Selection Sort");

        // Menjalankan Insertion Sort
        insertionSort(arrInsertion);
        printArray(arrInsertion, "Insertion Sort");


        System.out.println("=== BAGIAN 2: ANALISIS PERFORMA WAKTU ===");
        
        // bikin salinan data yg emang udah urut buat tes best case
        PesertaEvent[] dataBestBubble = Arrays.copyOf(arrBubble, arrBubble.length);
        PesertaEvent[] dataBestInsert = Arrays.copyOf(arrInsertion, arrInsertion.length);

        // Tes Bubble Sort acak
        // ngitung waktu eksekusi catet waktu mulai, jalanin sortingnya, trus catet waktu selesainya
        long startbuble = System.nanoTime();
        bubbleSort(Arrays.copyOf(dataAwal, dataAwal.length)); 
        long finishbuble = System.nanoTime();
        long lamabuble = finishbuble - startbuble; // selisihnya = lama waktu proses
        System.out.println("Waktu Bubble Sort (Data Acak)   : " + lamabuble + " ns");

        // Tes Bubble Sort best case
        long statropbuble = System.nanoTime();
        bubbleSort(dataBestBubble); 
        long finishopbuble = System.nanoTime();
        long lamaopbuble  = finishopbuble - statropbuble;
        System.out.println("Waktu Bubble Sort (Best Case)   : " + lamaopbuble  + " ns");

        System.out.println(); // spasi kosong biar rapi outputnya

        // Tes Insertion Sort acak
        long mulaiInsert = System.nanoTime();
        insertionSort(Arrays.copyOf(dataAwal, dataAwal.length)); 
        long beresInsert = System.nanoTime();
        long waktuInsert = beresInsert - mulaiInsert;
        System.out.println("Waktu Insertion Sort (Data Acak): " + waktuInsert + " ns");

        // Tes Insertion Sort best case
        long mulaiInsertBest = System.nanoTime();
        insertionSort(dataBestInsert); 
        long beresInsertBest = System.nanoTime();
        long waktuInsertBest = beresInsertBest - mulaiInsertBest;
        System.out.println("Waktu Insertion Sort (Best Case): " + waktuInsertBest + " ns");

    }
}