//
// Created by 남기륭 on 2021/10/06.
//

#include <iostream>
#include <ctime>
#include <random>
#include "math.h"
#include "Sort.h"

/**
 * - n : 1000
 *
 * BubbleSort : 2545ms
 * SelectionSort : 2055ms
 * InsertionSort : 1263ms
 * QuickSort : 118ms
 * MergeSort : 128ms
 *
 * - n : 10000
 *
 * BubbleSort : 170337ms
 * SelectionSort : 112707ms
 * InsertionSort : 69668ms
 * QuickSort : 837ms
 * MergeSort : 1209ms
 *
 * - n : 100000
 *
 * BubbleSort : 23460300ms
 * SelectionSort : 11158735ms
 * InsertionSort : 7252181ms
 * QuickSort : 10172ms
 * MergeSort : 14778ms
 *
 */

int main()
{
	const int length = 100;
	// 시드값을 얻기 위한 random_device 생성.
	std::random_device rd;
	// random_device 를 통해 난수 생성 엔진을 초기화 한다.
	std::mt19937 gen(rd());
	// 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	std::uniform_int_distribution<int> dis(0, length - 1);

	int src[length];

	for (int i = 0 ; i < length ; ++i)
	{
		src[i] = dis(gen);
	}

	{
		int scratch[length];

		for (int i = 0 ; i < length ; ++i)
		{
			scratch[i] = src[i];
		}

		clock_t startTime = clock();
		Sort::bubbleSort(scratch, length);
		clock_t endTime = clock();
		clock_t elapsed = endTime - startTime;
		std::cout << "BubbleSort : " << elapsed << "ms" << std::endl;

//		for (int i : src)
//		{
//			std::cout << i << " ";
//		}
		std::cout << std::endl;
	}

	{
		int scratch[length];

		for (int i = 0 ; i < length ; ++i)
		{
			scratch[i] = src[i];
		}

		clock_t startTime = clock();
		Sort::selectionSort(scratch, length);
		clock_t endTime = clock();
		clock_t elapsed = endTime - startTime;
		std::cout << "SelectionSort : " << elapsed << "ms" << std::endl;

//		for (int i : src)
//		{
//			std::cout << i << " ";
//		}
		std::cout << std::endl;
	}

	{
		int scratch[length];

		for (int i = 0 ; i < length ; ++i)
		{
			scratch[i] = src[i];
		}

		clock_t startTime = clock();
		Sort::insertionSort(scratch, length);
		clock_t endTime = clock();
		clock_t elapsed = endTime - startTime;
		std::cout << "InsertionSort : " << elapsed << "ms" << std::endl;

		Sort::printArray(scratch, length);
		std::cout << std::endl;
	}

	{
		int scratch[length];

		for (int i = 0 ; i < length ; ++i)
		{
			scratch[i] = src[i];
		}

		clock_t startTime = clock();
		Sort::quickSort(scratch, length);
		clock_t endTime = clock();
		clock_t elapsed = endTime - startTime;
		std::cout << "QuickSort : " << elapsed << "ms" << std::endl;

		Sort::printArray(scratch, length);
		std::cout << std::endl;
	}

	{
		int scratch[length];

		for (int i = 0 ; i < length ; ++i)
		{
			scratch[i] = src[i];
		}

		clock_t startTime = clock();
		Sort::mergeSort(scratch, length);
		clock_t endTime = clock();
		clock_t elapsed = endTime - startTime;
		std::cout << "MergeSort : " << elapsed << "ms" << std::endl;
		Sort::printArray(scratch, length);
		std::cout << std::endl;
	}
}
