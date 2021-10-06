class DoSort:
    def __init__(self, do_array):
        self.target_sort = None
        self.do_array = None
        self.swapped_array = None

    def do_print(self):
        print("\n\t%s=\n" % ("=-" * 10))
        print("We do the right %s Sort!!!\n\n" % self.target_sort)
        print("Input array (Before sort) >> \n\t\t", self.do_array)
        print("Output array (After sort) >> \n\t\t", self.swapped_array)
