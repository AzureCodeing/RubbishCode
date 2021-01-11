#!/usr/bin/python2
#coding=utf-8
class Solution:
    def jumpFloorII(self, number):
        # write code here
        print("台阶数：　", number)
        #方法一: 迭代法
        if number == 1:
            return 1
        last = 1
        result = 0
        for i in range(2, number + 1):
            result = 2*last
            last = result
        print("方法一: ", result)
        #方法二: 公式法
        print("方法二: ", pow(2, number - 1))

if __name__ == "__main__":
    jump = Solution()
    n = 4
    jump.jumpFloorII(n)
    