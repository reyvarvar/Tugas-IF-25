#include <bits/stdc++.h>
using namespace std;

/* =========================================================
   1) STRUCT / TIPE DATA
   ========================================================= */
struct pertanyaan {
    string teks;
    string jawaban;
    string jenis;
    bool pilgan = false;
    string opsi[4];
};

struct pemain {
    string nama;
    int hp;
    int skor;
    int jarak;
};

struct monster {
    string nama;
    int hp;
    int damage;
};

/* =========================================================
   2) KONSTANTA & GLOBAL
   ========================================================= */
const int totalsoal = 101;

pertanyaan soalsd[totalsoal];
pertanyaan soalsmp[totalsoal];
pertanyaan soalsma[totalsoal];
pertanyaan soalkuliah[totalsoal];

/* =========================================================
   4) IMPLEMENTASI FUNCTION
   ========================================================= */

// ---------- UTIL ----------
void clear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void delay() {
#ifdef _WIN32
    system("pause");
#else
    cout << "Tekan ENTER untuk lanjut...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
#endif
}

// ---------- HELPER SOAL ----------
string kelassoal(int j){
    if(j==1) return "SD";
    if(j==2) return "SMP";
    if(j==3) return "SMA";
    if(j==4) return "Kuliah";
    return "Unknown";
}

int sekolah() {
    int pilihan;
    clear();

    cout << "====================================================================\n";
    cout << "                           PILIH JENJANG                             \n";
    cout << "====================================================================\n";
    cout << " [1] SD\n";
    cout << " [2] SMP\n";
    cout << " [3] SMA\n";
    cout << " [4] Kuliah\n";
    cout << "--------------------------------------------------------------------\n";
    cout << "Pilihan kamu: ";
    cin >> pilihan;

    return pilihan;
}

void pilgan(pertanyaan &soal, const string &teks, const string &jenis,
            char kunci, const string &a, const string &b, const string &c, const string &d) {
    soal.teks = teks;
    soal.jenis = jenis;
    soal.pilgan = true;
    soal.opsi[0] = a;
    soal.opsi[1] = b;
    soal.opsi[2] = c;
    soal.opsi[3] = d;
    soal.jawaban = string(1, (char)tolower(kunci));
}

void soalSD() {

    pilgan(soalsd[1], "Berapakah hasil 12 x 8.", "mtk", 'c', "86", "90", "96", "108");

    soalsd[2] = {"Berapakah hasil 144 dibagi 12. jawab angka","12","mtk"};

    pilgan(soalsd[3], "Pola: 3, 6, 12, 24, ... berikutnya adalah.", "logika", 'b', "30", "48", "36", "54");

    soalsd[4] = {"Jika kamu punya 15 permen lalu memberi teman 7, sisa berapa. jawab angka","8","logika"};


    pilgan(soalsd[5], "Keliling persegi dengan sisi 9 cm adalah.", "mtk", 'a', "36", "18", "81", "27");
    pilgan(soalsd[6], "Luas persegi panjang 8 cm x 6 cm adalah.", "mtk", 'd', "40", "24", "20", "48");
    pilgan(soalsd[7], "Hasil 250 + 175 adalah.", "mtk", 'b', "400", "425", "450", "475");
    pilgan(soalsd[8], "Hasil 1000 - 468 adalah.", "mtk", 'c', "512", "522", "532", "542");
    pilgan(soalsd[9], "Hasil 36 : 6 adalah.", "mtk", 'a', "6", "5", "7", "8");
    pilgan(soalsd[10], "Nilai pecahan 1/2 sama dengan.", "mtk", 'b', "0.25", "0.5", "0.75", "1.5");
    pilgan(soalsd[11], "Jika 3 lusin pensil berarti ada ... pensil.", "mtk", 'c', "24", "30", "36", "48");
    pilgan(soalsd[12], "Jika 1 jam = ... menit.", "mtk", 'd', "30", "50", "80", "60");
    pilgan(soalsd[13], "Jika 2 kg = ... gram.", "mtk", 'a', "2000", "200", "20", "20000");
    pilgan(soalsd[14], "Hasil 7 x 9 adalah.", "mtk", 'b', "54", "63", "72", "81");
    pilgan(soalsd[15], "KPK dari 6 dan 8 adalah.", "mtk", 'c', "12", "18", "24", "48");
    pilgan(soalsd[16], "FPB dari 12 dan 18 adalah.", "mtk", 'a', "6", "3", "9", "12");
    pilgan(soalsd[17], "Nilai 3/4 jika dibuat persen adalah.", "mtk", 'd', "25 persen", "50 persen", "60 persen", "75 persen");
    pilgan(soalsd[18], "Jumlah sudut segitiga adalah.", "mtk", 'c', "90", "270", "180", "360");
    pilgan(soalsd[19], "Bilangan prima terkecil adalah.", "mtk", 'a', "2", "1", "3", "0");
    pilgan(soalsd[20], "Angka Romawi dari 9 adalah.", "mtk", 'b', "XI", "IX", "IV", "VI");
    pilgan(soalsd[21], "Jika sebuah kubus memiliki 12 rusuk, maka jumlah sisi kubus adalah.", "mtk", 'c', "4", "5", "6", "8");
    pilgan(soalsd[22], "Hasil 15 + 27 + 18 adalah.", "mtk", 'd', "50", "55", "58", "60");
    pilgan(soalsd[23], "Jika 5 x 6 = 30, maka 50 x 6 = ...", "mtk", 'a', "300", "60", "250", "500");
    pilgan(soalsd[24], "Jika 120 dibagi 10 lalu dibagi 3 hasilnya.", "mtk", 'b', "3", "4", "5", "6");


    soalsd[25] = {"Pola: 5, 10, 15, 20, ... berikutnya apa. jawab angka","25","logika"};
    soalsd[26] = {"Jika semua burung bisa terbang dan elang adalah burung, elang bisa apa.","terbang","logika"};
    soalsd[27] = {"Jika hari ini Senin, 7 hari lagi hari apa.","senin","logika"};
    soalsd[28] = {"Jika 2 kotak masing-masing berisi 4 bola, total bola berapa. jawab angka","8","logika"};
    soalsd[29] = {"Mana yang bukan buah. jawab: apel atau wortel","wortel","logika"};
    soalsd[30] = {"Jika 9 dikurangi 3 dikali 2 hasilnya. jawab angka","3","logika"};
    soalsd[31] = {"Jika sekarang jam 6 dan 5 jam lagi, jadi jam berapa. jawab angka","11","logika"};
    soalsd[32] = {"Jika kamu punya 20 kelereng dan hilang 9, sisa berapa. jawab angka","11","logika"};
    soalsd[33] = {"Pola huruf: B, D, F, H, ... berikutnya apa","j","logika"};
    soalsd[34] = {"Jika 10 orang duduk 2 baris sama banyak, tiap baris ada berapa. jawab angka","5","logika"};
    soalsd[35] = {"Jika 3 x 4 = 12 maka 3 x 5 = ... jawab angka","15","logika"};
    soalsd[36] = {"Jika semua ikan hidup di air dan lele ikan, lele hidup di mana.","air","logika"};
    soalsd[37] = {"Jika angka ganjil berikutnya setelah 19 adalah. jawab angka","21","logika"};
    soalsd[38] = {"Jika 100 dibagi 4 hasilnya. jawab angka","25","logika"};
    soalsd[39] = {"Jika 8 + 7 - 5 hasilnya. jawab angka","10","logika"};
    soalsd[40] = {"Jika 1/2 dari 20 adalah. jawab angka","10","logika"};


    pilgan(soalsd[41], "Arah matahari terbit dari.", "geo", 'a', "Timur", "Barat", "Utara", "Selatan");
    pilgan(soalsd[42], "Tiruan bola bumi dalam bentuk kecil disebut.", "geo", 'b', "Peta", "Globe", "Atlas", "Kompas");
    pilgan(soalsd[43], "Benua terbesar di dunia adalah.", "geo", 'c', "Eropa", "Afrika", "Asia", "Amerika");
    pilgan(soalsd[44], "Samudra terluas di dunia adalah.", "geo", 'd', "Hindia", "Atlantik", "Arktik", "Pasifik");
    pilgan(soalsd[45], "Iklim Indonesia adalah.", "geo", 'a', "Tropis", "Subtropis", "Kutub", "Sedang");
    pilgan(soalsd[46], "Gunung tertinggi di dunia adalah.", "geo", 'c', "Fuji", "Kilimanjaro", "Everest", "Elbrus");
    pilgan(soalsd[47], "Pulau terbesar di Indonesia adalah.", "geo", 'b', "Jawa", "Kalimantan", "Bali", "Madura");
    pilgan(soalsd[48], "Ibu kota Indonesia adalah.", "geo", 'a', "Jakarta", "Bandung", "Surabaya", "Medan");
    pilgan(soalsd[49], "Alat penunjuk arah mata angin disebut.", "geo", 'd', "Atlas", "Peta", "Globe", "Kompas");
    pilgan(soalsd[50], "Garis khatulistiwa membagi bumi menjadi.", "geo", 'b', "3 bagian", "2 bagian", "4 bagian", "5 bagian");


    soalsd[51] = {"Ibu kota provinsi Bali adalah.","denpasar","geo"};
    soalsd[52] = {"Ada berapa musim di Indonesia. jawab angka","2","geo"};
    soalsd[53] = {"Samudra yang ada di sebelah selatan Indonesia adalah samudra apa.","hindia","geo"};
    soalsd[54] = {"Negara tetangga Indonesia di sebelah utara adalah Malaysia atau apa. jawab salah satunya","malaysia","geo"};
    soalsd[55] = {"Benua tempat Indonesia berada adalah.","asia","geo"};
    soalsd[56] = {"Gunung di Jawa Barat yang terkenal adalah Gunung apa. jawab salah satunya","tangkuban perahu","geo"};
    soalsd[57] = {"Sungai terpanjang di Indonesia berada di pulau apa.","kalimantan","geo"};
    soalsd[58] = {"Alat untuk melihat permukaan bumi dari atas menggunakan apa.","satelit","geo"};
    soalsd[59] = {"Pulau terpadat di Indonesia adalah.","jawa","geo"};
    soalsd[60] = {"Ibu kota Jawa Tengah adalah.","semarang","geo"};


    pilgan(soalsd[61], "Proklamasi kemerdekaan Indonesia terjadi pada tahun.", "sejarah", 'c', "1942", "1944", "1945", "1950");
    pilgan(soalsd[62], "Pahlawan yang dikenal dengan julukan Bapak Pendidikan adalah.", "sejarah", 'a', "Ki Hajar Dewantara", "Cut Nyak Dien", "Diponegoro", "Kartini");
    pilgan(soalsd[63], "Hari Sumpah Pemuda diperingati tanggal.", "sejarah", 'b', "20 Mei", "28 Oktober", "17 Agustus", "1 Juni");
    pilgan(soalsd[64], "Kerajaan Majapahit terkenal berada di pulau.", "sejarah", 'd', "Sumatera", "Kalimantan", "Sulawesi", "Jawa");
    pilgan(soalsd[65], "VOC berasal dari negara.", "sejarah", 'c', "Inggris", "Portugal", "Belanda", "Spanyol");
    pilgan(soalsd[66], "Pahlawan wanita dari Aceh adalah.", "sejarah", 'a', "Cut Nyak Dien", "Kartini", "Dewi Sartika", "Martha Christina");
    pilgan(soalsd[67], "Perang Diponegoro terjadi di pulau.", "sejarah", 'b', "Sumatera", "Jawa", "Bali", "Papua");
    pilgan(soalsd[68], "Indonesia dijajah Jepang mulai tahun.", "sejarah", 'd', "1930", "1935", "1940", "1942");
    pilgan(soalsd[69], "Tokoh proklamator Indonesia adalah.", "sejarah", 'c', "Sudirman", "Diponegoro", "Soekarno", "Pattimura");
    pilgan(soalsd[70], "Kerajaan Sriwijaya terkenal di daerah.", "sejarah", 'a', "Sumatera", "Jawa", "Bali", "Nusa Tenggara");


    soalsd[71] = {"Tanggal proklamasi kemerdekaan Indonesia.","17 agustus 1945","sejarah"};
    soalsd[72] = {"Siapa presiden pertama Indonesia.","soekarno","sejarah"};
    soalsd[73] = {"Siapa wakil presiden pertama Indonesia.","hatta","sejarah"};
    soalsd[74] = {"Kerajaan Islam pertama di Indonesia.","samudra pasai","sejarah"};
    soalsd[75] = {"Konferensi Asia Afrika diadakan di kota apa.","bandung","sejarah"};
    soalsd[76] = {"Organisasi pergerakan nasional pertama Indonesia.","budi utomo","sejarah"};
    soalsd[77] = {"Pahlawan dari Maluku bernama siapa.","pattimura","sejarah"};
    soalsd[78] = {"Tahun berdirinya Budi Utomo. jawab angka","1908","sejarah"};
    soalsd[79] = {"Nama kota tempat garis bujur 0 derajat.","greenwich","sejarah"};
    soalsd[80] = {"Penjajah pertama yang datang ke Indonesia.","portugal","sejarah"};


    pilgan(soalsd[81], "Jika 4 orang menyelesaikan tugas dalam 6 hari, 12 orang menyelesaikan tugas yang sama dalam.", "logika", 'b',
           "1 hari", "2 hari", "3 hari", "4 hari");
    pilgan(soalsd[82], "Mana yang berbeda sendiri.", "logika", 'c', "Kucing", "Sapi", "Ayam", "Meja");
    pilgan(soalsd[83], "Jika semua segitiga punya 3 sisi, maka segitiga pasti punya.", "logika", 'a',
           "3 sisi", "4 sisi", "5 sisi", "2 sisi");
    pilgan(soalsd[84], "Pola: 10, 20, 40, 80, ... berikutnya.", "logika", 'd', "90", "100", "120", "160");
    pilgan(soalsd[85], "Jika hari ini Rabu, maka 3 hari lagi adalah.", "logika", 'b', "Jumat", "Sabtu", "Minggu", "Senin");
    pilgan(soalsd[86], "Jika 5 x 5 = 25 maka 6 x 5 = ...", "logika", 'c', "25", "28", "30", "35");
    pilgan(soalsd[87], "Jika kamu punya 30 dan dibagi 3 sama rata, tiap bagian dapat.", "logika", 'a', "10", "12", "15", "8");
    pilgan(soalsd[88], "Mana yang termasuk alat transportasi.", "logika", 'd', "Meja", "Buku", "Kucing", "Kereta");
    pilgan(soalsd[89], "Jika 2, 5, 8, 11, ... angka berikutnya.", "logika", 'c', "12", "13", "14", "15");
    pilgan(soalsd[90], "Jika 9 lebih besar dari 7 dan 7 lebih besar dari 3, maka 9 lebih besar dari.", "logika", 'a', "3", "7", "9", "1");


    soalsd[91] = {"Jika 7 + 8 = berapa. jawab angka","15","mtk"};
    soalsd[92] = {"Jika 100 - 45 = berapa. jawab angka","55","mtk"};
    soalsd[93] = {"Jika 9 x 7 = berapa. jawab angka","63","mtk"};
    soalsd[94] = {"Jika 81 dibagi 9 = berapa. jawab angka","9","mtk"};
    soalsd[95] = {"Jika 1/4 dari 40 = berapa. jawab angka","10","mtk"};
    soalsd[96] = {"Jika keliling persegi sisi 5 cm = berapa. jawab angka","20","mtk"};
    soalsd[97] = {"Jika luas persegi sisi 6 cm = berapa. jawab angka","36","mtk"};
    soalsd[98] = {"Jika 3 jam = berapa menit. jawab angka","180","mtk"};
    soalsd[99] = {"Jika 2 liter = berapa mililiter. jawab angka","2000","mtk"};
    soalsd[100] = {"Jika 1 minggu = berapa hari. jawab angka","7","mtk"};

}


