#ifndef MENU_PARKIR_H
#define MENU_PARKIR_H

#include "data_parkir.h"

void tambahKendaraan(Kendaraan data[], int &jumlah);
void tampilkanKendaraan(Kendaraan data[], int jumlah);
void cariKendaraan(Kendaraan data[], int jumlah);
void urutkanKendaraan(Kendaraan data[], int jumlah);
void ubahKendaraan(Kendaraan data[], int jumlah);
void hapusKendaraan(Kendaraan data[], int &jumlah);
void statistikKendaraan(Kendaraan data[], int jumlah);
void infoMemori(Kendaraan data[]);

#endif