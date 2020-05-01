#include<iostream>

#define clear system("CLS")
#define pause system("PAUSE")

#define next(A) A -> next
#define info(A) A -> info
#define toproduk(A) A -> toproduk
#define tocustomer(A) A -> tocustomer
#define firstcustomer(L) L.firstcustomer
#define firstrelasi(L) L.firstrelasi
#define firstproduk(L) L.firstproduk

using namespace std;

typedef struct customer *addresstocustomer;
typedef struct relasi *addresstorelasi;
typedef struct produk *addresstoproduk;

struct datadiri{
    string nama, username, password, kelahiran, nomerhp, email, pertanyaanlupapass, jawaban;
};

struct dataproduk{
    string namaproduk, keterangan;
    int nomor, jumlahperating, totalrating;
    float rataanrating;
    bool printed;
};

struct datarelasi{
    int rating;
    string ulasan;
};

struct produk{
    addresstoproduk next;
    dataproduk info;
};

struct relasi {
    addresstorelasi next;
    addresstoproduk toproduk;
    addresstocustomer tocustomer;
    datarelasi info;
};

struct customer{
    addresstocustomer next;
    datadiri info;
};

struct List {
    addresstocustomer firstcustomer;
    addresstorelasi firstrelasi;
    addresstoproduk firstproduk;
};


//// File Umum
void atas();  // Baris 3
void bawah(); // Baris 9
void inputberspasistring(string &kata); // Baris 14
void menuawal(string &menupilihan); // Baris  19
void menulogin(List L, string &username, string &password); // Baris 30
void menudaftar(List L, datadiri &id); // Baris 75
void menuatama(string &menupilihan, string username); // Baris 132
void menuproduk(string &menupilihan, string username); // Baris 146
void menulihatproduk(string &menupilihan, string username); // Baris 164
void menueditproduk(List L); // Baris 187
void menudeleteproduk(List &L, int &jumlahproduk); // Baris 217
void menucustomer(string &menupilihan); // Baris  233
void menuberirating(List &L, string username, addresstorelasi &R); // Baris 244
void menudeletecustomer(List &L); // Baris 278
void menuratingancustomer(List &L); // Baris 295
bool cekpassword(string password); // Baris 309
void lupapassword(addresstocustomer &C); // Baris 330


//// File List
void createList(List &L); // Baris 7

// List Produk
void createproduk(addresstoproduk &P, dataproduk produkinfo); // Baris 16
void tambahproduk(List L, dataproduk &produkinfo, int &nomorproduk);// Baris 22
void insertproduk(List &L, addresstoproduk P); // Baris 41
void deleteproduk(List &L, addresstoproduk P, int &jumlahproduk); // Baris 54
void editproduk(string pilihan, addresstoproduk P); // Baris 83
void viewproduk(List L); // Baris 108
void viewyangsudahdiratedanbelum(List L, string username); // Baris 124
void viewproduktelahdirate(List &L, string username); // Baris 149
void viewprodukbelumdirate(List L, string username); // Baris 225
void viewperatingproduk(List L, addresstoproduk P); // Baris 250
addresstoproduk findprodukbyname(List L, string namaproduk); // Baris 270
addresstoproduk findprodukbynumber(List L, int nomor); // Baris 285
void produkkosong(addresstoproduk &P); // Baris 294
void printAscending(List L, addresstoproduk P, int jumlahproduk); // Baris 305
void minrating(addresstoproduk min1, addresstoproduk &min2, addresstoproduk &temp, addresstoproduk P, int nomor); // Baris 320
void printDescending(List L, addresstoproduk P, int jumlahproduk); // Baris 339
void maxrating(addresstoproduk max1, addresstoproduk &max2, addresstoproduk &temp, addresstoproduk P, int nomor); // Baris 354
void returnprintedtofalse(List L); // Baris 373

// Relasi
void createRelasi(addresstorelasi &R, datarelasi isirating, addresstocustomer C, addresstoproduk P); // Baris 386
void insertRelasi(List &L, addresstorelasi R); // Baris 393
void deleteRelasi(List &L, addresstorelasi R); // Baris 398
void deleteRelasiproduk(List &L, addresstoproduk P); // Baris 417
void deleteRelasiCustomer(List &L, addresstocustomer C); // Baris 432
void viewrelasi(List L); // Baris 449
addresstorelasi findrelasi(List L, addresstoproduk P, addresstocustomer C); // Baris 458

// List Customer
void createCustomer(addresstocustomer &P, datadiri isiinfo); // Baris 480
void insertCustomer(List &L, addresstocustomer C); // Baris 486
void deletecustomer(List &L, addresstocustomer C); // Baris 505
void editprofil(List &L, string menupilihan, string &username, bool &kembali); // Baris 520
void replaceCustomer(List &L, addresstocustomer C); // Baris 577
addresstocustomer findcustomerbyusername(List L, string username); // Baris 584
addresstocustomer findcustomerbyemail(List L, string email); // Baris 593
addresstocustomer findcustomerbynumber(List L, int nomor); // Baris 602
void viewusernamecustomer(List L); // Baris 613
void viewdetaildiricustomer(List L, string username, string &menupilihan); // Baris 630
void viewratingancustomer(List L, addresstocustomer C); // Baris 659
