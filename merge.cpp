#include <iostream>
#include <sys/time.h>
// #include <sys/resource.h>

using namespace std;

// Merge two sorted subarrays into a single sorted subarray without auxiliary arrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create a temporary array to hold the merged subarray
    int temp[n1 + n2];

    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy the merged array back into the original array
    for (i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }
}

// Recursive function to perform Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // struct rusage r_usage;
    // getrusage(RUSAGE_SELF, &r_usage);
    // long start_time = r_usage.ru_utime.tv_sec * 1000000 + r_usage.ru_utime.tv_usec;

    // Perform Merge Sort
    mergeSort(arr, 0, n - 1);

    // getrusage(RUSAGE_SELF, &r_usage);
    // long end_time = r_usage.ru_utime.tv_sec * 1000000 + r_usage.ru_utime.tv_usec;

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // cout << "Time taken: " << (end_time - start_time) << " microseconds" << endl;
    // cout << "Space complexity: O(log n) (due to the recursive call stack)" << endl;

    return 0;
}
