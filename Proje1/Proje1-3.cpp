#include <iostream>
#include <string>
#include <vector>
using namespace std;

// text degiskeni ve kullanilacak buyuk kucuk harfler birden fazla fonksiyonda kullanilacagi icin global olarak tanimlandi
string text;
//Türkçe karakterlerin ASCII karsiliklari -> ç=135 Ç=128 ð=167 Ð=166 ý=141 Ý=152 Ö=153 ö=148 þ=159 Þ=158 Ü=154 ü=129
vector<int> alphabetUpperCase { 65,66,67,128,68,69,70,71,166,72,73,152,74,75,76,77,78,79,153,80,82,83,158,84,85,154,86,89,90 };
vector<int> alphabetLowerCase { 97,98,99,135,100,101,102,103,167,104,141,105,106,107,108,109,110,111,148,112,114,115,159,116,117,129,118,121,122 };
// Sifrelenecek veya sifresi cozulecek metni kullanicidan girdi alan fonksiyon
void getText() {
    cout << "Please Enter Your Text :";
    // Girilen metnin bosluk icererek alinmasi icin getline kullanildi
    getline(cin >> ws, text);
}

// Sifreleme Fonksiyonu
void encryption() {
    getText();
    // Girilen Metnin uzunluguna kadar devam eden for döngüsü
    for (int i = 0; i < text.length(); i++) {
        // 29 tane karakter oldugu icin 29'a kadar devam eden for döngüsü
        for (int j = 0; j < 29; j++) {
            //Eger girilen metnin i indeksindeki eleman kucukharf dizisinin j indeksindeki elemana esitse j yi 3 arttirip 29'a göre modunu al ve metnin i indeksindeki elemani kucukharf dizisinin j indeksindeki elemanla degistir
            if (text[i] == char(alphabetLowerCase[j])) {
                j += 3;
                j %= 29;
                text[i] = char(alphabetLowerCase[j]);
                break;
            }
            //Eger girilen metnin i indeksindeki eleman buyukharf dizisinin j indeksindeki elemana esitse j yi 3 arttirip 29'a göre modunu al ve metnin i indeksindeki elemani buyukharf dizisinin j indeksindeki elemanla degistir
            else if (text[i] == char(alphabetUpperCase[j])) {
                j += 3;
                j %= 29;
                text[i] = char(alphabetUpperCase[j]);
                break;
            }
            else {
                continue;
            }
        }
    }
    // Sifrelenmis Mesaji Yazdirma
    cout << "Encrypted Text :" << text << endl;
}

// Sifre Cozme Fonksiyonu
void decryption() {
    getText();
    // Girilen Metnin uzunluguna kadar devam eden for döngüsü
    for (int i = 0; i < text.length(); i++) {
        // 29 tane karakter oldugu icin 29'e kadar devam eden for döngüsü
        for (int j = 0; j < 29; j++) {
            //Eger girilen metnin i indeksindeki eleman kucukharf dizisinin j indeksindeki elemana esitse j yi 3 azaltip 29'a göre modunu al ve metnin i indeksindeki elemani kucukharf dizisinin j indeksindeki elemanla degistir.
            if (text[i] == char(alphabetLowerCase[j])) {
                j -= 3;
                //Eger j'den 3 cikartildiginda 0'dan kücük oluyorsa j'ye 29 eklenir ve 29'e göre modu alinir.
                if (j < 0)
                    j += 29;
                j %= 29;
                text[i] = char(alphabetLowerCase[j]);
                break;
            }
            //Eger girilen metnin i indeksindeki eleman buyukharf dizisinin j indeksindeki elemana esitse j yi 3 azaltip 29'a göre modunu al ve metnin i indeksindeki elemani buyukharf dizisinin j indeksindeki elemanla degistir
            else if (text[i] == char(alphabetUpperCase[j])) {
                j -= 3;
                //Eger j'den 3 cikartildiginda 0'dan kücük oluyorsa j'ye 29 eklenir ve 29'a göre modu alinir.
                if (j < 0)
                    j += 29;
                j %= 29;
                text[i] = char(alphabetUpperCase[j]);
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
    
    char restart = 'Y';
    char choice;
    // restart degiskeni 'y' veya 'Y' olduðu sürece devam etmesi icin while döngüsü
    while (restart == 'Y' || restart == 'y')
    {
        bool choiceControl = false;
        cout << "Please Select Operation!\n" << "1.Encryption\n" << "2.Decryption\n" << "Enter Number Of Your Choice :";
        // Kullanicidan alinan islem numarasinin dogru girilmesi icin while döngüsü icinde switch-case yapisi kullanildi yanlis girildiginde hata mesaji verildi ve tekrar islem numarasi girilmesi istendi.Dogru girildiginde while döngüsünden cikip programa devam edildi.
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
                cout << "Enter Number Of Your Choice :";
                break;
            }
        }
        // Kullaniciya programi bastan baslatmak isteyip istemedigi soruldu,cevap evetse y veya Y karakterini girmesi istendi.Bu karakterler girildiginde konsol temizlendi ve program main fonksiyonun ilk while döngüsünden itibaren bastan baslatildi.
        cout << "Do you want to restart the program?(If your answer is yes enter Y or y)\n";
        cout << "Your Answer : ";
        cin >> restart;
        if (restart == 'y' || restart == 'Y')
            system("cls");
    }
}