#include <iostream>
#include <regex>
#include <string>
using namespace std;

// Binary sayilarin toplamini hesaplayan ve donduren fonksiyon
string sumOfBinaries(string firstBinary, string secondBinary) {
	// Girilen Binary sayilarin uzunluklari bulunup son indexlerine ulasmak icin 1 cikarildi
	int firstBinIndex = firstBinary.size() - 1;
	int secondBinIndex = secondBinary.size() - 1;
	int temp = 0;
	string result = "";

	/*
	'0' ASCII karsiligi 48
	'1' ASCII karsiligi 49
	
	0 + 0 -> 0 elde = 0
	0 + 1 -> 1 elde = 0
	1 + 0 -> 1 elde = 0
	1 + 1 -> 0 elde = 1
	
	Eger temp 1 ise temp kendisi ve (49 - 48) yani 1 ile toplanarak guncellenir
	Eger temp 0 ise temp kendisi ve (48 - 48) yani 0 ile toplanarak guncellenir
	
	Eger temp 2 ise sonuc degiskeni basina 0 eklenerek guncellenir ve elde olan 1 sayisi sonraki indexte islem yapilmasi icin aktarilir.Eger elde kalan 1 islemler tamamlandiginda kalmissa sonuc degiskeni basina 1 eklenerek guncellenir
	Eger temp 1 ise sonuc degiskeni basina 1 eklenerek guncellenir
	Eger temp 0 ise sonuc degiskeni basina 0 eklenerek guncellenir
	*/
	while (firstBinIndex >= 0 || secondBinIndex >= 0 || temp == 1)
	{
		if (firstBinIndex >= 0)
			temp += firstBinary[firstBinIndex] - '0';
		if (secondBinIndex >= 0)
			temp += secondBinary[secondBinIndex] - '0';
		
		result = char(temp % 2 + '0') + result;
		temp /= 2;
		firstBinIndex--;
		secondBinIndex--;
	}
	return result;
}
// Bulunan Toplami 10'luk sistemde yazdiran fonksiyon
void convertBinToInt(string resultBinary) {
	int resultInt = 0;
	resultInt = stoi(resultBinary, 0, 2);
	cout << "Int Result of Sum of Binary Numbers : " << resultInt;
}

int main() {
	bool inpControl = false;
	string firstBin, secondBin, resultBin;
	// Sadece 0 ve 1 icermesini saglayan regex kodu
	regex onlyZeroAndOne("^[01]+$");
	cout << "Binary Addition Calculator\n";
	while (inpControl == false) {
		// Kullanicidan Girdi Alma Islemleri
		cout << "Enter First Binary Number : ";
		cin >> firstBin;
		cout << "Enter Second Binary Number : ";
		cin >> secondBin;
		// Kullanici girdisinde sadece 0 ve 1 olmasi gerektigi icin regexle kontrol edildi eger inpControl deðiskeni false dondurulduyse hata mesaji verildi
		if (regex_match(firstBin, onlyZeroAndOne) && regex_match(secondBin, onlyZeroAndOne))
			inpControl = true;
		else {
			inpControl = false;
			cout << "Please Enter Binary Numbers Correctly!!!(You can only use 0 and 1)\n";
		}
	}
	resultBin = sumOfBinaries(firstBin, secondBin);
	//Yazdirma Islemleri
	cout << "Binary Result of Sum of Binary Numbers : " << resultBin << endl;
	convertBinToInt(resultBin);
	
}
