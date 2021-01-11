#include <iostream>
#include <ctime>

int main(int argc, char *argv[])
{

    clock_t startTime,endTime;
    startTime = clock();
    for(int i = 0; i < 100000; i++);
    endTime = clock();

    std::cout << "花费: " << double (endTime - startTime)/CLOCKS_PER_SEC  << " S" << std::endl;
    return 0;
}