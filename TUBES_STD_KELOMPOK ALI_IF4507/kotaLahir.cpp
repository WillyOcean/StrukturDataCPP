#include "kotaLahir.h"


//Buat List
void createListOrang(listOrang &LO){
/*
    I.S -
    F.S first dari listOrang LO berisi nil
*/
    first(LO) = nil;
}

void createListKota(listKota &LK){
/*
    I.S -
    F.S first dari listKota LK berisi nil
*/
    first(LK) = nil;
}

//Buat Elemen
adr_orang createElemenOrang(infotypeOrang x){
/*
    Mengembalikan adr_orang yang berisi infotypeOrang x dan nextOrang berisi nil, kotaAsal berisi nil
*/
    adr_orang p;
    p = new elemenOrang;
    infoOrang(p) = x;
    nextOrang(p) = nil;
    kotaLahir(p) = nil;
    return p;
}

adr_kota createElemenKota(infotypeKota x){
/*
    Mengembalikan adr_kota yang berisi infotypeKota x dan nextKota berisi nil
*/
    adr_kota p;
    p = new elemenKota;
    infoKota(p) = x;
    nextKota(p) = nil;
    return p;
}

//Menambahkan Data
void insertLastOrang(listOrang &LO, adr_orang p){
/*
    I.S Terdefinisi ListOrang LO yang mungkin kosong dan adr_orang p
    F.S adr_orang p menjadi elemen paling akhir dari ListOrang LO
*/
    if(isEmptyOrang(LO)){
        first(LO) = p;
    }else{
        adr_orang o;
        o = first(LO);
        while(nextOrang(o) != nil){
            o = nextOrang(o);
        }
        nextOrang(o) = p;
    }
}

void insertLastKota(listKota &LK, adr_kota p){
/*
    I.S Terdefinisi ListKota LK yang mungkin kosong dan adr_kota p
    F.S adr_kota p menjadi elemen paling akhir dari ListKota LK
*/
    if(isEmptyKota(LK)){
        first(LK) = p;
    }else{
        adr_kota k;
        k = first(LK);
        while(nextKota(k) != nil){
            k = nextKota(k);
        }
        nextKota(k) = p;
    }
}

//Mencari Data
adr_kota searchKota(listKota LK, string nama_kota){
/*
    Mengembalikan adr_kota yang berisi nama_kota dari listKota LK
*/
    adr_kota p;
    p = first(LK);
    while (p != nil){
        if(infoKota(p).namaKota == nama_kota){
            return p;
        }
        p = nextKota(p);
    }
    return nil;
}

adr_orang searchOrang(listOrang LO, string nama_orang){
/*
    Mengembalikan adr_orang yang berisi nama_orang dari listOrang LO
*/
    adr_orang p;
    p = first(LO);
    while (p != nil){
        if(infoOrang(p).namaOrang == nama_orang){
            return p;
        }
        p = nextOrang(p);
    }
    return nil;
}

//Menampilkan Data (SLL)
void showAllKota(listKota LK,listOrang LO){
/*
    I.S Terdefinisi ListKota LK yang mungkin kosong
    F.S Menampilkan semua info kota dari ListKota LK
*/
    adr_kota p = first(LK);
    cout<<"======================"<<endl;
    cout<<"Menampilkan List Kota:"<<endl;
    cout<<"======================"<<endl;
    while(p!=nil){
        infotypeKota x = infoKota(p);
        cout<<"Nama Kota: "<<x.namaKota<<endl;
        cout<<"Provinsi Kota: "<<x.provinsiKota<<endl;
        int sumOrang = JumlahOrang(LO,LK,x.namaKota);
        cout<<"Banyak orang berkota lahir di "<<x.namaKota<<": "<<sumOrang<<endl;
        cout<<endl;
        p = nextKota(p);
    }
}

