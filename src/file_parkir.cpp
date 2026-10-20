#include "file_parkir.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Membuat laporan parkir
void buatLaporan(Kendaraan data[], int jumlah)
{
    ofstream file("../data/laporan_parkir.txt");

    if (!file.is_open()) {
        cout << "Gagal membuat laporan parkir!\n";
        return;
    }

    file << "====================================\n";
    file << "     LAPORAN PARKIR KENDARAAN\n";
    file << "====================================\n\n";

    for (int i = 0; i < jumlah; i++) {
        file << "Nomor Kendaraan : " << data[i].nomor << '\n';
        file << "Jenis Kendaraan : " << data[i].jenis << '\n';

        file << "Waktu Masuk     : "
             << setw(2) << setfill('0') << data[i].masuk.jam
             << ":"
             << setw(2) << setfill('0') << data[i].masuk.menit
             << '\n';

        file << "Waktu Keluar    : "
             << setw(2) << setfill('0') << data[i].keluar.jam
             << ":"
             << setw(2) << setfill('0') << data[i].keluar.menit
             << '\n';

        file << "Biaya Parkir    : Rp" << data[i].biaya << '\n';
        file << "------------------------------------\n\n";
    }

    file.close();
}

// Membaca laporan parkir
void bacaData(Kendaraan data[], int &jumlah)
{
    ifstream file("../data/laporan_parkir.txt");
    string baris;
    jumlah = 0;

    if (!file.is_open()) {
        cout << "Laporan belum tersedia. Data masih kosong.\n";
        return;
    }

    while (getline(file, baris)) {
        if (jumlah >= 20) {
            break;
        }

        if (baris.find("Nomor Kendaraan : ") == 0) {
            data[jumlah].nomor = baris.substr(19);

            getline(file, baris);
            data[jumlah].jenis = baris.substr(19);

            getline(file, baris);
            data[jumlah].masuk.jam = stoi(baris.substr(19, 2));
            data[jumlah].masuk.menit = stoi(baris.substr(22, 2));

            getline(file, baris);
            data[jumlah].keluar.jam = stoi(baris.substr(19, 2));
            data[jumlah].keluar.menit = stoi(baris.substr(22, 2));

            getline(file, baris);
            data[jumlah].biaya = stoi(baris.substr(19));

            jumlah++;
        }
    }

    file.close();

    cout << "Data dibaca: " << jumlah << " kendaraan.\n";
}

// Menyimpan data sekaligus membuat laporan
void simpanData(Kendaraan data[], int jumlah)
{
    buatLaporan(data, jumlah);
    cout << "Laporan berhasil disimpan.\n";
}