void soalSMP() {

    pilgan(soalsmp[1], "Hasil dari 15 x 12 adalah.", "mtk", 'b', "160", "180", "200", "210");

    soalsmp[2] = {"Hasil dari 225 dibagi 15 adalah. jawab angka","15","mtk"};

    pilgan(soalsmp[3], "Jika semua A adalah B dan semua B adalah C, maka kesimpulan yang benar adalah.", "logika", 'a',
           "Semua A adalah C", "Semua C adalah A", "Tidak ada A di C", "Tidak bisa disimpulkan");

    soalsmp[4] = {"Jika p benar dan q salah, maka p AND q bernilai apa. jawab: benar atau salah","salah","logika"};


    pilgan(soalsmp[5], "Nilai dari 2^5 adalah.", "mtk", 'c', "16", "24", "32", "64");
    pilgan(soalsmp[6], "Akar dari 169 adalah.", "mtk", 'a', "13", "12", "14", "15");
    pilgan(soalsmp[7], "Hasil 3/4 + 1/2 adalah.", "mtk", 'd', "1/4", "3/8", "5/8", "5/4");
    pilgan(soalsmp[8], "Jika 5x - 10 = 15 maka x = ...", "mtk", 'b', "3", "5", "6", "7");
    pilgan(soalsmp[9], "Keliling lingkaran dengan diameter 14 cm adalah. gunakan pi 22/7", "mtk", 'c', "22", "44", "44", "88");
    pilgan(soalsmp[10], "Luas segitiga alas 12 dan tinggi 8 adalah.", "mtk", 'a', "48", "96", "60", "72");
    pilgan(soalsmp[11], "Jika 2a = 18 maka a = ...", "mtk", 'd', "6", "7", "8", "9");
    pilgan(soalsmp[12], "Hasil 7^2 - 5^2 adalah.", "mtk", 'b', "12", "24", "49", "25");
    pilgan(soalsmp[13], "Jika 3x + 2 = 20 maka x = ...", "mtk", 'c', "5", "6", "6", "7");
    pilgan(soalsmp[14], "Nilai dari 0.25 dalam bentuk pecahan adalah.", "mtk", 'a', "1/4", "1/2", "3/4", "2/5");
    pilgan(soalsmp[15], "Jika sebuah persegi luasnya 81 maka sisinya adalah.", "mtk", 'd', "7", "8", "9", "10");
    pilgan(soalsmp[16], "Nilai x pada 2x + 5 = 25 adalah.", "mtk", 'c', "8", "10", "10", "12");
    pilgan(soalsmp[17], "Hasil 12! dibagi 11! adalah.", "mtk", 'b', "11", "12", "13", "22");
    pilgan(soalsmp[18], "Jika rasio 2:3 setara dengan ...", "mtk", 'a', "4:6", "4:5", "6:8", "8:10");
    pilgan(soalsmp[19], "Rata-rata dari 6, 8, 10, 12 adalah.", "mtk", 'd', "8", "9", "10", "9");
    pilgan(soalsmp[20], "Jika 1/5 dari x adalah 10 maka x = ...", "mtk", 'c', "40", "45", "50", "60");
    pilgan(soalsmp[21], "Persentase 25 dari 200 adalah.", "mtk", 'b', "10 persen", "12.5 persen", "20 persen", "25 persen");
    pilgan(soalsmp[22], "Jika 2/3 dari 90 adalah.", "mtk", 'a', "60", "45", "30", "75");
    pilgan(soalsmp[23], "Hasil 4(3 + 5) adalah.", "mtk", 'd', "20", "24", "28", "32");
    pilgan(soalsmp[24], "Jika x = 3 maka 2x^2 + x = ...", "mtk", 'c', "15", "18", "21", "24");


    soalsmp[25] = {"Jika hari ini Selasa maka 10 hari lagi hari apa.","jumat","logika"};
    soalsmp[26] = {"Jika 5 pensil harganya 15000 maka 1 pensil harga berapa. jawab angka","3000","logika"};
    soalsmp[27] = {"Jika p salah maka negasi p bernilai apa.","benar","logika"};
    soalsmp[28] = {"Jika 3 orang kerja selesai 12 jam maka 1 orang butuh berapa jam. jawab angka","36","logika"};
    soalsmp[29] = {"Pola 1, 3, 6, 10, 15 berikutnya apa. jawab angka","21","logika"};
    soalsmp[30] = {"Jika 40 dibagi 6 sisa berapa. jawab angka","4","logika"};
    soalsmp[31] = {"Jika semua siswa kelas 7 pakai seragam putih dan kamu siswa kelas 7 seragam kamu apa.","putih","logika"};
    soalsmp[32] = {"Jika 2x = 30 maka x berapa. jawab angka","15","logika"};
    soalsmp[33] = {"Jika 9 lebih besar dari 4 dan 4 lebih besar dari 2 maka 9 lebih besar dari berapa. jawab angka","2","logika"};
    soalsmp[34] = {"Jika 120 dibagi 8 hasilnya berapa. jawab angka","15","logika"};
    soalsmp[35] = {"Jika kamu punya 50 dan memberi 17 sisa berapa. jawab angka","33","logika"};
    soalsmp[36] = {"Jika sekarang jam 18 dan 7 jam lagi jam berapa. jawab angka","1","logika"};
    soalsmp[37] = {"Jika 4 kotak masing-masing 3 bola total berapa. jawab angka","12","logika"};
    soalsmp[38] = {"Mana yang ganjil 14 16 19 22 jawab angkanya","19","logika"};
    soalsmp[39] = {"Jika 11 x 11 hasilnya berapa. jawab angka","121","logika"};
    soalsmp[40] = {"Jika 1/4 dari 80 adalah berapa. jawab angka","20","logika"};


    pilgan(soalsmp[41], "Lapisan udara yang menyelimuti bumi disebut.", "geo", 'b', "Litosfer", "Atmosfer", "Hidrosfer", "Biosfer");
    pilgan(soalsmp[42], "Perpindahan penduduk dari desa ke kota disebut.", "geo", 'c', "Migrasi", "Transmigrasi", "Urbanisasi", "Emigrasi");
    pilgan(soalsmp[43], "Garis bujur 0 derajat melewati kota.", "geo", 'd', "Paris", "Roma", "Berlin", "Greenwich");
    pilgan(soalsmp[44], "Negara Asia Tenggara yang tidak punya laut adalah.", "geo", 'a', "Laos", "Thailand", "Vietnam", "Malaysia");
    pilgan(soalsmp[45], "Batas wilayah Indonesia di sebelah utara adalah negara.", "geo", 'b', "Australia", "Malaysia", "Timor Leste", "Papua Nugini");
    pilgan(soalsmp[46], "Samudra terluas di dunia adalah.", "geo", 'c', "Atlantik", "Hindia", "Pasifik", "Arktik");
    pilgan(soalsmp[47], "Iklim Indonesia adalah.", "geo", 'a', "Tropis", "Kutub", "Sedang", "Subtropis");
    pilgan(soalsmp[48], "Benua terkecil di dunia adalah.", "geo", 'd', "Asia", "Afrika", "Eropa", "Australia");
    pilgan(soalsmp[49], "Gunung tertinggi di Indonesia adalah.", "geo", 'b', "Merapi", "Puncak Jaya", "Semeru", "Kerinci");
    pilgan(soalsmp[50], "Danau terbesar di Indonesia adalah.", "geo", 'a', "Toba", "Poso", "Sentani", "Singkarak");


    soalsmp[51] = {"Ibu kota provinsi Jawa Timur adalah apa.","surabaya","geo"};
    soalsmp[52] = {"Pulau terpadat penduduknya di Indonesia adalah.","jawa","geo"};
    soalsmp[53] = {"Benua tempat Indonesia berada adalah.","asia","geo"};
    soalsmp[54] = {"Alat untuk mengukur gempa disebut apa.","seismograf","geo"};
    soalsmp[55] = {"Angin muson barat membawa musim apa di Indonesia.","hujan","geo"};
    soalsmp[56] = {"Batas laut Indonesia di sebelah selatan adalah samudra apa.","hindia","geo"};
    soalsmp[57] = {"Gunung meletus termasuk tenaga pembentuk muka bumi dari dalam disebut apa.","endogen","geo"};
    soalsmp[58] = {"Proses pengikisan pantai oleh gelombang laut disebut apa.","abrasi","geo"};
    soalsmp[59] = {"Peta yang menampilkan tinggi rendah permukaan bumi disebut peta apa.","topografi","geo"};
    soalsmp[60] = {"Garis yang membagi bumi menjadi belahan utara dan selatan disebut apa.","khatulistiwa","geo"};


    pilgan(soalsmp[61], "Proklamasi kemerdekaan Indonesia terjadi pada tanggal.", "sejarah", 'c', "20 Mei 1908", "28 Oktober 1928", "17 Agustus 1945", "1 Juni 1945");
    pilgan(soalsmp[62], "Konferensi Asia Afrika diadakan di kota.", "sejarah", 'b', "Jakarta", "Bandung", "Surabaya", "Medan");
    pilgan(soalsmp[63], "Perang Diponegoro terjadi pada tahun.", "sejarah", 'd', "1810", "1820", "1823", "1825");
    pilgan(soalsmp[64], "VOC berasal dari negara.", "sejarah", 'a', "Belanda", "Inggris", "Portugal", "Spanyol");
    pilgan(soalsmp[65], "Organisasi pergerakan nasional pertama Indonesia adalah.", "sejarah", 'c', "PNI", "Sarekat Islam", "Budi Utomo", "PKI");
    pilgan(soalsmp[66], "Kerajaan Hindu tertua di Indonesia adalah.", "sejarah", 'b', "Majapahit", "Kutai", "Sriwijaya", "Mataram");
    pilgan(soalsmp[67], "Perjanjian Linggarjati terjadi tahun.", "sejarah", 'a', "1946", "1947", "1948", "1949");
    pilgan(soalsmp[68], "Tokoh pahlawan dari Maluku adalah.", "sejarah", 'd', "Sudirman", "Diponegoro", "Imam Bonjol", "Pattimura");
    pilgan(soalsmp[69], "Sumpah Pemuda diperingati setiap tanggal.", "sejarah", 'b', "17 Agustus", "28 Oktober", "1 Juni", "20 Mei");
    pilgan(soalsmp[70], "Tanam paksa dicetuskan oleh.", "sejarah", 'c', "Daendels", "Raffles", "Van den Bosch", "Snouck Hurgronje");


    soalsmp[71] = {"Siapa presiden pertama Indonesia.","soekarno","sejarah"};
    soalsmp[72] = {"Siapa wakil presiden pertama Indonesia.","hatta","sejarah"};
    soalsmp[73] = {"Tahun berdirinya Budi Utomo. jawab angka","1908","sejarah"};
    soalsmp[74] = {"Nama kerajaan Islam pertama di Indonesia.","samudra pasai","sejarah"};
    soalsmp[75] = {"Nama pahlawan wanita dari Aceh.","cut nyak dien","sejarah"};
    soalsmp[76] = {"Nama kota tempat BPUPKI bersidang pertama kali.","jakarta","sejarah"};
    soalsmp[77] = {"Peristiwa Rengasdengklok terjadi tahun berapa. jawab angka","1945","sejarah"};
    soalsmp[78] = {"Nama tempat pembacaan proklamasi.","pegangsaan timur 56","sejarah"};
    soalsmp[79] = {"Kerajaan Sriwijaya berpusat di mana.","palembang","sejarah"};
    soalsmp[80] = {"Siapa tokoh bapak pendidikan Indonesia.","ki hajar dewantara","sejarah"};


    pilgan(soalsmp[81], "Jika 6 pekerja menyelesaikan pekerjaan dalam 10 hari, 15 pekerja menyelesaikan pekerjaan yang sama dalam.", "logika", 'b',
           "2 hari", "4 hari", "6 hari", "8 hari");
    pilgan(soalsmp[82], "Jika hari ini Jumat, maka 17 hari lagi adalah hari.", "logika", 'c',
           "Senin", "Selasa", "Rabu", "Kamis");
    pilgan(soalsmp[83], "Pola: 2, 5, 11, 23, ... berikutnya.", "logika", 'd',
           "45", "46", "47", "47");
    pilgan(soalsmp[84], "Jika semua bilangan kelipatan 4 genap, maka 28 itu.", "logika", 'a',
           "Genap", "Ganjil", "Prima", "Tidak tentu");
    pilgan(soalsmp[85], "Jika 3/5 siswa hadir, dan total 40 siswa, yang hadir adalah.", "logika", 'b',
           "20", "24", "30", "32");
    pilgan(soalsmp[86], "Jika p benar dan q salah, maka p XOR q bernilai.", "logika", 'c',
           "Benar", "Salah", "Benar", "Tidak tentu");
    pilgan(soalsmp[87], "Jika 2 orang menyelesaikan tugas 6 jam, maka 3 orang menyelesaikan tugas yang sama dalam.", "logika", 'a',
           "4 jam", "6 jam", "8 jam", "10 jam");
    pilgan(soalsmp[88], "Mana yang berbeda sendiri.", "logika", 'd',
           "Persegi", "Lingkaran", "Segitiga", "Kucing");
    pilgan(soalsmp[89], "Jika A lebih besar dari B dan B lebih besar dari C maka A lebih besar dari.", "logika", 'a',
           "C", "B", "A", "Tidak tentu");
    pilgan(soalsmp[90], "Jika 1/2 dari 60 ditambah 1/3 dari 60 adalah.", "logika", 'c',
           "40", "45", "50", "55");


    soalsmp[91] = {"Jika 7^2 adalah berapa. jawab angka","49","mtk"};
    soalsmp[92] = {"Jika 60 persen dari 200 adalah berapa. jawab angka","120","mtk"};
    soalsmp[93] = {"Jika 0.75 dalam pecahan paling sederhana adalah apa.","3/4","mtk"};
    soalsmp[94] = {"Jika keliling persegi sisi 12 adalah berapa. jawab angka","48","mtk"};
    soalsmp[95] = {"Jika luas persegi panjang 15 x 9 adalah berapa. jawab angka","135","mtk"};
    soalsmp[96] = {"Jika 3x + 9 = 0 maka x berapa. jawab angka","-3","mtk"};
    soalsmp[97] = {"Jika 2/5 dari 100 adalah berapa. jawab angka","40","mtk"};
    soalsmp[98] = {"Jika 3600 detik sama dengan berapa jam. jawab angka","1","mtk"};
    soalsmp[99] = {"Jika FPB dari 24 dan 36 adalah berapa. jawab angka","12","mtk"};
    soalsmp[100] = {"Jika KPK dari 9 dan 12 adalah berapa. jawab angka","36","mtk"};

}

