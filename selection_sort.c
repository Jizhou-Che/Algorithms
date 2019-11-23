// An implementation of the selection sort algorithm.
// This version of selection sort is not stable because of the swapping.

#include <stdio.h>

// The function to swap two integer values.
void swap(int * a, int * b) {
	int temp = * a;
	* a = * b;
	* b = temp;
}

// The selection sort main function.
// Takes a reference to the head of the array and the length of the array.
// Repeatedly scans through the remaining subarray, on each scan the smallest value is selected and swapped to the beginning.
void selection_sort(int * a, int length) {
	for (int i = 0; i < length - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < length; j++) {
			if (a[j] < a[minIndex]) {
				minIndex = j;
			}
		}
		swap(&a[i], &a[minIndex]);
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
	
	// Call the selection sort function.
	selection_sort(array, arrayLength);
	
	// Print out the sorted array.
	printf("The sorted array is: ");
	for (int i = 0; i < arrayLength; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	
	return 0;
}