//Menambahkan Relasi
void insertKotaAsal(listKota LK,listOrang &LO, string nama_orang, string nama_kota){
/*
    I.S Terdefinisi ListKota LK, ListOrang LO yang tidak kosong, nama_orang, nama_kota
    F.S elemen dari listOrang LO yang memiliki info nama_orang akan didefinisikan kotaAsal-nya dengan
        menunjuk ke elemen kota yang memiliki info nama_kota dari listKota LK
*/
    adr_orang orang = searchOrang(LO,nama_orang);
    adr_kota kota = searchKota(LK,nama_kota);

    if(orang == nil && kota == nil){
        cout<<"Nama orang dan Nama kota tersebut belum ada di list"<<endl;
    }else if(orang == nil){
        cout<<"Nama orang tersebut belum ada di list"<<endl;
    }else if(kota==nil){
        cout<<"Nama kota tersebut belum ada di list"<<endl;
    }else{
        kotaLahir(orang) = kota;
    }

}

//Menghapus Data beserta relasinya
void deleteFirstOrang(listOrang &LO,adr_orang &p){
/*
    I.S Terdefinisi ListOrang LO yang mungkin kosong,dan adr_orang p
    F.S Menghapus elemen pertama dari listOrang LO dan elemen tersebut disimpan di adr_orang p
*/
    if(isEmptyOrang(LO)){
        cout<<"List Kosong"<<endl;
    }else if(nextOrang(first(LO))==nil){
        p = first(LO);
        first(LO) = nil;
        kotaLahir(p)=nil;
    }else{
        p = first(LO);
        first(LO) = nextOrang(first(LO));
        nextOrang(p) = nil;
        kotaLahir(p)=nil;
    }
}

void deleteLastOrang(listOrang &LO,adr_orang &p){
/*
    I.S Terdefinisi ListOrang LO yang mungkin kosong,dan adr_orang p
    F.S Menghapus elemen terakhir dari listOrang LO dan elemen tersebut disimpan di adr_orang p
*/

    if(isEmptyOrang(LO)){
        cout<<"List Kosong"<<endl;
    }else if(nextOrang(first(LO))==nil){
        p = first(LO);
        first(LO) = nil;
        kotaLahir(p)=nil;
    }else{
        adr_orang q = first(LO);
        while(nextOrang(nextOrang(q))!=nil){
            q = nextOrang(q);
        }
        p = nextOrang(p);
        nextOrang(q) = nil;
        kotaLahir(p)=nil;
    }
}
void deleteAfterOrang(listOrang &LO, adr_orang prec, adr_orang &p){
/*
    I.S Terdefinisi ListOrang LO yang tidak kosong,adr_orang prec, adr_orang p
    F.S Menghapus elemen setelah elemen prec dari listOrang LO dan elemen tersebut disimpan di adr_orang p
*/
    p = nextOrang(prec);
    nextOrang(prec)= nextOrang(p);
    nextOrang(p)=nil;
    kotaLahir(p)=nil;
}
void deleteOrangSpesifik(listOrang &LO, string nama_orang,adr_orang &p){
/*
    I.S Terdefinisi ListOrang LO yang tidak kosong, nama_orang,dan adr_orang p
    F.S Menghapus elemen yang memiliki info nama_orang dari listOrang LO dan elemen tersebut disimpan di adr_orang p
*/
    adr_orang orang = searchOrang(LO,nama_orang);
    if(orang != nil){
        if(orang==first(LO)){
            deleteFirstOrang(LO,p);
        }else if(nextOrang(orang)==nil){
            deleteLastOrang(LO,p);
        }else{
            adr_orang q = first(LO);
            while(nextOrang(q)!=orang){
                q = nextOrang(q);
            }
            deleteAfterOrang(LO,q,p);
        }
    }else{
        cout<<"Nama tersebut tidak ditemukan"<<endl;
    }
}

