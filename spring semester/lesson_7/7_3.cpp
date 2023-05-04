#include <fstream>
#include <iostream>
#include <filesystem>
#include <algorithm>
#include <chrono>
#include <ctime>

std::string to_string(std::filesystem::file_time_type const& ftime) {
    std::time_t cftime = std::chrono::system_clock::to_time_t(
        std::chrono::file_clock::to_sys(ftime));
    std::string str = std::asctime(std::localtime(&cftime));
    str.pop_back();  
    return str;
}

int main(){
    
const std::filesystem::path sandbox{"."};

for (auto const& dir_entry : std::filesystem::directory_iterator{sandbox}) 
    {
        std::cout << dir_entry.path().stem().string() << '\n';
        std::cout << dir_entry.path().extension().string() << '\n';
        std::cout << to_string(dir_entry.last_write_time())
                  << " : " << dir_entry.path().filename() << '\n';
        std::cout << std::endl;
    }
    


return 0;
}