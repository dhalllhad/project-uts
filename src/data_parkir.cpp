#include "data_parkir.h"
#include <iostream>
using namespace std;

void tampilkanSatuKendaraan(Kendaraan k)
{
    cout << "Nomor kendaraan : " << k.nomor << endl;
    cout << "Jenis kendaraan : " << k.jenis << endl;

    cout << "Waktu masuk     : "
         << k.masuk.jam << ":"
         << k.masuk.menit << endl;

    cout << "Waktu keluar    : "
         << k.keluar.jam << ":"
         << k.keluar.menit << endl;

    cout << "Biaya parkir    : " << k.biaya << endl;
    return;
}