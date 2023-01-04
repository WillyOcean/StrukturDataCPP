#include "kotaLahir.h"

int main()
{
    infotypeKota newKota;
    infotypeOrang newOrang;

    adr_kota pKota;
    adr_orang pOrang;

    listOrang LO;
    listKota LK;

    createListOrang(LO);
    createListKota(LK);

    char input;
    int pilihan = selectMenu();

    char inputData;
    string nama_orang,nama_kota;
    adr_orang delOrang;
    adr_kota delKota;

    while(pilihan != 0){
        switch(pilihan){
            case 1:{
                inputData = 'Y';
                cout<<"===================="<<endl;
                cout<<"Masukkan Data Kota: "<<endl;
                cout<<"===================="<<endl;
                while (inputData == 'Y'){
                    cout<<"Nama Kota: ";
                    cin>>newKota.namaKota;
                    cout<<"Provinsi Kota: ";
                    cin>>newKota.provinsiKota;

                    cout<<endl;
                    pKota = createElemenKota(newKota);
                    insertLastKota(LK,pKota);
                    cout<<"Apakah anda ingin menambahkan lagi? (Y/N): ";
                    cin>>inputData;
                    cout<<endl;
                }
                break;
            }
            case 2 :{
                inputData = 'Y';
                cout<<"===================="<<endl;
                cout<<"Masukkan Data Orang: "<<endl;
                cout<<"===================="<<endl;
                while (inputData == 'Y'){
                    cout<<"Nama Orang: ";
                    cin>>newOrang.namaOrang;
                    cout<<"Umur: ";
                    cin>>newOrang.umur;
                    cout<<"Jenis Kelamin (L/P): ";
                    cin>>newOrang.jk;

                    cout<<endl;
                    pOrang = createElemenOrang(newOrang);
                    insertLastOrang(LO,pOrang);
                    cout<<"Apakah anda ingin menambahkan lagi? (Y/N): ";
                    cin>>inputData;
                    cout<<endl;
                }
                break;
            }
            case 3:{
                showAllKota(LK,LO);
                break;
            }
            case 4:{
                showAllOrang(LO);
                break;
            }
            case 5:{
                inputData = 'Y';
                cout<<"======================================="<<endl;
                cout<<"Masukkan Data Orang dan Kota Kelahiran: "<<endl;
                cout<<"======================================="<<endl;
                while(inputData == 'Y'){
                    cout<<"Nama Orang: ";
                    cin>>nama_orang;
                    cout<<"Nama Kota Lahir: ";
                    cin>>nama_kota;
                    cout<<endl;

                    insertKotaAsal(LK,LO,nama_orang,nama_kota);
                    cout<<"Apakah anda ingin menambahkan lagi? (Y/N): ";
                    cin>>inputData;
                    cout<<endl;
                }
                break;
            }
            case 6:{
                inputData = 'Y';
                cout<<"====================================="<<endl;
                cout<<"Masukkan Data Orang yang akan dihapus:"<<endl;
                cout<<"====================================="<<endl;
                while(inputData == 'Y'){
                    cout<<"Nama Orang: ";
                    cin>>nama_orang;

                    deleteOrangSpesifik(LO,nama_orang,delOrang);
                    cout<<"Apakah anda ingin menghapus lagi? (Y/N): ";
                    cin>>inputData;
                }
                break;
            }
            case 7:{
                inputData = 'Y';
                cout<<"======================================"<<endl;
                cout<<"Masukkan Data Kota yang akan dihapus:"<<endl;
                cout<<"======================================"<<endl;
                while(inputData == 'Y'){
                    cout<<"Nama Kota: ";
                    cin>>nama_kota;

                    deleteKotaSpesifik(LK,LO,nama_kota,delKota);
                    cout<<"Apakah anda ingin menghapus lagi? (Y/N): ";
                    cin>>inputData;
                }
                break;
            }
            case 8:{
                showMax(LO,LK);
                break;
            }
            case 9:{
                showMin(LO,LK);
                break;
            }
            default:{
                cout<<"Pilihan tidak ada"<<endl;
                break;
            }
        }
        cout<<"Kembali ke menu utama? (Y/N): ";
        cin>>input;
        if (input == 'Y'){
            cout<<endl;
            pilihan = selectMenu();
        }else if(input == 'N'){
            pilihan = 0;
        }else{
            while(input != 'Y' && input != 'N'){
                cout<<"Pilihan tidak tersedia"<<endl;
                cout<<"Kembali ke menu utama? (Y/N): ";
                cin>>input;
                if (input == 'Y'){
                    cout<<endl;
                    pilihan = selectMenu();
                }else if(input == 'N'){
                    pilihan = 0;
                }
            }
        }
    }
    cout<<"Anda Telah Keluar dari Menu"<<endl;
    return 0;
}
