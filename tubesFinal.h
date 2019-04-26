#ifndef TUBESFINAL_H_INCLUDED
#define TUBESFINAL_H_INCLUDED
#include <iostream>
#define nama(p)  p->nama
#define date(p)  p->date
#define month(p)  p->month
#define year(p)  p->year
#define firstPbl(L)  L.firstPbl
#define nextP(p)  p->nextP
#define prevP(p)  p->prevP

#define firstBrg(L) L.firstBrg
#define elmBarang(P) (P)->elmBarang
#define namaBarang(P) (P)->namaBarang
#define JenisBarang(P) (P)->JenisBarang
#define JumlahBarang(P) (P)->JumlahBarang
#define KodeBarang(P) (P)->KodeBarang
#define Harga(P) (P)->Harga
#define nextB(P) (P)->nextB
#define prevB(P) (P)->prevB

#define firstRel(r)  r.firstRel
#define lastRel(r)  r.lastRel
#define berat(r)  r->berat
#define nextRel(r)  r->nextRel
#define prevRel(r)  r->prevRel
#define nextBarang(r)  r->nextBarang
#define nextPembeli(r)  r->nextPembeli
#define total(r)  r->totalHargaBarang
#define tanggal(r)  r->tanggal

using namespace std;

typedef struct elmPembeli *adrPembeli;
typedef struct elmRelasi *adrRelasi;
typedef struct elmBarang *adrBarang;

struct elmPembeli {
    string nama;
    string date,month,year;
    adrPembeli nextP;
    adrPembeli prevP;
};
struct elmBarang
{
	string namaBarang,JenisBarang ;
	int JumlahBarang,KodeBarang;
	int Harga;
	adrBarang nextB;
	adrBarang prevB;
};
struct elmRelasi {
    float berat;
    float totalHargaBarang;
    string tanggal;
    adrRelasi nextRel;
    adrRelasi prevRel;
    adrPembeli nextPembeli;
    adrBarang nextBarang;
};

struct LPembeli {           /** Double Linked List */
    adrPembeli firstPbl;
};
struct ListRel {            /** Circular Double Linked List */
    adrRelasi firstRel;
    adrRelasi lastRel;
};
struct LBarang {            /** Double linked list */
    adrBarang firstBrg;
};


/** Bagian LIST PEMBELI */
bool isEmptyPembeli(LPembeli L);
void createListPembeli(LPembeli &L);
adrPembeli alokasiPembeli(string name,string tl,string bl,string th);
void insertLastPembeli(LPembeli &L, adrPembeli p);
void deleteFirstPembeli(LPembeli &L, adrPembeli &p);
void deleteLastPembeli(LPembeli &L, adrPembeli &p);
void deleteAfterPembeli(LPembeli &L, adrPembeli prec, adrPembeli &p);
adrPembeli searchNama(LPembeli L,string name);

/** bagian LIST BARANG */
bool isEmpty(LBarang L);
void createLBarangarang(LBarang &L);
adrBarang createNewElmBarang(string jBarang,string nBarang,int kBarang,int jumBarang,int hBarang);
void inserLastBarang(LBarang &L, adrBarang p);
void insertAfterBarang(LBarang &L , adrBarang Prec , adrBarang P);
void deleteFirstBarang(LBarang &L , adrBarang &P);
void deleteLastBarang(LBarang &L, adrBarang &p);
void deleteAfterBarang(LBarang &L, adrBarang Prec,adrBarang &P);
adrBarang searchBarang(LBarang L, string nBarang);
void kurangStokBarang(LBarang &L,adrBarang B);
void updateStok(LBarang &L,adrBarang B, int update);
void stok(LBarang L);
void barangDefault(LBarang &L);
void Chart(ListRel &L,LPembeli LP, LBarang LB, adrPembeli pb);
void diskon(ListRel &L,adrRelasi r,adrPembeli pb,int sum,string ulangTahun);

/** bagian LIST RELASI */
bool isEmptyRel(ListRel L);
adrRelasi alokasiRelasi(adrPembeli pembeli, adrBarang barang, string dt,string mon,string yr);
void createListRelasi(ListRel &L);
void insertLastRelasi(ListRel &L, adrRelasi p);
void deleteFirstRelasi(ListRel &L, adrRelasi &p);
void deleteLastRelasi(ListRel &L, adrRelasi &p);
void deleteAfterRelasi(ListRel &L, adrRelasi prec, adrRelasi &p);
void logPembeli(ListRel L, LPembeli LP, LBarang LB);
void deleteChart(ListRel &L,adrBarang br,adrPembeli pb, adrRelasi &p);


#endif // TUBESFINAL_H_INCLUDED