void soalSMA() {

    pilgan(soalsma[1], "Nilai dari 2^8 adalah.", "mtk", 'c', "128", "200", "256", "512");

    soalsma[2] = {"Nilai dari log basis 10 dari 1000 adalah. jawab angka","3","mtk"};

    pilgan(soalsma[3], "Jika semua P adalah Q dan tidak ada Q yang R, maka kesimpulan yang benar adalah.", "logika", 'b',
           "Semua R adalah P", "Tidak ada P yang R", "Semua Q adalah P", "Semua R adalah Q");

    soalsma[4] = {"Jika (p -> q) salah, maka p bernilai apa. jawab benar atau salah","benar","logika"};


    pilgan(soalsma[5], "Jika 2^x = 32 maka x = ...", "mtk", 'c', "4", "6", "5", "8");
    pilgan(soalsma[6], "Turunan dari f(x)=3x^2 adalah.", "mtk", 'a', "6x", "3x", "6x^2", "9x");
    pilgan(soalsma[7], "Integral dari 6x dx adalah.", "mtk", 'b', "6x + C", "3x^2 + C", "x^2 + C", "12x^2 + C");
    pilgan(soalsma[8], "Jika sin 30 = 1/2 maka cos 60 adalah.", "mtk", 'd', "0", "1", "sqrt(3)/2", "1/2");
    pilgan(soalsma[9], "Nilai dari log basis 2 dari 64 adalah.", "mtk", 'a', "6", "8", "5", "4");
    pilgan(soalsma[10], "Jika x^2 - 5x + 6 = 0 maka x = ...", "mtk", 'c', "1 dan 6", "2 dan 5", "2 dan 3", "3 dan 4");
    pilgan(soalsma[11], "Nilai determinan matriks [[1,2],[3,7]] adalah.", "mtk", 'b', "1", "1", "5", "-5");
    pilgan(soalsma[12], "Jika a_n = 3n + 2 maka a_5 = ...", "mtk", 'd', "14", "15", "16", "17");
    pilgan(soalsma[13], "Jumlah deret aritmetika 2+5+8+...+29 adalah.", "mtk", 'a', "155", "160", "165", "170");
    pilgan(soalsma[14], "Jika (x-1)(x+4)=0 maka x = ...", "mtk", 'b', "-1 dan 4", "1 dan -4", "1 dan 4", "-1 dan -4");
    pilgan(soalsma[15], "Nilai dari sin^2 0 + cos^2 0 adalah.", "mtk", 'c', "0", "2", "1", "1/2");
    pilgan(soalsma[16], "Limit x ke 0 dari sin x / x adalah.", "mtk", 'a', "1", "0", "tak hingga", "-1");
    pilgan(soalsma[17], "Jika 3 log 9 berarti log basis 3 dari 9 nilainya.", "mtk", 'b', "1", "2", "3", "4");
    pilgan(soalsma[18], "Jika jumlah peluang semua kejadian adalah.", "mtk", 'd', "0", "2", "1/2", "1");
    pilgan(soalsma[19], "Jika titik potong sumbu y fungsi y=2x+5 adalah.", "mtk", 'a', "5", "2", "-5", "0");
    pilgan(soalsma[20], "Jika gradien garis y=4x-3 adalah.", "mtk", 'c', "3", "-3", "4", "-4");
    pilgan(soalsma[21], "Jika 5C2 adalah.", "mtk", 'b', "5", "10", "15", "20");
    pilgan(soalsma[22], "Jika 5P2 adalah.", "mtk", 'd', "10", "15", "20", "20");
    pilgan(soalsma[23], "Jika (a+b)^2 adalah.", "mtk", 'a', "a^2+2ab+b^2", "a^2-ab+b^2", "a^2+ab+b^2", "a^2+2a+b^2");
    pilgan(soalsma[24], "Nilai cos 180 derajat adalah.", "mtk", 'b', "1", "-1", "0", "1/2");


    soalsma[25] = {"Jika p benar dan q salah maka p OR q bernilai apa.","benar","logika"};
    soalsma[26] = {"Negasi dari 'Semua siswa hadir' adalah apa.","ada siswa tidak hadir","logika"};
    soalsma[27] = {"Jika 3 orang menyelesaikan kerja 6 hari maka 1 orang butuh berapa hari. jawab angka","18","logika"};
    soalsma[28] = {"Jika 100 dibagi 8 sisa berapa. jawab angka","4","logika"};
    soalsma[29] = {"Pola 2,3,5,8,13 berikutnya apa. jawab angka","21","logika"};
    soalsma[30] = {"Jika A lebih besar dari B dan B lebih besar dari C maka A lebih besar dari siapa.","c","logika"};
    soalsma[31] = {"Jika semua bilangan genap habis dibagi 2 maka 48 habis dibagi 2 atau tidak. jawab ya atau tidak","ya","logika"};
    soalsma[32] = {"Jika sekarang jam 23 dan 4 jam lagi jam berapa. jawab angka","3","logika"};
    soalsma[33] = {"Jika (p AND q) benar maka q bernilai apa. jawab benar atau salah","benar","logika"};
    soalsma[34] = {"Jika (p OR q) salah maka p bernilai apa. jawab benar atau salah","salah","logika"};
    soalsma[35] = {"Jika 7! dibagi 6! adalah berapa. jawab angka","7","logika"};
    soalsma[36] = {"Jika 2^6 adalah berapa. jawab angka","64","logika"};
    soalsma[37] = {"Jika 25 persen dari 160 adalah berapa. jawab angka","40","logika"};
    soalsma[38] = {"Jika 0.2 dalam pecahan paling sederhana adalah apa.","1/5","logika"};
    soalsma[39] = {"Jika 9 lebih besar dari 3 dan 3 lebih besar dari 1 maka 9 lebih besar dari berapa. jawab angka","1","logika"};
    soalsma[40] = {"Jika 5x = 35 maka x berapa. jawab angka","7","logika"};


    pilgan(soalsma[41], "Ilmu teknik pembuatan peta disebut.", "geo", 'a', "Kartografi", "Geologi", "Meteorologi", "Oseanografi");
    pilgan(soalsma[42], "Lapisan atmosfer tempat cuaca terjadi adalah.", "geo", 'd', "Stratosfer", "Mesosfer", "Termosfer", "Troposfer");
    pilgan(soalsma[43], "Pengikisan tanah oleh air laut disebut.", "geo", 'a', "Abrasi", "Erosi", "Sedimentasi", "Deflasi");
    pilgan(soalsma[44], "Pusat gempa di dalam perut bumi disebut.", "geo", 'c', "Episentrum", "Seismograf", "Hiposentrum", "Litosfer");
    pilgan(soalsma[45], "Data SIG berbentuk piksel disebut data.", "geo", 'b', "Vektor", "Raster", "Kontur", "Poligon");
    pilgan(soalsma[46], "Angka kelahiran per 1000 penduduk disebut.", "geo", 'c', "Mortalitas", "Migrasi", "Natalitas", "Urbanisasi");
    pilgan(soalsma[47], "Batuan yang terbentuk dari magma membeku disebut batuan.", "geo", 'a', "Beku", "Sedimen", "Metamorf", "Gamping");
    pilgan(soalsma[48], "Pola pemukiman di sepanjang sungai biasanya berbentuk.", "geo", 'd', "Melingkar", "Mengelompok", "Menyebar", "Linear");
    pilgan(soalsma[49], "Desa yang mampu memenuhi kebutuhan sendiri dan menjual kelebihan hasil disebut desa.", "geo", 'b', "Swadaya", "Swasembada", "Berkembang", "Tertinggal");
    pilgan(soalsma[50], "Garis pada peta yang menghubungkan tempat dengan ketinggian sama disebut.", "geo", 'c', "Isobar", "Isoterm", "Kontur", "Isohyet");


    soalsma[51] = {"Angin yang bertiup dari benua Asia ke Australia disebut angin apa.","muson barat","geo"};
    soalsma[52] = {"Proses pelapukan batuan karena perubahan suhu disebut pelapukan apa.","fisika","geo"};
    soalsma[53] = {"Lapisan bumi paling luar disebut apa.","litosfer","geo"};
    soalsma[54] = {"Benua terbesar di dunia adalah.","asia","geo"};
    soalsma[55] = {"Samudra terluas di dunia adalah.","pasifik","geo"};
    soalsma[56] = {"Garis khatulistiwa berada pada lintang berapa derajat. jawab angka","0","geo"};
    soalsma[57] = {"Ibu kota provinsi Sumatera Utara adalah.","medan","geo"};
    soalsma[58] = {"Gunung tertinggi di dunia adalah.","everest","geo"};
    soalsma[59] = {"Hujan karena udara naik di lereng gunung disebut hujan apa.","orografis","geo"};
    soalsma[60] = {"Proses perpindahan penduduk dari desa ke kota disebut apa.","urbanisasi","geo"};


    pilgan(soalsma[61], "Perang Dunia II berakhir pada tahun.", "sejarah", 'c', "1942", "1943", "1945", "1950");
    pilgan(soalsma[62], "Konferensi Meja Bundar terjadi pada tahun.", "sejarah", 'd', "1946", "1947", "1948", "1949");
    pilgan(soalsma[63], "Sumpah Pemuda terjadi pada tahun.", "sejarah", 'b', "1908", "1928", "1945", "1955");
    pilgan(soalsma[64], "VOC dibubarkan pada tahun.", "sejarah", 'a', "1799", "1808", "1811", "1825");
    pilgan(soalsma[65], "Perang Diponegoro berlangsung tahun 1825 sampai.", "sejarah", 'c', "1827", "1828", "1830", "1835");
    pilgan(soalsma[66], "Sarekat Islam didirikan oleh.", "sejarah", 'b', "Soekarno", "Haji Samanhudi", "Hatta", "Kartini");
    pilgan(soalsma[67], "Kerajaan Majapahit mencapai puncak kejayaan pada masa.", "sejarah", 'd', "Ken Arok", "Airlangga", "Raden Wijaya", "Hayam Wuruk");
    pilgan(soalsma[68], "Perjanjian Linggarjati ditandatangani tahun.", "sejarah", 'a', "1946", "1947", "1948", "1949");
    pilgan(soalsma[69], "Konferensi Asia Afrika dilaksanakan tahun.", "sejarah", 'c', "1950", "1953", "1955", "1960");
    pilgan(soalsma[70], "BPUPKI dibentuk oleh.", "sejarah", 'b', "Belanda", "Jepang", "Inggris", "Amerika");


    soalsma[71] = {"Tokoh proklamator Indonesia.","soekarno","sejarah"};
    soalsma[72] = {"Wakil proklamator Indonesia.","hatta","sejarah"};
    soalsma[73] = {"Tanggal proklamasi kemerdekaan Indonesia.","17 agustus 1945","sejarah"};
    soalsma[74] = {"Isi utama sumpah pemuda salah satunya satu bahasa yaitu.","indonesia","sejarah"};
    soalsma[75] = {"Kerajaan maritim besar di Sumatera pada masa lampau adalah.","sriwijaya","sejarah"};
    soalsma[76] = {"Kerajaan hindu tertua di Indonesia adalah.","kutai","sejarah"};
    soalsma[77] = {"Tanam paksa dicetuskan oleh siapa.","van den bosch","sejarah"};
    soalsma[78] = {"Perang Aceh terjadi melawan negara apa.","belanda","sejarah"};
    soalsma[79] = {"Kota tempat proklamasi dibacakan.","jakarta","sejarah"};
    soalsma[80] = {"Organisasi pergerakan nasional pertama Indonesia.","budi utomo","sejarah"};


    pilgan(soalsma[81], "Jika (p -> q) benar dan q salah, maka p bernilai.", "logika", 'b',
           "Benar", "Salah", "Tidak tentu", "Tidak bisa ditentukan");
    pilgan(soalsma[82], "Pernyataan yang setara dengan 'Jika hujan maka jalan basah' adalah.", "logika", 'a',
           "Jika jalan tidak basah maka tidak hujan", "Jika tidak hujan maka jalan tidak basah", "Jika jalan basah maka hujan", "Jalan basah dan hujan");
    pilgan(soalsma[83], "Nilai kebenaran (True XOR False) adalah.", "logika", 'a',
           "True", "False", "Tidak tentu", "Error");
    pilgan(soalsma[84], "Jika A = {1,2,3,4} dan B = {3,4,5} maka A ∩ B adalah.", "logika", 'c',
           "{1,2}", "{4,5}", "{3,4}", "{ }");
    pilgan(soalsma[85], "Jika semua bilangan prima ganjil kecuali 2, maka 2 itu.", "logika", 'd',
           "Ganjil", "Komposit", "Tidak tentu", "Prima");
    pilgan(soalsma[86], "Jika 4 orang menyelesaikan kerja 12 hari, maka 6 orang menyelesaikan kerja yang sama dalam.", "logika", 'b',
           "6 hari", "8 hari", "10 hari", "12 hari");
    pilgan(soalsma[87], "Pola: 1, 2, 6, 24, ... berikutnya.", "logika", 'c',
           "60", "96", "120", "144");
    pilgan(soalsma[88], "Jika x > y dan y > z maka kesimpulan benar adalah.", "logika", 'b',
           "z > x", "x > z", "x = z", "Tidak bisa ditentukan");
    pilgan(soalsma[89], "Jika peluang muncul angka pada dadu adalah.", "logika", 'a',
           "1/6", "1/3", "1/2", "1/4");
    pilgan(soalsma[90], "Jika 3/4 dari 80 ditambah 1/5 dari 100 adalah.", "logika", 'd',
           "70", "75", "78", "80");


    soalsma[91] = {"Jika integral dari 2x adalah apa.","x^2 + C","mtk"};
    soalsma[92] = {"Jika turunan dari 5x^4 adalah apa.","20x^3","mtk"};
    soalsma[93] = {"Jika limit x ke tak hingga dari 1/x adalah berapa. jawab angka","0","mtk"};
    soalsma[94] = {"Jika sin 0 derajat adalah berapa. jawab angka","0","mtk"};
    soalsma[95] = {"Jika cos 0 derajat adalah berapa. jawab angka","1","mtk"};
    soalsma[96] = {"Jika FPB dari 48 dan 60 adalah berapa. jawab angka","12","mtk"};
    soalsma[97] = {"Jika KPK dari 15 dan 20 adalah berapa. jawab angka","60","mtk"};
    soalsma[98] = {"Jika 25 persen dari 360 adalah berapa. jawab angka","90","mtk"};
    soalsma[99] = {"Jika 0.125 dalam pecahan adalah apa.","1/8","mtk"};
    soalsma[100] = {"Jika jumlah sudut segitiga adalah berapa derajat. jawab angka","180","mtk"};

}

