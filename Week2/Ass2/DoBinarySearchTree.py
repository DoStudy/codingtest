"""
__filename__ = "DoBinarySearchTree.py"
__author__ = "Ryu"
__email__ = "ryuk9302@gmail.com"
"""
from codingtest.Week2.Ass1.DoNode import *


class DoBinarySearchTree(DoNode):
    def __init__(self):
        self.do_root = None

    def do_set_root(self, do_data):
        self.do_root = DoNode(do_data)
