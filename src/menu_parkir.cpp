#include <iostream>
#include <string>
#include <cctype>
#include "file_parkir.h"
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

    string waktuMasuk, waktuKeluar;

    cout << "Waktu masuk (JJ:MM): ";
    cin >> waktuMasuk;

    cout << "Waktu keluar (JJ:MM): ";
    cin >> waktuKeluar;

    if (waktuMasuk.length() != 5 ||
        waktuKeluar.length() != 5 ||
        waktuMasuk[2] != ':' ||
        waktuKeluar[2] != ':') {
        cout << "Format salah! Contoh: 09:55\n";
        return;
    }

    if (!isdigit(waktuMasuk[0]) ||
        !isdigit(waktuMasuk[1]) ||
        !isdigit(waktuMasuk[3]) ||
        !isdigit(waktuMasuk[4]) ||
        !isdigit(waktuKeluar[0]) ||
        !isdigit(waktuKeluar[1]) ||
        !isdigit(waktuKeluar[3]) ||
        !isdigit(waktuKeluar[4])) {
        cout << "Waktu harus berupa angka!\n";
        return;
    }

    data[jumlah].masuk.jam =
        stoi(waktuMasuk.substr(0, 2));
    data[jumlah].masuk.menit =
        stoi(waktuMasuk.substr(3, 2));

    data[jumlah].keluar.jam =
        stoi(waktuKeluar.substr(0, 2));
    data[jumlah].keluar.menit =
        stoi(waktuKeluar.substr(3, 2));

    if (data[jumlah].masuk.jam < 0 ||
        data[jumlah].masuk.jam > 23 ||
        data[jumlah].masuk.menit < 0 ||
        data[jumlah].masuk.menit > 59 ||
        data[jumlah].keluar.jam < 0 ||
        data[jumlah].keluar.jam > 23 ||
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

    data[jumlah].biaya = lamaJam * 2000;

    jumlah++;
    simpanData(data, jumlah);

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
    cout << "No | Nomor | Jenis | Masuk | Keluar | Biaya\n";

    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << " | "
             << data[i].nomor << " | "
             << data[i].jenis << " | "
             << data[i].masuk.jam << ":"
             << data[i].masuk.menit << " | "
             << data[i].keluar.jam << ":"
             << data[i].keluar.menit << " | Rp"
             << data[i].biaya << '\n';
    }
}

// 3. Mencari kendaraan
void cariKendaraan(Kendaraan data[], int jumlah)
{
    string nomor;

    cout << "Nomor kendaraan yang dicari: ";
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

// 4. Mengurutkan kendaraan
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

    simpanData(data, jumlah);
    cout << "Data berhasil diurutkan.\n";
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

            simpanData(data, jumlah);
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
            simpanData(data, jumlah);

            cout << "Data berhasil dihapus.\n";
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

    cout << "Ukuran WaktuParkir: "
         << sizeof(WaktuParkir) << " byte\n";

    cout << "Ukuran Kendaraan: "
         << sizeof(Kendaraan) << " byte\n";

    cout << "Ukuran array 20 kendaraan: "
         << sizeof(Kendaraan) * 20 << " byte\n";
}