void deleteFirstKota(listKota &LK,listOrang &LO,adr_kota &p){
/*
    I.S Terdefinisi ListKota LK yang mungkin kosong,dan adr_kota p
    F.S Menghapus elemen pertama dari listKota LK dan elemen tersebut disimpan di adr_kota p
*/
    if(isEmptyKota(LK)){
        cout<<"List Kosong"<<endl;
    }else if(nextKota(first(LK))==nil){
        p = first(LK);
        first(LK) = nil;

        adr_orang r = first(LO);
        while(r != nil){
            if(kotaLahir(r)==p){
                kotaLahir(r)= nil;
            }
            r= nextOrang(r);
        }
    }else{
        p = first(LK);
        first(LK) = nextKota(first(LK));
        nextKota(p) = nil;

        adr_orang r = first(LO);
        while(r != nil){
            if(kotaLahir(r)==p){
                kotaLahir(r)= nil;
            }
            r= nextOrang(r);
        }
    }


}
void deleteLastKota(listKota &LK, listOrang &LO, adr_kota &p){
/*
    I.S Terdefinisi ListKota LK yang mungkin kosong,dan adr_kota p
    F.S Menghapus elemen terakhir dari listKota LK dan elemen tersebut disimpan di adr_kota p
*/
    if(isEmptyKota(LK)){
        cout<<"List Kosong"<<endl;
    }else if(nextKota(first(LK))==nil){
        p = first(LK);
        first(LK) = nil;

        adr_orang r = first(LO);
        while(r != nil){
            if(kotaLahir(r)==p){
                kotaLahir(r)= nil;
            }
            r= nextOrang(r);
        }
    }else{
        adr_kota q = first(LK);
        while(nextKota(nextKota(q))!=nil){
            q = nextKota(q);
        }
        p = nextKota(q);
        nextKota(q) = nil;

        adr_orang r = first(LO);
        while(r != nil){
            if(kotaLahir(r)==p){
                kotaLahir(r)= nil;
            }
            r= nextOrang(r);
        }
    }


}
void deleteAfterKota(listKota &LK, listOrang &LO, adr_kota prec, adr_kota &p){
/*
    I.S Terdefinisi ListKota LK yang tidak kosong,adr_kota prec, adr_kota p
    F.S Menghapus elemen setelah elemen prec dari listKota LK dan elemen tersebut disimpan di adr_kota p
*/
    p = nextKota(prec);
    nextKota(prec)= nextKota(p);
    nextKota(p)=nil;

    adr_orang r = first(LO);
    while(r != nil){
        if(kotaLahir(r)==p){
            kotaLahir(r) = nil;
        }
        r= nextOrang(r);
    }
}

void deleteKotaSpesifik(listKota &LK, listOrang &LO, string nama_kota,adr_kota &p){
/*
    I.S Terdefinisi ListKota LK yang mungkin kosong, nama_kota,dan adr_kota p
    F.S Menghapus elemen yang memiliki info nama_kota dari listKota LK dan elemen tersebut disimpan di adr_kota p
*/
    adr_kota kota = searchKota(LK,nama_kota);
    if(kota != nil){
        if(kota==first(LK)){
            deleteFirstKota(LK,LO,p);
        }else if(nextKota(kota)==nil){
            deleteLastKota(LK,LO,p);
        }else{
            adr_kota q = first(LK);
            while(nextKota(q)!=kota){
                q = nextKota(q);
            }
            deleteAfterKota(LK,LO,q,p);
        }
    }else{
        cout<<"Nama Kota tersebut tidak ditemukan"<<endl;
    }
}

//Menampilkan Data (MLL)
void showAllOrang(listOrang LO){
/*
    I.S Terdefinisi ListOrang LO yang mungkin kosong
    F.S Menampilkan semua info orang dari ListOrang LO
*/
    adr_orang p = first(LO);
    cout<<"======================="<<endl;
    cout<<"Menampilkan List Orang:"<<endl;
    cout<<"======================="<<endl;
    while(p!=nil){
        infotypeOrang x = infoOrang(p);
        cout<<"Nama Orang: "<<x.namaOrang<<endl;
        cout<<"Umur: "<<x.umur<<endl;
        cout<<"Jenis Kelamin: "<<x.jk<<endl;
        if (kotaLahir(p)!= nil){
            cout<<"Kota Lahir: "<<infoKota(kotaLahir(p)).namaKota<<endl;
        }else{
            cout<<"Kota Lahir: -"<<endl;
        }

        cout<<endl;
        p = nextOrang(p);
    }
}

//Menghitung Jumlah Data (MLL)
int JumlahOrang(listOrang LO,listKota LK ,string nama_kota){
/*
    Mengembalikan jumlah orang yang berasal dari elemen kota dengan info nama_kota
*/
    adr_kota kota = searchKota(LK,nama_kota);

    adr_orang p = first(LO);
    int jumlah = 0;
    while(p!=nil){
        if(kotaLahir(p)==kota){
            jumlah++;
        }
        p = nextOrang(p);
    }
    return jumlah;
}

