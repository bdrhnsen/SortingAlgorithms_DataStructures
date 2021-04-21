#include <iostream>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void SelectionSort(int arr[], int n){
    int i, j, index_of_min;


    for(int i=0;i<n-1;i++){
        index_of_min=i;
        for(int k=i+1;k<n;k++){
            if(arr[k]<arr[index_of_min]){ //finding the smallest element and its index
                index_of_min=k;
            }

        }
        swap(&arr[i],&arr[index_of_min]);
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
    std::cout << "Hello, World!" << std::endl;
    int array_size = rand()%100+1;

    int arr[array_size];
    for (int l;l<array_size;l++){
       arr[l]=rand()%50+1;
        cout<<arr[l];
    }
    SelectionSort(arr,array_size);
    cout << "Sorting the array... \n" ;
    printArray(arr,array_size);

    return 0;
}
