#include <iostream>
#include <string>

using namespace std;

// text degiskeni ve kullanilacak buyuk kucuk harfler birden fazla fonksiyonda kullanilacagi icin global olarak tanimlandi
string text;
char alphabetUpperCase[23] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U','V','Y','Z' };
char alphabetLowerCase[23] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','r','s','t','u','v','y','z' };

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
        // 23 tane karakter oldugu icin 23'e kadar devam eden for döngüsü
        for (int j = 0; j < 23; j++) {
            //Eger girilen metnin i indeksindeki eleman kucukharf dizisinin j indeksindeki elemana esitse j yi 3 arttirip 23'e göre modunu al ve metnin i indeksindeki elemani kucukharf dizisinin j indeksindeki elemanla degistir
            if (text[i] == alphabetLowerCase[j]) {
                j += 3;
                j %= 23;
                text[i] = alphabetLowerCase[j];
                break;
            }
            //Eger girilen metnin i indeksindeki eleman buyukharf dizisinin j indeksindeki elemana esitse j yi 3 arttirip 23'e göre modunu al ve metnin i indeksindeki elemani buyukharf dizisinin j indeksindeki elemanla degistir
            else if (text[i] == alphabetUpperCase[j]) {
                j += 3;
                j %= 23;
                text[i] = alphabetUpperCase[j];
                break;
            }
            else
                continue;
         }
    }
    // Sifrelenmis Mesaji Yazdirma
    cout << "Encrypted Text: " << text << endl;
}

// Sifre Cozme Fonksiyonu
void decryption() {
    getText();
    // Girilen Metnin uzunluguna kadar devam eden for döngüsü
    for (int i = 0; i < text.length(); i++) {
        // 23 tane karakter oldugu icin 23'e kadar devam eden for döngüsü
        for (int j = 0; j < 23; j++) {
            //Eger girilen metnin i indeksindeki eleman kucukharf dizisinin j indeksindeki elemana esitse j yi 3 azaltip 23'e göre modunu al ve metnin i indeksindeki elemani kucukharf dizisinin j indeksindeki elemanla degistir.
            if (text[i] == alphabetLowerCase[j]) {
                j -= 3;
                //Eger j'den 3 cikartildiginda 0'dan kücük oluyorsa j'ye 23 eklenir ve 23'e göre modu alinir.
                if (j < 0)
                    j += 23;
                j %= 23;
                text[i] = alphabetLowerCase[j];
                break;
            }
            //Eger girilen metnin i indeksindeki eleman buyukharf dizisinin j indeksindeki elemana esitse j yi 3 azaltip 23'e göre modunu al ve metnin i indeksindeki elemani buyukharf dizisinin j indeksindeki elemanla degistir
            else if (text[i] == alphabetUpperCase[j]) {
                j -= 3;                
                //Eger j'den 3 cikartildiginda 0'dan kücük oluyorsa j'ye 23 eklenir ve 23'e göre modu alinir.
                if (j < 0)
                    j += 23;
                j %= 23;
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
    char restart = 'Y';
    char choice;
    // restart degiskeni 'y' veya 'Y' olduðu sürece devam etmesi icin while döngüsü
    while (restart == 'Y' || restart == 'y')
    {
        bool choiceControl = false;
        cout << "Please Select Operation!\n" << "1.Encryption\n" << "2.Decryption\n" << "Enter Number Of Your Choice : ";
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
                cout << "Enter Number Of Your Choice : ";
                break;
            }
        }
        // Kullaniciya programi bastan baslatmak isteyip istemedigi soruldu,cevap evetse y veya Y karakterini girmesi istendi.Bu karakterler girildiginde konsol temizlendi ve program main fonksiyonun ilk while döngüsünden itibaren bastan baslatildi.
        cout << "Do you want to restart the program?(If your answer is yes enter Y or y)\n";
        cout << "Your Answer : ";
        cin >> restart;
        if(restart == 'y' || restart == 'Y')
            system("cls");
        
    }
        
    
    
    
    
    
    
}


