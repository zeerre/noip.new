//*************************************************************************
//* File Name: bucketsort.cpp
//* Author:GeekBear
//* Mail:zeerre98988@gmail.com 
//* Created And Modified Time: ====2022-10-31  20-22-15====
//*************************************************************************

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void display(float *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void bucketSort(float *array, int size) {
   vector<float> bucket[size];
   for(int i = 0; i<size; i++)  {          //put elements into different buckets
      bucket[int(size*array[i])].push_back(array[i]);
   }
   for(int i = 0; i<size; i++) {
      sort(bucket[i].begin(), bucket[i].end());       //sort individual vectors
   }
   int index = 0;
   for(int i = 0; i<size; i++) {
      while(!bucket[i].empty()) {
         array[index++] = *(bucket[i].begin());
         bucket[i].erase(bucket[i].begin());
      }
   }
}
int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   float arr[n];     //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   display(arr, n);
   bucketSort(arr, n);
   cout << "Array after Sorting: ";
   display(arr, n);
}
