#include <iostream>
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
    //等长法
    ListNode* FindFirstCommonNode1( ListNode* pHead1, ListNode* pHead2) {
        ListNode* temp1 = pHead1, *temp2 = pHead2;
        int len_1 = 0, len_2 = 0; 
        while(temp1 != NULL || temp2 != NULL){
            if(temp1 != NULL){ 
                len_1++;
                temp1 = temp1->next;
            }
            if(temp2 != NULL){
                 len_2++;
                 temp2=temp2->next;
            }
        }
        // int num = abs(len_1 - len_2); //计算两个链表之间的长度差

        temp1 = pHead1;
        temp2 = pHead2;
        if(len_1 > len_2){
            for(int i = 0; i < abs(len_1 - len_2); i++){
                temp1 = temp1->next;    
            }
        }else if(len_1 < len_2){
            for(int i = 0; i < abs(len_1 - len_2); i++){
                temp2 = temp2->next;
            }
        }

        while(temp1 != NULL && temp2 != NULL){
            if(temp1 == temp2) return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }

    //最优解:利用两个链表和是等长的
    ListNode* FindFirstCommonNode2( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == NULL || pHead2 == NULL) return NULL;
        ListNode *temp1 = pHead1, *temp2 = pHead2;
        while(temp1 != temp2){
            temp1 = temp1 == NULL? pHead2 : temp1->next;
            temp2 = temp2 == NULL? pHead1 : temp2->next;  
        }
        return temp1;
    }
};

int main(int argc, char *argv[])
{
    ListNode a1(1);
    ListNode b1(2);
    ListNode c1(3);
    ListNode d1(4);
    ListNode e1(5);
    ListNode f1(10);

    ListNode a2(6);

    // a1->b1->c1->d1->e1->f1
    a1.next = &b1;
    b1.next = &c1;
    c1.next = &d1;
    d1.next = &e1;
    e1.next = &f1;

    // a2->d1->e1->f1
    a2.next = &e1;

    Solution list;

    ListNode *result = list.FindFirstCommonNode2(&a1, &a2);

    std::cout << result->val << std::endl;

    return 0;
}