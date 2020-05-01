#include"header.h"

void atas(){
    cout << "===================================" << endl;
    cout << "==        Rating Produk          ==" << endl;
    cout << "===================================" << endl;
}

void bawah(){
    cout << "===================================" << endl;
    cout << "Pilihan: ";
}

void inputberspasistring(string &kata){
    cin.ignore(1, '\n');
    getline(cin, kata);
}

void menuawal(string &menupilihan){
    atas();
    cout << "==     (1) Masuk                 ==" << endl;
    cout << "==     (2) Daftar                ==" << endl;
    cout << "==     (3) Lihat Rating Produk   ==" << endl;
    cout << "==     (9) Keluar                ==" << endl;
    bawah();
    cin >> menupilihan;
    clear;
}

void menulogin(List L, string &username, string &password){
    addresstocustomer P;
    string lupapass, salahpassword;
    int i = 1;

    atas();
    cout << "    Username : ";
    cin >> username;
    while(findcustomerbyusername(L, username)==NULL && username != "Admin" ){
        cout << "    Username tidak ditemukan : ";
        cin >> username;
    }
    cout << "    Password : ";
    inputberspasistring(password);
    if(username != "Admin"){
        P = findcustomerbyusername(L, username);
        salahpassword = "    Password yang anda masukan salah : ";
        while(info(P).password != password){
            cout << salahpassword;
            getline(cin, password);
            if(i == 3 || i > 6 && info(P).password != password){
                cout << "    Lupa password? (YES/NO)" << endl;
                cout << "    ";
                cin >> lupapass;
                while(lupapass != "YES" && lupapass != "Yes" && lupapass != "YeS" && lupapass != "yes" && lupapass != "yeS" && lupapass != "yES" && lupapass != "NO" && lupapass != "No" && lupapass != "nO" && lupapass != "no"){
                    cin >> lupapass;
                }
                if(lupapass == "YES" || lupapass == "Yes" || lupapass == "YeS" || lupapass == "yes" || lupapass == "yeS" || lupapass == "yES"){
                    lupapassword(P);
                    salahpassword = "    Masukan Password : ";
                } else if (lupapass == "No" || lupapass == "NO" || lupapass == "nO" || lupapass == "no"){
                    cin.ignore(1, '\n');
                }
            }
            i++;
        }
    } else {
        while(password != "adMin105"){
            cout << "    Password yang anda masukan salah : ";
            getline(cin, password);
        }
    }
    clear;
}

void menudaftar(List L, datadiri &id){
    string pilihan;
    int penanda = 0;
    atas();

    cout << "Masukan nama anda : ";
    inputberspasistring(id.nama);
    cout << "Masukan email : ";
    cin >> id.email;
    while(findcustomerbyemail(L, id.email)!=NULL){
        cout << "Email telah digunakan!" << endl;
        cout << "Masukan kembali email : ";
        cin >> id.email;
    }
    cout << "Masukan nomer hp : ";
    cin >> id.nomerhp;
    cout << "Masukan tanggal/bulan/tahun lahir : ";
    inputberspasistring(id.kelahiran);
    cout << "Username tidak boleh berspasi!" << endl;
    cout << "Masukan username : ";
    cin >> id.username;
    while(findcustomerbyusername(L, id.username)!=NULL || id.username == "Admin"){
        cout << "Username telah digunakan!"<<endl;
        cout << "Masukan ulang username : ";
        cin >> id.username;
    }
    cout << "Masukan password : ";
    inputberspasistring(id.password);
    while(!cekpassword(id.password)){
        if(penanda==0){
            cout << "Syarat password : " << endl;
            cout << "1.Password harus terdiri dari 8 karakter" << endl;
            cout << "2.Password harus terdiri dari huruf kapital dan huruf kecil" << endl;
            cout << "3.Password harus terdiri dari angka" << endl;
            penanda = 1;
        }
        cout << "Masukan ulang password : ";
        getline(cin, id.password);
    }
    cout << "Pertanyaan apabila lupa password : " << endl;
    cout << "(1) Nomer hp pertamamu ?" << endl;
    cout << "(2) Nama peliharaan pertamamu ?" << endl;
    cout << "(3) Nama guru sd pertamamu ?" << endl;
    cout << "Pilihan : ";
    cin >> pilihan;
    if(pilihan == "1"){
        id.pertanyaanlupapass = "Nomer hp pertamamu ?";
    }else if(pilihan == "2"){
        id.pertanyaanlupapass = "Nama peliharaan pertamamu ?";
    } else if(pilihan == "3"){
        id.pertanyaanlupapass = "Nama guru sd pertamamu ?";
    }
    cout << "Jawaban : ";
    inputberspasistring(id.jawaban);
    clear;
}

