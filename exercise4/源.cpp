#include <iostream>
#include <opencv.hpp>
#include <stdlib.h>
using namespace cv;
int main() {
	float histgram[256];
	for (int i = 0; i < 256; i++) {
		histgram[i] = 0;
	}
	cv::Mat srcMat = imread("D:\\1.jpg", 0);
	imshow("¡¾Ô­Í¼¡¿", srcMat);
	int height = srcMat.rows;
	int width = srcMat.cols*srcMat.channels();
	int totalpixel;
	totalpixel = width * height;
	for (int j = 0; j < height; j++) {
		uchar* data = srcMat.ptr<uchar>(j);
		for (int i = 0; i < width; i++) {
			int index = data[i];
			histgram[index] = histgram[index] + 1;

		}
	}
	int max = 0;
	for (int i = 0; i < 256; i++)
	{
		if (histgram[i] > max)  max = histgram[i];
		std::cout << histgram[i] << std::endl;
	}
	Mat drawImage = Mat::zeros(Size(256, 256), CV_8UC3);

	for (int i = 0; i < 256; i++)

	{

		int value = cvRound(histgram[i] * 256 * 0.9 / max);

		line(drawImage, Point(i, drawImage.rows - 1), Point(i, drawImage.rows - 1 - value), Scalar(255, 0, 0));
		std::cout << "Value " << i << " = " << value << std::endl;


	}

	std::cout << totalpixel << std::endl;
	imshow("¡¾Ö±·½Í¼¡¿", drawImage);

	waitKey(0);

	return 0;

}