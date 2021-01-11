#include <iostream>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* slow = pHead;
        ListNode* fast = pHead->next;

        //1. 判断是否有环
        while(fast != NULL && slow != fast){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //2. 得到环的元素个数
        int num = 0;
        while(fast->next != slow){
            fast = fast->next;
            num++;
        }

        // //3. 得到入口节点
        slow = pHead;
        fast = pHead->next;
        while(num--) fast = fast->next;

        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
            std::cout << "fast" << fast->val << std::endl;
        }
        
        return fast;
    }
};


int main(int argc, char *argv[])
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    ListNode f(6);
    ListNode g(7);
    ListNode h(8);
    ListNode i(9);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    g.next = &h;
    h.next = &i;

    //环
    i.next = &e;

    Solution List;

    ListNode *result = List.EntryNodeOfLoop(&a);

    std::cout << "result: " << result->val << std::endl;

    return 0;
}