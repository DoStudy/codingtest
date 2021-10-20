"""
__filename__ = "DoTest.py"
__author__ = "Ryu"
__email__ = "ryuk9302@gmail.com"
"""

from codingtest.Week2.Lab1.DoBubbleSort import DoBubbleSort
from codingtest.Week2.Lab1.DoSelectionSort import DoSelectionSort
from codingtest.Week2.Lab1.DoInsertionSort import DoInsertionSort
from codingtest.Week2.Lab1.DoQuickSort import DoQuickSort
from codingtest.Week2.Lab1.DoMergeSort import DoMergeSort

from codingtest.Week2.Ass1.DoBinarySearchTree import DoBinarySearchTree


if __name__ == "__main__":
    # input_array = [1, 5, 4, 3, 2]
    # bubble = DoBubbleSort(input_array)
    # bubble.do_sort()
    # bubble.do_print()
    #
    # selection = DoSelectionSort(input_array)
    # selection.do_sort()
    # selection.do_print()
    #
    # insertion = DoInsertionSort(input_array)
    # insertion.do_sort()
    # insertion.do_print()
    #
    # Quick = DoQuickSort(input_array)
    # Quick.do_sort()
    # Quick.do_print()
    #
    # Merge = DoMergeSort(input_array)
    # Merge.do_sort()
    # Merge.do_print()

    se = DoBinarySearchTree()
    se.do_set_root(10)
