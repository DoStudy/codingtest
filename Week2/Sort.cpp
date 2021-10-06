//
// Created by 남기륭 on 2021/10/06.
//
/**
 * - 왜 QuickSort가 MergeSort보다 빠른가?
 * https://cs.stackexchange.com/questions/3/why-is-quicksort-better-than-other-sorting-algorithms-in-practice
 */
#include "Sort.h"

namespace Sort
{
	void bubbleSort(int* src, int length)
	{
		for (int i = 0 ; i < length - 1 ; ++i)
		{
			for (int j = 0 ; j < length - i - 1 ; ++j)
			{
				if (src[j] > src[j + 1])
				{
					int temp = src[j];
					src[j] = src[j + 1];
					src[j + 1] = temp;
				}
			}
		}
	}

	void selectionSort(int* src, int length)
	{
		int minIndex;

		for (int i = 0 ; i < length - 1 ; ++i)
		{
			minIndex = i; // 바깥 루프의 인덱스가 바꿀 위치를 지정

			// 최솟값 찾기
			for (int j = i + 1 ; j < length ; ++j)
			{
				if (src[j] < src[minIndex])
				{
					minIndex = j;
				}
			}

			int temp = src[minIndex];
			src[minIndex] = src[i];
			src[i] = temp;
		}
	}

	void insertionSort(int* src, int length)
	{
		for (int i = 1 ; i < length ; ++i)
		{

			int prevIndex = i - 1;
			int currentValue = src[i];

			while (prevIndex >= 0 && currentValue < src[prevIndex])
			{
				int temp = src[prevIndex];
				src[prevIndex] = src[prevIndex + 1];
				src[prevIndex + 1] = temp;
				prevIndex--;
			}
		}
	}

	void quickSort(int* src, int length)
	{
		quickRecursive(src, 0, length - 1);
	}

	void quickRecursive(int* src, int start, int end)
	{
		if (start >= end)
		{
			return;
		}

		int pivotPos = partition(src, start, end);

		quickRecursive(src, start, pivotPos - 1);
		quickRecursive(src, pivotPos + 1, end);
	}

	int partition(int* src, int start, int end)
	{
		int pivot = src[end]; // 가장 오른쪽 요소를 기준값으로 사용

		int i = (start - 1); // 나중에 기준 Index와 바꿀 부분 pivotPos를 찾는 Index

		for (int j = start ; j < end ; ++j)
		{
			if (src[j] < pivot)
			{
				++i;
				int temp = src[j];
				src[j] = src[i];
				src[i] = temp;
			}
		}

		int pivotPos = i + 1;
		int temp = src[end];
		src[end] = src[pivotPos];
		src[pivotPos] = temp;

		return pivotPos;
	}

	void mergeSort(int src[], int length)
	{
		mergeRecursive(src, 0, length - 1);
	}

	void mergeRecursive(int dest[], int start, int end)
	{
		if (start == end)
		{
			return;
		}

		int midPosition = (start + end) / 2;

		mergeRecursive(dest, start, midPosition);
		mergeRecursive(dest, midPosition + 1, end);
		merge(dest, start, midPosition, end);
	}

	void merge(int dest[], int start, int midPosition, int end)
	{
		int leftSideStart = start;
		int rightSideStart = midPosition + 1;
		int mergedResultIndex = 0;

		int mergedResult[end - start + 1];

		while (leftSideStart <= midPosition && rightSideStart <= end)
		{
			if (dest[leftSideStart] <= dest[rightSideStart])
			{
				mergedResult[mergedResultIndex] = dest[leftSideStart];
				leftSideStart++;
				mergedResultIndex++;
			}
			else
			{
				mergedResult[mergedResultIndex] = dest[rightSideStart];
				rightSideStart++;
				mergedResultIndex++;
			}
		}

		if (leftSideStart > midPosition)
		{
			for (int i = rightSideStart ; i <= end ; ++i)
			{
				mergedResult[mergedResultIndex] = dest[i];
				mergedResultIndex++;
			}
		}
		else
		{
			for (int i = leftSideStart ; i <= midPosition ; ++i)
			{
				mergedResult[mergedResultIndex] = dest[i];
				mergedResultIndex++;
			}
		}

		int mergedResultToDestIndex = 0;
		for (int i = start ; i <= end ; ++i)
		{
			dest[i] = mergedResult[mergedResultToDestIndex];
			mergedResultToDestIndex++;
		}
	}

	void printArray(int src[], int length)
	{
		for (int i = 0 ; i < length ; ++i)
		{
			std::cout << src[i] << " ";
		}
		std::cout << std::endl;
	}
}
