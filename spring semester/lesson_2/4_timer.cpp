#include <iostream>
#include <chrono>
#include <windows.h>
 
long fibonacci(unsigned n)
{
    if (n < 2) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

class SuperTimer{

    public:
    
    std::chrono::time_point< std::chrono::steady_clock > end_time;

    std::chrono::time_point< std::chrono::steady_clock > begin_time;

    double count;

    

    void start(){
        begin_time = std::chrono::steady_clock::now();
        count = 0;
    }

     void stop(){
        end_time = std::chrono::steady_clock::now();
        pause();
    }

    void pause(){
        std::chrono::time_point< std::chrono::steady_clock > end_time = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end_time - begin_time;

        std::cout << "add to count" << elapsed_seconds.count() << std::endl;
        count += elapsed_seconds.count();
    }

    void resume(){
        begin_time = std::chrono::steady_clock::now();
    }

     double elapsed_seconds(){
        return count;
    }

};
 
int main()
{
    SuperTimer timer;
    timer.start();
    std::cout << "f(42) = " << fibonacci(42) << '\n';
    timer.pause();
    Sleep(1000);
    timer.resume();
    Sleep(400);
    timer.stop();
    std::cout << "elapsed time: " << timer.elapsed_seconds() << "s\n";

}