void soalKuliah() {

    pilgan(soalkuliah[1], "Turunan dari sin x adalah.", "mtk", 'a', "cos x", "-cos x", "sin x", "-sin x");

    soalkuliah[2] = {"Turunan dari cos x adalah apa.","-sin x","mtk"};

    pilgan(soalkuliah[3], "Negasi dari pernyataan 'Semua mahasiswa hadir' adalah.", "logika", 'b',
           "Semua mahasiswa tidak hadir", "Ada mahasiswa yang tidak hadir", "Tidak ada mahasiswa hadir", "Semua hadir dan tidak hadir");

    soalkuliah[4] = {"Jika (p AND q) benar, maka p bernilai apa. jawab benar atau salah","benar","logika"};


    pilgan(soalkuliah[5], "Integral dari 1/x dx adalah.", "mtk", 'c', "1/x + C", "x + C", "ln x + C", "e^x + C");
    pilgan(soalkuliah[6], "Limit x menuju tak hingga dari (1 + 1/x)^x adalah.", "mtk", 'd', "0", "1", "pi", "e");
    pilgan(soalkuliah[7], "Determinan matriks [[1,2],[3,4]] adalah.", "mtk", 'a', "-2", "2", "1", "0");
    pilgan(soalkuliah[8], "Jika 2^x = 256 maka x = ...", "mtk", 'b', "6", "8", "10", "12");
    pilgan(soalkuliah[9], "Integral dari 2x dx adalah.", "mtk", 'a', "x^2 + C", "2x^2 + C", "x + C", "2x + C");
    pilgan(soalkuliah[10], "Turunan dari ln x adalah.", "mtk", 'c', "ln x", "x", "1/x", "e^x");
    pilgan(soalkuliah[11], "Nilai log basis 10 dari 100000 adalah.", "mtk", 'd', "3", "4", "5", "6");
    pilgan(soalkuliah[12], "Jika sin 30 = 1/2 maka cos 60 adalah.", "mtk", 'b', "0", "1/2", "1", "sqrt(3)/2");
    pilgan(soalkuliah[13], "Jika (x-2)(x+5)=0 maka x = ...", "mtk", 'a', "2 dan -5", "-2 dan 5", "2 dan 5", "-2 dan -5");
    pilgan(soalkuliah[14], "Integral dari e^x dx adalah.", "mtk", 'a', "e^x + C", "x e^x + C", "ln x + C", "1/x + C");
    pilgan(soalkuliah[15], "Jika 5C2 nilainya adalah.", "mtk", 'c', "5", "8", "10", "20");
    pilgan(soalkuliah[16], "Jika 5P2 nilainya adalah.", "mtk", 'b', "10", "20", "5", "25");
    pilgan(soalkuliah[17], "Jika peluang satu kejadian pasti adalah.", "mtk", 'd', "0", "1/2", "2", "1");
    pilgan(soalkuliah[18], "Jika x^2 - 9 = 0 maka x = ...", "mtk", 'a', "3 dan -3", "9 dan -9", "3", "-3");
    pilgan(soalkuliah[19], "Nilai dari i^2 adalah.", "mtk", 'c', "1", "0", "-1", "i");
    pilgan(soalkuliah[20], "Jika matriks A berordo 3x2 maka jumlah elemennya adalah.", "mtk", 'b', "5", "6", "8", "9");
    pilgan(soalkuliah[21], "Turunan dari x^5 adalah.", "mtk", 'a', "5x^4", "x^4", "5x", "x^5");
    pilgan(soalkuliah[22], "Integral dari sin x dx adalah.", "mtk", 'd', "cos x + C", "sin x + C", "tan x + C", "-cos x + C");
    pilgan(soalkuliah[23], "Integral dari cos x dx adalah.", "mtk", 'b', "cos x + C", "sin x + C", "-sin x + C", "-cos x + C");
    pilgan(soalkuliah[24], "Jika a_n = 2n - 1 maka a_10 adalah.", "mtk", 'c', "18", "19", "19", "21");


    soalkuliah[25] = {"Jika (p OR q) salah, maka q bernilai apa. jawab benar atau salah","salah","logika"};
    soalkuliah[26] = {"Jika (p -> q) salah, maka p bernilai apa. jawab benar atau salah","benar","logika"};
    soalkuliah[27] = {"Jika 3 orang menyelesaikan kerja 6 hari, 1 orang butuh berapa hari. jawab angka","18","logika"};
    soalkuliah[28] = {"Jika 12 dibagi 5 sisa berapa. jawab angka","2","logika"};
    soalkuliah[29] = {"Pola: 1, 1, 2, 3, 5, 8 berikutnya apa. jawab angka","13","logika"};
    soalkuliah[30] = {"Jika semua dosen mengajar dan kamu dosen, kamu apa.","mengajar","logika"};
    soalkuliah[31] = {"Jika p salah, negasi p bernilai apa.","benar","logika"};
    soalkuliah[32] = {"Jika 2^7 nilainya berapa. jawab angka","128","logika"};
    soalkuliah[33] = {"Jika 25 persen dari 400 adalah berapa. jawab angka","100","logika"};
    soalkuliah[34] = {"Jika x > 3 dan x < 5, nilai bulat x berapa. jawab angka","4","logika"};
    soalkuliah[35] = {"Jika (p AND q) benar maka q bernilai apa. jawab benar atau salah","benar","logika"};
    soalkuliah[36] = {"Jika (p AND q) salah dan p benar maka q bernilai apa. jawab benar atau salah","salah","logika"};
    soalkuliah[37] = {"Jika sekarang jam 22 dan 5 jam lagi jam berapa. jawab angka","3","logika"};
    soalkuliah[38] = {"Jika 7 dikali 9 hasilnya berapa. jawab angka","63","logika"};
    soalkuliah[39] = {"Jika 100 dibagi 4 sisa berapa. jawab angka","0","logika"};
    soalkuliah[40] = {"Jika semua segitiga punya 3 sisi maka segitiga punya berapa sisi. jawab angka","3","logika"};


    pilgan(soalkuliah[41], "Zona pertemuan lempeng yang membuat Indonesia aktif tektonik dikenal sebagai.", "geo", 'a', "Cincin Api Pasifik", "Garis Wallace", "Dataran Sunda", "Sabuk Atlantik");
    pilgan(soalkuliah[42], "Garis tekanan udara sama pada peta cuaca disebut.", "geo", 'b', "Isohyet", "Isobar", "Isoterm", "Isoline");
    pilgan(soalkuliah[43], "Hujan karena massa udara naik di lereng pegunungan disebut.", "geo", 'c', "Konveksi", "Frontal", "Orografis", "Siklonal");
    pilgan(soalkuliah[44], "Arus laut panas dari pantai timur Amerika Utara menuju Eropa Barat bernama.", "geo", 'd', "Kuroshio", "Labrador", "Humboldt", "Gulf Stream");
    pilgan(soalkuliah[45], "Lapisan atmosfer pemantul gelombang radio untuk komunikasi jauh adalah.", "geo", 'a', "Ionosfer", "Troposfer", "Stratosfer", "Mesosfer");
    pilgan(soalkuliah[46], "Garis pada peta yang menghubungkan tempat dengan suhu sama disebut.", "geo", 'c', "Isobar", "Isohyet", "Isoterm", "Kontur");
    pilgan(soalkuliah[47], "Proses perubahan batuan padat menjadi tanah akibat pelapukan disebut.", "geo", 'b', "Erosi", "Pedogenesis", "Sedimentasi", "Abrasi");
    pilgan(soalkuliah[48], "Konsep ruang dan jarak menyusut karena kemajuan transportasi disebut.", "geo", 'd', "Globalisasi", "Urbanisasi", "Difusi", "Time space compression");
    pilgan(soalkuliah[49], "Model perubahan tingkat kelahiran dan kematian seiring perkembangan ekonomi disebut.", "geo", 'a', "Model transisi demografi", "Model migrasi", "Model urban", "Model klimatologi");
    pilgan(soalkuliah[50], "Pola aliran sungai pada wilayah batuan homogen dan relatif datar biasanya.", "geo", 'c', "Radial", "Trellis", "Dendritik", "Rektangular");


    soalkuliah[51] = {"Ilmu yang mengkaji bentuk permukaan bumi beserta proses pembentukannya disebut apa.","geomorfologi","geo"};
    soalkuliah[52] = {"Proses pelapukan batuan karena reaksi kimia disebut pelapukan apa.","kimia","geo"};
    soalkuliah[53] = {"Garis lintang 0 derajat disebut apa.","khatulistiwa","geo"};
    soalkuliah[54] = {"Batuan yang terbentuk dari magma yang membeku disebut batuan apa.","beku","geo"};
    soalkuliah[55] = {"Pola pemukiman memanjang mengikuti jalan atau sungai disebut pola apa.","linear","geo"};
    soalkuliah[56] = {"Data SIG yang berbentuk titik garis poligon disebut data apa.","vektor","geo"};
    soalkuliah[57] = {"Angka kematian per 1000 penduduk disebut apa.","mortalitas","geo"};
    soalkuliah[58] = {"Hujan akibat pemanasan kuat permukaan bumi disebut hujan apa.","konveksi","geo"};
    soalkuliah[59] = {"Garis pada peta cuaca yang menghubungkan tekanan udara sama disebut apa.","isobar","geo"};
    soalkuliah[60] = {"Arus laut dingin di pantai barat Amerika Selatan bernama apa.","humboldt","geo"};


    pilgan(soalkuliah[61], "Perang Dunia II berakhir pada tahun.", "sejarah", 'c', "1940", "1943", "1945", "1950");
    pilgan(soalkuliah[62], "Revolusi Industri pertama kali terjadi di negara.", "sejarah", 'b', "Prancis", "Inggris", "Jerman", "Amerika");
    pilgan(soalkuliah[63], "Perang Dingin terjadi antara blok Barat dan blok.", "sejarah", 'a', "Timur", "Selatan", "Utara", "Tengah");
    pilgan(soalkuliah[64], "Konferensi Asia Afrika dilaksanakan tahun.", "sejarah", 'd', "1949", "1950", "1953", "1955");
    pilgan(soalkuliah[65], "Tokoh proklamator Indonesia yang membacakan naskah proklamasi adalah.", "sejarah", 'a', "Soekarno", "Hatta", "Sudirman", "Syahrir");
    pilgan(soalkuliah[66], "VOC dibubarkan pada tahun.", "sejarah", 'b', "1700", "1799", "1808", "1811");
    pilgan(soalkuliah[67], "Perang Diponegoro berlangsung tahun 1825 sampai.", "sejarah", 'c', "1827", "1828", "1830", "1835");
    pilgan(soalkuliah[68], "KMB menghasilkan pengakuan kedaulatan Indonesia pada tahun.", "sejarah", 'd', "1947", "1948", "1949", "1950");
    pilgan(soalkuliah[69], "Sumpah Pemuda terjadi pada tahun.", "sejarah", 'b', "1908", "1928", "1945", "1955");
    pilgan(soalkuliah[70], "BPUPKI dibentuk oleh negara.", "sejarah", 'c', "Belanda", "Inggris", "Jepang", "Amerika");


    soalkuliah[71] = {"Tanggal proklamasi kemerdekaan Indonesia.","17 agustus 1945","sejarah"};
    soalkuliah[72] = {"Wakil presiden pertama Indonesia.","hatta","sejarah"};
    soalkuliah[73] = {"Presiden pertama Indonesia.","soekarno","sejarah"};
    soalkuliah[74] = {"Kota tempat Konferensi Asia Afrika.","bandung","sejarah"};
    soalkuliah[75] = {"Organisasi pergerakan nasional pertama Indonesia.","budi utomo","sejarah"};
    soalkuliah[76] = {"Kerajaan maritim besar di Sumatera adalah.","sriwijaya","sejarah"};
    soalkuliah[77] = {"Kerajaan hindu tertua di Indonesia.","kutai","sejarah"};
    soalkuliah[78] = {"Tokoh pencetus tanam paksa.","van den bosch","sejarah"};
    soalkuliah[79] = {"Tempat perumusan naskah proklamasi.","rumah laksamana maeda","sejarah"};
    soalkuliah[80] = {"Perang aceh melawan negara apa.","belanda","sejarah"};


    pilgan(soalkuliah[81], "Jika P -> Q benar dan Q salah, maka P bernilai.", "logika", 'b',
           "Benar", "Salah", "Tidak tentu", "Tidak bisa ditentukan");
    pilgan(soalkuliah[82], "Nilai kebenaran (True XOR True) adalah.", "logika", 'b',
           "True", "False", "Tidak tentu", "Error");
    pilgan(soalkuliah[83], "Jika (p OR q) salah, maka p dan q keduanya.", "logika", 'a',
           "Salah", "Benar", "Tidak tentu", "Error");
    pilgan(soalkuliah[84], "Jika semua A adalah B dan semua B adalah C, maka.", "logika", 'c',
           "Semua C adalah A", "Tidak ada A di C", "Semua A adalah C", "Tidak bisa disimpulkan");
    pilgan(soalkuliah[85], "Jika 5 pekerja menyelesaikan kerja 12 hari, 10 pekerja menyelesaikan kerja yang sama dalam.", "logika", 'b',
           "4 hari", "6 hari", "8 hari", "12 hari");
    pilgan(soalkuliah[86], "Pola: 2, 3, 5, 8, 13, ... berikutnya.", "logika", 'd',
           "18", "19", "20", "21");
    pilgan(soalkuliah[87], "Jika x > y dan y > z maka pernyataan benar adalah.", "logika", 'a',
           "x > z", "z > x", "x = z", "Tidak tentu");
    pilgan(soalkuliah[88], "Jika peluang muncul angka genap pada dadu adalah.", "logika", 'c',
           "1/6", "1/3", "1/2", "2/3");
    pilgan(soalkuliah[89], "Jika semua bilangan prima kecuali 2 adalah ganjil, maka 2 itu.", "logika", 'd',
           "Ganjil", "Komposit", "Tidak tentu", "Prima");
    pilgan(soalkuliah[90], "Jika 3/4 dari 80 ditambah 1/5 dari 100 adalah.", "logika", 'd',
           "70", "75", "78", "80");


    soalkuliah[91] = {"Turunan dari e^x adalah apa.","e^x","mtk"};
    soalkuliah[92] = {"Integral dari 0 dx adalah apa.","c","mtk"};
    soalkuliah[93] = {"Jika 2^10 nilainya berapa. jawab angka","1024","mtk"};
    soalkuliah[94] = {"Jika cos 0 derajat nilainya berapa. jawab angka","1","mtk"};
    soalkuliah[95] = {"Jika sin 0 derajat nilainya berapa. jawab angka","0","mtk"};
    soalkuliah[96] = {"Jika 6C2 nilainya berapa. jawab angka","15","mtk"};
    soalkuliah[97] = {"Jika 6P2 nilainya berapa. jawab angka","30","mtk"};
    soalkuliah[98] = {"Jika limit x ke tak hingga dari 5/x adalah berapa. jawab angka","0","mtk"};
    soalkuliah[99] = {"Jika integral dari 3x^2 adalah apa.","x^3 + C","mtk"};
    soalkuliah[100] = {"Jika turunan dari x^7 adalah apa.","7x^6","mtk"};

}

