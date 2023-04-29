#include<vector>
#include<iostream>
#include <algorithm>
#include <chrono>
#include <execution>


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

int main(){

    std::vector<int> vec(3000000);

    for (auto it = vec.begin(); it != vec.end(); ++it)
            *it = rand() % 100 * 1.0 / 10;


    SuperTimer timer;
    timer.start();
    // std::sort(vec.begin(), vec.end());
    std::sort(std::execution::par_unseq, vec.begin(), vec.end());
    timer.stop();

    std::cout << "elapsed time: " << timer.elapsed_seconds() << "s\n";

    return 0;



}