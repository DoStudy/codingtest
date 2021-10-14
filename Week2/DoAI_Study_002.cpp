#include <iostream>
#include <time.h>
#include <random>
#include "Sort.h"
using namespace std;

const int length = 1500;
// �õ尪�� ��� ���� random_device ����.
std::random_device rd;
// random_device �� ���� ���� ���� ������ �ʱ�ȭ �Ѵ�.
std::mt19937 gen(rd());
// 0 ���� 99 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.
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