// ---------- WORLD / LOKASI ----------
string lokasi(int jarak) {
    if (jarak < 5)  return "Hutan kematian";
    if (jarak < 10) return "Laut selatan";
    if (jarak < 15) return "Rawa beracun";
    if (jarak < 20) return "Rawa Kabut";
    if (jarak < 25) return "Tebing Sunyi";
    if (jarak < 30) return "Lembah Bayangan";
    if (jarak < 40) return "Kawah keputusasaan";
    return "Puncak Ujian Terakhir";
}

monster mosterlah(int level, int jarak) {
    monster m;
    const string daftar_nama[] = {"SLIME", "GOBLIN", "BAT", "SKELETON", "WISP"};
    int jumlah_nama = (int)(sizeof(daftar_nama) / sizeof(daftar_nama[0]));

    m.nama = daftar_nama[rand() % jumlah_nama] + string(" Lv.") + to_string(level);
    m.hp = 40 + 20 * level;
    m.damage = 15 + 5 * level;

    (void)jarak;
    return m;
}

// ---------- UI GAME ----------
void intro() {
    clear();

    cout << "====================================================================\n";
    cout << "  ____    _    __  __ _____     ___  _   _ ___ _____               \n";
    cout << " / ___|  / \\  |  \\/  | ____|   / _ \\| | | |_ _|__  /               \n";
    cout << "| |  _  / _ \\ | |\\/| |  _|    | | | | | | || |  / /                \n";
    cout << "| |_| |/ ___ \\| |  | | |___   | |_| | |_| || | / /_                \n";
    cout << " \\____/_/   \\_\\_|  |_|_____|   \\__\\_\\\\___/|___/____|               \n";
    cout << "====================================================================\n";
    cout << "             P E N J E L A J A H A N   Q U I Z   R P G               \n";
    cout << "====================================================================\n\n";

    cout << "Kamu adalah seorang penjelajah yang harus menembus wilayah berbahaya\n";
    cout << "Setiap langkah akan ada monster menghadang\n";
    cout << "Untuk menyerang, kamu harus menjawab soal dengan benar\n\n";

    cout << "------------------------------- ATURAN -----------------------------\n";
    cout << "1) Soal random setiap ronde\n";
    cout << "2) Jawaban benar      musuh kena hit dan skor naik\n";
    cout << "3) Jawaban salah      kamu kena damage\n";
    cout << "4) Jawaban telat      kamu kena damage\n";
    cout << "5) Musuh mati         kamu maju dan jarak bertambah\n";
    cout << "6) Setiap 3 musuh     regenerasi HP\n";
    cout << "--------------------------------------------------------------------\n\n";

    cout << "Tekan ENTER untuk mulai petualangan\n";
    delay();
    clear();
}

