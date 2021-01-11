#include <iostream>
#include <future>
#include <thread>

//类模板 std::future 提供访问异步操作结果的机制：

int main()
{
    std::packaged_task<int()> task([](){return 7;}); //包装函数
    std::future<int> f1 = task.get_future(); //获取future
    std::thread(std::move(task)).detach(); //在线程上运行

    //from async() 的 future
    std::future<int> f2 = std::async(std::launch::async, [](){return 8;});

    //from promise 的 future
    std::promise<int> p;
    std::future<int> f3 = p.get_future();
    std::thread([&p]{p.set_value_at_thread_exit(9);}).detach();

    std::cout << "Waiting ... " << std::flush;
    f1.wait();
    f2.wait();
    f3.wait();

    std::cout << "Done! \n Results are:"
              << f1.get() << " " << f2.get() << " " << f3.get() << std::endl;
}
