// Nama: Fauzan Juniar Mulyana 
// Kelas: 1A-D4
// Prodi: D4 Teknik informatika
// Tanggal: 27 Mar 2025
// Nama File: SLL.h
#ifndef SLL_H
#define SLL_H
#define NAMA 20
#include "config.h"


typedef char nama[NAMA];
typedef struct tElmtList *address;
typedef struct tElmtList {
    nama nm;
    address q;
} ElmtList;

typedef struct {
    address First;
} List;

List createList();
void deleteList(List *L);
int isEmpty(List L);
void insertFirst(List *L, nama nm);
void InsertAkhir(List *L, nama nm);
int removeFirst(List *L);

/* Aksesor */
#define nm(P) (P)->nm
#define q(P) (P)->q
#define first(L) (L).First

#endif
