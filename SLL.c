// Nama: Fauzan Juniar Mulyana 
// Kelas: 1A-D4
// Prodi: D4 Teknik informatika
// Tanggal: 27 Mar 2025
// Nama File: SLL.c
#include "SLL.h"
#include <stdlib.h>
#include <string.h>

List createList() {
    List L;
    first(L) = NULL;
    return L;
}

void deleteList(List *L) {
    address P = first(*L);
    while (P != NULL) {
        address temp = P;
        P = q(P);
        free(temp);
    }
    first(*L) = NULL;
}

int isEmpty(List L) {
    return (first(L) == NULL);
}

void insertFirst(List *L, nama nm) {
    address newNode = (address)malloc(sizeof(ElmtList));
    if (newNode == NULL) {
        printf("Alokasi memori gagal!\n");
        return;
    }
    strcpy(nm(newNode), nm);
    q(newNode) = first(*L);
    first(*L) = newNode;
}

void InsertAkhir(List *L, nama nm) {
    address newNode = (address)malloc(sizeof(ElmtList));
    if (newNode == NULL) {
        printf("Alokasi memori gagal!\n");
        return;
    }
    strcpy(nm(newNode), nm);
    q(newNode) = NULL;

    if (first(*L) == NULL) {
        first(*L) = newNode;
    } else {
        address current = first(*L);
        while (q(current) != NULL) {
            current = q(current);
        }
        q(current) = newNode;
    }
}

int removeFirst(List *L) {
    if (isEmpty(*L)) {
        printf("List kosong, tidak dapat menghapus\n");
        return -1;
    }
    address temp = first(*L);
    first(*L) = q(temp);
    free(temp);
    return 0;
}

