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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(!pListHead || k <= 0) return NULL;
        ListNode *left = pListHead;
        ListNode *right = pListHead;

        for(int i = 0; i < k; i++){
            if(!right) return NULL;
            right = right->next;
        }
        while(right){
            right = right->next;
            left = left->next;
        }
        // std::cout << "result: " << left->val << std::endl;
        return left;
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
    
    ListNode* result = list.FindKthToTail(&a, 1);

    std::cout << "result: " << result->val << std::endl;
    return 0;
}