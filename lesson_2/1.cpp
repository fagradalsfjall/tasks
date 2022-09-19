#include <iostream>
using namespace std;

int main() {
    
    int n, m;

    cout << "Number of rows: ";
    cin >> n;
    cout << "Number of columns: ";
    cin >> m;
    
    cout << "Enter the augmented matrix: " << endl;

    float A[n][m];

    for(int i = 0; i < n; ++i)
       { 
            for(int j = 0; j < m; ++j) 
            {
                cin >> A[i][j];
                cout << " ";
            }
            
            cout << endl;
       }

    for (int i = 0; i < n; i++) 
    {
        for (int k = m - 1; k >= i; k--)
            A[i][k] = A[i][k]/A[i][i];

        for (int j = 0; j < n; j++)
        {
            float a;
            if (j != i)
            {
                a = A[j][i]/A[i][i];
                for (int k = i; k < m; k++)
                {
                    A[j][k] = A[j][k]-a*A[i][k];
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << A[i][j] << " ";
    
        cout << endl;
    }
    
    return 0;
}
