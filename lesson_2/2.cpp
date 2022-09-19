#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int size;
    cin >> size;
    vector<int> a(size);

    for (int i = 0; i < a.size(); i++)
        a[i] = rand() % 100;
        
    for (int i = 0; i < a.size(); i++)
       cout << a[i] << " ";
       
    for (int i = 1; i < a.size(); i++)
    {
        int j = i;
        while (j > 0 && a[j-1] > a[j])
        {
            swap(a[j], a[j-1]);
            j--;
        }
    }
    
cout << endl;

for (int i = 0; i < a.size(); i++)
       cout << a[i] << " ";

return 0;

}