
#include <iostream>
#include "data_parkir.h"
#include "file_parkir.h"
#include "menu_parkir.h"

using namespace std;

int main()
{
    const int MAKS_DATA = 20;
    Kendaraan data[MAKS_DATA];
    int jumlah = 0;
    int pilihan;
    
    // Membaca data dari file
    bacaData(data, jumlah);

    do {
        cout << "\n=== SISTEM PARKIR STASIUN WONOGIRI ===\n";
        cout << "1. Tambah kendaraan\n";
        cout << "2. Tampilkan semua kendaraan\n";
        cout << "3. Cari kendaraan\n";
        cout << "4. Urutkan kendaraan\n";
        cout << "5. Ubah data kendaraan\n";
        cout << "6. Hapus data kendaraan\n";
        cout << "7. Statistik kendaraan\n";
        cout << "8. Informasi memori\n";
        cout << "9. Simpan dan keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahKendaraan(data, jumlah);
                break;

            case 2:
                tampilkanKendaraan(data, jumlah);
                break;

            case 3:
                cariKendaraan(data, jumlah);
                break;

            case 4:
                urutkanKendaraan(data, jumlah);
                break;

            case 5:
                ubahKendaraan(data, jumlah);
                break;

            case 6:
                hapusKendaraan(data, jumlah);
                break;

            case 7:
                statistikKendaraan(data, jumlah);
                break;

            case 8:
                infoMemori(data);
                break;

            case 9:
                simpanData(data, jumlah);
                cout << "Data disimpan. Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }

    } while (pilihan != 9);

    return 0;
}