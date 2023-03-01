#include<iostream>
#include<chrono>
#include<windows.h>
#include<vector>
#include <algorithm>
#include <array>
#include<deque>
#include<list>
#include<forward_list>

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


        count += elapsed_seconds.count();
    }

    void resume(){
        begin_time = std::chrono::steady_clock::now();
    }

     double elapsed_seconds(){
        return count;
    }

};

template <typename container>
void izmerenie(container data, std::string name){

SuperTimer timer;
    timer.start();

    std::sort(data.begin(), data.end());

    timer.stop();

    std::cout << name << ": " << timer.elapsed_seconds() << "s\n";

}


template <typename container>
void izmerenie_list(container data, std::string name){

SuperTimer timer;
    timer.start();

    data.sort();

    timer.stop();

    std::cout << name << ": " << timer.elapsed_seconds() << "s\n";

}


int main()
{
    const int N = 100000;

    std::vector<int> vector(N);
    std::array<int, N> array;
    std::deque<int> deque;
    std::list<int> list;
    std::forward_list<int> forward_list;


    for (int i = 0; i < vector.size(); i++) {
        vector[i] = rand();
        array[i] = vector[i];
        deque.push_back(vector[i]);
        list.push_back(vector[i]);
        forward_list.push_front(vector[N-1-i]);
    }

    izmerenie(vector, "vector");
    izmerenie(array, "array");
    izmerenie(deque, "deque");
    izmerenie_list(list, "list");
    izmerenie_list(forward_list, "forward_list");

}