void interface(const pemain &p, const monster &m) {
    cout << "============================================================\n";
    cout << p.nama << "  HP " << p.hp << "  Skor " << p.skor << "  Jarak " << p.jarak << " km\n";
    cout << "Daerah: " << lokasi(p.jarak) << "\n";
    cout << "------------------------------------------------------------\n";
    cout << "Musuh: " << m.nama << "  HP " << m.hp << "  DMG " << m.damage << "\n";
    cout << "============================================================\n\n";
}


void gamemain(const pertanyaan &soal, pemain &p, monster &m, int level) {
    interface(p, m);

    int batas_waktu = 240 - level * 20;
    if (batas_waktu < 20) batas_waktu = 20;

    cout << "Lv " << level << "  Kategori " << soal.jenis << "  Waktu " << batas_waktu << " detik\n";
    cout << "Soal: " << soal.teks << "\n\n";

    if (soal.pilgan) {
        cout << "A. " << soal.opsi[0] << "\n";
        cout << "B. " << soal.opsi[1] << "\n";
        cout << "C. " << soal.opsi[2] << "\n";
        cout << "D. " << soal.opsi[3] << "\n";
        cout << "\nJawaban (A B C D): ";
    } else {
        cout << "Jawaban: ";
    }

    string jawaban_pemain;
    time_t mulai = time(NULL);
    getline(cin >> ws, jawaban_pemain);
    time_t selesai = time(NULL);

    int durasi = (int)(selesai - mulai);

    for (char &huruf : jawaban_pemain) huruf = (char)tolower(huruf);

    if (soal.pilgan) {
        char pilihan = 0;
        for (char huruf : jawaban_pemain) {
            if (huruf == 'a' || huruf == 'b' || huruf == 'c' || huruf == 'd') {
                pilihan = huruf;
                break;
            }
        }
        if (pilihan != 0) jawaban_pemain = string(1, pilihan);
        else jawaban_pemain.clear();
    }

    if (durasi > batas_waktu) {
        cout << "\nWaktu habis, kamu telat " << durasi << " detik\n";
        p.hp -= m.damage;
        if (p.hp < 0) p.hp = 0;
        cout << "Kamu kena -" << m.damage << " HP\n";
        return;
    }

    if (jawaban_pemain == soal.jawaban) {
        int serang = 20;
        m.hp -= serang;
        if (m.hp < 0) m.hp = 0;
        p.skor += 10;

        cout << "\nBenar, musuh kena -" << serang << " HP\n";
        cout << "Skor +10\n";
    } else {
        p.hp -= m.damage;
        if (p.hp < 0) p.hp = 0;

        cout << "\nSalah, kamu kena -" << m.damage << " HP\n";
    }
}


