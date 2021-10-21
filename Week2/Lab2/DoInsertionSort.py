"""
__filename__ = "DoInsertionSort.py"
__author__ = "Ryu"
__email__ = "ryuk9302@gmail.com"
"""

from codingtest.Week2.Lab2 import DoSort as Sort


class DoInsertionSort(Sort.DoSort):
    def __init__(self, do_array):
        self.target_sort = "Insertion"
        self.do_array = do_array
        self.swapped_array = do_array.copy()

    def do_sort(self):
        array = self.swapped_array
        for end in range(1, len(array)):
            to_insert = array[end]
            i = end
            while i > 0 and array[i - 1] > to_insert:
                array[i] = array[i - 1]
                i -= 1
            array[i] = to_insert

    def do_print(self):
        super().do_print()
