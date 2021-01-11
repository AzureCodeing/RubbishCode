class Solution:
    def MoreThanHalfNum_Solution(self, numbers):
        # write code here
        numbersCount = 0
        lastNumber = 0
        for num in numbers:
            if numbersCount == 0:
                lastNumber = num
                numbersCount = 1
            else:
                if lastNumber == num:
                    numbersCount += 1
                else:
                    numbersCount -= 1
        if numbersCount == 0:
            return 0
        else:
            numberCount = 0
            for num in numbers:
                if lastNumber == num:
                    numbersCount += 1
        if numbersCount > (len(numbers)>>1):
            return lastNumber
        return 0