// ---------- RANDOM SOAL & FLOW ----------
int soalbelumdipake(bool sudahdipakai[]) {
    int jumlah_belum = 0;
    for (int nomor = 1; nomor <= 30; nomor++) {
        if (!sudahdipakai[nomor]) jumlah_belum++;
    }
    if (jumlah_belum == 0) return -1;

    int target = rand() % jumlah_belum;
    int hitung = 0;

    for (int nomor = 1; nomor <= 30; nomor++) {
        if (!sudahdipakai[nomor]) {
            if (hitung == target) return nomor;
            hitung++;
        }
    }
    return -1;
}

bool lanjutga() {
    cout << "\n--------------------------------------------------------------------\n";
    cout << "Tekan ENTER untuk lanjut\n";
    cout << "Ketik Y lalu ENTER untuk keluar\n";
    cout << "--------------------------------------------------------------------\n";
    cout << "Input: ";

    string inp;
    getline(cin, inp);

    if (!inp.empty() && (inp[0] == 'y' || inp[0] == 'Y')) return false;
    return true;
}

// ---------- SAVE / LOAD ----------
string saveFileName(int slot) {
    return "save" + to_string(slot) + ".txt";
}

bool save(const pemain &p, int jenjang, int slot) {
    if (slot < 1 || slot > 3) return false;
    ofstream out(saveFileName(slot));
    if (!out) return false;

    out << p.nama << "\n";
    out << p.hp << " " << p.skor << " " << p.jarak << " " << jenjang << "\n";
    return true;
}

