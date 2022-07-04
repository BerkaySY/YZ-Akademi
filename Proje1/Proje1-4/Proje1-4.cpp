#include <iostream>
//opencv kutuphanesini kullanmak icin
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

// Sistem Saatini elde etmek icin kullanilan kutuphaneler
#include <chrono>
#include <ctime>
// 'ctime': This function or variable may be unsafe. Hatasini Devre Disi Birakmak Ýcin Yazildi
#pragma warning(disable : 4996)

using namespace cv;
using namespace std;

// Sistemden tarih ve saat degerlerini alan ve string olarak döndüren fonksiyon
string getDateTimeNow() {
	auto time = chrono::system_clock::now();
	time_t now = chrono::system_clock::to_time_t(time);
	string dateTimeNow = ctime(&now);
	dateTimeNow.pop_back(); //Cektigim tarih ve saatin stringinde en sonda ? oluyordu onu silmek icin kullandim.
	return dateTimeNow;
}

int main() {
	// Videoyu acmak icin videocapture kullanarak bulundugu konumu belirttim.
	VideoCapture vidCapture("testvideos/video3.mp4");
	// videocapture sonucunda video acilmamissa hata döndürdüm.
	if (!vidCapture.isOpened())
		cout << "Error!! Couldn't open video!\n";
	
	// Videonun en boy ve fps degerlerini degiskenlere atadim
	int frame_width = vidCapture.get(CAP_PROP_FRAME_WIDTH);
	int frame_height = vidCapture.get(CAP_PROP_FRAME_HEIGHT);
	int fps = vidCapture.get(CAP_PROP_FPS);
	
	// Videonun VideoWriterla kaydetme islemi
	VideoWriter video("kayit.mp4",VideoWriter::fourcc('M', 'P', '4', 'V'), fps, Size(frame_width, frame_height));

	// VideoCapture sonucunda video acilmissa yapilacak islemler
	while (vidCapture.isOpened()) {
		Mat frame;
		// Videonun framelerini yakalamak icin
		vidCapture >> frame;
		// Frame okuma islemi basariliysa videonun sol üst kösesine tarih saat bilgisi yazildi ve video gösterildi.
		if (!frame.empty()) {
			putText(frame, getDateTimeNow(), Point(0, 25), FONT_HERSHEY_SIMPLEX, 1, Scalar(0,0,255), 2, LINE_8);
			video.write(frame);
			imshow("Video", frame);
			
		}
		// Frame okuma islemi basarili degilse kullaniciya hata donduruldu.
		else {
			cout << "Video disconnected" << endl;
			break;
		}
		
		// s tusuna basildiginda videoyu durdurmasi icin
		int key = waitKey(15);
		if (key == 's')
			break;
		;
		
	}
	// videocapture ve videowriteri serbest býrak ve acik olan bütün pencereleri kapat
	vidCapture.release();
	video.release();
	destroyAllWindows();
	return 0;
}