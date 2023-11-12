#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Fonksiyon prototipleri
void toplamaVeCarpma(int* dizi1, int boyut1, int* dizi2, int boyut2, int* toplam, int* carpim);
void tekVeCiftAyir(int* dizi, int boyut, int* tekSayilar, int& tekBoyut, int* ciftSayilar, int& ciftBoyut);
void dosyayaYaz(int* toplam, int* carpim, int boyut, int* tekSayilar, int tekBoyut, int* ciftSayilar, int ciftBoyut);

int main() {
    int boyut1;
    cout << "Dizi 1 boyutunu girin: ";
    cin >> boyut1;

    int* dizi1 = new int[boyut1];
    cout << "Dizi 1 elemanlarini girin: ";
    for (int i = 0; i < boyut1; ++i) {
        cin >> dizi1[i];
    }

    string dosyaAdi = "/Users/vahitakcay/Downloads/vss/oop/ödv_10_1/dizi2.txt";
    ifstream dosya(dosyaAdi);

    if (!dosya) {
        cerr << "Dosya acilamadi!" << endl;
        delete[] dizi1;
        return 1;
    }

    int boyut2;
    dosya >> boyut2;

    int* dizi2 = new int[boyut2];
    for (int i = 0; i < boyut2; ++i) {
        dosya >> dizi2[i];
    }

    dosya.close();

    int* toplam = new int[boyut1];
    int* carpim = new int[boyut1];
    toplamaVeCarpma(dizi1, boyut1, dizi2, boyut2, toplam, carpim);

    int* tekSayilar = new int[boyut1];
    int tekBoyut = 0;
    int* ciftSayilar = new int[boyut1];
    int ciftBoyut = 0;
    tekVeCiftAyir(dizi1, boyut1, tekSayilar, tekBoyut, ciftSayilar, ciftBoyut);

    dosyayaYaz(toplam, carpim, boyut1, tekSayilar, tekBoyut, ciftSayilar, ciftBoyut);

    delete[] dizi1;
    delete[] dizi2;
    delete[] toplam;
    delete[] carpim;
    delete[] tekSayilar;
    delete[] ciftSayilar;

    return 0;
}

void toplamaVeCarpma(int* dizi1, int boyut1, int* dizi2, int boyut2, int* toplam, int* carpim) {
    for (int i = 0; i < boyut1; ++i) {
        toplam[i] = dizi1[i] + dizi2[i];
        carpim[i] = dizi1[i] * dizi2[i];
    }
}

void tekVeCiftAyir(int* dizi, int boyut, int* tekSayilar, int& tekBoyut, int* ciftSayilar, int& ciftBoyut) {
    for (int i = 0; i < boyut; ++i) {
        if (dizi[i] % 2 == 0) {
            ciftSayilar[ciftBoyut++] = dizi[i];
        } else {
            tekSayilar[tekBoyut++] = dizi[i];
        }
    }
}

void dosyayaYaz(int* toplam, int* carpim, int boyut, int* tekSayilar, int tekBoyut, int* ciftSayilar, int ciftBoyut) {
    string dosyaAdi = "/Users/vahitakcay/Downloads/vss/oop/ödv_10_1/output.txt";
    ofstream dosya(dosyaAdi);

    if (!dosya) {
        cerr << "Dosya acilamadi!" << endl;
        return;
    }

    dosya << "Toplama isleminin sonucu: ";
    for (int i = 0; i < boyut; ++i) {
        dosya << toplam[i] << " ";
    }
    dosya << "\n";

    dosya << "Carpma isleminin sonucu: ";
    for (int i = 0; i < boyut; ++i) {
        dosya << carpim[i] << " ";
        }
    dosya << "\n";

    dosya << "Tek sayilari tutan dizi: ";
    for (int i = 0; i < tekBoyut; ++i) {
        dosya << tekSayilar[i] << " ";
    }
    dosya << "\n";

    dosya << "Cift sayilari tutan dizi: ";
    for (int i = 0; i < ciftBoyut; ++i) {
        dosya << ciftSayilar[i] << " ";
    }
    dosya << "\n";

    dosya.close();
}