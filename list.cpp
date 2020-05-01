#include"header.h"


//// List


void createList(List &L){
    firstcustomer(L) = NULL;
    firstrelasi(L) = NULL;
    firstproduk(L) = NULL;
}


// List Produk

void createproduk(addresstoproduk &P, dataproduk produkinfo){
    P = new produk;
    info(P) = produkinfo;
    next(P) = NULL;
}

void tambahproduk(List L, dataproduk &produkinfo, int &nomorproduk){
    atas();
    cout << "Masukan nama produk : ";
    inputberspasistring(produkinfo.namaproduk);
    while(findprodukbyname(L, produkinfo.namaproduk)!=NULL){
        cout << "Masukan nama produk : ";
        getline(cin, produkinfo.namaproduk);
    }
    cout << "Keterangan Produk : ";
    getline(cin, produkinfo.keterangan);
    produkinfo.rataanrating = 0;
    nomorproduk++;
    produkinfo.nomor = nomorproduk;
    produkinfo.totalrating = 0;
    produkinfo.jumlahperating = 0;
    produkinfo.printed = false;
    clear;
}

void insertproduk(List &L, addresstoproduk P){
    addresstoproduk Q = firstproduk(L);

    if(Q == NULL){
        firstproduk(L) = P;
    } else {
        while(next(Q)!=NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void deleteproduk(List &L, addresstoproduk P, int &jumlahproduk){
    addresstoproduk Q = firstproduk(L);
    addresstorelasi R = firstrelasi(L);

    if(Q==P){
        firstproduk(L) = next(P);
        next(Q) = NULL;
        jumlahproduk--;
        Q = firstproduk(L);
        while(Q!=NULL){
            info(Q).nomor--;
            Q = next(Q);
        }
    } else {
        jumlahproduk--;
        deleteRelasiproduk(L, P);
        while(next(Q)!= NULL && next(Q) != P){
            Q = next(Q);
        }
        next(Q) = next(next(Q));
        next(P) = NULL;
        Q = next(Q);
        while(Q!=NULL){
            info(Q).nomor--;
            Q = next(Q);
        }
    }
}

void editproduk(string pilihan, addresstoproduk P){
    if(pilihan == "1"){
        clear;
        atas();
        cout << endl << "   Nama Produk sebelumnya: "<< info(P).namaproduk << endl;
        cout << "   Ubah menjadi: ";
        inputberspasistring(info(P).namaproduk);
    } else if(pilihan == "2") {
        clear;
        atas();
        cout << endl << "   Keterangan Produk sebelumnya: "<< info(P).keterangan << endl;
        cout << "   Ubah menjadi: ";
        inputberspasistring(info(P).keterangan);
    } else if(pilihan == "3"){
        clear;
        atas();
        cout << endl << "   Nama Produk sebelumnya: " << info(P).namaproduk;
        cout << endl << "   Keterangan Produk sebelumnya: " << info(P).keterangan << endl;
        cout << "   Ubah nama menjadi: ";
        inputberspasistring(info(P).namaproduk);
        cout << "   Ubah keterangan menjadi: ";
        getline(cin, info(P).keterangan);
    }
}

void viewproduk(List L){
    addresstoproduk P = firstproduk(L);

    atas();
    if(P==NULL){
        cout << "Belum ada produk!" << endl;
    }
    while(P!=NULL){
        cout << info(P).nomor << ") Nama Produk: " << info(P).namaproduk << endl;
        cout << "Keterangan Produk: " << info(P).keterangan << endl;
        cout << "Total perating: " << info(P).jumlahperating << endl;
        cout << "Rating: "<< info(P).rataanrating << "/5" << endl << endl;
        P = next(P);
    }
}

void viewyangsudahdiratedanbelum(List L, string username){
    addresstoproduk P = firstproduk(L);
    addresstocustomer C = findcustomerbyusername(L, username);
    addresstorelasi R;

    atas();
    if(P==NULL){
        cout << "Belum ada produk!" << endl;
    }
    while(P!=NULL){
        cout << info(P).nomor << ") Nama Produk: " << info(P).namaproduk << endl;
        cout << "Keterangan Produk: " << info(P).keterangan << endl;
        cout << "Rating: "<< info(P).rataanrating << "/5" << endl;
        R = findrelasi(L,P,C);
        if(R!=NULL){
            cout << "Sudah di beri rating " << endl;
            cout << "Rate yang diberi: "<< info(R).rating << endl;
            cout << "Ulasan: "<< info(R).ulasan << endl << endl;
        } else {
            cout << "Produk belum di beri rating " << endl << endl;
        }
        P = next(P);
    }
}

void viewproduktelahdirate(List &L, string username){
    addresstoproduk P = firstproduk(L);
    addresstocustomer C = findcustomerbyusername(L, username);
    addresstorelasi R, temp;
    string pilihan;
    string nama;
    datarelasi isirating;
    int i = 1;

    atas();
    if(P==NULL){
        cout << "Belum ada produk!" << endl;
    }
    while(P!=NULL){
        R = findrelasi(L,P,C);
        if(R!=NULL){
            cout << i << ") Nama Produk: " << info(P).namaproduk << endl;
            cout << "Keterangan Produk: " << info(P).keterangan << endl;
            cout << "Rating: "<< info(P).rataanrating << "/5" << endl;
            cout << "Sudah di beri rating " << endl;
            cout << "Rate yang diberi: "<< info(R).rating << endl;
            cout << "Ulasan: "<< info(R).ulasan << endl << endl;
            i++;
        }
        P = next(P);
    }
    cout << "Apakah Anda ingin Mengedit rating?(YES/NO)"<< endl;
    cin >> pilihan;
    while(pilihan != "YES" && pilihan != "Yes" && pilihan != "YeS" && pilihan != "yes" && pilihan != "yeS" && pilihan != "yES" && pilihan != "NO" && pilihan != "No" && pilihan != "nO" && pilihan != "no"){
        cin >> pilihan;
    }
    if(pilihan == "YES" || pilihan == "Yes" || pilihan == "YeS" || pilihan == "yes" || pilihan == "yeS" || pilihan == "yES" ){
        cout << "Nama produk yang ingin diedit?";
        inputberspasistring(nama);
        P = findprodukbyname(L, nama);
        if(P!=NULL){
            cout << "Nama Produk: "<< info(P).namaproduk << endl << "Beri rating 0-5: ";
            cin >> isirating.rating;
            while(isirating.rating>5 || isirating.rating<0){
                cout << "Beri rating 0-5: ";
                cin >> isirating.rating;
            }
            cout << "Ulasan: ";
            inputberspasistring(isirating.ulasan);
            temp = findrelasi(L, P, C);
            info(P).totalrating = info(P).totalrating+float(isirating.rating)-float(info(temp).rating);
            info(P).rataanrating = float(info(P).totalrating)/float(info(P).jumlahperating);
            deleteRelasi(L, temp);
            createRelasi(R, isirating, C, P);
            insertRelasi(L, R);
        }
    }
    cout << "Apakah Anda ingin Menghapus rating?(YES/NO)"<< endl;
    cin >> pilihan;
    while(pilihan != "YES" && pilihan != "Yes" && pilihan != "YeS" && pilihan != "yes" && pilihan != "yeS" && pilihan != "yES" && pilihan != "NO" && pilihan != "No" && pilihan != "nO" && pilihan != "no"){
        cin >> pilihan;
    }
    if(pilihan == "YES" || pilihan == "Yes" || pilihan == "YeS" || pilihan == "yes" || pilihan == "yeS" || pilihan == "yES" ){
        cout << "Nama produk yang ingin dihapus?";
        inputberspasistring(nama);
        P = findprodukbyname(L, nama);
        if(P!=NULL){
            temp = findrelasi(L, P, C);
            info(P).jumlahperating = info(P).jumlahperating - 1;
            info(P).totalrating = info(P).totalrating-float(info(temp).rating);
            if(info(P).jumlahperating!=0){
                info(P).rataanrating = float(info(P).totalrating)/float(info(P).jumlahperating);
            } else {
                info(P).rataanrating = 0;
            }
            deleteRelasi(L, temp);
        }
    }
    clear;
}

void viewprodukbelumdirate(List L, string username){
    addresstoproduk P = firstproduk(L);
    addresstocustomer C = findcustomerbyusername(L, username);
    addresstorelasi R, temp;
    string pilihan, nama;
    int i = 1;
    atas();
    if(P==NULL){
        cout << "Belum ada produk!" << endl;
    }
    while(P!=NULL){
        R = findrelasi(L,P,C);
        if(R==NULL){
            cout << i << ") Nama Produk: " << info(P).namaproduk << endl;
            cout << "Keterangan Produk: " << info(P).keterangan << endl;
            cout << "Rating: "<< info(P).rataanrating << "/5" << endl;
            cout << "Produk belum di beri rating " << endl << endl;
            i++;
        }
        P = next(P);
    }
    pause;
    clear;
}

void viewperatingproduk(List L, addresstoproduk P){
    int nomor, i;
    addresstorelasi R = firstrelasi(L);
    i = 1;

    cout << "Pilih nomer produk yang ingin dilihat peratingnya: ";
    cin >> nomor;
    P = findprodukbynumber(L, nomor);
    if(P!=NULL){
        clear;
        atas();
        cout << endl << "Nama Produk: " << info(P).namaproduk << endl;
        cout << "Customer perating: " << endl << endl;
        while(R!=NULL){
            if(P == toproduk(R)){
                cout << i << ") " << info(tocustomer(R)).nama << endl;
                cout << "Rating yang diberi: " << info(R).rating << endl;
                cout << "Ulasan yang diberi: " << info(R).ulasan << endl << endl;
                i++;
            }
            R = next(R);
        }
    } else {
        cout << "Produk tidak ditemukan! " << endl << endl;
    }
}

addresstoproduk findprodukbyname(List L, string namaproduk){
    addresstoproduk P = firstproduk(L);
    while(P!=NULL && info(P).namaproduk != namaproduk){
        P = next(P);
    }
    return P;
}

addresstoproduk findprodukbynumber(List L, int nomor){
    addresstoproduk P = firstproduk(L);

    while(P!=NULL && info(P).nomor != nomor){
        P = next(P);
    }
    return P;
}

void produkkosong(addresstoproduk &P){
    P = new produk;
    next(P) = NULL;
    info(P).namaproduk = "";
    info(P).keterangan = "";
    info(P).nomor = 0;
    info(P).jumlahperating = 0;
    info(P).totalrating = 0;
    info(P).rataanrating= 0;
}

void printAscending(List L, addresstoproduk P, int jumlahproduk){
    addresstoproduk min1, min2, temp;
    int i = 1;

    produkkosong(min1);
    produkkosong(min2);
    while (i <= jumlahproduk){
        P = firstproduk(L);
        info(min1).rataanrating = 6;
        minrating(min1, min2, temp, P, i);
        i++;
    }
    returnprintedtofalse(L);
}

void minrating(addresstoproduk min1, addresstoproduk &min2, addresstoproduk &temp, addresstoproduk P, int nomor){
    while(P!=NULL){
        if(info(min1).rataanrating >= info(P).rataanrating){
            if (nomor == 1){
                min1 = P;
            } else if (info(P).rataanrating >= info(min2).rataanrating && P != temp && info(P).printed == false){
                min1 = P;
            }
        }
        P = next(P);
    }
    cout << nomor << ") Nama produk: " << info(min1).namaproduk << endl;
    cout << "Jumlah yang merating: " << info(min1).jumlahperating << endl;
    cout << "Rating: " << info(min1).rataanrating << endl << endl;
    info(min2) = info(min1);
    temp = min1;
    info(min1).printed = true;
}

void printDescending(List L, addresstoproduk P, int jumlahproduk){
    addresstoproduk max1, max2, temp;
    int i = 1;

    produkkosong(max1);
    produkkosong(max2);
    while (i <= jumlahproduk){
        P = firstproduk(L);
        info(max1).rataanrating = -1;
        maxrating(max1, max2, temp, P, i);
        i++;
    }
    returnprintedtofalse(L);
}

void maxrating(addresstoproduk max1, addresstoproduk &max2, addresstoproduk &temp,addresstoproduk P, int nomor){
    while(P!=NULL){
        if(info(max1).rataanrating < info(P).rataanrating){
            if (nomor == 1){
                max1 = P;
            }else if (info(max2).rataanrating >= info(P).rataanrating && P != temp && info(P).printed == false){
                max1 = P;
            }
        }
        P = next(P);
    }
    cout << nomor << ") Nama produk: " << info(max1).namaproduk << endl;
    cout << "Jumlah yang merating: " << info(max1).jumlahperating << endl;
    cout << "Rating: " << info(max1).rataanrating << endl << endl;
    info(max2) = info(max1);
    temp = max1;
    info(max1).printed = true;
}

void returnprintedtofalse(List L){
    addresstoproduk P = firstproduk(L);

    while(P != NULL){
        info(P).printed = false;
        P = next(P);
    }
}


// List Relasi


void createRelasi(addresstorelasi &R, datarelasi isirating, addresstocustomer C, addresstoproduk P){
    R = new relasi;
    info(R) = isirating;
    toproduk(R) = P;
    tocustomer(R) = C;
}

void insertRelasi(List &L, addresstorelasi R){
    next(R) = firstrelasi(L);
    firstrelasi(L) = R;
}

void deleteRelasi(List &L, addresstorelasi R){
    addresstorelasi Q = firstrelasi(L);

    if(Q==R){
        firstrelasi(L) = next(R);
        next(Q) = NULL;
        toproduk(Q) == NULL;
        tocustomer(Q) == NULL;
    } else {
        while(next(Q)!= NULL && next(Q) != R){
            Q = next(Q);
        }
        next(Q) = next(next(Q));
        next(R) = NULL;
        toproduk(R) == NULL;
        tocustomer(R) == NULL;
    }
}

void deleteRelasiproduk(List &L, addresstoproduk P){
    addresstorelasi R = firstrelasi(L);
    addresstorelasi temp;

    while(R!=NULL){
        if(toproduk(R)==P){
            temp = R;
            R = next(R);
            deleteRelasi(L, temp);
        } else {
            R = next(R);
        }
    }
}

void deleteRelasiCustomer(List &L, addresstocustomer C){
    addresstorelasi R = firstrelasi(L);
    addresstorelasi temp;

    while(R!=NULL){
        if(tocustomer(R)==C){
            info(toproduk(R)).jumlahperating--;
            info(toproduk(R)).rataanrating = ((info(toproduk(R)).rataanrating * float(info(toproduk(R)).jumlahperating+1))-info(R).rating)/float(info(toproduk(R)).jumlahperating);
            temp = R;
            R = next(R);
            deleteRelasi(L, temp);
        } else {
            R = next(R);
        }
    }
}

void viewrelasi(List L){
    addresstorelasi R = firstrelasi(L);

    while(R!=NULL){
        cout << info(tocustomer(R)).username << " ";
        R = next(R);
    }
}

addresstorelasi findrelasi(List L, addresstoproduk P, addresstocustomer C){
    addresstorelasi R = firstrelasi(L);

    bool found = false;
    while(R!=NULL && !found){
        if(toproduk(R)==P && tocustomer(R)==C){
            found = true;
        }else{
            R = next(R);
        }
    }
    if(found){
        return R;
    } else {
        return NULL;
    }
}


// List Customer


void createCustomer(addresstocustomer &P, datadiri isiinfo){
    P = new customer;
    info(P) = isiinfo;
    next(P) = NULL;
}

void insertCustomer(List &L, addresstocustomer C){
    addresstocustomer Q = firstcustomer(L);

    if(Q == NULL){
        firstcustomer(L) = C;
    } else {
        if(info(Q).username > info(C).username){
            next(C) = firstcustomer(L);
            firstcustomer(L) = C;
        }else {
            while(next(Q) != NULL && info(next(Q)).username<info(C).username){
                Q = next(Q);
            }
            next(C) = next(Q);
            next(Q) = C;
        }
    }
}

void deletecustomer(List &L, addresstocustomer C){
    addresstocustomer Q = firstcustomer(L);

    if(Q==C){
        firstcustomer(L) = next(C);
        next(Q) = NULL;
    } else {
        while(next(Q)!= NULL && next(Q) != C){
            Q = next(Q);
        }
        next(Q) = next(next(Q));
        next(C) = NULL;
    }
}

void editprofil(List &L, string menupilihan, string &username, bool &kembali){
    addresstocustomer C = findcustomerbyusername(L, username);
    string pilihan;

    atas();
    if(menupilihan == "1"){
        cout << "Nama sebelumnya: " << info(C).nama << endl;
        cout << "Ubah menjadi: ";
        inputberspasistring(info(C).nama);
    } else if(menupilihan == "2"){
        cout << "E-mail sebelumnya: " << info(C).email << endl;
        cout << "Ubah menjadi: ";
        cin >> info(C).email;
    } else if(menupilihan == "3"){
        cout << "Nomer handphone sebelumnya: " << info(C).nomerhp << endl;
        cout << "Ubah menjadi: ";
        cin >> info(C).nomerhp;
    } else if(menupilihan == "4"){
        cout << "Tanggal/bulan/tahun lahir sebelumnya: " << info(C).kelahiran<< endl;
        cout << "Ubah menjadi: ";
        inputberspasistring(info(C).kelahiran);
    } else if(menupilihan == "5"){
        cout << "Username sebelumnya: " << info(C).username << endl;
        cout << "Ubah menjadi: ";
        cin >> info(C).username;
        replaceCustomer(L, C);
        username = info(C).username;
    } else if(menupilihan == "6"){
        cout << "Password sebelumnya: " << info(C).password << endl;
        cout << "Ubah menjadi: ";
        inputberspasistring(info(C).password);
    } else if(menupilihan == "7"){
        cout << "Pertanyaan lupa password sebelumnya: " << info(C).pertanyaanlupapass << endl;
        cout << "(1) Nomer hp pertamamu ?" << endl;
        cout << "(2) Nama peliharaan pertamamu ?" << endl;
        cout << "(3) Nama guru sd pertamamu ?" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
        if(pilihan == "1"){
            info(C).pertanyaanlupapass = "Nomer hp pertamamu ?";
        }else if(pilihan == "2"){
            info(C).pertanyaanlupapass = "Nama peliharaan pertamamu ?";
        } else if(pilihan == "3"){
            info(C).pertanyaanlupapass = "Nama guru sd pertamamu ?";
        }
        cout << "Ubah menjadi: ";
    } else if(menupilihan == "8"){
        cout << "Pertanyaan lupa password: " << info(C).pertanyaanlupapass << endl;
        cout << "Jawaban pertanyaan sebelumnya: " << info(C).jawaban << endl;
        cout << "Ubah menjadi: ";
        inputberspasistring(info(C).jawaban);
    } else if(menupilihan == "9"){
        kembali = true;
    }
    clear;
}

void replaceCustomer(List &L, addresstocustomer C){
    addresstocustomer C1;
    deletecustomer(L,C);
    createCustomer(C1, info(C));
    insertCustomer(L, C1);
}

addresstocustomer findcustomerbyusername(List L, string username){
    addresstocustomer P = firstcustomer(L);

    while(P!=NULL && info(P).username != username){
        P = next(P);
    }
    return P;
}

addresstocustomer findcustomerbyemail(List L, string email){
    addresstocustomer P = firstcustomer(L);

    while(P!=NULL && info(P).email != email){
        P = next(P);
    }
    return P;
}

addresstocustomer findcustomerbynumber(List L, int nomor){
    addresstocustomer P = firstcustomer(L);
    int i = 1;

    while(i<nomor && P != NULL){
        P = next(P);
        i++;
    }
    return P;
}

void viewusernamecustomer(List L){
    addresstocustomer p = firstcustomer(L);
    int i = 1;

    atas();
    if(p!=NULL){
        while(p != NULL){
            cout << i << ") "<< info(p).username << endl;
            p = next(p);
            i++;
        }
    } else {
        cout << "Belum ada customer yang terdaftar!";
    }
    cout << endl;
}

void viewdetaildiricustomer(List L, string username, string &menupilihan){
    addresstocustomer C = findcustomerbyusername(L, username);

    atas();
    cout << "1) Nama                     : " << info(C).nama << endl;
    cout << "2) id.email                 : " << info(C).email << endl;
    cout << "3) Nomer hp                 : " << info(C).nomerhp << endl;
    cout << "4) tanggal/bulan/tahun lahir: " << info(C).kelahiran << endl;;
    if(username!="Admin"){
        cout << "5) Username                 : " << info(C).username << endl;
        cout << "6) Password                 : " << info(C).password << endl;
        cout << "7) Pertanyaan Lupa Password : " << info(C).pertanyaanlupapass << endl;
        cout << "8) Jawab                    : " << info(C).jawaban << endl;
        cout << "9) Kembali" << endl;
        cout << "Pilih nomer yang ingin diedit: ";
        cin >> menupilihan;
        while(menupilihan < "1" && menupilihan > "9"){
            cin >> menupilihan;
        }
    } else {
        cout << "5) Username                 : " << info(C).username << endl;
        cout << "6) Password                 : " << info(C).password << endl;
        cout << "7) Pertanyaan Lupa Password : " << info(C).pertanyaanlupapass << endl;
        cout << "8) Jawab                    : " << info(C).jawaban << endl;
        pause;
    }
    clear;
}

void viewratingancustomer(List L, addresstocustomer C){
    addresstorelasi R = firstrelasi(L);
    addresstoproduk P;
    int i = 1;

    atas();
    cout << endl;
    cout << "Nama Customer: " << info(C).nama << endl;
    cout << "Produk yang telah dirating: " << endl << endl;
    while(R!=NULL){
        if(info(C).username == info(tocustomer(R)).username){
            P = toproduk(R);
            cout << i << ") Nama Produk: " << info(P).namaproduk << endl;
            cout << "Rating yang diberikan: " << info(R).rating << endl;
            cout << "Ulasan diberikan: " << info(R).ulasan << endl << endl;
            i++;
        }
        R = next(R);
    }
    pause;
    clear;
}
