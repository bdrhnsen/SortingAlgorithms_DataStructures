#include <iostream>
#include <chrono>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubbleSort(int arr[], int n){
    int i, k;
    for (i = 0; i < n-1; i++){ //n-1 times tries
        for (k = 0; k < n-i-1; k++){
            if (arr[k] > arr[k+1]){ // literally checking one by one simplest algorithm
                swap(&arr[k], &arr[k+1]);}}
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
    bubbleSort(arr,array_size);
    end = std::chrono::system_clock::now();
    cout << "Sorting the array... \n" ;
    printArray(arr,array_size);

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    return 0;
}
