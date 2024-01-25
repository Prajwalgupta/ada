#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
void selectionSort(int arr[], int n)
{
int i, j, mini;
for (i = 0; i < n - 1; i++) {
mini = i;
for (j = i + 1; j < n; j++) {
if (arr[j] < arr[mini])
mini = j;
}
if (mini != i)
swap(arr[mini], arr[i]);
}
}
void printArray(int arr[], int size)
{
int i;
for (i = 0; i < size; i++) {
cout << arr[i] << " ";
cout << endl;
}
}
int main()
{
int n;
cout<<"Enter the size of the array:"<<endl;
cin>>n;
int arr[n];
cout<<"Enter the array:"<<endl;
for(int i=0;i<n;i++){
cin>>arr[i];
}
selectionSort(arr, n);
cout << "Sorted array: \n";
printArray(arr, n);
auto quickSortStartTime = chrono::high_resolution_clock::now();
selectionSort(arr, n - 1);
auto selecttionSortEndTime = chrono::high_resolution_clock::now();
chrono::duration<double> selectionSortExecutionTime = (selecttionSortEndTime - quickSortStartTime)/1.0e6 * CLOCKS_PER_SEC;
cout << "Selection Sort Execution Time: " << selectionSortExecutionTime.count() << " microseconds.\n";
cout << "Space used by Selection Sort: " << sizeof(arr) + n * sizeof(arr[0]) << " bytes.\n";
return 0;
}