void menuatama(string &menupilihan, string username){
    atas();
    cout << "==     (1) Produk                ==" << endl;
    if(username == "Admin"){
        cout << "==     (2) Customer              ==" << endl;
    } else {
        cout << "==     (2) Edit Profil           ==" << endl;
    }
    cout << "==     (3) Log-out               ==" << endl;
    bawah();
    cin >> menupilihan;
    clear;
}

void menuproduk(string &menupilihan, string username){
    atas();
    cout << "==     (1) Lihat Rating Produk   ==" << endl;
    if(username == "Admin"){
        cout << "==     (2) Tambah Produk         ==" << endl;
        cout << "==     (3) Edit Produk           ==" << endl;
        cout << "==     (4) Hapus Produk          ==" << endl;
    } else {
        cout << "==     (2) Beri Rating Produk    ==" << endl;
        cout << "==     (3) Produk Telah Dirating ==" << endl;
        cout << "==     (4) Produk Belum Dirating ==" << endl;
    }
    cout << "==     (9) Kembali               ==" << endl;
    bawah();
    cin >> menupilihan;
    clear;
}

void menulihatproduk(string &menupilihan, string username){
    atas();
    cout << "==  (1) Lihat Secara Normal      ==" << endl;
    cout << "==  (2) Lihat Secara Ascending   ==" << endl;
    cout << "==  (3) Lihat Secara Descending  ==" << endl;
    if(username != "Guest"){
        cout << "==  (4) Lihat Perating Produk    ==" << endl;
    }
    cout << "==  (9) Kembali                  ==" << endl;
    bawah();
    cin >> menupilihan;
    if(username != "Guest"){
        while((menupilihan < "0" && menupilihan > "5") && menupilihan != "9"){
            cin >> menupilihan;
        }
    } else {
        while((menupilihan < "0" && menupilihan > "4") && menupilihan != "9"){
            cin >> menupilihan;
        }
    }
    clear;
}

void menueditproduk(List L){
    addresstoproduk P;
    int nomor;
    string pilihan;

    cout << "Pilih nomor produk yang ingin di edit: ";
    cin >> nomor;
    P = findprodukbynumber(L, nomor);
    clear;
    if(P!=NULL){
        atas();
        cout << endl << "Nama Produk yang ingin diedit: "<< info(P).namaproduk;
        cout << endl << "Keterangan Produk: "<< info(P).keterangan << endl << endl;
        cout << "==  Apa yang ingin diedit?       ==" << endl;
        cout << "==     (1) Nama Produk           ==" << endl;
        cout << "==     (2) Keterangan Produk     ==" << endl;
        cout << "==     (3) Nama dan Keterangan   ==" << endl;
        cout << "==     (9) Kembali               ==" << endl;
        bawah();
        cin >> pilihan;
        while(pilihan != "1" && pilihan != "2" && pilihan != "3" && pilihan != "9"){
            cin >> pilihan;
        }
        editproduk(pilihan, P);
    } else {
        cout << "Produk tidak ditemukan! " << endl;
    }
    pause;
    clear;
}

void menudeleteproduk(List &L, int &jumlahproduk){
    addresstoproduk P;
    int nomor;

    cout << "Pilih nomor produk yang ingin di hapus: ";
    cin >> nomor;
    P = findprodukbynumber(L, nomor);
    if(P!=NULL){
        deleteRelasiproduk(L, P);
        deleteproduk(L,P, jumlahproduk);
    } else {
        cout << "Produk tidak ditemukan!";
    }
    clear;
}

void menucustomer(string &menupilihan){
    atas();
    cout << "==    (1) View Customer          ==" << endl;
    cout << "==    (2) View Ratingan Customer ==" << endl;
    cout << "==    (3) Hapus Customer         ==" << endl;
    cout << "==    (9) Kembali                ==" << endl;
    bawah();
    cin >> menupilihan;
    clear;
}

