#include<iostream>
#include<vector>
#include <thread> 
#include <mutex>

std::mutex inside_mutex; 


bool is_point_in_the_circle(std::vector<float> point){
// std::cout << point[0] << ' ' << point[1] << std::endl;
return point[0]*point[0] + point[1]*point[1] < 1;
}

void monte_carlo(int *inside_points, int points){

int outside = 0;

    for (int i = 0; i < points; ++i){
        std::vector<float> point(2);
        for (auto it = point.begin(); it != point.end(); ++it)
            *it = (rand() % 20001) *1e-4 - 1;

        if (is_point_in_the_circle(point) == true){
            const std::lock_guard<std::mutex> lock(inside_mutex);
            *inside_points += 1;
        }
        else{
            outside += 1;
        }
    }

}

int main(){
    
    int inside;
    float res;
    float another_res;

    
    int points;
    points = 100000;
    std::thread first (monte_carlo, &inside, points);     
    std::thread second (monte_carlo, &inside, points); 
  first.join();                // pauses until first finishes
  second.join();               // pauses until second finishes
  
    std::cout << inside << std::endl;
    std::cout << "pi = " << 2.0*inside/points;
    

    return 0;
}