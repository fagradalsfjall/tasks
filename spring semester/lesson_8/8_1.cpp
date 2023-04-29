#include<iostream>
#include<vector>
#include <thread> 


bool is_point_in_the_circle(std::vector<float> point){
// std::cout << point[0] << ' ' << point[1] << std::endl;
return point[0]*point[0] + point[1]*point[1] < 1;
}

float monte_carlo(float *res, std::string name){

int inside = 0;
int outside = 0;

    for (int i = 0; i < 10000; ++i){
        std::vector<float> point(2);
        for (auto it = point.begin(); it != point.end(); ++it)
            *it = (rand() % 20001) *1e-4 - 1;

        if (is_point_in_the_circle(point) == true){
            inside += 1;
        }
        else{
            outside += 1;
        }
    }


    float pi = 4.0*inside/(inside + outside);
    *res = pi;
    std::cout << "число пи " << name << " " << pi << std::endl;
    return pi;
}

int main(){
    
    float res;
    float another_res;

    monte_carlo(&res, "Последовательный");
    
    std::thread first (monte_carlo, &res, "Первый");     
    std::thread second (monte_carlo, &another_res, "Второй"); 
  first.join();                // pauses until first finishes
  second.join();               // pauses until second finishes
    
    // std::cout << "res " << res << std::endl;
    // std::cout << "another_res " << another_res << std::endl;
    std::cout << "число пи Параллельный " << (res+another_res)/2;

    return 0;
}