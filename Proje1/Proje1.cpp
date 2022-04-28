#include <limits>
#include <iostream>
#include <locale.h>
#include <cmath>
using namespace std;

int sayiGir() { // Kullan�c�dan Say� Girdisi Al�p De�i�ken Olarak D�nd�ren Fonksiyon
    int sayi;
    cout << "Sayi Giriniz : ";
    while (!(cin >> sayi)) { // Girdinin Sadece Say� Olarak Al�nmas� ��in While D�ng�s�
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "L�tfen Sayi Giriniz!!! : ";
    }
    return sayi;
}

int sayiUzunlugu(int girilenSayi) { // Girilen Say�n�n Ka� Basamakl� Oldu�unu D�nd�ren Fonksiyon 
    int sayac = 0;
    while (true) { // Basamak Say�s�n� Bulmak i�in while d�ng�s� 
        sayac++;
        girilenSayi /= 10;
        if (girilenSayi <= 0)
            break;
    }
    return sayac;
}

void armsstrongKontrol(int girilenSayi) { // Girilen Say�n�n Armstrong Olup Olmad���n� Kontrol Eden ve Konsola Yazd�ran Fonksiyon
    int sonBasamak, kopyaSayi, toplam = 0;
    int �s = sayiUzunlugu(girilenSayi); // sayiUzunlugu fonksiyonu �s de�i�kenine atand�.
    kopyaSayi = girilenSayi; // girilenSayi'da i�lem yap�laca�� i�in kopyaSayiya girdi al�nan say� atand�.
    
    while (girilenSayi > 0) { // Armstrong ��lemi Yap�lmas� ��in while d�ng�s� �rnek(371 = 3^3 + 7^3 + 1^3)
        sonBasamak = girilenSayi % 10;
        toplam += pow(sonBasamak,�s);
        girilenSayi /= 10;
    }
    
    if (kopyaSayi == toplam) // Armstrong Say�ysa Yazd�r
        cout << "Girdi�iniz Say� Armstrong Say�d�r.";
    else //Armstrong Say� De�ilse Yazd�r
        cout << "Girdi�iniz Say� Armstrong Say� De�ildir.";
}


int main()
{
    setlocale(LC_ALL, "Turkish"); //T�rk�e Karakter Kullan�lmas� ��in
    cout << "************ Armstrong Say� Kontrol� ************\n";
    armsstrongKontrol(sayiGir());
}