//Menampilkan Jumlah data Paling banyak (MLL)
void showMax(listOrang LO,listKota LK){
/*
    I.S Terdefinisi ListOrang LO, listKota LK yang mungkin kosong
    F.S Menampilkan info kota yang memiliki paling banyak orang berasal dari kota tersebut
*/
     if(!isEmptyKota(LK) && !isEmptyOrang(LO)){
        adr_kota p = first(LK);
        adr_kota pMax = first(LK);
        int Max = JumlahOrang(LO,LK,infoKota(p).namaKota);
        p = nextKota(p);
        while(p!=nil){
            if (Max < JumlahOrang(LO,LK,infoKota(p).namaKota)){
                Max = JumlahOrang(LO,LK,infoKota(p).namaKota);
            }
            p = nextKota(p);
        }
        cout<<"============================================"<<endl;
        cout<<"Menampilkan Kota dengan Kelahiran Terbanyak:"<<endl;
        cout<<"============================================"<<endl;
        while(pMax != nil){
            if(Max == JumlahOrang(LO,LK,infoKota(pMax).namaKota)){
                infotypeKota x = infoKota(pMax);
                cout<<"Nama Kota: "<<x.namaKota<<endl;
                cout<<"Provinsi Kota: "<<x.provinsiKota<<endl;
                cout<<"Banyak Orang yang berasal dari Kota ini: "<<Max<<endl;

                cout<<endl;
            }
            pMax = nextKota(pMax);
        }
     }else{
          cout<<"List Orang atau List Kota Kosong"<<endl;
     }
}

//Menampilkan Jumlah data Paling sedikit (MLL)
void showMin(listOrang LO,listKota LK){
/*
    I.S Terdefinisi ListOrang LO, listKota LK yang mungkin kosong
    F.S Menampilkan info kota yang memiliki paling sedikit orang berasal dari kota tersebut
*/

    if(!isEmptyKota(LK) && !isEmptyOrang(LO)){
        adr_kota p = first(LK);
        adr_kota pMin = first(LK);
        int Min = JumlahOrang(LO,LK,infoKota(p).namaKota);
        p = nextKota(p);
        while(p!=nil){
            if (Min > JumlahOrang(LO,LK,infoKota(p).namaKota)){
                Min = JumlahOrang(LO,LK,infoKota(p).namaKota);
            }
            p = nextKota(p);
        }
        cout<<"============================================"<<endl;
        cout<<"Menampilkan Kota dengan Kelahiran Tersedikit:"<<endl;
        cout<<"============================================"<<endl;
        while(pMin != nil){
            if(Min == JumlahOrang(LO,LK,infoKota(pMin).namaKota)){
                infotypeKota x = infoKota(pMin);
                cout<<"Nama Kota: "<<x.namaKota<<endl;
                cout<<"Provinsi Kota: "<<x.provinsiKota<<endl;
                cout<<"Banyak Orang yang berasal dari Kota ini: "<<Min<<endl;

                cout<<endl;
            }
            pMin = nextKota(pMin);
        }
    }else{
        cout<<"List Orang atau List Kota Kosong"<<endl;
    }
}

//Function Tambahan
bool isEmptyKota(listKota LK){
    return first(LK) == nil;
}

bool isEmptyOrang(listOrang LO){
    return first(LO) == nil;
}

int selectMenu(){
    int input;
    cout<<"======================================================="<<endl;
    cout<<"=                         MENU                        ="<<endl;
    cout<<"======================================================="<<endl;
    cout<<"1. Menambah data Kota baru"<<endl;
    cout<<"2. Menambah data Orang baru"<<endl;
    cout<<"3. Menampilkan semua data Kota"<<endl;
    cout<<"4. Menampilkan semua data Orang"<<endl;
    cout<<"5. Menambahkan Kota Lahir pada Seseorang"<<endl;
    cout<<"6. Menghapus Data orang dan relasinya"<<endl;
    cout<<"7. Menghapus Data kota dan relasinya"<<endl;
    cout<<"8. Menampilkan Kota dengan jumlah kelahiran paling banyak"<<endl;
    cout<<"9. Menampilkan Kota dengan jumlah kelahiran paling sedikit"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"Masukkan menu: ";
    cin>>input;
    return input;
}
