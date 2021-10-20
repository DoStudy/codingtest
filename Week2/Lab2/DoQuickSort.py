"""
__filename__ = "DoQuickSort.py"
__author__ = "Ryu"
__email__ = "ryuk9302@gmail.com"
"""

from codingtest.Week2.Lab1 import DoSort as Sort


class DoQuickSort(Sort.DoSort):
    def __init__(self, do_array):
        self.target_sort = "Quick"
        self.do_array = do_array
        self.swapped_array = do_array.copy()

    def do_sort(self):
        array = self.swapped_array

        def sort(low, high):
            if high <= low:
                return

            mid = do_partition(low, high)
            sort(low, mid - 1)
            sort(mid, high)

        def do_partition(low, high):
            pivot = array[(low + high) // 2]
            while low <= high:
                while array[low] < pivot:
                    low += 1
                while array[high] > pivot:
                    high -= 1
                if low <= high:
                    array[low], array[high] = array[high], array[low]
                    low, high = low + 1, high - 1
            return low

        sort(0, len(array) - 1)

    def do_print(self):
        super().do_print()
