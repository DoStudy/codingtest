from DoBubbleSort import DoBubbleSort
from DoSelectionSort import DoSelectionSort
from DoInsertionSort import DoInsertionSort


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

