// Nama: Fauzan Juniar Mulyana 
// Kelas: 1A-D4
// Prodi: D4 Teknik informatika
// Tanggal: 27 Mar 2025
// Nama File: Case5.c

#include "Case5.h"


Kota kota[MAX_KOTA];
int jumlahKota = 0;

int isKotaExist(const char *kt) {
    int i;
	for (i = 0; i < jumlahKota; i++) {
        if (strcasecmp(kota[i].kt, kt) == 0) {
            return i; // return index jika ditemukan
        }
    }
    return -1; // tidak ditemukan
}

void insertKota(char *kt) {
    // Pastikan tidak ada duplikat (seharusnya sudah dicek di main)
    if (jumlahKota < MAX_KOTA) {
        strcpy(kota[jumlahKota].kt, kt);
        kota[jumlahKota].p = createList();
        jumlahKota++;
    }
}

void deleteKota(int index) {
    int i;
	if (index < 0 || index >= jumlahKota) {
        printf("Indeks kota tidak valid!\n");
        return;
    }
    deleteList(&kota[index].p);
    for (i = index; i < jumlahKota - 1; i++) {
        kota[i] = kota[i + 1];
    }
    jumlahKota--;
}

void insertNamaKeKota(int index, char *nm) {
    if (index < 0 || index >= jumlahKota) {
        printf("Indeks kota tidak valid!\n");
        return;
    }
    InsertAkhir(&kota[index].p, nm);
}

int hapusNamaGlobal(const char *nm) {
    int totalDeleted = 0, i;
    
    for(i = 0; i < jumlahKota; i++) {
        List *L = &kota[i].p;
        address prev = NULL;
        address current = first(*L);
        
        while(current != NULL) {
            if(strcasecmp(nm(current), nm) == 0) {
                address toDelete = current;
                
                if(prev == NULL) {
                    // Update head jika menghapus node pertama
                    first(*L) = q(current);
                } else {
                    // Hubungkan node sebelumnya ke node berikutnya
                    q(prev) = q(current);
                }
                
                // Pindah ke node berikutnya SEBELUM menghapus
                current = q(current);
                
                // Bebaskan memori
                free(toDelete);
                totalDeleted++;
            } else {
                // Lanjutkan traversal
                prev = current;
                current = q(current);
            }
        }
    }
    
    return totalDeleted;
}

void tampilkanSemuaKota() {
    int i;
	for (i = 0; i < jumlahKota; i++) {
        printf("%s", kota[i].kt);
        address current = first(kota[i].p);
        while (current != NULL) {
            printf(" -> %s", nm(current));
            current = q(current);
        }
        printf("\n");
    }
}

void tampilkanKota(char *inputKt) {
    int found = 0, i;
    for (i = 0; i < jumlahKota; i++) {
        if (strcasecmp(kota[i].kt, inputKt) == 0) {
            printf("%s", kota[i].kt);
            address current = first(kota[i].p);
            while (current != NULL) {
                printf(" -> %s", nm(current));
                current = q(current);
            }
            printf("\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Kota '%s' tidak ditemukan\n", inputKt);
    }
}

void tampilkanSemuaDataSebelumInput() {
    printf("\n=== DATA SAAT INI ===\n");
    tampilkanSemuaKota();
    printf("=====================\n\n");
}
