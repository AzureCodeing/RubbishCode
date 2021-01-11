#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* current;
        std::vector<std::vector<int>> result;
        if(root == NULL) return{};
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            vector<int> temp;
            while(len--){
                current = q.front();
                q.pop();//出队列
                if(current == NULL) break;
                q.push(current->left); //入队列
                q.push(current->right); //入队列
                temp.push_back(current->val);
            }
            if(!temp.empty()) result.push_back(temp);
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    /*
             a
            / \
           b   c
          / \   \
         d   e   f
                / \
               g   h
    */

    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    TreeNode g(7);
    TreeNode h(8);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    f.left = &g;
    f.right = &h;

    Solution tree;

    std::vector<std::vector<int>> result = tree.levelOrder(&a);

    std::cout << "前序遍历结果: " << std::endl;
    for(auto elemt: result){
        for(auto nums: elemt){
            std::cout << nums << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}