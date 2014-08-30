#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
/*
Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence of the given array such that the intgers in the subsequence are sorted in increasing order. For example, if input is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100), if the input array is {3, 4, 5, 10}, then output should be 22 (3 + 4 + 5 + 10) and if the input array is {10, 5, 4, 3}, then output should be 10
*/

int maxSumIS(int array[], int n) {
	int* maxSumArray, maxSumArrayIterator, subArrayIterator, currentMaxSum=INT_MIN;
	maxSumArray = (int*)malloc(sizeof(int) *n);
	for(maxSumArrayIterator = 0; maxSumArrayIterator < n; maxSumArrayIterator++ ) {
		maxSumArray[maxSumArrayIterator] = array[maxSumArrayIterator];
	}
		
	for(maxSumArrayIterator = 0; maxSumArrayIterator<n;maxSumArrayIterator++) {
		for(subArrayIterator = 0; subArrayIterator<maxSumArrayIterator; subArrayIterator++){
			if(((maxSumArray[subArrayIterator] + array[maxSumArrayIterator]) > maxSumArray[maxSumArrayIterator])&&(array[subArrayIterator]<array[maxSumArrayIterator])){
				maxSumArray[maxSumArrayIterator] = maxSumArray[subArrayIterator] + array[maxSumArrayIterator];
			}

		}
	}
	
	for(maxSumArrayIterator = 0; maxSumArrayIterator < n; maxSumArrayIterator++) {
		if(currentMaxSum < maxSumArray[maxSumArrayIterator]) {
			currentMaxSum = maxSumArray[maxSumArrayIterator];
		}
	}
		
	free(maxSumArray);
		
	return currentMaxSum;
			
	}

	int main() {
		int arr[] = {1, 101, 2, 3, 100, 4, 5};
		int n = sizeof(arr)/sizeof(arr[0]);
		printf("Sum of maximum sum increasing subsequence is %d\n",
         	maxSumIS( arr, n ) );
		getchar();
		return 0;
	}	

