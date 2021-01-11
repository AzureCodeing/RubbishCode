#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//首先需要一个栈，来记录元素FILO
//弹出的时候循环判断是否要弹出
//刚刚压如栈就判断
//判断弹出的条件是栈顶部的元素与没有弹出序列的头是否相等
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty() || popV.empty() ||pushV.size() != popV.size()) return false;
        int index = 0;
        for(auto node: pushV){
            sta.push(node);
            while(!sta.empty() && (sta.top() == popV[index])){
                sta.pop();
                index++;
            }
        }
        //如果栈为空则表示弹出序列争取,否则表示不正确
        return sta.empty() ? true : false;
    }
private:
    std::stack<int> sta;
};

int main(int argc, char *argv[])
{
    Solution pop1, pop2;
    std::vector<int> a = {1, 2, 3, 4, 5};
    std::vector<int> b = {4, 5, 3, 2 ,1};
    std::vector<int> c = {4, 3, 5, 1 ,2};

    std::cout << "b是否为a的弹出顺序: " << pop1.IsPopOrder(a,b) << std::endl;
    std::cout << "c是否为a的弹出顺序: " << pop2.IsPopOrder(a,c)<< std::endl ;

    return 0;
}