"""
__filename__ = "DoMergeSort.py"
__author__ = "Ryu"
__email__ = "ryuk9302@gmail.com"
"""

import DoSort as Sort


class DoMergeSort(Sort.DoSort):
    def __init__(self, do_array):
        self.target_sort = "Merge"
        self.do_array = do_array
        self.swapped_array = do_array.copy()

    def do_sort(self):
        array = self.swapped_array

        def sort(low, high):
            if high - low < 2:
                return
            mid = (low + high) // 2
            sort(low, mid)
            sort(mid, high)
            do_merge(low, mid, high)

        def do_merge(low, mid, high):
            temp = []
            l, h = low, mid

            while l < mid and h < high:
                if array[l] < array[h]:
                    temp.append(array[l])
                    l += 1
                else:
                    temp.append(array[h])
                    h += 1

            while l < mid:
                temp.append(array[l])
                l += 1
            while h < high:
                temp.append(array[h])
                h += 1

            for i in range(low, high):
                array[i] = temp[i - low]

        sort(0, len(array))

    def do_print(self):
        super().do_print()
