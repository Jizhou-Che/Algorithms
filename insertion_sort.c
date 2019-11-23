// An implementation of the insertion sort algorithm.
// Insertion sort is stable.

#include <stdio.h>

// The insertion sort main function.
// Takes a reference to the head of the array and the length of the array.
// Maintains a sorted portion of the array, on each iteration the first value in the remaining portion is inserted to the sorted portion.
void insertion_sort(int * a, int length) {
	for (int i = 1; i < length; i++) {
		int key = a[i];
		// Insert (a[i]) to the sorted portion.
		int j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
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
	
	// Call the insertion sort function.
	insertion_sort(array, arrayLength);
	
	// Print out the sorted array.
	printf("The sorted array is: ");
	for (int i = 0; i < arrayLength; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	
	return 0;
}
