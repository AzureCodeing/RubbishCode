#!/usr/bin/python2
#coding=utf-8

class Solution:
    def __init__(self):
        self.output_stack = []
        self.append_stack = []

    def push(self, node):
        # write code here
        self.append_stack.append(node)

    def pop(self):
        # return xx
        if self.output_stack == []:
            while self.append_stack:
                self.output_stack.append(self.append_stack.pop())
        
        return self.output_stack.pop()


if __name__ == "__main__":
    a = Solution()
    a.push(1)
    a.push(2)
    a.push(3)
    a.push(4)

    print("first: ", a.pop())
    print("second: ", a.pop())
    print("third: ", a.pop())