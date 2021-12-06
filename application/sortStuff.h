
int auxVector[VECTOR_SIZE];

// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
    int j;
    for (j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

/* Function to print an array */
void printArray(int arr[], int start, int end) 
{ 
    int i; 
    for (i = start; i <= end; i++) 
        printf("%d, ",arr[i]);
    printf("\n");
} 

/* Merges two sorted vectors into one */
void mergeSort(int arr[], int low_1, int high_1, int low_2, int high_2){
    int i, j, k;
    i = low_1;
    j = low_2;
    for(k = 0; k < (high_1-low_1)+(high_2-low_2)+2; k++){
        if((arr[i] < arr[j] && i <= high_1) || j >  high_2){
            auxVector[k] = arr[i];
            i++;
        } else{
            auxVector[k] = arr[j];
            j++;
        }
    }
    for(k=0; k < (high_1-low_1)+(high_2-low_2)+2; k++){
        arr[k+low_1] = auxVector[k];
    }
}
