
#include "file_parkir.h"
#include <iostream>
#include <fstream>
using namespace std;

// Membaca data dari file
void bacaData(Kendaraan data[], int &jumlah)
{
    ifstream file("../data/parkir.txt");
    jumlah = 0;

    if (!file.is_open()) {
        cout << "File data belum dapat dibuka.\n";
        return;
    }

    while (jumlah < 20 &&
           file >> data[jumlah].nomor
                >> data[jumlah].jenis
                >> data[jumlah].masuk.jam
                >> data[jumlah].masuk.menit
                >> data[jumlah].keluar.jam
                >> data[jumlah].keluar.menit
                >> data[jumlah].biaya) {
        jumlah++;
    }

    file.close();
}

// Menyimpan data ke file
void simpanData(Kendaraan data[], int jumlah)
{
    ofstream file("../data/parkir.txt");

    if (!file.is_open()) {
        cout << "File data tidak dapat disimpan.\n";
        return;
    }

    for (int i = 0; i < jumlah; i++) {
        file << data[i].nomor << " "
             << data[i].jenis << " "
             << data[i].masuk.jam << " "
             << data[i].masuk.menit << " "
             << data[i].keluar.jam << " "
             << data[i].keluar.menit << " "
             << data[i].biaya << '\n';
    }

    file.close();
    cout << "Data berhasil disimpan.\n";
}
