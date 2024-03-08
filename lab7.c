#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct myElement{
    int data;
    int numSwaps;
} myElement;

myElement* selectionSort(myElement* arr, int size, int* totSwaps);
myElement* bubbleSort(myElement* arr, int size, int* totSwaps);
void printArr(myElement* arr, int size, int totSwaps);

int main(){

    int inputArr1[9]= {97, 16, 45, 63,  13,  22,  7,  58,  72};
    int inputArr2[9]= {90,  80,  70,  60,  50,  40,  30,  20,  10};
    int i;

    myElement* originalArr1 = (myElement*) malloc(sizeof(myElement) * 9);

    for(i=0; i < 9; i++){
        originalArr1[i].data= inputArr1[i];
        originalArr1[i].numSwaps = 0;
    }

    myElement* originalArr2 = (myElement*) malloc(sizeof(myElement) * 9);

    for(i=0; i < 9; i++){
        originalArr2[i].data= inputArr2[i];
        originalArr2[i].numSwaps = 0;
    }

    int totSwaps= 0;

    myElement* bubbleArr1= bubbleSort(originalArr1, 9, &totSwaps);
    printf("Array 1 after bubble sort\n -------------- \n");
    printArr(bubbleArr1, 9, totSwaps);
    totSwaps= 0;

    myElement* bubbleArr2= bubbleSort(originalArr2, 9, &totSwaps);
    printf("Array 2 after bubble sort\n -------------- \n");
    printArr(bubbleArr2, 9, totSwaps);
    totSwaps= 0;


    myElement* selectionArr1= selectionSort(originalArr1, 9, &totSwaps);
    printf("Array 1 after selection sort\n -------------- \n");
    printArr(selectionArr1, 9, totSwaps);
    totSwaps= 0;

    myElement* selectionArr2= selectionSort(originalArr2, 9, &totSwaps);
    printf("Array 2 after selection sort\n -------------- \n");
    printArr(selectionArr2, 9, totSwaps);
    totSwaps= 0;

    // free(originalArr1);
    // free(originalArr2);

    return 0;
}

myElement* selectionSort(myElement* arr, int size, int* totSwaps){
    int i, j, min_idx;
    myElement temp;

    myElement* newArr= (myElement*) malloc(sizeof(myElement)* size);
    memcpy(newArr, arr, sizeof(myElement) * size);


    for (i = 0; i < size-1; i++){
        min_idx = i;

        for (j = i+1; j < size; j++){
            if (newArr[j].data < newArr[min_idx].data)
                min_idx = j;
        }
        
        temp = newArr[i];
        newArr[i] = newArr[min_idx];

        newArr[min_idx] = temp;

        if(min_idx != i){
            *totSwaps += 1;
            newArr[i].numSwaps+= 1;
            newArr[min_idx].numSwaps+= 1;
        } 
    }

    return newArr;
}


myElement* bubbleSort(myElement* arr, int size, int* totSwaps){
    myElement temp;
    
    myElement* newArr= (myElement*) malloc(sizeof(myElement)* size);
    memcpy(newArr, arr, sizeof(myElement) * size);

    for(int i=0; i < size; i++){
        for(int j=0; j < size - i - 1; j++){
            if(newArr[j].data > newArr[j+1].data){
                temp= newArr[j];
                newArr[j] = newArr[j+1];
                newArr[j].numSwaps+= 1;

                newArr[j+1] = temp;
                newArr[j+1].numSwaps+= 1;
                *totSwaps += 1;
            }
        }
    }

    return newArr;
}

void printArr(myElement* arr, int size, int totSwaps){
    printf("Number of swaps for each element: \n");
    for(int i=0; i < size; i++){
        printf("%d: %d\n", arr[i].data, arr[i].numSwaps);
    }
    printf("Total number of swaps: %d\n\n", totSwaps);

    // free(arr);
    return;
}