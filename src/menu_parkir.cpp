
#include <iostream>
#include "menu_parkir.h"
using namespace std;

// 1. Menambah kendaraan
void tambahKendaraan(Kendaraan data[], int &jumlah)
{
    if (jumlah >= 20) {
        cout << "Data parkir sudah penuh!\n";
        return;
    }

    cout << "Nomor kendaraan: ";
    cin >> data[jumlah].nomor;

    cout << "Jenis kendaraan: ";
    cin >> data[jumlah].jenis;

    cout << "Jam masuk: ";
    cin >> data[jumlah].masuk.jam;

    cout << "Menit masuk: ";
    cin >> data[jumlah].masuk.menit;

    cout << "Jam keluar: ";
    cin >> data[jumlah].keluar.jam;

    cout << "Menit keluar: ";
    cin >> data[jumlah].keluar.menit;

    // Validasi waktu
    if (data[jumlah].masuk.jam < 0 ||
        data[jumlah].masuk.jam > 23 ||
        data[jumlah].keluar.jam < 0 ||
        data[jumlah].keluar.jam > 23 ||
        data[jumlah].masuk.menit < 0 ||
        data[jumlah].masuk.menit > 59 ||
        data[jumlah].keluar.menit < 0 ||
        data[jumlah].keluar.menit > 59) {
        cout << "Waktu tidak valid!\n";
        return;
    }

    int masuk = data[jumlah].masuk.jam * 60
              + data[jumlah].masuk.menit;

    int keluar = data[jumlah].keluar.jam * 60
               + data[jumlah].keluar.menit;

    if (keluar <= masuk) {
        cout << "Waktu keluar harus setelah waktu masuk.\n";
        return;
    }

    int durasi = keluar - masuk;
    int lamaJam = (durasi + 59) / 60;

    // Contoh tarif Rp2.000 per jam
    data[jumlah].biaya = lamaJam * 2000;

    jumlah++;
    cout << "Kendaraan berhasil ditambahkan.\n";
}

// 2. Menampilkan kendaraan
void tampilkanKendaraan(Kendaraan data[], int jumlah)
{
    if (jumlah == 0) {
        cout << "Belum ada data kendaraan.\n";
        return;
    }

    cout << "\n=== DATA KENDARAAN ===\n";

    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". "
             << data[i].nomor << " | "
             << data[i].jenis << " | Biaya: Rp"
             << data[i].biaya << '\n';
    }
}

// 3. Mencari kendaraan
void cariKendaraan(Kendaraan data[], int jumlah)
{
    string nomor;

    cout << "Masukkan nomor kendaraan: ";
    cin >> nomor;

    for (int i = 0; i < jumlah; i++) {
        if (data[i].nomor == nomor) {
            cout << "Nomor: " << data[i].nomor << '\n';
            cout << "Jenis: " << data[i].jenis << '\n';
            cout << "Biaya: Rp" << data[i].biaya << '\n';
            return;
        }
    }

    cout << "Kendaraan tidak ditemukan.\n";
}

// 4. Mengurutkan kendaraan dengan Bubble Sort
void urutkanKendaraan(Kendaraan data[], int jumlah)
{
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - 1 - i; j++) {
            if (data[j].nomor > data[j + 1].nomor) {
                Kendaraan sementara = data[j];
                data[j] = data[j + 1];
                data[j + 1] = sementara;
            }
        }
    }

    cout << "Data kendaraan berhasil diurutkan.\n";
}

// 5. Mengubah jenis kendaraan
void ubahKendaraan(Kendaraan data[], int jumlah)
{
    string nomor;

    cout << "Nomor kendaraan yang ingin diubah: ";
    cin >> nomor;

    for (int i = 0; i < jumlah; i++) {
        if (data[i].nomor == nomor) {
            cout << "Jenis kendaraan baru: ";
            cin >> data[i].jenis;

            cout << "Data berhasil diubah.\n";
            return;
        }
    }

    cout << "Kendaraan tidak ditemukan.\n";
}

// 6. Menghapus kendaraan
void hapusKendaraan(Kendaraan data[], int &jumlah)
{
    if (jumlah == 0) {
        cout << "Belum ada data kendaraan.\n";
        return;
    }

    string nomor;
    cout << "Nomor kendaraan yang ingin dihapus: ";
    cin >> nomor;

    for (int i = 0; i < jumlah; i++) {
        if (data[i].nomor == nomor) {
            for (int j = i; j < jumlah - 1; j++) {
                data[j] = data[j + 1];
            }

            jumlah--;
            cout << "Data kendaraan berhasil dihapus.\n";
            return;
        }
    }

    cout << "Kendaraan tidak ditemukan.\n";
}

// 7. Statistik kendaraan
void statistikKendaraan(Kendaraan data[], int jumlah)
{
    int totalBiaya = 0;

    for (int i = 0; i < jumlah; i++) {
        totalBiaya += data[i].biaya;
    }

    cout << "\n=== STATISTIK KENDARAAN ===\n";
    cout << "Jumlah kendaraan: " << jumlah << '\n';
    cout << "Total biaya parkir: Rp" << totalBiaya << '\n';
}

// 8. Informasi memori
void infoMemori(Kendaraan data[])
{
    cout << "\n=== INFORMASI MEMORI ===\n";

    cout << "Ukuran struct WaktuParkir: "
         << sizeof(WaktuParkir) << " byte\n";

    cout << "Ukuran struct Kendaraan: "
         << sizeof(Kendaraan) << " byte\n";

    cout << "Ukuran array 20 kendaraan: "
         << sizeof(Kendaraan) * 20 << " byte\n";
}
