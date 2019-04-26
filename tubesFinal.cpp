#include "tubesFinal.h"

/** Bagian LIST PEMBELI */
bool isEmptyPembeli(LPembeli L){
    return (firstPbl(L) == NULL);
}
void createListPembeli(LPembeli &L){
    firstPbl(L) = NULL;
}
adrPembeli alokasiPembeli(string name,string tl,string bl,string th){
    adrPembeli p = new elmPembeli;
    nama(p) = name;
    date(p) = tl;
    month(p) = bl;
    year(p) = th;
    nextP(p) = NULL;
    prevP(p) = NULL;
    return p;
}
void insertLastPembeli(LPembeli &L, adrPembeli p){
    if (isEmptyPembeli(L)){
        firstPbl(L) = p;
    } else {
        adrPembeli q = firstPbl(L);
        while (nextP(q) != NULL){
            q= nextP(q);
        }
        nextP(q) = p;
        prevP(p) = q;
    }
}
void deleteFirstPembeli(LPembeli &L, adrPembeli &p){
    if (!isEmptyPembeli(L)){
        if (nextP(firstPbl(L)) == NULL){
            p = firstPbl(L);
        } else {
            p = firstPbl(L);
            firstPbl(L) = nextP(p);
            nextP(p) = NULL;
            prevP(firstPbl(L)) = NULL;
        }
    } else {
        cout << "data kosong" <<endl;
    }
}
void deleteLastPembeli(LPembeli &L, adrPembeli &p){
    if (!isEmptyPembeli(L)){
        adrPembeli q = firstPbl(L);
        while (nextP(nextP(q)) != NULL){
            q = nextP(q);
        }
        if (q == firstPbl(L)){
            p = firstPbl(L);
            firstPbl(L) = NULL;
        } else {
            p = nextP(q);
            nextP(q) = NULL;
            prevP(p) = NULL;
        }
    }
}
void deleteAfterPembeli(LPembeli &L, adrPembeli prec, adrPembeli &p){
    if ((prec == firstPbl(L)) && (nextP(nextP(prec)) == NULL)) {
        p = nextP(prec);
        nextP(prec) = NULL;
        prevP(p) = NULL;
    } else {
        p = nextP(prec);
        nextP(prec) = nextP(p);
        prevP(nextP(p)) = prec;
        nextP(p) = NULL;
        prevP(p) = NULL;
    }
}
adrPembeli searchNama(LPembeli L,string name){
    adrPembeli pb = firstPbl(L);
    bool nemu = false;
    while ((pb != NULL) && (nemu != true)){
        if (nama(pb) == name){
            nemu = true;
        } else {
            pb = nextP(pb);
        }
    }
    if (nemu){
        return pb;
    }
    return NULL;
}


