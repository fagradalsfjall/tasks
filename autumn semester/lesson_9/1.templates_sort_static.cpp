#include <iostream>
using namespace std;

template<typename A,typename Compare>
void merge(A arr[], int p, int q, int l, Compare comparator) {
  
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
      
    if (comparator(arr1[i],arr2[j])) {
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

template<typename A, typename Compare>
void merge_sort(A arr[], int l, int r, Compare comparator) {
  if (l < r) {
   
    int m = l + (r - l) / 2;

    merge_sort(arr, l, m, comparator);
    merge_sort(arr, m + 1, r, comparator);

    merge(arr, l, m, r, comparator);
  }
  
}

template<typename A, std::size_t N,typename Compare>
void merge_sort(A (& arr) [N], Compare comparator) {
    merge_sort(arr, 0, N - 1, comparator);
}


int main() {


int a [] = { 1 ,2 ,3 ,4 };
   
    const int len = 5;
    // cin >> len;
    double arr[len];
    // double arr[] = {1.5, 2.5, 3, 1, 2};
    printf("~~~~~~~~~~~~~~~~~~~~");
    for (int i = 0; i < len; i++)
        arr[i] = rand() % 100 * 1.0 / 10;
        
    for (int i = 0; i < len; i++)
       cout << arr[i] << " ";
       
    cout << endl;
       
    merge_sort(arr, std::less<double>());
    merge_sort(arr, std::greater<double>());

    for (int i = 0; i < len; i++)
       cout << arr[i] << " ";
      
    
 return 0;   
}