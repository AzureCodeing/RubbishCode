#include <iostream>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL) return NULL;
        RandomListNode *old_node = pHead;
        //第一步将复制的节点与旧节点交替链接
        while(old_node != NULL){
            RandomListNode *new_node = new RandomListNode(old_node->label); //新建节点
            //将新节点插入到旧节点之间     1 2 3 4 -> 1 1 2 2 3 3 4 4
            new_node->next = old_node->next;
            old_node->next = new_node;
            old_node = new_node->next;
        }  
        //第二步复制旧节点的random指向的地址
        old_node = pHead;
        while(old_node != NULL){
            RandomListNode * new_node = old_node->next;
            if(old_node->random != NULL)
                new_node->random = old_node->random->next;
            old_node = new_node->next;
        }
        //第三步将新旧节点之间断开
        old_node = pHead;
        RandomListNode *result = pHead->next;
        while(old_node != NULL){
            RandomListNode * new_node = old_node->next;
            old_node->next = new_node->next;
            old_node = old_node->next; //经过上一步操作此时上一个旧节点与新节点断开
            if(old_node) new_node->next = old_node->next;
        }

        return result;
    }
};

int main(int argc, char *argv[])
{
    RandomListNode a(1);
    RandomListNode b(2);
    RandomListNode c(3);
    RandomListNode d(4);

    a.next = &b;
    b.next = &c;
    c.next = &d;

    a.random = &c;
    b.random = &b;
    c.random = &b;
    d.random = &a;

    Solution list;

    RandomListNode *result = list.Clone(&a);
    while(result != NULL){
        std::cout << "random: " << result->label << "->" << result->random->label << "\tdress: " << result->random<< std::endl;
        result = result->next;
    }
    return 0;
}