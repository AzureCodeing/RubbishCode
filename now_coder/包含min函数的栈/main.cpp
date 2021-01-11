#include <iostream>
#include <stack>

class Solution {
public:
    void push(int value) {
        if(sta.empty()){
            sta_min.push(value);
            sta.push(value);
        }else{
            if(sta_min.top() < value){
                sta_min.push(sta_min.top());
            }else{
                sta_min.push(value);
            }
            sta.push(value);
        }
    }
    void pop() {
        sta.pop();
        sta_min.pop();
    }
    int top() {
        return sta.top();
    }
    int min() {
        return sta_min.top();
    }

private:
    std::stack<int> sta;
    std::stack<int> sta_min;
};

int main(int argc, char *argv[])
{
    Solution a;

    a.push(2);
    a.push(3);
    a.push(7);
    a.push(1);
    
    std::cout << "栈最小值为: " << a.min() << std::endl;
    a.pop();
    std::cout << "栈最小值为: " << a.min() << std::endl;

    return 0;
}