#include <iostream>
#include "lol.h"

using namespace std;

void createList(ListHero &L){
    L.first = nullptr;
}
adrHero createElmHero(string name,string role,string type){
    adrHero P = new elmHero;
    P->info.heroName = name;
    P->info.role = role;
    P->info.attackType = type;
    P->next = nullptr;
    P->nextItem = nullptr;
    return P;
}
adrItem createElmItem(string name,string itemType,int harga){
    adrItem P = new elmItem;
    P->info.itemName = name;
    P->info.itemType = itemType;
    P->info.harga = harga;
    P->next = nullptr;
    return P;
}
bool isEmpty(ListHero L){
    return L.first == nullptr;
}
bool isEmptyItem(adrHero p) {
    return p->nextItem == nullptr;
}
bool isFullItem(adrHero H) {
    return countItem(H) >= 6;
}
void insertLastHero(ListHero &L, adrHero P){
    if (isEmpty(L)) {
        L.first = P;
    } else {
        adrHero Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}
adrHero findHero(ListHero L, string heroName){
    adrHero P = L.first;
    while (P != nullptr) {
        if (P->info.heroName == heroName) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}
void deleteHeroByName(ListHero &L, string heroName) {
    adrHero target = findHero(L, heroName);
    if (target == nullptr) {
        cout << "Hero tidak ditemukan." << endl;
    } else {
        if (target == L.first) {
            L.first = target->next;
        } else {
            adrHero prec = L.first;
            while (prec->next != target) {
                prec = prec->next;
            }
            prec->next = target->next;
        }
        adrItem I = target->nextItem;
        while (I != nullptr) {
            adrItem hapus = I;
            I = I->next;
            delete hapus;
        }
        delete target;
        cout << "Hero dan item-nya dihapus." << endl;
    }
}
void insertLastItem(adrHero H, adrItem P) {
    if (isFullItem(H)) {
        cout << "Slot item penuh (maks 6)." << endl;
        delete P;
    } else {
        if (isEmptyItem(H)) {
            H->nextItem = P;
        } else {
            adrItem Q = H->nextItem;
            while (Q->next != nullptr) {
                Q = Q->next;
            }
            Q->next = P;
        }
    }
}
adrItem findItem(adrHero H, string itemName) {
    adrItem Q = H->nextItem;
    while (Q != nullptr) {
        if (Q->info.itemName == itemName) {
            return Q;
        }
        Q = Q->next;
    }
    return nullptr;
}
void deleteItemByName(adrHero H, string itemName){
    adrItem target = findItem(H, itemName);
    if (target == nullptr) {
        cout << "Item tidak ditemukan." << endl;
    } else {
        if (target == H->nextItem) {
            H->nextItem = target->next;
        } else {
            adrItem prec = H->nextItem;
            while (prec->next != target) {
                prec = prec->next;
            }
            prec->next = target->next;
        }
        delete target;
        cout << "Item terjual." << endl;
    }
}
int countItem(adrHero H) {
    int n = 0;
    adrItem Q = H->nextItem;
    while (Q != nullptr) {
        n++;
        Q = Q->next;
    }
    return n;
}
void showAll(ListHero L){
    if (isEmpty(L)) {
        cout << "Armory masih kosong." << endl;
    }
    adrHero P = L.first;
    while (P != nullptr) {
        cout << "Hero : " << P->info.heroName << " | "
             << P->info.role << " | " << P->info.attackType << endl;

        if (isEmptyItem(P)) {
            cout << "   (belum ada item)" << endl;
        }
        adrItem Q = P->nextItem;
        while (Q != nullptr) {
            cout << "   - " << Q->info.itemName << " | "
                 << Q->info.itemType << " | " << Q->info.harga << "G" << endl;
            Q = Q->next;
        }
        cout << endl;
        P = P->next;
    }
}
