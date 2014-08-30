#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
/*
Given an array arr[0 ... n-1] containing n positive integers, a subsequence of arr[] is called Bitonic if it is first increasing, then decreasing. Write a function that takes an array as argument and returns the length of the longest bitonic subsequence.
A sequence, sorted in increasing order is considered Bitonic with the decreasing part as empty. Similarly, decreasing order sequence is considered Bitonic with the increasing part as empty.
*/

int* lis(int array[], int n) {
	int maximumLisLength = INT_MIN, lisArrayIterator, lisArraySubIterator;
	int* lisArray = (int*) malloc (sizeof (int) * n);
	for (lisArrayIterator = 0; lisArrayIterator < n; lisArrayIterator++) {
		lisArray [lisArrayIterator] = 1;
	}
	
	for (lisArrayIterator = 0; lisArrayIterator < n; lisArrayIterator++) {
		for (lisArraySubIterator = 0; lisArraySubIterator < lisArrayIterator; lisArraySubIterator++) {
			if ( (array [lisArraySubIterator] < array [lisArrayIterator]) && (lisArray [lisArrayIterator] < lisArray [lisArraySubIterator] + 1)) {
				lisArray[lisArrayIterator] = lisArray[lisArraySubIterator] + 1;
			}
		} 
	}
	return lisArray;
}


int* lds(int array[], int n) {
	int maximumLdsLength = INT_MIN, ldsArrayIterator, ldsArraySubIterator;
	int* ldsArray = (int*) malloc (sizeof (int) * n);
	for (ldsArrayIterator = n-1; ldsArrayIterator >= 0; ldsArrayIterator--) {
		ldsArray [ldsArrayIterator] = 1;
	}
	
	for (ldsArrayIterator = n-1; ldsArrayIterator >= 0; ldsArrayIterator--) {
		for (ldsArraySubIterator = n-1; ldsArraySubIterator >= ldsArrayIterator; ldsArraySubIterator--) {
			if ( (array [ldsArraySubIterator] < array [ldsArrayIterator]) && (ldsArray [ldsArrayIterator] < ldsArray [ldsArraySubIterator] + 1)) {
				ldsArray[ldsArrayIterator] = ldsArray[ldsArraySubIterator] + 1;
			}
		} 
	}
	
	return ldsArray;
}

int lbs(int array[], int n) {
	int maximumLbsLength = INT_MIN, lbsArrayIterator;
	int* lisArray = lis (array, n);	
	int* ldsArray = lds (array, n);	
	for(lbsArrayIterator = 0; lbsArrayIterator < n ; lbsArrayIterator++) {
		if ((lisArray[lbsArrayIterator] + ldsArray[lbsArrayIterator] - 1) > maximumLbsLength) {
			maximumLbsLength = lisArray[lbsArrayIterator] + ldsArray[lbsArrayIterator] - 1;

		}		
	}
	free(lisArray);
	free(ldsArray);
	return maximumLbsLength;

}




int main()
{
  int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Length of LBS is %d\n", lbs( arr, n ) );
 
  getchar();
  return 0;
}
