#include <iostream>
#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    CreateList(L);

    // Latihan 1: input 4 data kendaraan, nopol harus unik
    int jumlah = 4;
    for (int i = 0; i < jumlah; i++) {
        infotype x;
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        if (findElm(L, x) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            insertLast(L, alokasi(x));
        }
        cout << endl;
    }

    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);
    cout << endl;

    // Latihan 2: cari nomor polisi
    infotype cari;
    cout << "Masukkan Nomor Polisi yang dicari  : ";
    cin >> cari.nopol;
    address P = findElm(L, cari);
    if (P != Nil) {
        cout << endl;
        cout << "Nomor Polisi  : " << P->info.nopol << endl;
        cout << "Warna         : " << P->info.warna << endl;
        cout << "Tahun         : " << P->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }
    cout << endl;

    // Latihan 3: hapus nomor polisi
    infotype hapus;
    cout << "Masukkan Nomor Polisi yang akan dihapus  : ";
    cin >> hapus.nopol;
    address target = findElm(L, hapus);
    if (target != Nil) {
        address dihapus = Nil;
        if (target == L.First) {
            deleteFirst(L, dihapus);
        } else if (target == L.Last) {
            deleteLast(L, dihapus);
        } else {
            deleteAfter(target->prev, dihapus);
        }
        cout << "Data dengan nomor polisi " << dihapus->info.nopol
             << " berhasil dihapus." << endl;
        dealokasi(dihapus);
    } else {
        cout << "Data tidak ditemukan" << endl;
    }
    cout << endl;

    cout << "DATA LIST 1" << endl << endl;
    // Format cetak akhir mengikuti Gambar 6-25 (Nomor Polisi / Warna / Tahun)
    address Q = L.Last;
    while (Q != Nil) {
        cout << "Nomor Polisi  : " << Q->info.nopol << endl;
        cout << "Warna         : " << Q->info.warna << endl;
        cout << "Tahun         : " << Q->info.thnBuat << endl;
        Q = Q->prev;
    }

    return 0;
}
