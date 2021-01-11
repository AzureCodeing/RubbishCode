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
    //方法一: 装入数组输出时颠倒
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> temp;
        while(head != NULL){
            // std::cout << head->val << " ";
            temp.push_back(head->val);
            head = head->next;
        }
        std::cout << std::endl;

        //返回从右边到左边的数组
        return {temp.rbegin(), temp.rend()};
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

    std::vector<int> result;
    result = list.printListFromTailToHead(&a);

//------------结果验证---------------
    for(auto res:result){
        std::cout << res << " ";
    }
    std::cout << std::endl;

    return 0;
}