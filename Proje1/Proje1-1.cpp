#include <limits>
#include <iostream>
#include <locale.h>
#include <cmath>
using namespace std;

int sayiGir() { // Kullanýcýdan Sayý Girdisi Alýp Deðiþken Olarak Döndüren Fonksiyon
    int sayi;
    cout << "Sayi Giriniz : ";
    while (!(cin >> sayi)) { // Girdinin Sadece Sayý Olarak Alýnmasý Ýçin While Döngüsü
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Lütfen Sayi Giriniz!!! : ";
    }
    return sayi;
}

int sayiUzunlugu(int girilenSayi) { // Girilen Sayýnýn Kaç Basamaklý Olduðunu Döndüren Fonksiyon 
    int sayac = 0;
    while (true) { // Basamak Sayýsýný Bulmak için while döngüsü 
        sayac++;
        girilenSayi /= 10;
        if (girilenSayi <= 0)
            break;
    }
    return sayac;
}

void armsstrongKontrol(int girilenSayi) { // Girilen Sayýnýn Armstrong Olup Olmadýðýný Kontrol Eden ve Konsola Yazdýran Fonksiyon
    int sonBasamak, kopyaSayi, toplam = 0;
    int üs = sayiUzunlugu(girilenSayi); // sayiUzunlugu fonksiyonu üs deðiþkenine atandý.
    kopyaSayi = girilenSayi; // girilenSayi'da iþlem yapýlacaðý için kopyaSayiya girdi alýnan sayý atandý.
    
    while (girilenSayi > 0) { // Armstrong Ýþlemi Yapýlmasý Ýçin while döngüsü Örnek(371 = 3^3 + 7^3 + 1^3)
        sonBasamak = girilenSayi % 10;
        toplam += pow(sonBasamak,üs);
        girilenSayi /= 10;
    }
    
    if (kopyaSayi == toplam) // Armstrong Sayýysa Yazdýr
        cout << "Girdiðiniz Sayý Armstrong Sayýdýr.";
    else //Armstrong Sayý Deðilse Yazdýr
        cout << "Girdiðiniz Sayý Armstrong Sayý Deðildir.";
}


int main()
{
    setlocale(LC_ALL, "Turkish"); //Türkçe Karakter Kullanýlmasý Ýçin
    cout << "************ Armstrong Sayý Kontrolü ************\n";
    armsstrongKontrol(sayiGir());
}


