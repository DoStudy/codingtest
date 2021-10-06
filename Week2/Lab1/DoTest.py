from DoBubbleSort import DoBubbleSort
from DoSelectionSort import DoSelectionSort
from DoInsertionSort import DoInsertionSort
from DoQuickSort import DoQuickSort
from DoMergeSort import DoMergeSort


if __name__ == "__main__":
    input_array = [1, 5, 4, 3, 2]
    bubble = DoBubbleSort(input_array)
    bubble.do_sort()
    bubble.do_print()

    selection = DoSelectionSort(input_array)
    selection.do_sort()
    selection.do_print()

    insertion = DoInsertionSort(input_array)
    insertion.do_sort()
    insertion.do_print()

    Quick = DoQuickSort(input_array)
    Quick.do_sort()
    Quick.do_print()

    Merge = DoMergeSort(input_array)
    Merge.do_sort()
    Merge.do_print()
