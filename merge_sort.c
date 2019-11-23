// An implementation of the merge sort algorithm.
// Merge sort is stable.

#include <stdio.h>
#include <limits.h>

// The merge function.
// Takes a reference to the head of the array, and the beginning, partitioning and ending indices of the portion of array to be merged.
// Merges the two sorted subarrays.
void merge(int * a, int p, int q, int r) {
	// Load the portion from (p) to (q) into (a1), with an additional very large value attached to the end.
	int length1 = q - p + 1;
	int a1[length1 + 1];
	for (int i = 0; i < length1; i++) {
		a1[i] = a[p + i];
	}
	a1[length1] = INT_MAX;
	// Load the portion from (q + 1) to (r) into (a2), with an additional very large value attached to the end.
	int length2 = r - q;
	int a2[length2 + 1];
	for (int i = 0; i < length2; i++) {
		a2[i] = a[q + i + 1];
	}
	a2[length2] = INT_MAX;
	
	// Merge the two sorted subarrays back to the original position in the array.
	int i = 0, j = 0;
	for (int k = p; k <= r; k++) {
		if (a1[i] <= a2[j]) {
			a[k] = a1[i];
			i++;
		} else {
			a[k] = a2[j];
			j++;
		}
	}
}

// The merge sort main function.
// Takes a reference to the head of the array and the beginning and ending indices of the portion of array to be sorted.
// Applies the divide-and-conquer strategy and gets the subarray sorted recursively.
void merge_sort(int * a, int p, int r) {
	if (p < r) {
		// Do the sorting only if the array has more than one element.
		// Set the middle of the array to be the partitioning point.
		int q = (p + r) / 2;
		// Partition the array recursively.
		// A subarray with no more than one element will reach the end of recursion.
		merge_sort(a, p, q);
		merge_sort(a, q + 1, r);
		// Merge the sorted partitions from the bottom.
		merge(a, p, q, r);
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
	
	// Call the merge sort function. In this case, the whole array is sorted.
	merge_sort(array, 0, arrayLength - 1);
	
	// Print out the sorted array.
	printf("The sorted array is: ");
	for (int i = 0; i < arrayLength; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	
	return 0;
}