/** Bagian LIST BARANG */
bool isEmpty(LBarang L){
    return(firstBrg(L) == NULL);
}
void createLBarangarang(LBarang &L){
    firstBrg(L) = NULL;
}
adrBarang createNewElmBarang(string jBarang,string nBarang,int kBarang,int jumBarang,int hBarang){
    adrBarang P = new elmBarang;
	JenisBarang(P) = jBarang;
	namaBarang(P) = nBarang;
	KodeBarang(P) = kBarang;
	JumlahBarang(P) = jumBarang;
	Harga(P) = hBarang;
	nextB(P) = NULL;
	prevB(P) = NULL;
	return P;
}
void inserLastBarang(LBarang &L, adrBarang p){
    if (isEmpty(L)){
        firstBrg(L) = p;
    } else {
        adrBarang q = firstBrg(L);
        while (nextB(q) != NULL){
            q= nextB(q);
        }
        nextB(q) = p;
        prevB(p) = q;
    }
}
void insertAfterBarang(LBarang &L , adrBarang Prec , adrBarang P){
    if ((Prec == firstBrg(L)) && (nextB(Prec) == NULL)){
        nextB(Prec) = P;
        prevB(P) = Prec;
    } else {
        nextB(P) = nextB(Prec);
        prevB(P) = Prec;
        prevB(nextB(Prec)) = P;
        nextB(Prec) = P;
    }
}
void deleteFirstBarang(LBarang &L , adrBarang &P){
    if (!isEmpty(L)){
        if (nextB(firstBrg(L)) == NULL){
            P = firstBrg(L);
        } else {
            P = firstBrg(L);
            firstBrg(L) = nextB(P);
            nextB(P) = NULL;
            prevB(firstBrg(L)) = NULL;
        }
    } else {
        cout << "data kosong" <<endl;
    }
}
void deleteLastBarang(LBarang &L, adrBarang &p){
    if (!isEmpty(L)){
        adrBarang q = firstBrg(L);
        while (nextB(nextB(q)) != NULL){
            q = nextB(q);
        }
        if (q == firstBrg(L)){
            p = firstBrg(L);
            firstBrg(L) = NULL;
        } else {
            p = nextB(q);
            nextB(q) = NULL;
            prevB(p) = NULL;
        }
    }
}
void deleteAfterBarang(LBarang &L, adrBarang prec,adrBarang &P){
    if ((prec == firstBrg(L)) && (nextB(nextB(prec)) == NULL)) {
        P = nextB(prec);
        nextB(prec) = NULL;
        prevB(P) = NULL;
    } else {
        P = nextB(prec);
        nextB(prec) = nextB(P);
        prevB(nextB(P)) = prec;
        nextB(P) = NULL;
        prevB(P) = NULL;
    }
}
adrBarang searchBarang(LBarang L, string nBarang){
    adrBarang p = firstBrg(L);
    bool f = false;
    while ((p != NULL) && (f != true)){
        if (namaBarang(p) == nBarang){
            f = true;
        } else {
            p = nextB(p);
        }
    }
    if (f){
        return p;
    }
    return NULL;
}
void kurangStokBarang(LBarang &L,adrBarang B){
    JumlahBarang(B)--;
}
void updateStok(LBarang &L,adrBarang B, int update){
    JumlahBarang(B) = JumlahBarang(B)+update;
}
void stok(LBarang L){
    cout << "stok tersedia" <<endl;
    adrBarang b = firstBrg(L);
    while (b != NULL){
        cout << namaBarang(b) << "(" << JumlahBarang(b) << ") | ";
        b = nextB(b);
    }
    cout <<endl;
}
void barangDefault(LBarang &L){
    adrBarang b = createNewElmBarang("minuman","susu",01,3,5000);
    inserLastBarang(L,b);
    b = createNewElmBarang("minuman","airMineral",02,3,5000);
    inserLastBarang(L,b);
    b = createNewElmBarang("snack","roti",03,3,3000);
    inserLastBarang(L,b);
    b = createNewElmBarang("snack","cheetos",04,3,5000);
    inserLastBarang(L,b);
    b = createNewElmBarang("makanan","mie",05,3,2500);
    inserLastBarang(L,b);
}
void Chart(ListRel &L,LPembeli LP, LBarang LB, adrPembeli pb){      /** show relasi dengan paramater nama pembeli */
    if (firstRel(L) != NULL){
        int sum = 0;
        string ulangTahun = date(pb)+month(pb);
        cout << "Nama: " << nama(pb) <<endl;
        adrRelasi r = firstRel(L);
        cout << "============ daftar barang dibeli ===================="<<endl;
        while (r != lastRel(L)) {
            if (nextPembeli(r) == pb) {
                cout << namaBarang(nextBarang(r)) <<endl;
                cout << JenisBarang(nextBarang(r)) <<endl;
                cout << Harga(nextBarang(r)) <<endl;
                sum = sum+Harga(nextBarang(r));
            }
            r = nextRel(r);
        }
        if (nextPembeli(r) == pb) {
            cout << namaBarang(nextBarang(r)) <<endl;
            cout << JenisBarang(nextBarang(r)) <<endl;
            cout << Harga(nextBarang(r)) <<endl;
            sum = sum+Harga(nextBarang(r));
        }
        diskon(L,r,pb,sum,ulangTahun);
        cout <<endl;
    }
}
void diskon(ListRel &L,adrRelasi r,adrPembeli pb,int sum,string ulangTahun){
    int dis = sum*20/100;
    if (tanggal(r) == ulangTahun){
        total(r) = sum - dis;
        cout << "Diskon 20% karena anda hari ini ulang tahun!"<<endl;
        cout << "total pembayaran: " << total(r) <<endl;
    } else {
        total(r) = sum;
        cout << "total pembayaran: " << total(r) <<endl;
    }
}

