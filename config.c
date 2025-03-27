// Nama: Fauzan Juniar Mulyana 
// Kelas: 1A-D4
// Prodi: D4 Teknik informatika
// Tanggal: 27 Mar 2025
// Nama File: config.c
#include "config.h"

// Menunggu user untuk menekan Enter untuk lanjut
void waitForEnter() {
    printf("\nTekan Enter untuk melanjutkan...");
	getchar();
}

// Untuk Clear Buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Membersihkan layar
void clearScreen() {
    system("cls || clear");
}
