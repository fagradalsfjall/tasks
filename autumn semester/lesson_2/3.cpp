#include <iostream>
#include <vector>

using namespace std;

int search(int t, vector<int> a)
{
    int l = 0;
    int r = a.size() - 1;
    while (l <= r)
    {
        int m = (l + r)/2;
        if (a[m] < t)
        
            l = m + 1;
        else 
        {
            if(a[m] > t)
            r = m - 1;
            else
            return m;
        }
            
    }
    return -1;
}

int main() {
    
    int size;
    cin >> size;
    vector<int> a(size);
    
    for (int i = 0; i < a.size(); i++)
        a[i] = rand() % 100;
       
    for (int i = 1; i < a.size(); i++)
    {
        int j = i;
        while (j > 0 && a[j-1] > a[j])
            
        {
            swap(a[j], a[j-1]);
            j--;
        }
    }

for (int i = 0; i < a.size(); i++)
       cout << a[i] << " ";

cout << endl;

int t;
cin >> t;
int b = search (t, a);
cout << b;

    return 0;

}