
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex i_mutex;   
char dna[N+1];
char symbols[] = {'A', 'G' ,'C', 'T'};

void generate_dna(){

    for (int i = 0; i < N; i++)
        dna[i] = symbols[rand() % 4];
    dna[N] = 10;
}

void search(char* str_what, char* str_where, int size, std::vector<int>* result, int offset){
    int j;
    for (int i = 0; i < size; i++) {
        for (j = 0; str_what[j]==str_where[i+j]; j++){};
        if (str_what[j] == 0){
            
            const std::lock_guard<std::mutex> lock(i_mutex);
            result->push_back(i + offset);
        }
    }


}

int main(){

    generate_dna();

    char stroka[50] = "TT";
    // std::cin >> stroka;
    std::vector<int> result;
    // search(stroka, dna, N, &result);

    
    std::cout << dna << std::endl;

    std::thread first (search, stroka, dna, N/2, &result, 0);     
    std::thread second (search, stroka, dna + N/2, N/2, &result, N/2); 
     first.join();                // pauses until first finishes
     second.join();               // pauses until second finishes
    

    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << " " << std::endl;
    return 0;
}