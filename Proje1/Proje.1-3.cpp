#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

// text degiskeni ve kullanilacak buyuk kucuk harfler birden fazla fonksiyonda kullanilacagi icin global olarak tanimlandi
string text;
string alphabetUpperCase = "ABC�DEFG�HI�JKLMNO�PRS�TU�VYZ";
string alphabetLowerCase = "abc�defg�h�ijklmno�prs�tu�vyz";

// Sifrelenecek veya sifresi cozulecek metni kullanicidan girdi alan fonksiyon
void getText() {
    cout << "Please Enter Your Text :";
    // Girilen metnin bosluk icererek alinmasi icin getline kullanildi
    getline(cin >> ws, text);
}

// Sifreleme Fonksiyonu
void encryption() {
    getText();
    // Girilen Metnin uzunluguna kadar devam eden for d�ng�s�
    for (int i = 0; i < text.length(); i++) {
        // 23 tane karakter oldugu icin 23'e kadar devam eden for d�ng�s�
        for (int j = 0; j < 29; j++) {
            if (text[i] == char(128)) { // � karakteri i�in
                text[i] = 'A';
                break;
            }
            else if (text[i] == char(129)) { // � karakteri i�in
                text[i] = 'z';
                break;
            }
            else if (text[i] == char(135)) { // � karakteri i�in
                text[i] = 'f';
                break;
            }
            else if (text[i] == char(141)) { // � karakteri i�in
                text[i] = 'k';
                break;
            }
            else if (text[i] == char(148)) { // � karakteri i�in
                text[i] = 's';
                break;
            }
            else if(text[i] == char(152)) { // � karakteri i�in
                text[i] = 'L';
                break;
            }
            else if (text[i] == char(153)) { // � karakteri i�in
                text[i] = 'S';
                break;
            }
            else if (text[i] == char(154)) { // � karakter i�in
                text[i] = 'Z';
                break;
            }
            else if (text[i] == char(158)) { // � karakteri i�in
                text[i] = '�';
                break;
            }
            else if (text[i] == char(159)) { // � karakteri i�in
                text[i] = '�';
                break;
            }
            else if (text[i] == char(166)) { // � karakteri i�in
                text[i] = '�';
                break;
            }
            else if (text[i] == char(167)) { // � karakteri i�in
                text[i] = 'i';
                break;
            }
            //Eger girilen metnin i indeksindeki eleman kucukharf dizisinin j indeksindeki elemana esitse j yi 3 arttirip 23'e g�re modunu al ve metnin i indeksindeki elemani kucukharf dizisinin j indeksindeki elemanla degistir
            else if (text[i] == alphabetLowerCase[j]) {
                j += 3;
                j %= 29;
                text[i] = alphabetLowerCase[j];
                break;
            }
            //Eger girilen metnin i indeksindeki eleman buyukharf dizisinin j indeksindeki elemana esitse j yi 3 arttirip 23'e g�re modunu al ve metnin i indeksindeki elemani buyukharf dizisinin j indeksindeki elemanla degistir
            else if (text[i] == alphabetUpperCase[j]) {
                j += 3;
                j %= 29;
                text[i] = alphabetUpperCase[j];
                break;
            }
            else {
                continue;
            }
                
        }
    }
    // Sifrelenmis Mesaji Yazdirma
    cout << "Encrypted Text: " << text << endl;
}

