#include<vector>
#include<iostream>
#include <algorithm>

std::vector<int>::iterator search(std::vector<int>::iterator l, std::vector<int>::iterator r, int ischem)
{
    auto end_data = r;
    while (l <= r)
    {
        int tt = (r-l)/2;
        auto m = l + tt;
        if (*m < ischem)
        
            l = m + 1;
        else 
        {
            if(*m > ischem)
            r = m - 1;
            else
            return m;
        }
            
    }
    return end_data;
}


int main(){


    std::vector<int> vec(7);

    for (auto it = vec.begin(); it != vec.end(); ++it)
            *it = rand() % 100 * 1.0 / 10;

    std::sort(vec.begin(), vec.end());

    for (auto it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";

    auto result = search(vec.begin(), vec.end(), 5);

    std::cout << std::endl << result - vec.begin() << std::endl;

    return 0;
}