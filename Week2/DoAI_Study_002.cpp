#include <iostream>
#include <time.h>
#include <random>
#include "Sort.h"
using namespace std;

const int length = 1500;
// 시드값을 얻기 위한 random_device 생성.
std::random_device rd;
// random_device 를 통해 난수 생성 엔진을 초기화 한다.
std::mt19937 gen(rd());
// 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
std::uniform_int_distribution<int> dis(0, length - 1);

void RunBubble(int InputData[]) {
	clock_t start, finish;
	double duration;
	int InputDataSize = length;
	start = clock();
	bubbleSort(InputData, InputDataSize);
	finish = clock();
	duration = (double)(finish - start);
	/*for (int i = 0; i < length; i++) {
		cout << InputData[i] << " ";
	}*/
	cout << "Bubble Sort : " << duration << "ms" << endl;
}

void RunSelection(int InputData[]) {
	clock_t start, finish;
	double duration;

	int InputDataSize = length;
	start = clock();
	selectionSort(InputData, InputDataSize);
	finish = clock();
	duration = (double)(finish - start);
	/*for (int i = 0; i < length; i++) {
		cout << InputData[i] << " ";
	}*/
	cout << "Selection Sort : " << duration << "ms" << endl;
}

void RunInsertion(int InputData[]) {
	clock_t start, finish;
	double duration;

	int InputDataSize = length;
	start = clock();
	insertionSort(InputData, InputDataSize);
	finish = clock();
	duration = (double)(finish - start);
	/*for (int i = 0; i < length; i++) {
		cout << InputData[i] << " ";
	}*/
	cout << "Insertion Sort : " << duration << "ms" << endl;
}

void RunQuick(int InputData[]) {
	clock_t start, finish;
	double duration;

	int InputDataSize = length;
	start = clock();
	QuickSort(InputData, InputDataSize, 0, InputDataSize - 1);
	finish = clock();
	duration = (double)(finish - start);
	/*for (int i = 0; i < length; i++) {
		cout << InputData[i] << " ";
	}*/
	cout << "Quick Sort : " << duration << "ms" << endl;
}

void RunMerge(int InputData[]) {
	clock_t start, finish;
	double duration;

	int InputDataSize = length;
	start = clock();
	int* ResultArray = new int[length];
	MergeSort(InputData, InputDataSize, 0, InputDataSize - 1, ResultArray);
	finish = clock();
	duration = (double)(finish - start);
	/*for (int i = 0; i < length; i++) {
		cout << InputData[i] << " ";
	}*/
	cout << "Merge Sort : " << duration << "ms" << endl;
}

int main()
{
	int src[length];

	for (int i = 0; i < length; ++i)
	{
		src[i] = dis(gen);
	}

	RunBubble(src);
	for (int i = 0; i < length; ++i)
	{
		src[i] = dis(gen);
	}
	RunSelection(src);
	for (int i = 0; i < length; ++i)
	{
		src[i] = dis(gen);
	}
	RunInsertion(src);
	for (int i = 0; i < length; ++i)
	{
		src[i] = dis(gen);
	}
	RunQuick(src);
	for (int i = 0; i < length; ++i)
	{
		src[i] = dis(gen);
	}
	RunMerge(src);

}