#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Case5.h"


int main(int argc, char *argv[]) {
    int pilihan, i;
    char inputKota[NAMA];
    char inputNama[NAMA];
    int index;

    // Initialize some default cities
    insertKota("Bandung");
    insertKota("Jakarta");
    insertKota("Depok");
    insertKota("Garut");
    insertKota("Bogor");

    do {
        printf("\nMenu:\n");
        printf("1. Entry Nama\n");
        printf("2. Delete Nama\n");
        printf("3. Delete Kota\n");
        printf("4. Tampilkan data\n");
        printf("5. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        clearBuffer();

        switch (pilihan) {
            case 1: {
   				char inputKota[NAMA];
   				char inputNama[NAMA];
    
    			tampilkanSemuaDataSebelumInput();
    
    			printf("Masukkan nama kota (Slot tersedia: %d): ", MAX_KOTA - jumlahKota);
    			fgets(inputKota, NAMA, stdin);
    			inputKota[strcspn(inputKota, "\n")] = '\0';
    
    			// Case-insensitive search
    			int index = isKotaExist(inputKota);
    
    			if(index == -1) {
        			if(jumlahKota < MAX_KOTA) {
            			// Convert to title case for consistency
            			for(i = 0; inputKota[i]; i++) {
                			if(i == 0 || inputKota[i-1] == ' ') {
                    			inputKota[i] = toupper(inputKota[i]);
                			} else {
                    			inputKota[i] = tolower(inputKota[i]);
                			}
            			}
            
            			insertKota(inputKota);
            			index = jumlahKota - 1;
            			printf("Kota baru '%s' ditambahkan.\n", inputKota);
        			} else {
            			printf("Gagal menambahkan kota. Slot penuh!\n");
            			waitForEnter();
            			break;
        			}
    			}
    
    			printf("Masukkan nama: ");
    			fgets(inputNama, NAMA, stdin);
    			inputNama[strcspn(inputNama, "\n")] = '\0';
    
    			// Auto-format nama
    			for(i = 0; inputNama[i]; i++) {
        			if(i == 0 || inputNama[i-1] == ' ') {
            			inputNama[i] = toupper(inputNama[i]);
        			} else {
            			inputNama[i] = tolower(inputNama[i]);
        			}
    			}
    
    			insertNamaKeKota(index, inputNama);
    			printf("Nama Berhasil Ditambahkan");
    			waitForEnter();
    			break;
			}
            case 2: {
			    char inputNama[NAMA];
    
    			tampilkanSemuaDataSebelumInput();
    
    			printf("Masukkan nama yang akan dihapus: ");
    			fgets(inputNama, NAMA, stdin);
    			inputNama[strcspn(inputNama, "\n")] = '\0';
    
   	 			int deletedCount = hapusNamaGlobal(inputNama);
    	
    			if(strlen(inputNama) == 0) {
     			   	printf("Nama tidak boleh kosong!\n");
        			waitForEnter();
        			break;
    			}
    	
		        // Cleanup empty cities
        		for(i = jumlahKota-1; i >= 0; i--) {
            		if(isEmpty(kota[i].p)) {
                		deleteKota(i);
            		}
        		}
        		
    			if(deletedCount > 0) {
        			printf("Berhasil menghapus %d entri nama '%s'\n", deletedCount, inputNama);
    			} else {
        			printf("Nama '%s' tidak ditemukan\n", inputNama);
    			}	
    
    			waitForEnter();
    			break;	
			}
            case 3: {
            	
            	tampilkanSemuaDataSebelumInput();
            	
                printf("Masukkan kota yang akan dihapus: ");
                fgets(inputKota, NAMA, stdin);
                inputKota[strcspn(inputKota, "\n")] = '\0';
                // Convert to title case for consistency
            	for(i = 0; inputKota[i]; i++) {
                	if(i == 0 || inputKota[i-1] == ' ') {
                    	inputKota[i] = toupper(inputKota[i]);
                	} else {
                   		inputKota[i] = tolower(inputKota[i]);
               		}
           		}
                index = -1;
                for (i = 0; i < jumlahKota; i++) {
                    if (strcmp(kota[i].kt, inputKota) == 0) {
                        index = i;
                        break;
                    }
                }
                if (index != -1) {
                    deleteKota(index);
                } else {
                    printf("Kota tidak ditemukan.\n");
                    break;
                }
                printf("Kota Berhasil Dihapus");
                waitForEnter();
                break;
            }
            case 4: {
                int subPilihan;
                printf("\nTampilkan Data:\n");
                printf("1. Tampilkan Semua Kota\n");
                printf("2. Cari Salah Satu Kota\n");
                printf("Pilihan: ");
                scanf("%d", &subPilihan);
                clearBuffer();

                if (subPilihan == 1) {
                    printf("\nData Seluruh Kota:\n");
                    tampilkanSemuaKota();
                } else if (subPilihan == 2) {
                    char cariKota[NAMA];
                    printf("Masukkan nama kota: ");
                    fgets(cariKota, NAMA, stdin);
                    cariKota[strcspn(cariKota, "\n")] = '\0';
                    
                    printf("\nHasil Pencarian:\n");
                    tampilkanKota(cariKota);
                } else {
                    printf("Pilihan tidak valid!\n");
                }
                waitForEnter();
                break;
            }
            case 5:
                exit(0);
                break;
            default:
                printf("Pilihan tidak valid!\n");
                waitForEnter();
        }
        clearScreen();
    } while (pilihan != 5);
    return 0;
}
