#include <iostream>
#include <fstream>
#include <string>
 
int main()
{
    std::string filename = "oooooooo.txt";
 
    std::ofstream ostrm(filename);

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            char bukva = rand()%26 + 65;
            ostrm << bukva;
            
        }
        ostrm << std::endl;
    }

    double d = 3.14;
 
    char bukva;
    int i = 0;

    std::ifstream istrm(filename, std::ios::binary);
    if (!istrm.is_open())
        std::cout << "failed to open " << filename << '\n';
    else
    {    
        do
        {  
            istrm.get(bukva);
            i += 1;
        } while (bukva != '\n');

        int stroka;
        std::cin >> stroka;
        istrm.seekg(stroka * i);

        for(int j = 0; j < i; j++){
            istrm.get(bukva);
            std::cout << bukva;
        }

        std::cout << std::endl;
    }



}