//bdrhsen
#include <iostream>
#include <chrono>

using namespace std;

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {
    //First copy the original array to 2 different arrays

    int n1 = q - p + 1;
    int n2 = r - q;
//n1 is the number of elements in n1 and n2 is the ...
    int A[n1], B[n2];

    for (int i = 0; i < n1; i++)
        A[i] = arr[p + i]; // copying the content of the original array to subarrays
    for (int j = 0; j < n2; j++)
        B[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]

    // we have 3 pointers each points to a different array we are checking whether if the current index value corresponds to a smaller element in comparison and change the indexes after every iteration
    while (i < n1 && j < n2) {
        if (A[i] <= B[j]) {
            arr[k] = A[i];
            i++;
        } else {
            arr[k] = B[j];
            j++;
        }
        k++;
    }
    //After this procedure we will most likely run out of elements in one of the arrays if that happens we can just copy the remaining elements inside the other list.

    while (i < n1) {
        arr[k] = A[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = B[j];
        j++;
        k++;
    }
}

//Divide and conquer approach we first apply the mergesort to subarrays and create sub arrays of subarrays end merge them
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m); // applying the function to smaller pieces first
        mergeSort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    srand(time(0));
    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now();

    std::cout << "Hello, World!" << std::endl;
    int array_size = 100000;

    int arr[array_size];
    for (int l;l<array_size;l++){
        arr[l]=rand()+1; //create random integers and fill the array with them

    }
    mergeSort(arr,0,array_size-1);
    end = std::chrono::system_clock::now();
    cout << "Sorting the array... \n" ;
    printArray(arr,array_size);

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    return 0;
}
