// A most basic implemention of the quicksort algorithm.
// This version of quicksort is not stable because of the swapping.

#include <stdio.h>

// The function to swap two integer values.
void swap(int * a, int * b) {
	int temp = * a;
	* a = * b;
	* b = temp;
}

// A most basic implementation of the partition function.
// Simply selects the last element of the array as pivot.
// Takes a reference to the head of the array and the beginning and ending indices of the subarray to be partitioned.
// Rearranges and partitions the subarray and returns the final index of the pivot.
int partition(int * a, int p, int r) {
	// (flag) keeps track of the final index of the pivot.
	int flag = p;
	// Rearrange the array so that elements smaller than the pivot (a[r]) are placed in the left part of the array.
	for (int i = p; i < r; i++) {
		if (a[i] < a[r]) {
			swap(&a[i], &a[flag]);
			flag++;
		}
	}
	// Place the pivot in the right place.
	swap(&a[r], &a[flag]);
	// Return the final index of the pivot.
	return flag;
}

// The quicksort main function.
// Takes a reference to the head of the array and the beginning and ending indices of the portion of array to be sorted.
// Applies the divide-and-conquer strategy and partitions the array recursively.
// After all recursive partitions the array will be sorted.
void quicksort(int * a, int p, int r) {
	if (p < r) {
		// Do the sorting only if the array has more than one element.
		// Get the final position of the pivot after partition.
		int q = partition(a, p, r);
		// Partition the array recursively.
		// A subarray with no more than one element will reach the end of recursion.
		quicksort(a, p, q - 1);
		quicksort(a, q + 1, r);
	}
}

int main() {
	// Read in the length of the array and then the whole array.
	int arrayLength;
	printf("Please input the length of the array: ");
	scanf("%d", &arrayLength);
	int array[arrayLength];
	printf("Please input %d integer values:\n", arrayLength);
	for (int i = 0; i < arrayLength; i++) {
		scanf("%d", &array[i]);
	}
	
	// Print out the original array.
	printf("The original array is: ");
	for (int i = 0; i < arrayLength; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	
	// Call the quicksort function. In this case, the whole array is sorted.
	quicksort(array, 0, arrayLength - 1);
	
	// Print out the sorted array.
	printf("The sorted array is: ");
	for (int i = 0; i < arrayLength; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	
	return 0;
}
