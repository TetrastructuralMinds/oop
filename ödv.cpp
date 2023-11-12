#include <iostream>
#include <vector>
#include <fstream>

// Fonksiyon prototipleri
int hesaplaToplam(const std::vector<int>& dizi1, const std::vector<int>& dizi2);
void ayirTekCift(const std::vector<int>& dizi, std::vector<int>& tekler, std::vector<int>& ciftler);
void dosyayaYazdir(const std::string& dosyaAdi, int toplam, int carpim, const std::vector<int>& tekler, const std::vector<int>& ciftler, const std::vector<int>& carpimSonuclari);
std::vector<int> satirlariKiyaslaVeCarp(const std::vector<int>& dizi1, const std::vector<int>& dizi2);

int main() {
    int diziboyut;

    // Kullanıcıdan dizi boyutunu al
    std::cout << "Lutfen dizi boyutunu giriniz: ";
    std::cin >> diziboyut;

    // Dizi boyutu kadar bir vektör oluştur
    std::vector<int> dizi1(diziboyut);

    // Kullanıcıdan elemanları al
    std::cout << "Lutfen " << diziboyut << " adet sayi giriniz:" << std::endl;
    for (int i = 0; i < diziboyut; ++i) {
        std::cout << "Sayi " << i + 1 << ": ";
        std::cin >> dizi1[i];
    }

    // Dosyadan dizi2'yi oku
    std::ifstream dosya("/Users/vahitakcay/Downloads/vss/oop/ödv_10_1/dizi2.txt");
    if (!dosya) {
        std::cerr << "dizi2.txt dosyasi acilamadi." << std::endl;
        return 1;
    }

    std::vector<int> dizi2;
    int sayi;
    while (dosya >> sayi) {
        dizi2.push_back(sayi);
    }
    dosya.close();
    int carpim ;

    // Toplam ve çarpımı hesapla
    int toplam = hesaplaToplam(dizi1, dizi2);

    // Tek ve çift sayıları ayır
    std::vector<int> tekler, ciftler;
    ayirTekCift(dizi1, tekler, ciftler);

    // İlk satır hariç diğer satırları karşılaştır ve çarp
    std::vector<int> carpimSonuclari = satirlariKiyaslaVeCarp(dizi1, dizi2);


    // Sonuçları dosyaya yazdır
    dosyayaYazdir("/Users/vahitakcay/Downloads/vss/oop/ödv_10_1/output.txt", toplam, carpim, tekler, ciftler, carpimSonuclari);

    return 0;
}

// Toplam fonksiyonu
int hesaplaToplam(const std::vector<int>& dizi1, const std::vector<int>& dizi2) {
    int toplam = 0;
    for (size_t i = 0; i < dizi1.size(); ++i) {
        toplam += dizi1[i] + dizi2[i];
    }
    return toplam;
}


// İki dizinin belirli bir satırını karşılaştır ve çarp fonksiyonu
std::vector<int> satirlariKiyaslaVeCarp(const std::vector<int>& dizi1, const std::vector<int>& dizi2) {
    std::vector<int> carpimSonuclari;

    for (size_t satir = 1; satir < std::min(dizi1.size(), dizi2.size()); ++satir) {
        if (satir < dizi1.size() && satir < dizi2.size()) {
            int carpim = dizi1[satir] * dizi2[satir];
            carpimSonuclari.push_back(carpim);
        } else {
            std::cerr << "Belirtilen satir dizilerin boyutundan buyuk." << std::endl;
        }
    }

    return carpimSonuclari;
}

// Tek ve çift sayıları ayırma fonksiyonu
void ayirTekCift(const std::vector<int>& dizi, std::vector<int>& tekler, std::vector<int>& ciftler) {
    for (size_t i = 0; i < dizi.size(); ++i) {
        if (dizi[i] % 2 == 0) {
            ciftler.push_back(dizi[i]);
        } else {
            tekler.push_back(dizi[i]);
        }
    }
}

// Sonuçları dosyaya yazma fonksiyonu
void dosyayaYazdir(const std::string& dosyaAdi, int toplam, int carpim, const std::vector<int>& tekler, const std::vector<int>& ciftler, const std::vector<int>& carpimSonuclari) {
    std::ofstream dosya(dosyaAdi);
    dosya << "Dizilerin Toplami: " << toplam << std::endl;

    dosya << "Tek Sayilar:" << std::endl;
    for (size_t i = 0; i < tekler.size(); ++i) {
        dosya << tekler[i] << " ";
    }
    dosya << std::endl;

    dosya << "Cift Sayilar:" << std::endl;
    for (size_t i = 0; i < ciftler.size(); ++i) {
        dosya << ciftler[i] << " ";
    }
    dosya << std::endl;

    dosya << "Satirların Carpimi:" << std::endl;
    for (size_t i = 0; i < carpimSonuclari.size(); ++i) {
        dosya << carpimSonuclari[i] << " ";
    }
    dosya << std::endl;

    dosya.close();
}
