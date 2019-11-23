// An implementation of the bubble sort algorithm.
// Bubble sort is stable.

#include <stdio.h>

// The function to swap two integer values.
void swap(int * a, int * b) {
	int temp = * a;
	* a = * b;
	* b = temp;
}

// The bubble sort main function.
// Takes a reference to the head of the array and the length of the array.
// Repeatedly scans through the remaining subarray, on each scan the smaller values bubble up, and the smallest value bubbles up to the top.
void bubble_sort(int * a, int length) {
	for (int i = 0; i < length - 1; i++) {
		for (int j = length - 1; j > i; j--) {
			if (a[j] < a[j - 1]) {
				swap(&a[j], &a[j - 1]);
			}
		}
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
	
	// Call the bubble sort function.
	bubble_sort(array, arrayLength);
	
	// Print out the sorted array.
	printf("The sorted array is: ");
	for (int i = 0; i < arrayLength; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	
	return 0;
}