/** Bagian LIST RELASI */
bool isEmptyRel(ListRel L){
    return(firstRel(L) == NULL);
}
adrRelasi alokasiRelasi(adrPembeli pembeli, adrBarang barang, string dt,string mon,string yr){
    adrRelasi p = new elmRelasi;
    nextPembeli(p) = pembeli;
    nextBarang(p) = barang;
    tanggal(p) = dt+mon;
    berat(p) = 0.3;          /** default 0.3 kg */
    nextRel(p) = NULL;
    prevRel(p) = NULL;
    return p;
}
void createListRelasi(ListRel &L){
    firstRel(L) = NULL;
    lastRel(L) = NULL;
}
void insertLastRelasi(ListRel &L, adrRelasi p){
    if (isEmptyRel(L)){
        firstRel(L)= p;
        lastRel(L) = p;
        nextRel(lastRel(L)) = firstRel(L);
        prevRel(firstRel(L)) = lastRel(L);
    } else {
        nextRel(lastRel(L)) = p;
        prevRel(p) = lastRel(L);
        lastRel(L) = p;
        nextRel(lastRel(L)) = firstRel(L);
        prevRel(firstRel(L)) = lastRel(L);
    }
}
void deleteFirstRelasi(ListRel &L, adrRelasi &p){
    if (!isEmptyRel(L)){
        if (firstRel(L) == lastRel(L)){
            p = firstRel(L);
            firstRel(L) = NULL;
            lastRel(L) = NULL;
            nextPembeli(p) = NULL;
            nextBarang(p) = NULL;
        } else {
            p = firstRel(L);
            firstRel(L) = nextRel(p);
            prevRel(firstRel(L)) = lastRel(L);
            nextRel(lastRel(L)) = firstRel(L);
            nextRel(p) = NULL;
            prevRel(p) = NULL;
            nextBarang(p) = NULL;
            nextPembeli(p) = NULL;

        }
    } else {
        cout << "list kosong" <<endl;
    }
}
void deleteLastRelasi(ListRel &L, adrRelasi &p){
    if (!isEmptyRel(L)){
        if (firstRel(L) == lastRel(L)){
            p = lastRel(L);
            prevRel(p) = NULL;
            nextRel(p) = NULL;
            nextBarang(p) = NULL;
            nextPembeli(p) = NULL;
            firstRel(L) = NULL;
            lastRel(L) = NULL;
        } else {
            p = lastRel(L);
            lastRel(L) = prevRel(p);
            nextRel(lastRel(L)) = firstRel(L);
            prevRel(firstRel(L)) = lastRel(L);
            nextRel(p) = NULL;
            prevRel(p) = NULL;
            nextPembeli(p) = NULL;
            nextBarang(p) = NULL;
        }
    } else {
        cout << "list kosong" <<endl;
    }
}
void deleteAfterRelasi(ListRel &L, adrRelasi prec, adrRelasi &p){
    if ((prec == firstRel(L)) && (nextRel(nextRel(prec)) == firstRel(L))) {
        p = nextRel(prec);
        nextRel(prec) = firstRel(L);
        prevRel(firstRel(L)) = prec;
        prevRel(p) = NULL;
        nextRel(p) = NULL;
        nextBarang(p) = NULL;
        nextPembeli(p) = NULL;
    } else {
        if (prec == lastRel(L)){
            deleteFirstRelasi(L,p);
        }else if ((prec != firstRel(L))&&(nextRel(prec) == lastRel(L))) {
            deleteLastRelasi(L,p);
        } else {
            p = nextRel(prec);
            nextRel(prec) = nextRel(p);
            prevRel(nextRel(p)) = prec;
            nextBarang(p) = NULL;
            nextPembeli(p) = NULL;
            nextRel(p) = NULL;
            prevRel(p) = NULL;
        }
    }
}
void logPembeli(ListRel L,LPembeli LP,LBarang LB){
    if (firstRel(L)!=NULL){                         /** show relasi */
        adrPembeli pb = firstPbl(LP);
        while (pb != NULL){
            int sum = 0;
            cout << "Nama         : " << nama(pb) <<endl;
            cout << "tanggal lahir: " << date(pb)<<"/"<<month(pb)<<"/"<<year(pb)<<endl;
            adrRelasi r = firstRel(L);
            cout << "============ daftar barang dibeli ===================="<<endl;
            while (r != lastRel(L)) {
                if (nextPembeli(r) == pb) {
                    cout << namaBarang(nextBarang(r)) <<endl;
                    cout << JenisBarang(nextBarang(r)) <<endl;
                    cout << Harga(nextBarang(r)) <<endl;
                    sum = sum+Harga(nextBarang(r));
                }
                r = nextRel(r);
            }
            if (nextPembeli(r) == pb) {
                cout << namaBarang(nextBarang(r)) <<endl;
                cout << JenisBarang(nextBarang(r)) <<endl;
                cout << Harga(nextBarang(r)) <<endl;
                sum = sum+Harga(nextBarang(r));
            }
            diskon(L,r,pb,sum,date(pb)+month(pb));
            pb = nextP(pb);
        }
    }
}
void deleteChart(ListRel &L,adrBarang br,adrPembeli pb, adrRelasi &p){  /** delete relasi */
    adrRelasi r = firstRel(L);
    bool nemu = false;
    while ((nextRel(r) != firstRel(L))&&(nemu != true)){
        if ((nextPembeli(r) == pb)&&(nextBarang(r) == br)){     /** searching di relasi */
            nemu = true;
        } else {
            r = nextRel(r);
        }
    }
    if ((nextPembeli(r) == pb)&&(nextBarang(r) == br)){
        nemu = true;
    }
    if (nemu){
        adrRelasi p;
        if (r == firstRel(L)){              /** delete relasi */
            deleteFirstRelasi(L,p);
        } else if (r==lastRel(L)){
            deleteLastRelasi(L,p);
        } else {
            r = prevRel(r);
            deleteAfterRelasi(L,r,p);
        }
    }
}
