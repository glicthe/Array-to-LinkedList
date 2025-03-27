// Nama: Fauzan Juniar Mulyana 
// Kelas: 1A-D4
// Prodi: D4 Teknik informatika
// Tanggal: 27 Mar 2025
// Nama File: Case5.h

#ifndef CASE5_H
#define CASE5_H
#include "SLL.h"
#define MAX_KOTA 10
#define NAMA 20

typedef struct NamaKota {
    char kt[NAMA];
    List p;
} Kota;

extern Kota kota[MAX_KOTA];
extern int jumlahKota;

int isKotaExist(const char *kt);
void insertKota(char *kt);
void deleteKota(int index);
void insertNamaKeKota(int index, char *nm);
int hapusNamaGlobal(const char *nm);
void tampilkanSemuaKota();
void tampilkanKota(char *inputKt);
void tampilkanSemuaDataSebelumInput();


#endif

