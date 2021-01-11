#!/usr/bin/python2
#coding=utf-8
    
class Solution:
    def reOrderArray(self, array):
        # write code here
        for i in range(len(array) - 1):
            for j in range(len(array) - i - 1):
                if array[j] % 2 == 0 and array[j+1] % 2 == 1:
                    array[j], array[j+1] = array[j+1], array[j]

                
if __name__ == "__main__":
    array = [1,2,3,4,5,6,7,8]
    a = Solution()

    a.reOrderArray(array)
    print(array)