#!/usr/bin/python2
#coding=utf-8
class Solution:
    def __init__(self):
        self.stack = []
        self.min_stack = []

    def push(self, node):
        # write code here
        if(self.stack == []):
            self.stack.append(node)
            self.min_stack.append(node)
        else:
            if(self.min_stack[-1] < node):
                self.min_stack.append(self.min_stack[-1])
            else:
                self.min_stack.append(node)
            self.stack.append(node)

    def pop(self):
        # write code here
        self.stack.pop()
        self.min_stack.pop()

    def top(self):
        # write code here
        return self.stack[-1]

    def min(self):
        # write code here
        return self.min_stack[-1]

if __name__ == "__main__":
    a = Solution()
    a.push(2)
    a.push(7)
    a.push(4)
    a.push(1)
    
    print("min_value: ", a.min())
    
    a.pop()

    print("min_value: ", a.min())