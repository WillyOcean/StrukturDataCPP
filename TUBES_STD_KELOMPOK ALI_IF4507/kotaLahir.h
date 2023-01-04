#ifndef KOTALAHIR_H_INCLUDED
#define KOTALAHIR_H_INCLUDED

#include <iostream>
using namespace std;

#define nil NULL
#define infoKota(P) (P)->infoKota
#define infoOrang(P) (P)->infoOrang
#define nextKota(P) (P)->nextKota
#define nextOrang(P) (P)->nextOrang
#define kotaLahir(P) (P)->kotaLahir
#define first(L) ((L).first)
#define kota(p) (p)->kota

struct infotypeKota{
    string namaKota, provinsiKota;
};

typedef struct elemenKota *adr_kota;

struct elemenKota{
    infotypeKota infoKota;
    adr_kota nextKota;
};

struct infotypeOrang{
    string namaOrang, jk;
    int umur;
};

typedef struct elemenOrang *adr_orang;

struct elemenOrang{
    infotypeOrang infoOrang;
    adr_orang nextOrang;
    adr_kota kotaLahir;
};

struct listOrang{
    adr_orang first;
};

struct listKota{
    adr_kota first;
};

//Buat List
void createListOrang(listOrang &LO);
/*
    I.S -
    F.S first dari listOrang LO berisi nil
*/
void createListKota(listKota &LK);
/*
    I.S -
    F.S first dari listKota LK berisi nil
*/

//Buat Elemen
adr_orang createElemenOrang(infotypeOrang x);
/*
    Mengembalikan adr_orang yang berisi infotypeOrang x dan nextOrang berisi nil, kotaAsal berisi nil
*/
adr_kota createElemenKota(infotypeKota x);
/*
    Mengembalikan adr_kota yang berisi infotypeKota x dan nextKota berisi nil
*/

//Menambahkan Data
void insertLastOrang(listOrang &LO, adr_orang p);
/*
    I.S Terdefinisi ListOrang LO yang mungkin kosong dan adr_orang p
    F.S adr_orang p menjadi elemen paling akhir dari ListOrang LO
*/
void insertLastKota(listKota &LK, adr_kota p);
/*
    I.S Terdefinisi ListKota LK yang mungkin kosong dan adr_kota p
    F.S adr_kota p menjadi elemen paling akhir dari ListKota LK
*/


//Mencari Data
adr_kota searchKota(listKota LK, string nama_kota);
/*
    Mengembalikan adr_kota yang berisi nama_kota dari listKota LK
*/
adr_orang searchOrang(listOrang LO, string nama_orang);
/*
    Mengembalikan adr_orang yang berisi nama_orang dari listOrang LO
*/

//Menampilkan Data (SLL)
void showAllKota(listKota LK,listOrang LO);
/*
    I.S Terdefinisi ListKota LK yang mungkin kosong
    F.S Menampilkan semua info kota dari ListKota LK
*/

//Menambahkan Relasi
void insertKotaAsal(listKota LK,listOrang &LO, string nama_orang, string nama_kota);
/*
    I.S Terdefinisi ListKota LK, ListOrang LO yang tidak kosong, nama_orang, nama_kota
    F.S elemen dari listOrang LO yang memiliki info nama_orang akan didefinisikan kotaAsal-nya dengan
        menunjuk ke elemen kota yang memiliki info nama_kota dari listKota LK
*/

//Menghapus Data beserta relasinya
void deleteFirstOrang(listOrang &LO,adr_orang &p);
/*
    I.S Terdefinisi ListOrang LO yang mungkin kosong,dan adr_orang p
    F.S Menghapus elemen pertama dari listOrang LO dan elemen tersebut disimpan di adr_orang p
*/
void deleteLastOrang(listOrang &LO,adr_orang &p);
/*
    I.S Terdefinisi ListOrang LO yang mungkin kosong,dan adr_orang p
    F.S Menghapus elemen terakhir dari listOrang LO dan elemen tersebut disimpan di adr_orang p
*/
void deleteAfterOrang(listOrang &LO, adr_orang prec, adr_orang &p);
/*
    I.S Terdefinisi ListOrang LO yang tidak kosong,adr_orang prec, adr_orang p
    F.S Menghapus elemen setelah elemen prec dari listOrang LO dan elemen tersebut disimpan di adr_orang p
*/
void deleteOrangSpesifik(listOrang &LO, string nama_orang,adr_orang &p);
/*
    I.S Terdefinisi ListOrang LO yang mungkin kosong, nama_orang,dan adr_orang p
    F.S Menghapus elemen yang memiliki info nama_orang dari listOrang LO dan elemen tersebut disimpan di adr_orang p
*/

void deleteFirstKota(listKota &LK, listOrang &LO,adr_kota &p);
/*
    I.S Terdefinisi ListKota LK yang mungkin kosong,dan adr_kota p
    F.S Menghapus elemen pertama dari listKota LK dan elemen tersebut disimpan di adr_kota p
*/
void deleteLastKota(listKota &LK, listOrang &LO,adr_kota &p);
/*
    I.S Terdefinisi ListKota LK yang mungkin kosong,dan adr_kota p
    F.S Menghapus elemen terakhir dari listKota LK dan elemen tersebut disimpan di adr_kota p
*/
void deleteAfterKota(listKota &LK, listOrang &LO, adr_kota prec, adr_kota &p);
/*
    I.S Terdefinisi ListKota LK yang tidak kosong,adr_kota prec, adr_kota p
    F.S Menghapus elemen setelah elemen prec dari listKota LK dan elemen tersebut disimpan di adr_kota p
*/
void deleteKotaSpesifik(listKota &LK, listOrang &LO, string nama_kota,adr_kota &p);
/*
    I.S Terdefinisi ListKota LK yang mungkin kosong, nama_kota,dan adr_kota p
    F.S Menghapus elemen yang memiliki info nama_kota dari listKota LK dan elemen tersebut disimpan di adr_kota p
*/

//Menampilkan Data (MLL)
void showAllOrang(listOrang LO);
/*
    I.S Terdefinisi ListOrang LO yang mungkin kosong
    F.S Menampilkan semua info orang dari ListOrang LO
*/

//Menghitung Jumlah Data (MLL)
int JumlahOrang(listOrang LO,listKota LK ,string nama_kota);
/*
    Mengembalikan jumlah orang yang berasal dari elemen kota dengan info nama_kota
*/

//Menampilkan Jumlah data Paling banyak (MLL)
void showMax(listOrang LO,listKota LK);
/*
    I.S Terdefinisi ListOrang LO, listKota LK yang tidak kosong
    F.S Menampilkan info kota yang memiliki paling banyak orang berasal dari kota tersebut
*/

//Menampilkan Jumlah data Paling sedikit (MLL)
void showMin(listOrang LO,listKota LK);
/*
    I.S Terdefinisi ListOrang LO, listKota LK yang tidak kosong
    F.S Menampilkan info kota yang memiliki paling sedikit orang berasal dari kota tersebut
*/

//Function Tambahan
bool isEmptyKota(listKota LK);
bool isEmptyOrang(listOrang LO);
int selectMenu();

#endif // KOTALAHIR_H_INCLUDED
