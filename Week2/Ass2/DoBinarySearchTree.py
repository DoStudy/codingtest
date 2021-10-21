"""
__filename__ = "DoBinarySearchTree.py"
__author__ = "Ryu"
__email__ = "ryuk9302@gmail.com"
"""
from codingtest.Week2.Ass2.DoNode import *


class DoBinarySearchTree(DoNode):
    def __init__(self):
        self.do_root = None

    def do_insert(self, do_data):
        self.do_root = self.do_insert_data(self.do_root, do_data)
        return self.do_root is not None

    def do_insert_data(self, do_node, do_data):
        if do_node is None:
            do_node = DoNode(do_data)

        else:
            if do_data <= do_node.do_data:
                do_node.do_left = self.do_insert_data(do_node.do_left, do_data)
            else:
                do_node.do_left = self.do_insert_data(do_node.do_left, do_data)

        return do_node

    def do_delete(self):
        pass

    def do_find(self):
        pass

    # def do_print(self):
    #     print("\n\t%s=\n" % ("=-" * 10))
    #     print("\n\t\t")

