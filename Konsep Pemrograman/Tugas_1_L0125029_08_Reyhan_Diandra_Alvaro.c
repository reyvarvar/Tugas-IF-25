#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// code ini digunakan agar bisa menghapus print lama dan diganti print baru
#ifdef _WIN32
    #define clear() system("cls")
#else
    #define clear() system("clear")
#endif

// di deklrasi diluar karena banyak dipakai di function
char simbol[5][3] = {"$", "*", "#", "@", "&"};

// mencetak hasil slotnya
void printSlot(int s1, int s2, int s3, int s4) {
    printf(" [ %s | %s | %s | %s ]\n", simbol[s1], simbol[s2], simbol[s3], simbol[s4]);
}

// unutuk milih taruhan dan memperngaruui besarnya hadiah
int pilihTaruhan() {
    int taruhan;
    printf("\nPilih taruhan (2000 / 4000 / 6000 / 10000) \n");
    printf("besarnya taruhan mempengaruhi besarnya hadiah\n") ;
    printf("silahkan masukan taruhan anda :") ;
    scanf("%d", &taruhan);

    while (taruhan != 2000 && taruhan != 4000 && taruhan != 6000 && taruhan != 10000) {
        printf("Pilihan tidak valid!\n");
        printf("\nPilih taruhan (2000 / 4000 / 6000 / 10000): ");
        scanf("%d", &taruhan);
    }
    return taruhan;
}
int updateWinrate(int saldo, int winrate) {
    if (saldo >= 200000) {
        return 15;   // turunkan winrate jadi 15% setelah saldo lewat 200k
    }
    return winrate;
}



// spanspin
int spin(int saldo, int taruhan, int winrate) {
    int chance = rand() % 100 + 1;
    int s1, s2, s3, s4;

    clear();
    printf("\n=== SLOT ===\n");

    if (chance <= winrate) { // ini fungsinya misal di chance kita dapat angka 60 dan wr nya cuma 40 maka kalah
        // MENANG
        int tipe = rand() % 100; // mengatur hadiahe
        if (tipe < 5) {
            s1 = s2 = s3 = s4 = rand() % 5; // mengatur simbolya
            saldo += taruhan * 5;
            printSlot(s1, s2, s3, s4);
            printf("JACKPOT 4 simbol samaa +%d\n", taruhan * 5);
        }
        else if (tipe < 30) {
            int tiga = rand () % 5 ;
            s1 = s2 =  s3 = tiga ;

            do { s4 = rand () % 5;} while (s4 == tiga) ;
            saldo += taruhan * 3 ;

            printSlot(s1,s2,s3,s4) ;
            printf("gacor 3 simbol sama! +%d\n", taruhan * 3) ;  
        }
        else {
          int kembar = rand () % 5 ;
          s1 = s2 =kembar ;

          do { s3 = rand() % 5 ; } while (s3 == kembar) ;
          do { s4 = rand() % 5 ; } while (s4 ==kembar || s4 == s3);
          saldo += taruhan*2 ;

          printSlot(s1,s2,s3,s4) ;
          printf("okelah 2 simbol sama! +%d\n", taruhan * 2) ;
        }


    } else {
        // KALAH paksa beda semua wkwkwkwkw
        int dinggo[5] = {0};
        s1 = rand() % 5; dinggo[s1] = 1;

        do { s2 = rand() % 5; } while (dinggo[s2]); dinggo[s2] = 1;
        do { s3 = rand() % 5; } while (dinggo[s3]); dinggo[s3] = 1;
        do { s4 = rand() % 5; } while (dinggo[s4]); dinggo[s4] = 1;

        printSlot(s1, s2, s3, s4);
        saldo -= taruhan;
        printf("Maaf belum beruntung. -%d\n", taruhan);
    }
    return saldo;
}




// ====================== MAIN ======================
int main() {
    srand(time(NULL));
    clear();

    printf("==================================\n\n");
    printf("    Selamat datang di game ini \n\n");
    printf("==================================\n\n");

    int saldo;
    printf("Masukan deposit anda (minimal 10000) = ");
    scanf("%d", &saldo);

    while (saldo < 10000) {
        printf("Maaf deposit anda tidak mencukupi, silahkan topup lagi!\n\n");
        printf("Masukan deposit anda (minimal 10000) = ");
        scanf("%d", &saldo);
    }
    int saldoAwal = saldo;

    int taruhan = pilihTaruhan();

    int winrate = 80;  
    getchar(); // buang enter sisa scanf

     while (saldo > 0 && saldo - taruhan >= 0) {

        printf("\nTekan ENTER untuk spin, atau X untuk ganti taruhan \n ");
        printf("   Tekan huruf lain untuk mengakhiri slot.... ");
        char ch = getchar();
        if (ch == '\n') {
            winrate = updateWinrate(saldo, winrate);
            saldo = spin(saldo, taruhan, winrate);
            printf("Saldo sekarang: %d\n", saldo);
        }
        else if (ch == 'x' || ch == 'X') {
            taruhan = pilihTaruhan();
            getchar(); // buang enter sisa scanf
        }
        
        else break;
    }
    

    // ending gamenya 
    if (saldo <= 0) {
        printf("\nGame selesai. Saldo habis!\n");
    }
    if (saldo > saldoAwal) {
        printf("\n==================================\n");
        printf("Saldo akhirmu adalah: %d\n", saldo);
        printf("Main lagi brooo sampe gacor.\n");
        printf("Terus terus terus sampe dapet mobil!\n");
        printf("==================================\n");
    } else {
        printf("\n          ===================================\n");
        printf("                saldo akhirmu adalah: %d\n", saldo);
        printf("Pesan moral: janganlah berjudi ya adik adik terkedik kedik.\n");
        printf("Mungkin kamu menang di awal, tapi akhirnya kalah wkwkwk.\n");
        printf("                  #BANDARSELALUMENANG\n");
        printf("            ==================================\n\n\n\n\n\n\n\n\n");
    }

    return 0;
}
