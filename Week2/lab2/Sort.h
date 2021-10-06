//
// Created by 남기륭 on 2021/10/06.
//

#pragma once

#include <iostream>

namespace Sort
{
	/**
	 * 값이 크다고 정해 놓은 것이 위로 계속 올라가도록
	 * @param src
	 * @param length
	 */
	void bubbleSort(int* src, int length);

	/**
	 * 최솟값을 찾아 선택한다고 해서 선택 정렬
	 * @param src
	 * @param length
	 */
	void selectionSort(int* src, int length);

	/**
	 * 외부는 고정된 횟수, 내부는 비교에 따라 결정되므로 while
	 * @param src
	 * @param length
	 */
	void insertionSort(int* src, int length);

	/**
	 * 재귀 + 분할
	 * @param src
	 * @param length
	 */
	void quickSort(int* src, int length);

	void quickRecursive(int* src, int start, int end);

	int partition(int* src, int start, int end);

	void mergeSort(int src[], int length);

	void mergeRecursive(int dest[], int start, int end);

	void merge(int dest[], int start, int midPosition, int end);

	void printArray(int src[], int length);
}
