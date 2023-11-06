#include<stdio.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void heapify(int arr[], int N, int i)
{
	int smallest = i; 
	int l = 2 * i + 1;
	int r = 2 * i + 2; 


	if (l < N && arr[l] < arr[smallest])
		smallest = l;

	
	if (r < N && arr[r] < arr[smallest])
		smallest = r;


	if (smallest != i) {
		swap(&arr[i], &arr[smallest]);

		heapify(arr, N, smallest);
	}
}


void buildHeap(int arr[], int N)
{

	int startIdx = (N / 2) - 1;

	int i;
	for ( i = startIdx; i >= 0; i--) {
		heapify(arr, N, i);
	}
}


void insert(int *N, int arr[], int val) {
    (*N)++;
    int current = *N - 1;
    arr[current] = val;

    while (current > 0 && arr[current] < arr[(current - 1) / 2]) {
        swap(&arr[current], &arr[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
}






int deletemin(int *N, int arr[]) {
    if (*N == 0) {
        
        return -1; 
    }

    int minVal = arr[0];
    arr[0] = arr[*N - 1];
    (*N)--; 

  
    heapify(arr, *N, 0);

    return minVal;
}



void printHeap(int arr[], int N)
{
	printf("Array representation of Heap is:\n");
    int i;
	for ( i = 0; i < N; ++i)
		printf("%d ",arr[i]);
	printf("\n");
}


int main()
{

	int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};

	int N = sizeof(arr) / sizeof(arr[0]);

	
	buildHeap(arr, N);
	printHeap(arr,N);
	printf("\n");
      
    
    insert(&N, arr, 2); 
    printf("after inserting an element:\n");
    printHeap(arr, N);

     
    
    int min = deletemin(&N, arr); 
    printf("Deleted min element: %d\n", min);

    printHeap(arr, N);

	return 0;
}