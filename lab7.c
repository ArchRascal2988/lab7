#include <stdlib.h>
#include <stdio.h>

int* selectionSort(int* arr, int size);
int* bubbleSort(int* arr, int size);

int main(){

    int originalArr1[9]= {97, 16, 45, 63,  13,  22,  7,  58,  72};
    int originalArr2[9]= {90,  80,  70,  60,  50,  40,  30,  20,  10};

    int* selectionArr1= selectionSort(originalArr1, 9);
    int* selectionArr2= selectionSort(originalArr2, 9);

    int* bubbleArr1= bubbleSort(originalArr1, 9);
    int* bubbleArr2= bubbleSort(originalArr2, 9);


     printf("hi");

    return 0;
}

int* selectionSort(int* arr, int size){
    int i, j, min_idx, temp;

    for (i = 0; i < size-1; i++){
        min_idx = i;

        for (j = i+1; j < size; j++){
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }

    return arr;
}


int* bubbleSort(int* arr, int size){
    int temp;

    for(int i=0; i < size; i++){
        for(int j=i; j < size - 1; j++){
            if(arr[j] > arr[j+1]){
                temp= arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }


    return arr;
}