#include<vector>
#include<iostream>
#include<algorithm>
#include<array>
#include<set>
#include<chrono>

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


int main(){

const int N = 1000000;

    std::vector<int> vector(N);
    std::array<int, N> array;
    std::set<int> set;

    for (int i = 0; i < vector.size(); i++) {
        vector[i] = rand();
        array[i] = vector[i];

    }


    SuperTimer timer;
    timer.start();

    for (int i = 0; i < vector.size(); i++) {
        set.insert(vector[i]);
    }

    timer.stop();
    std::cout << "set: " << timer.elapsed_seconds() << "s\n";

    izmerenie(vector, "vector");
    izmerenie(array, "array");


    return 0;
}