// Sifre Cozme Fonksiyonu
void decryption() {
    getText();
    // Girilen Metnin uzunluguna kadar devam eden for d�ng�s�
    for (int i = 0; i < text.length(); i++) {
        // 23 tane karakter oldugu icin 23'e kadar devam eden for d�ng�s�
        for (int j = 0; j < 29; j++) {
            if (text[i] == char(128)) { // � karakteri i�in
                text[i] = 'F';
                break;
            }
            else if (text[i] == char(129)) { // � karakteri i�in
                text[i] = '�';
                break;
            }
            else if (text[i] == char(135)) { // � karakteri i�in
                text[i] = 'a';
                break;
            }
            else if (text[i] == char(141)) { // � karakteri i�in
                text[i] = 'g';
                break;
            }
            else if (text[i] == char(148)) { // � karakteri i�in
                text[i] = 'm';
                break;
            }
            else if (text[i] == char(152)) { // � karakteri i�in
                text[i] = '�';
                break;
            }
            else if (text[i] == char(153)) { // � karakteri i�in
                text[i] = 'M';
                break;
            }
            else if (text[i] == char(154)) { // � karakter i�in
                text[i] = '�';
                break;
            }
            else if (text[i] == char(158)) { // � karakteri i�in
                text[i] = '�';
                break;
            }
            else if (text[i] == char(159)) { // � karakteri i�in
                text[i] = '�';
                break;
            }
            else if (text[i] == char(166)) { // � karakteri i�in
                text[i] = 'E';
                break;
            }
            else if (text[i] == char(167)) { // � karakteri i�in
                text[i] = 'e';
                break;
            }
            //Eger girilen metnin i indeksindeki eleman kucukharf dizisinin j indeksindeki elemana esitse j yi 3 azaltip 23'e g�re modunu al ve metnin i indeksindeki elemani kucukharf dizisinin j indeksindeki elemanla degistir.
            else if (text[i] == alphabetLowerCase[j]) {
                j -= 3;
                //Eger j'den 3 cikartildiginda 0'dan k�c�k oluyorsa j'ye 23 eklenir ve 23'e g�re modu alinir.
                if (j < 0)
                    j += 29;
                j %= 29;
                text[i] = alphabetLowerCase[j];
                break;
            }
            //Eger girilen metnin i indeksindeki eleman buyukharf dizisinin j indeksindeki elemana esitse j yi 3 azaltip 23'e g�re modunu al ve metnin i indeksindeki elemani buyukharf dizisinin j indeksindeki elemanla degistir
            else if (text[i] == alphabetUpperCase[j]) {
                j -= 3;
                //Eger j'den 3 cikartildiginda 0'dan k�c�k oluyorsa j'ye 23 eklenir ve 23'e g�re modu alinir.
                if (j < 0)
                    j += 29;
                j %= 29;
                text[i] = alphabetUpperCase[j];
                break;
            }
            else 
                continue;
        }
    }
    // Sifresi Cozulen Mesaji Yazdirma
    cout << "Decrypted Text :" << text << endl;
}


int main()
{
    setlocale(LC_ALL, "Turkish");
    char restart = 'Y';
    char choice;
    // restart degiskeni 'y' veya 'Y' oldu�u s�rece devam etmesi icin while d�ng�s�
    while (restart == 'Y' || restart == 'y')
    {
        bool choiceControl = false;
        cout << "Please Select Operation!\n" << "1.Encryption\n" << "2.Decryption\n" << "Enter Number Of Your Choice : ";
        // Kullanicidan alinan islem numarasinin dogru girilmesi icin while d�ng�s� icinde switch-case yapisi kullanildi yanlis girildiginde hata mesaji verildi ve tekrar islem numarasi girilmesi istendi.Dogru girildiginde while d�ng�s�nden cikip programa devam edildi.
        while (choiceControl == false) {
            cin >> choice;
            switch (choice)
            {
            case '1':
                encryption();
                choiceControl = true;
                break;
            case '2':
                decryption();
                choiceControl = true;
                break;
            default:
                cout << "Please Enter Operation Number Correctly!(You Can Only Use 1 And 2)\n";
                cout << "Enter Number Of Your Choice : ";
                break;
            }
        }
        // Kullaniciya programi bastan baslatmak isteyip istemedigi soruldu,cevap evetse y veya Y karakterini girmesi istendi.Bu karakterler girildiginde konsol temizlendi ve program main fonksiyonun ilk while d�ng�s�nden itibaren bastan baslatildi.
        cout << "Do you want to restart the program?(If your answer is yes enter Y or y)\n";
        cout << "Your Answer : ";
        cin >> restart;
        if (restart == 'y' || restart == 'Y')
            system("cls");
    }
}