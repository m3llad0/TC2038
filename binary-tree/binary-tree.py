# Graph theory
# Build a binary tree with the numbers {11,6,8,19,4,10,5,17,43,49,31}

# import csv

import numpy as np


# elements = []
# [11,6,8,19,4,10,5,17,43,49,31]

def getElements():
    with open("elements.csv") as elementscsv:
        elements = np.loadtxt(elementscsv, delimiter = ',')

    return elements

class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.value = data

class Tree:
    def __init__(self):
        self.root = None

    def getRoot(self):
        return self.root

    def add(self, value):
        if self.root is None:
            self.root = Node(value)
        else:
            self._add(value, self.root)

    def _add(self, value, node):
        if value < node.value:
            if node.left is not None:
                self._add(value, node.left)
            else:
                node.left = Node(value)
        else:
            if node.right is not None:
                self._add(value, node.right)
            else:
                node.right = Node(value)

    def printTree(self):
        if self.root is not None:
            self._printTree(self.root)

    def _printTree(self, node):
        if node is not None:
            # print(node.value)
            self._printTree(node.left)
            print(str(node.value) + ' ')
            self._printTree(node.right)

def main():

    elements = getElements()
    tree = Tree()

    for element in elements:
        tree.add(element)

    tree.printTree()

main()