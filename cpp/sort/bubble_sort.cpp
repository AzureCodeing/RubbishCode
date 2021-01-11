#include <iostream>
#include <vector>
using namespace std;

std::vector<int> a = {1, 4, 5, 9, 2, 3, 5};

void sort(std::vector<int> &array)
{
    for(int i = 0; i < array.size(); i++){
        for(int j = 0; j < array.size() - i - 1; j++){
            if(array[j] > array[j + 1]){
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }    
}

int main(int argc, char *argv[])
{
    sort(a);
    for(auto vec: a){
        std::cout << vec;
    }
    std::cout << std::endl;
}