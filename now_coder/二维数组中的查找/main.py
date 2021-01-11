#!/usr/bin/python2
#coding=utf-8

class Solution:
    # array 二维列表
    #方法一: 遍历整个二维数组 时间复杂度O(n^2)
    def Find1 (self, target, array):
        for i in range(len(array)):
            for j in range(len(array[0])):
                if(array[i][j] == target):
                    return True
        return False

    #方法二: 利用数组特性 时间复杂度为O(logn)
    def Find2(self, target, array):
        i = 0
        j = len(array[0]) - 1
        while i < len(array) and j >= 0:
            if array[i][j] > target:
                j = j - 1
            elif array[i][j] < target:
                i = i + 1
            else:
                return True
        return False
        # write code here

if __name__ == "__main__":
    a = Solution()
    array = [[1,3,5,7],[2,4,6,8],[5,6,7,11],[7,9,12,13]]
    target = 23
    print("方法一: ", a.Find1(target, array))
    print("方法二: ", a.Find2(target, array))