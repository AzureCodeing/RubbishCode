#!/usr/bin/python2
#coding=utf-8

class Solution:
    def minNumberInRotateArray(self, rotateArray):
        if rotateArray == []:
            return 0
        # write code here
        left = 0
        right = len(rotateArray) - 1
        while left <= right :
            middle = (right + left) >> 1
            if rotateArray[middle] < rotateArray[middle - 1]:
                return rotateArray[middle]
            elif rotateArray[middle] < rotateArray[right]:
                right = middle - 1
            else:
                left = middle + 1

if __name__ == "__main__":
    a = Solution()
    array = [4,5,6,1,2,3]
    print("min_num = ", a.minNumberInRotateArray(array))

    