#include <iostream>
#include <cstdlib>
#include "tubesFinal.h"

using namespace std;

int main()
{
    LPembeli LP;                /** list pembeli */
    ListRel LR;                 /** List relasi  */
    LBarang LB;                 /** list barang  */
    createListPembeli(LP);      /** create list pembeli */
    createLBarangarang(LB);     /** create list barang  */
    createListRelasi(LR);       /** create list relasi  */

    barangDefault(LB);                                                   /** set barang default = 5 buah */ /** bisa di update dan di delete */

    string dt,mon,yr;
    string tgl,bln,thn;
    cout << "Masukkan tanggal: "<<endl;                                /** Lokal time */
    cout << "tanggal: "; cin >> dt;
    cout << "Bulan  : "; cin >> mon;
    cout << "Tahun  : "; cin >> yr;

    string lokalTime = dt + "/"+ mon + "/" + yr;                                          /**  date/month/year   */

    /** var */
    int pil,pilAdmin,i;

    string namaBrg,jenisBrg, namaPlg;
    int jumBrg,kodeBrg,hargaBrg, update;
    adrBarang br,p;
    adrPembeli pb;
    adrRelasi rl,r;

    /** Main */
    do{
        system("CLS");
        cout << string(84, ' ') << "Current time"<<endl;
        cout << string(85, ' ') << lokalTime <<endl;                                        /** set lokal time */

        cout << "1. Admin mode" <<endl;
        cout << "2. User mode" <<endl;
        cout << "pilih: "; cin >> pil;
        switch (pil){
        case 1:
            system("CLS");
            do{
                cout << " ===== stok sementara ====="<<endl;
                stok(LB);
                cout << "1. insert barang" <<endl;
                cout << "2. hapus barang" <<endl;
                cout << "3. update stock" <<endl;
                cout << "4. log pembeli" <<endl;
                cout << "5. cari nama pembeli"<<endl;
                cout << "0. back" <<endl;
                cout << "pilih: "; cin >> pilAdmin;
                switch (pilAdmin) {
                case 1:
                    cout << "Nama barang  : "; cin >> namaBrg;
                    cout << "Jenis Barang : "; cin >> jenisBrg;
                    cout << "kode barang  : "; cin >> kodeBrg;
                    cout << "jumlah barang: "; cin >> jumBrg;
                    cout << "harga/kg     : "; cin >> hargaBrg;
                    br = createNewElmBarang(jenisBrg,namaBrg,kodeBrg,jumBrg,hargaBrg);  /** alokasi barang baru */
                    inserLastBarang(LB,br); break;
                case 2:
                    stok(LB);
                    cout << "nama barang yang akan di hapus: "; cin >> namaBrg;        /** delete barang */
                    br = searchBarang(LB,namaBrg);
                    if (br != NULL){
                        if (br == firstBrg(LB)){
                            deleteFirstBarang(LB,p);
                        } else if (nextB(br) == NULL){
                            deleteLastBarang(LB,p);
                        } else {
                            p = br;
                            br = prevB(p);
                            deleteAfterBarang(LB,br,p);
                        }
                        cout << "deleted !" <<endl;
                    } else {
                        cout << "not found !" <<endl;
                    }; break;
                case 3:
                    stok(LB);
                    cout << "nama dari barang yang akan di update: "; cin >> namaBrg;       /** update stok */
                    br = searchBarang(LB,namaBrg);
                    if (br != NULL){
                        cout << "tambah stok: "; cin >> update;
                        updateStok(LB,br,update);
                        cout << "updated !"<<endl;
                    } else {
                        cout << "not found!"<<endl;
                    }
                    cout<<endl; break;
                case 4:
                    logPembeli(LR,LP,LB);break;
                case 5:
                    cout << "Masukkan nama yang dicari: "; cin >> namaPlg;
                    pb = searchNama(LP,namaPlg);                                            /** show pembeli */
                    if (pb != NULL){
                        cout << nama(pb) << " found !" <<endl;
                        Chart(LR,LP,LB,pb);
                    } else {
                        cout << "not found!" <<endl;
                    }
                    cout << endl; break;
                case 0:break;
                default:break;
                }
            } while (pilAdmin != 0);break;
        case 2:
            cout << "nama :"; cin >> namaPlg;
            cout << "tanggal lahir" <<endl;
            cout << "tanggal: "; cin >> tgl;
            cout << "bulan  : "; cin >> bln;
            cout << "tahun  : "; cin >>thn;
            pb = alokasiPembeli(namaPlg,tgl,bln,thn);                                /** alokasi pembeli */
            insertLastPembeli(LP,pb);                                                /** insert last ke list pembeli */

            system("CLS");
            cout << string(84, ' ') << "Current time"<<endl;                          /** pasang waktu di menu */
            cout << string(85, ' ') << lokalTime <<endl;                              /** pasang waktu di menu */

            stok(LB);                                                                  /** tampilkan stok tersedia */
            cout << "Masukkan nama barang yang akan dibeli (ketik 'stop' untuk berhenti)" <<endl;
            cout <<endl;
            i = 1;
            cout << "barang ke " << i  <<" :"; cin >> namaBrg;                          /** input nama barang yang akan dibeli */
            while (namaBrg != "stop"){
                br = searchBarang(LB,namaBrg);
                if (br != NULL){
                    if (JumlahBarang(br) != 0) {
                        rl = alokasiRelasi(pb,br,dt,mon,yr);                            /** alokasi relasi */
                        insertLastRelasi(LR,rl);                                        /** insert last ke list relasi */
                        kurangStokBarang(LB,br);                                        /** stock berkurang 1 */
                        cout << "added!" <<endl;
                        i++;                                                             /** menandakan inputan barang ke i */
                    } else {
                        cout << "stok habis"<<endl;                                     /** jika stok habis */
                    }
                }
                system("PAUSE");                                                        /** menunggu enter */
                system("CLS");
                cout << string(84, ' ') << "Current time"<<endl;
                cout << string(85, ' ') << lokalTime <<endl;                            /** set lokal time */

                stok(LB);
                cout <<endl;
                cout << "Masukkan nama barang yang akan dibeli (ketik 'stop' untuk berhenti)" <<endl;
                cout <<endl;
                cout << "barang ke " << i  <<" :"; cin >> namaBrg;
            }
            system("CLS");
            Chart(LR,LP,LB,pb);
            cout << "batalkan pembelian barang (ketik deal untuk melanjutkan pembayaran): "; cin >> namaBrg;
            while (namaBrg != "deal"){
                br = searchBarang(LB,namaBrg);                                          /** search barang */
                if (br != NULL){
                    deleteChart(LR,br,pb,r);                                            /** delete relasi */
                    cout<<" Deleted! "<<endl;
                }
                system("PAUSE");
                system("CLS");
                Chart(LR,LP,LB,pb);
                cout << "batalkan pembelian barang (ketik deal untuk melanjutkan pembayaran): "; cin >> namaBrg;
            };
            system("CLS");
            Chart(LR,LP,LB,pb);                                                          /** Update chart */
            system("PAUSE");break;
        default:break;
        }
    } while (pil != 0);

    return 0;
}
