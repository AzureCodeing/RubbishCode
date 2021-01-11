#!/usr/bin/python2
#coding=utf-8

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, listNode):
        array = []
        
        while(listNode):
            array.append(listNode.val)
            listNode = listNode.next
        array.reverse()
        return array
        # write code here

if __name__ == "__main__":
    a = ListNode(1)
    b = ListNode(2)
    c = ListNode(3)
    d = ListNode(4)

    a.next = b
    b.next = c
    c.next = d

    listreverse = Solution()
    
    array = listreverse.printListFromTailToHead(a)

    print(array)

