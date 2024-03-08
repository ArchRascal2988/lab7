#include <stdlib.h>
#include <stdio.h>

myElement* selectionSort(int* arr, int size, int* totSwaps);
myElement* bubbleSort(int* arr, int size, int* totSwaps);
int printArr(myElement* arr, int size, int totSwaps);

typedef struct myElement{
    int data;
    int numSwaps;
} myElement;

int main(){

    int inputArr1[9]= {97, 16, 45, 63,  13,  22,  7,  58,  72};
    int inputArr2[9]= {90,  80,  70,  60,  50,  40,  30,  20,  10};

    myElement* originalArr1 = (myElement*) malloc(sizeof(myElement) * 9);
    myElement* originalArr2 = (myElement*) malloc(sizeof(myElement) * 9);

    int totSwaps= 0;
    myElement* selectionArr1= selectionSort(originalArr1, 9, &totSwaps);
    myElement* selectionArr2= selectionSort(originalArr2, 9, &totSwaps);

    myElement* bubbleArr1= bubbleSort(originalArr1, 9, &totSwaps);
    free(originalArr1);

    myElement* bubbleArr2= bubbleSort(originalArr2, 9, &totSwaps);
    free(originalArr2);



    return 0;
}

myElement* selectionSort(myElement* arr, int size, int* totSwaps){
    int i, j, min_idx;
    myElement temp;


    for (i = 0; i < size-1; i++){
        min_idx = i;

        for (j = i+1; j < size; j++){
            if (arr[j].data < arr[min_idx].data) 
                min_idx = j;
        }
        
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[i].numSwaps++;

        arr[min_idx] = temp;
        arr[min_idx].numSwaps++;

        *totSwaps ++;
    }

    return arr;
}


myElement* bubbleSort(myElement* arr, int size, int* totSwaps){
    myElement temp;

    for(int i=0; i < size; i++){
        for(int j=i; j < size - 1; j++){
            if(arr[j].data > arr[j+1].data){
                temp= arr[j];
                arr[j] = arr[j+1];
                arr[j].numSwaps++;

                arr[j+1] = temp;
                arr[j+1].numSwaps++;
                *totSwaps ++;
            }
        }
    }

    return arr;
}

int printArr(myElement* arr, int size, int totSwaps){
    for()
}