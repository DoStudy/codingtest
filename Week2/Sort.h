#pragma once
#include <iostream>
using namespace std;

void bubbleSort(int InputArray[], int length) {
	int count = 0;
	for (int i = 0; i < length - 1; i++) {
		count++;
		for (int j = 0; j < length - count; j++) {
			if (InputArray[j] > InputArray[j + 1]) {
				int temp = InputArray[j];
				InputArray[j] = InputArray[j + 1];
				InputArray[j + 1] = temp;
			}
		}
	}
	return;
}

void selectionSort(int InputArray[], int length) {
	for (int i = 0; i < length - 1; i++) {
		int min = INT_MAX;
		int index = 0;
		for (int j = i; j < length; j++) {
			if (InputArray[j] < min) {
				min = InputArray[j];
				index = j;
			}
		}
		int temp = InputArray[i];
		InputArray[i] = min;
		InputArray[index] = temp;
	}
	return;
}

void insertionSort(int InputArray[], int length) {
	for (int i = 1; i < length; i++) {
		int checkValue = InputArray[i];
		for (int j = i - 1; j >= 0; j--) {
			if (checkValue < InputArray[j]) {
				InputArray[j + 1] = InputArray[j];
				if (j == 0) {
					InputArray[0] = checkValue;
				}
				continue;
			}
			else {
				InputArray[j + 1] = checkValue;
				break;
			}
		}
	}
	return;
}

void QuickSort(int InputArray[], int length, int left, int right) {
	if (length == 0)
		return;
	int PivotIndex = left;
	int Pivot = InputArray[PivotIndex];
	int Low = left + 1;
	int High = right;
	while (true) {
		while (true) {
			if (InputArray[Low] > Pivot || Low > right)
				break;
			Low++;
		}
		while (true) {
			if (InputArray[High] <= Pivot || High <= left)
				break;
			High--;
		}
		if (Low >= High)
		{
			int temp = InputArray[High];
			InputArray[High] = InputArray[PivotIndex];
			InputArray[PivotIndex] = temp;
			PivotIndex = High;
			break;
		}
		if (Low < High) {
			int temp = InputArray[Low];
			InputArray[Low] = InputArray[High];
			InputArray[High] = temp;
		}
	}
	if (PivotIndex - 1 > left)
		QuickSort(InputArray, length, left, PivotIndex - 1);
	if (PivotIndex + 1 < right)
		QuickSort(InputArray, length, PivotIndex + 1, right);
	return;
}

void MergeSort(int InputArray[], int length, int left, int right, int resultArray[]) {
	if (left < right) {
		int mid = (left + right) / 2;
		MergeSort(InputArray, length, left, mid, resultArray);
		MergeSort(InputArray, length, mid + 1, right, resultArray);

		int i = left;
		int j = mid + 1;
		int k = left;
		while (true) {
			if (i > mid || j > right)
				break;
			if (InputArray[i] <= InputArray[j])
			{
				resultArray[k] = InputArray[i];
				i++;
				k++;
			}
			else {
				resultArray[k] = InputArray[j];
				j++;
				k++;
			}
		}
		int RemainIndex = i > mid ? j : i;
		while (true) {
			if (k > right)
				break;
			resultArray[k] = InputArray[RemainIndex];
			k++;
			RemainIndex++;
		}
		for (int i = left; i <= right; i++) {
			InputArray[i] = resultArray[i];
		}
	}
	return;
}