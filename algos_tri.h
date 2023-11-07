#include <stdio.h>
#include <stdlib.h>

void afficher_table(int *t, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ,", *(t + i));
    }
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void shellSort(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortHelper(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(int arr[], int size) {
    quickSortHelper(arr, 0, size - 1);
}




void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int *t,int size){
    if(size <=1 ){
        return;
    }
    int mid = size/2;
    int *left=(int*)malloc(sizeof(int)*mid);
    int *right=(int*)malloc(sizeof(int)*(size-mid));

    for (int i = 0; i < mid; i++)
    {
        left[i]=t[i];
    }
    for (int i = mid; i < size; i++)
    {
        right[i-mid]=t[i];
    }
    
    merge_sort(left,mid);
    merge_sort(right,size-mid);
     merge(t, left, mid, right, size - mid);

    free(left);
    free(right);
    
}


void bulles(int *t, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (t[j] > t[j + 1])
            {
                swap(&t[j], &t[j + 1]);
            }
        }
    }
}

void selection(int *t, int size)
{
    int imin;
    for (int i = 0; i < size - 1; i++)
    {
        imin = i;
        for (int j = i + 1; j < size; j++)
        {
            if (t[j] < t[imin]){
                imin = j ;
            }
        }
        swap(&t[i],&t[imin]);
    }
}

void insertion(int *t, int size){
    int j,tmp;
    for (int i = 1; i < size; i++)
    {
        tmp = t[i];
        j=i-1;
        while (j>=0 && t[j]>tmp)
        {
            t[j+1] = t[j];
            j--;
        }
        t[j+1]=tmp;
    }
    
}