bool loadGameSlot(pemain &p, int &jenjang, int slot) {
    if (slot < 1 || slot > 3) return false;
    ifstream in(saveFileName(slot));
    if (!in) return false;

    getline(in, p.nama);
    if (p.nama.empty()) return false;

    in >> p.hp >> p.skor >> p.jarak >> jenjang;
    if (!in) return false;

    if (p.hp < 0) p.hp = 0;
    if (p.hp > 200) p.hp = 200;
    if (p.skor < 0) p.skor = 0;
    if (p.jarak < 0) p.jarak = 0;
    if (jenjang < 1 || jenjang > 4) jenjang = 1;

    return true;
}

void showslot() {
    cout << "===== DAFTAR SAVE (MAX 3) =====\n";
    for (int slot = 1; slot <= 3; slot++) {
        pemain temp; int j = 1;
        cout << slot << ". ";
        if (loadGameSlot(temp, j, slot)) {
            cout << temp.nama
                 << " | HP: " << temp.hp
                 << " | Skor: " << temp.skor
                 << " | Jarak: " << temp.jarak
                 << " | Jenjang: " << kelassoal(j)
                 << "\n";
        } else {
            cout << "(kosong)\n";
        }
    }
    cout << "===============================\n";
}

void addLeaderboard(const pemain &p) {
    const string filename = "leaderboard.txt";

    ifstream cek(filename);
    bool kosong = true;
    if (cek) {
        cek.seekg(0, ios::end);
        kosong = (cek.tellg() == 0);
    }
    cek.close();

    int nomor = 1;
    if (!kosong) {
        ifstream baca(filename);
        string line;
        while (getline(baca, line)) {
            if (!line.empty() && isdigit((unsigned char)line[0])) nomor++;
        }
        baca.close();
    }

    ofstream out(filename, ios::app);
    if (!out) return;

    if (kosong) {
        out << "================ LEADERBOARD ================\n";
        out << left
            << setw(4)  << "No"
            << setw(20) << "Nama"
            << setw(8)  << "Skor"
            << setw(8)  << "Jarak"
            << setw(6)  << "HP"
            << "\n";
        out << "--------------------------------------------\n";
    }

    out << left
        << setw(4)  << nomor
        << setw(20) << p.nama.substr(0, 19)
        << setw(8)  << p.skor
        << setw(8)  << p.jarak
        << setw(6)  << p.hp
        << "\n";
}

/* =========================================================
   5) MAIN
   ========================================================= */
int main() {
    srand((unsigned)time(NULL));

    soalSD();
    soalSMP();
    soalSMA();
    soalKuliah();

    pemain p;
    int jenjang = 1;

    clear();
    cout << "====================================================================\n";
    cout << "  ____    _    __  __ _____     ___  _   _ ___ _____               \n";
    cout << " / ___|  / \\  |  \\/  | ____|   / _ \\| | | |_ _|__  /               \n";
    cout << "| |  _  / _ \\ | |\\/| |  _|    | | | | | | || |  / /                \n";
    cout << "| |_| |/ ___ \\| |  | | |___   | |_| | |_| || | / /_                \n";
    cout << " \\____/_/   \\_\\_|  |_|_____|   \\__\\_\\\\___/|___/____|               \n";
    cout << "====================================================================\n";
    cout << "             P E N J E L A J A H A N   Q U I Z   R P G               \n";
    cout << "====================================================================\n\n";
    cout << " [1] New Game\n";
    cout << " [2] Load Game\n";
    cout << "--------------------------------------------------------------------\n";
    cout << "Pilihan: ";

    int menu;
    cin >> menu;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (menu == 2) {
        clear();
        showslot();
        cout << "Pilih slot untuk LOAD (1-3), atau 0 untuk batal: ";
        int slot;
        cin >> slot;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (slot >= 1 && slot <= 3) {
            if (loadGameSlot(p, jenjang, slot)) {
                cout << "\nLoad berhasil dari slot " << slot << "\n";
                delay();
            } else {
                cout << "\nSlot " << slot << " kosong. Mulai New Game\n";
                delay();
                cout << "Masukkan nama pemain: ";
                getline(cin, p.nama);
                p.hp = 50; p.skor = 0; p.jarak = 0;
                clear();
                intro();
                jenjang = sekolah();
            }
        } else {
            cout << "\nBatal load. Mulai New Game\n";
            delay();
            cout << "Masukkan nama pemain: ";
            getline(cin, p.nama);
            p.hp = 50; p.skor = 0; p.jarak = 0;
            clear();
            intro();
            jenjang = sekolah();
        }
    } else {
        cout << "Masukkan nama pemain: ";
        getline(cin, p.nama);

        p.hp = 150;
        p.skor = 0;
        p.jarak = 0;

        clear();
        intro();
        jenjang = sekolah();
    }

    pertanyaan *bank_soal = nullptr;
    switch (jenjang) {
        case 1: bank_soal = soalsd; break;
        case 2: bank_soal = soalsmp; break;
        case 3: bank_soal = soalsma; break;
        case 4: bank_soal = soalkuliah; break;
        default:
            cout << "Pilihan jenjang tidak valid\n";
            return 0;
    }

    bool sudahdipakai[31] = {false};
    bool lanjut_game = true;
    int jumlah_musuh_kalah = 0;

    while (p.hp > 0 && lanjut_game) {
        int level = 1 + (p.jarak / 8);
        if (level > 5) level = 5;

        monster m = mosterlah(level, p.jarak);

        int ronde = 1;
        while (p.hp > 0 && m.hp > 0) {
            clear();
            cout << "====================================================================\n";
            cout << "                           PENJELAJAHAN                               \n";
            cout << "====================================================================\n";
            cout << "RONDE " << ronde << "\n";
            cout << "--------------------------------------------------------------------\n";

            int nomor_soal = soalbelumdipake(sudahdipakai);
            if (nomor_soal == -1) {
                cout << "Semua soal sudah habis\n";
                lanjut_game = false;
                break;
            }

            sudahdipakai[nomor_soal] = true;

            pertanyaan &soal = bank_soal[nomor_soal];
            gamemain(soal, p, m, level);

            ronde++;

            if (!lanjutga()) {
                lanjut_game = false;
                break;
            }
        }

        if (p.hp <= 0) break;
        if (!lanjut_game) break;

        jumlah_musuh_kalah++;

        int maju = 2 + (level / 2);
        p.jarak += maju;

        clear();
        cout << "====================================================================\n";
        cout << "                           MUSUH DIKALAHKAN                           \n";
        cout << "====================================================================\n";
        cout << "Kamu maju +" << maju << " km\n";
        cout << "Jarak sekarang : " << p.jarak << " km\n";
        cout << "Daerah         : " << lokasi(p.jarak) << "\n";
        cout << "Skor           : " << p.skor << "\n";

        if (jumlah_musuh_kalah % 3 == 0) {
            int regen = 10;
            p.hp += regen;
            cout << "--------------------------------------------------------------------\n";
            cout << "Kamu menemukan tempat istirahat\n";
            cout << "Regenerasi +" << regen << " HP\n";
        }

        cout << "====================================================================\n";
        delay();
    }

    clear();
    cout << "====================================================================\n";
    cout << "                              HASIL AKHIR                            \n";
    cout << "====================================================================\n";
    cout << "Nama  : " << p.nama << "\n";
    cout << "Skor  : " << p.skor << "\n";
    cout << "HP    : " << p.hp << "\n";
    cout << "Jarak : " << p.jarak << " km\n";
    cout << "--------------------------------------------------------------------\n";
    cout << "Terima kasih sudah bermain\n";
    cout << "====================================================================\n\n";

    showslot();
    cout << "Simpan ke slot berapa? (1-3, atau 0 untuk tidak menyimpan): ";
    cout << "Jika timpa slot maka save sebelumnya hilang";
    int slotsave;
    cin >> slotsave;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (slotsave >= 1 && slotsave <= 3) {
        if (save(p, jenjang, slotsave)) cout << "Berhasil menyimpan ke slot " << slotsave << "!\n";
        else cout << "Gagal menyimpan.\n";
    } else {
        cout << "Tidak menyimpan.\n";
    }

    addLeaderboard(p);
    delay();
    return 0;
}
