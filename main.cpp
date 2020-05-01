#include "header.h"

using namespace std;

// Nama: Kevin Usmayadhy Wijaya
// Nim: 1301194011

int main() {
    string menupilihan, pilihan, enter, username, password;
    bool exit, logout, kembali;
    int jumlahproduk;
    datadiri customerbaru;
    dataproduk produkbaru;
    addresstocustomer C;
    addresstoproduk P;
    addresstorelasi R;
    List L;

    createList(L);

    cout << "Selamat datang diaplikasi Rating Produk" << endl;
    cout << "Tekan enter..............";
    getline(cin,enter);
    clear;

    jumlahproduk = 0;
    exit = false;
    while(!exit){
        menuawal(pilihan);

        if(pilihan == "1"){
            menulogin(L, username, password);

            logout = false;
            while(!logout){
                menuatama(pilihan, username);

                if(pilihan == "1"){
                    kembali = false;

                    while(!kembali){
                        menuproduk(pilihan, username);

                        if (pilihan == "1"){

                            while(!kembali){
                            menulihatproduk(pilihan, username);

                                if(pilihan == "1"){
                                    viewproduk(L);
                                    pause;
                                    clear;
                                } else if (pilihan == "2"){
                                    printAscending(L, P, jumlahproduk);
                                    pause;
                                    clear;
                                } else if (pilihan == "3"){
                                    printDescending(L, P, jumlahproduk);
                                    pause;
                                    clear;
                                } else if (pilihan == "4"){
                                    viewproduk(L);
                                    viewperatingproduk(L, P);
                                    pause;
                                    clear;
                                } else if (pilihan == "9"){
                                    kembali = true;
                                } // EndIf
                            } // EndWhile
                            kembali = false;

                        } else if (pilihan == "2"){

                            if(username == "Admin"){
                                tambahproduk(L, produkbaru, jumlahproduk);
                                createproduk(P, produkbaru);
                                insertproduk(L, P);
                            } else {
                                viewyangsudahdiratedanbelum(L,username);
                                menuberirating(L, username, R);
                                insertRelasi(L, R);
                            } // EndIf

                        } else if (pilihan == "3" ){

                            if(username == "Admin"){
                                viewproduk(L);
                                menueditproduk(L);
                            } else {
                                viewproduktelahdirate(L, username);
                            } // EndIf

                        } else if (pilihan == "4"){

                            if(username == "Admin"){
                                viewproduk(L);
                                menudeleteproduk(L, jumlahproduk);
                            } else {
                                viewprodukbelumdirate(L, username);
                            } // EndIf

                        } else if(pilihan == "9"){
                            kembali = true;
                        } // EndIf
                    }// Endwhile

                }else if(pilihan == "2"){

                    if(username == "Admin"){
                        kembali = false;
                        while(!kembali){
                            menucustomer(pilihan);

                            if(pilihan == "1"){
                                viewusernamecustomer(L);
                                pause;
                                clear;
                            }else if(pilihan == "2"){
                                viewusernamecustomer(L);
                                menuratingancustomer(L);
                            }else if(pilihan == "3"){
                                viewusernamecustomer(L);
                                menudeletecustomer(L);
                                clear;
                            }else if(pilihan == "9"){
                                kembali = true;
                            } //EndIf
                        } // Endwhile

                    } else {

                        kembali = false;
                        while(!kembali){
                            viewdetaildiricustomer(L, username, pilihan);
                            editprofil(L, pilihan, username ,kembali);
                        } // Endwhile
                    }//EndIf

                } else if(pilihan == "3"){
                    logout = true;
                }// EndIf
            } // Endwhile

        } else if(pilihan == "2"){

            menudaftar(L, customerbaru);
            createCustomer(C, customerbaru);
            insertCustomer(L,C);

        } else if(pilihan == "3"){

            kembali = false;
            while(!kembali){
                menulihatproduk(pilihan, "Guest");

                if(pilihan == "1"){
                    viewproduk(L);
                    pause;
                    clear;
                } else if (pilihan == "2"){
                    printAscending(L, P, jumlahproduk);
                    pause;
                    clear;
                } else if (pilihan == "3"){
                    printDescending(L, P, jumlahproduk);
                    pause;
                    clear;
                } else if (pilihan == "9"){
                    kembali = true;
                } // EndIf
            } // Endwhile

        } else if(pilihan == "9"){
            exit = true;
        } // EndIf

    } // Endwhile

    return 0;
} // END
