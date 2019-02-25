#include <stdio.h>

// A most basic implementation of the Partition function.
// Simply selects the last element of the array as pivot.
// Takes a reference to the head of the array and the beginning and ending indices of the array to be sorted.
// Partitions the array and returns the final index of the pivot.
int Partition(int * a, int p, int r){
	// (flag + 1) is used to keep track of the final index of the pivot.
	int flag = p - 1;
	// Rearrange the array so that elements smaller than the pivot are placed in the left part of the array.
	for(int i = p; i < r; i++){
		if(a[i] < a[r]){
			flag++;
			int temp = a[i];
			a[i] = a[flag];
			a[flag] = temp;
		}
	}
	// Place the pivot in the right place.
	int temp = a[flag + 1];
	a[flag + 1] = a[r];
	a[r] = temp;
	// Returns the final index of the pivot.
	return flag + 1;
}

// The Quicksort main function.
// Takes a reference to the head of the array and the beginning and ending indices of the array to be sorted.
// Gets the array sorted recursively and returns nothing.
void Quicksort(int * a, int p, int r){
	if(p < r){
		// Do the sorting only if the array has more than one elements.
		int q = Partition(a, p, r);
		Quicksort(a, p, q - 1);
		Quicksort(a, q + 1, r);
	}
	return;
}

int main(){
	// Read in the length of the array and then the whole array.
	int arrayLength;
	printf("Please input the length of the array: ");
	scanf("%d", &arrayLength);
	int array[arrayLength];
	printf("Please input %d integer values:\n", arrayLength);
	for(int i = 0; i < arrayLength; i++){
		scanf("%d", &array[i]);
	}

	// Print out the original array.
	printf("The original array is: ");
	for(int i = 0; i < arrayLength; i++){
		printf("%d ", array[i]);
	}
	printf("\n");

	// Call the Quicksort function. In this case, the whole array is sorted.
	Quicksort(array, 0, arrayLength - 1);

	// Print out the sorted array.
	printf("The sorted array is:");
	for(int i = 0; i < arrayLength; i++){
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}
