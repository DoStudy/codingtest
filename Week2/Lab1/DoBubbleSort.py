"""
__filename__ = "DoBubbleSort.py"
__author__ = "Ryu"
__email__ = "ryuk9302@gmail.com"
"""

import DoSort as Sort


class DoBubbleSort(Sort.DoSort):
    def __init__(self, do_array):
        self.target_sort = "Bubble"
        self.do_array = do_array
        self.swapped_array = do_array.copy()

    def do_sort(self):
        array = self.swapped_array
        end = len(array) - 1
        while end > 0:
            last_swap = 0
            for i in range(end):
                if array[i] > array[i + 1]:
                    array[i], array[i + 1] = array[i + 1], array[i]
                    last_swap = i
            end = last_swap

    def do_print(self):
        super().do_print()
