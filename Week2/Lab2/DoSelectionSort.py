"""
__filename__ = "DoSelectionSort.py"
__author__ = "Ryu"
__email__ = "ryuk9302@gmail.com"
"""

from codingtest.Week2.Lab1 import DoSort as Sort


class DoSelectionSort(Sort.DoSort):
    def __init__(self, do_array):
        self.target_sort = "Selection"
        self.do_array = do_array
        self.swapped_array = do_array.copy()

    def do_sort(self):
        array = self.swapped_array
        for i in range(len(array) - 1):
            min_idx = i
            for j in range(i + 1, len(array)):
                if array[j] < array[min_idx]:
                    min_idx = j
            array[i], array[min_idx] = array[min_idx], array[i]

    def do_print(self):
        super().do_print()
