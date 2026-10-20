
#ifndef DATA_PARKIR_H
#define DATA_PARKIR_H

#include <string>
using namespace std;

struct WaktuParkir {
    int jam;
    int menit;
};

struct Kendaraan {
    string nomor;
    string jenis;
    WaktuParkir masuk;
    WaktuParkir keluar;
    int biaya;
};

#endif
