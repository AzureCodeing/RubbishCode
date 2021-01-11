#!/usr/bin/python2
#coding=utf-8

class Solution:
    def __init__(self):
        self.stack = []

    def IsPopOrder(self, pushV, popV):
        # write code here                
        if pushV and popV and len(pushV) != len(popV):
            return False
        index = 0
        for node in pushV:
            self.stack.append(node)
            while self.stack and self.stack[-1] == popV[index]:
                self.stack.pop()
                index = index + 1
        if self.stack == []:
            return True
        else:
            return False

if __name__ == "__main__":
    sol = Solution()

    a = [1,2,3,4,5]
    b = [4,5,3,2,1]
    c = [4,3,5,1,2]
    
    print("a is pop order b ? ",sol.IsPopOrder(a,b))
    print("a is pop order b ? ",sol.IsPopOrder(a,c))