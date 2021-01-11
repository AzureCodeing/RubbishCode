#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);//将节点入栈
    }

    int pop() {
        if(stack1.empty() && stack2.empty()) return 0; //防止错误
        int output;
        if(stack2.empty()){
            while(!stack1.empty()){ //将stack1中的元素压入stack2中
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
            output = stack2.top();
            stack2.pop();       
        return output;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(int argc, char *argv[])
{
    Solution a;
    
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);

    std::cout << "元素一出队列: " << a.pop();
    std::cout << "\t元素二出队列: " << a.pop();
    std::cout << "\t元素三出队列: " <<  a.pop();
    std::cout << "\t元素四出队列: " << std::endl;
    return 0;
}