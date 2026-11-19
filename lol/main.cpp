#include <iostream>
#include "lol.h"
using namespace std;


int main() {
    ListHero L;
    createList(L);

    adrHero garen  = createElmHero("Garen", "Tank/Fighter", "Mele");
    adrHero aatrox = createElmHero("Aatrox", "Fighter", "Mele");
    adrHero jhin   = createElmHero("Jhin", "Marksman", "Range");
    insertLastHero(L, garen);
    insertLastHero(L, aatrox);
    insertLastHero(L, jhin);

    insertLastItem(garen, createElmItem("PlatedSteelCaps", "Defense", 1200));
    insertLastItem(garen, createElmItem("BlackCleaver", "Attack", 3000));
    insertLastItem(garen, createElmItem("DeadMan'sPlate", "Defense", 2800));
    insertLastItem(jhin, createElmItem("TheCollector", "Attack_Critical", 3000));
    insertLastItem(jhin, createElmItem("BootsOfDynamism", "Move_Speed", 1200));

    int pilih, harga;
    string namaHero, role, tipeSerangan, namaItem, tipeItem;
    adrHero H;

    do {
        cout << "\n===== RIFT ARMORY MANAGER =====" << endl;
        cout << "1. Tambah hero" << endl;
        cout << "2. Beli item untuk hero" << endl;
        cout << "3. Jual item milik hero" << endl;
        cout << "4. Hapus hero" << endl;
        cout << "5. Cari hero" << endl;
        cout << "6. Tampilkan semua" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;
        cout << endl;

        if (pilih == 1) {
            cout << "Nama hero : ";
            cin >> namaHero;
            cout << "Role      : ";
            cin >> role;
            cout << "Mele/Range: ";
            cin >> tipeSerangan;
            insertLastHero(L, createElmHero(namaHero, role, tipeSerangan));
            cout << "Hero ditambahkan." << endl;

        } else if (pilih == 2) {
            cout << "Nama hero : ";
            cin >> namaHero;
            H = findHero(L, namaHero);
            if (H == nullptr) {
                cout << "Hero tidak ditemukan." << endl;
            } else {
                cout << "Nama item : ";
                cin >> namaItem;
                cout << "Tipe item : ";
                cin >> tipeItem;
                cout << "Harga     : ";
                cin >> harga;
                insertLastItem(H, createElmItem(namaItem, tipeItem, harga));
                cout << "Jumlah item " << H->info.heroName << " sekarang: "
                     << countItem(H) << endl;
            }

        } else if (pilih == 3) {
            cout << "Nama hero : ";
            cin >> namaHero;
            H = findHero(L, namaHero);
            if (H == nullptr) {
                cout << "Hero tidak ditemukan." << endl;
            } else {
                cout << "Item yang dijual: ";
                cin >> namaItem;
                deleteItemByName(H, namaItem);
            }

        } else if (pilih == 4) {
            cout << "Nama hero : ";
            cin >> namaHero;
            deleteHeroByName(L, namaHero);

        } else if (pilih == 5) {
            cout << "Nama hero : ";
            cin >> namaHero;
            H = findHero(L, namaHero);
            if (H == nullptr) {
                cout << "Hero tidak ditemukan." << endl;
            } else {
                cout << "Ditemukan: " << H->info.heroName << " | " << H->info.role
                     << " | " << H->info.attackType << " | "
                     << countItem(H) << " item" << endl;
            }

        } else if (pilih == 6) {
            showAll(L);

        } else if (pilih != 0) {
            cout << "Menu tidak valid." << endl;
        }

    } while (pilih != 0);

    return 0;
}
