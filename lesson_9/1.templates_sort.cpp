#include <iostream>
using namespace std;

template<typename A>
void merge(A arr[], int p, int q, int l) {
  
  int len_arr1 = q - p + 1;
  int len_arr2 = l - q;

  A arr1[len_arr1], arr2[len_arr2];

  for (int i = 0; i < len_arr1; i++)
    arr1[i] = arr[p + i];
    
  for (int j = 0; j < len_arr2; j++)
    arr2[j] = arr[q + 1 + j];

  int i = 0;
  int j = 0;
  int k = p;

  while (i < len_arr1 && j < len_arr2) {
      
    if (arr1[i] <= arr2[j]) {
      arr[k] = arr1[i];
      i++;
    } 
    
    else {
      arr[k] = arr2[j];
      j++;
    }
    
    k++;
  }
  
  while (i < len_arr1) {
      
    arr[k] = arr1[i];
    i++;
    k++;
    
  }

  while (j < len_arr2) {
      
    arr[k] = arr2[j];
    j++;
    k++;
    
  }
  
}

template<typename A>
void merge_sort(A arr[], int l, int r) {
  if (l < r) {
   
    int m = l + (r - l) / 2;

    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
  
}

template<typename A>
void merge_sort(A arr[], int r) {
    merge_sort(arr, 0, r);
}


int main() {
    
    int len = 5;
    // cin >> len;
    double arr[len];

    for (int i = 0; i < len; i++)
        arr[i] = rand() % 100 * 1.0 / 10;
        
    for (int i = 0; i < len; i++)
       cout << arr[i] << " ";
       
    cout << endl;
       
    merge_sort(arr, len-1);
    
    for (int i = 0; i < len; i++)
       cout << arr[i] << " ";
      
    
 return 0;   
}