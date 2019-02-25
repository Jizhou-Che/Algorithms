#include <stdio.h>

int Partition(int * arrayHead, int p, int r){
	/*
	for(int i = p; i <= r; i++){
		arrayHead[i] = 0;
	}
	*/
	return r;
}

// The Quicksort main function.
// Takes a reference to the head of the array and the beginning and ending indices of the array to be sorted.
void Quicksort(int * arrayHead, int p, int r){
	if(p < r){
		// Do the sorting only if the array is not empty.
		int q = Partition(arrayHead, p, r);
		Quicksort(arrayHead, p, q - 1);
		Quicksort(arrayHead, q + 1, r);
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

	// Call the Quicksort function.
	Quicksort(array, 0, arrayLength - 1);

	// Print out the original array.
	printf("The original array is: ");
	for(int i = 0; i < arrayLength; i++){
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}