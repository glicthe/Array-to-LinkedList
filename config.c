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