void menuberirating(List &L, string username, addresstorelasi &R){
    addresstocustomer C;
    addresstoproduk P;
    datarelasi isirating;
    string ulasan;
    int nomor, rating;

    cout << "Pilih nomor produk yang ingin diberi rating: ";
    cin >> nomor;
    P = findprodukbynumber(L, nomor);
    C = findcustomerbyusername(L, username);
    while(findrelasi(L, P, C)!=NULL||P == NULL){
        if(P==NULL){
            cout << "Produk tidak ada! " << endl;
        } else {
            cout << "Produk telah diberi rating! " << endl;
        }
        cout << "Pilih nomor ulang: ";
        cin >> nomor;
        P = findprodukbynumber(L, nomor);
    }
    while(P == NULL){
        cout << "Produk tidak ada! " << endl;
        cout << "Pilih nomor ulang: ";
        cin >> nomor;
        P = findprodukbynumber(L, nomor);
    }
    clear;
    cout << "Nama Produk: "<< info(P).namaproduk << endl << "Beri rating 0-5: ";
    cin >> isirating.rating;
    while(isirating.rating>5 || isirating.rating<0){
        cout << "Beri rating 0-5: ";
        cin >> isirating.rating;
    }
    cout << "Ulasan: ";
    inputberspasistring(isirating.ulasan);
    info(P).jumlahperating = info(P).jumlahperating + 1;
    info(P).totalrating = info(P).totalrating+float(isirating.rating);
    info(P).rataanrating = float(info(P).totalrating)/float(info(P).jumlahperating);
    createRelasi(R, isirating, C, P);
    pause;
    clear;
}

void menudeletecustomer(List &L){
    addresstocustomer C;
    int nomor;
    cout << "Pilih nomor customer yang ingin di hapus: ";
    cin >> nomor;
    C = findcustomerbynumber(L, nomor);
    if(C!=NULL){
        deleteRelasiCustomer(L, C);
        deletecustomer(L,C);
    } else {
        cout << "Costumer tidak ditemukan!";
    }
    pause;
    clear;
}

void menuratingancustomer(List &L){
    addresstocustomer P;
    int nomor;
    cout << "Pilih nomor customer yang ingin di lihat: ";
    cin >> nomor;
    P = findcustomerbynumber(L, nomor);
    if(P!=NULL){
        viewratingancustomer(L,P);
    } else {
        cout << "Costumer tidak ditemukan!";
    }
    clear;
}

bool cekpassword(string password){
    bool memenuhi, angka, huruf, kapital = false;
    string cek = password;
    int i = 0;

    while(cek[i] && !memenuhi){
        if(cek[i]>='1' && cek[i]<='9'){
            angka = true;
        }else if(cek[i]>='a' && cek[i]<='z'){
            huruf = true;
        } else if (cek[i]>='A' && cek[i]<='Z'){
            kapital = true;
        }
        if(i>=7 && angka && huruf && kapital){
            memenuhi = true;
        }
        i++;
    }
    return memenuhi;
}

void lupapassword(addresstocustomer &C){
    string email, jawaban, password;
    int penanda;

    cout << "Masukan E-mail Anda: ";
    cin >> email;
    while(email != info(C).email){
        cout << "Email yang anda masukan tidak sesuai!" << endl;
        cout << "Masukan Ulang E-mail Anda: ";
        cin >> email;
    }
    cout << info(C).pertanyaanlupapass << endl;
    cout << "Jawaban: ";
    inputberspasistring(jawaban);
    while(jawaban != info(C).jawaban){
        cout << "Jawaban yang anda masukan tidak sesuai!" << endl;
        cout << "Masukan ulang jawaban: ";
        getline(cin, jawaban);
    }
    cout << "Masukan password baru: ";
    getline(cin, password);
    while(!cekpassword(password)){
        if(penanda==0){
            cout << "Syarat password : " << endl;
            cout << "1.Password harus terdiri dari 8 karakter" << endl;
            cout << "2.Password harus terdiri dari huruf kapital dan huruf kecil" << endl;
            cout << "3.Password harus terdiri dari angka" << endl;
            penanda = 1;
        }
        cout << "Masukan ulang password : ";
        getline(cin, password);
    }
    info(C).password = password;
}
