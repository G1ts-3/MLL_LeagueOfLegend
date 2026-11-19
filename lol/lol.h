#ifndef LOL_H_INCLUDED
#define LOL_H_INCLUDED

#include <iostream>
using namespace std;

struct Hero {
    string heroName;
    string role;
    string attackType;
};

struct Item {
    string itemName;
    string itemType;
    int harga;
};

struct elmHero;
struct elmItem;
typedef elmHero *adrHero;
typedef elmItem *adrItem;

struct elmItem {
    Item info;
    adrItem next;
};

struct elmHero {
    Hero info;
    adrHero next;
    adrItem nextItem;
};

struct ListHero {
    adrHero first;
};

void createList(ListHero &L);
adrHero createElmHero(string name,string role,string type);
adrItem createElmItem(string name,string itemType,int harga);
bool isEmpty(ListHero L);
bool isEmptyItem(adrHero p);
bool isFullItem(adrHero H);
void insertLastHero(ListHero &L, adrHero P);
void deleteHeroByName(ListHero &L, string heroName);
adrHero findHero(ListHero L, string heroName);
void insertLastItem(adrHero H, adrItem P);
void deleteItemByName(adrHero H, string itemName);
adrItem findItem(adrHero H, string itemName);
int countItem(adrHero H);
void showAll(ListHero L);
#endif // LOL_H_INCLUDED
