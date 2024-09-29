#include <bits/stdc++.h> //  this is the header file which includes all the necessary header files
using namespace std;

void selectionSort(int arr[], int size)
{
      for (int i = 0; i < size - 1; i++){ // Iterate through the array from the first element to the second-to-last element
            // int smallest=INT_MAX; // Initialize the smallest element as the maximum possible integer value
            int smallest=i; // Initialize the smallest element as the current element
            for(int j=i+1;j<size-1;j++){ // Iterate through the remaining unsorted elements of the array
               if(arr[j]<arr[smallest]){ // If a smaller element is found
                  smallest=j; // storing the index of the smallest element
               }

               if(arr[smallest]<arr[i]){ // If the smallest element is smaller than the current element
                  swap(arr[i],arr[smallest]); // Swap the smallest element with the current element
               }   

            }
      }
}

int main()
{
      // Prompt the user to enter the size of the array
      int n;
      cin >> n;

      // Declare an array of size n to store the elements
      int arr[n];

      // Read the elements of the array from the user
      for (int i = 0; i < n; i++)
      {
            cin >> arr[i];
      }

      // Call the selectionSort function to sort the array
      selectionSort(arr, n);

      // Print the sorted array
      for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
      }

      // Return 0 to indicate successful execution of the program
      return 0;
}