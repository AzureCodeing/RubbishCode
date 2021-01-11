#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    //非递归
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {   
        if(pHead1 == NULL) return pHead2;
        if(pHead2 == NULL) return pHead1;

        ListNode *new_head = new ListNode(-1);
        ListNode *head = new_head;
        while(pHead1 != NULL && pHead2 != NULL){
            if(pHead1->val > pHead2->val){
                new_head->next = pHead1;
                
                pHead1 = pHead1->next;
            }else{
                new_head->next = pHead2;
                pHead2 = pHead2->next;
            }
            new_head = new_head->next;   
        }
        if(pHead1 == NULL) new_head->next = pHead2;
        if(pHead2 == NULL) new_head->next = pHead1;
    
        return head->next;
    }
    //递归
    ListNode* Merge1(ListNode* pHead1, ListNode* pHead2)
    {   
        if(pHead1 == NULL) return pHead2;
        if(pHead2 == NULL) return pHead1;

        if(pHead1->val > pHead2->val){
            pHead1->next = Merge1(pHead1->next, pHead2);
            return pHead1;
        }else{
            pHead2->next = Merge1(pHead1, pHead2->next);
            return pHead2;            
        }
    }
};

int main(int argc, char *argv[])
{
    ListNode a1(5);
    ListNode b1(4);
    ListNode c1(3);
    ListNode d1(2);

    ListNode a2(8);
    ListNode b2(7);
    ListNode c2(6);
    ListNode d2(1);

    a2.next = &b2;
    b2.next = &c2;
    c2.next = &d2;

    a1.next = &b1;
    b1.next = &c1;
    c1.next = &d1;

    Solution list;

    ListNode *result = list.Merge1(&a1,&a2);
    while(result != NULL){
        std::cout  << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;

    return 0;
}