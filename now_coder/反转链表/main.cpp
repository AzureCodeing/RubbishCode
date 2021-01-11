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
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL) return NULL;
        ListNode* prev = NULL;
        ListNode* pnext = pHead;
        
        while(pnext){
            pHead = pnext; //更新当前节点
            pnext = pHead->next; //记录当前节点的下一个节点
            pHead->next = prev; //节点反向
            prev = pHead; //记录前一个节点
        }
        return pHead;
    }
};


int main(int argc, char *argv[])
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);

    a.next = &b;
    b.next = &c;
    c.next = &d;

    Solution list;

    ListNode *result = list.ReverseList(&a);

    while(result != NULL){
        std::cout << result->val << " "; 
        result = result->next;
    }
    std::cout << std::endl;

    return 0;
}
