#include <bits/stdc++.h>


using namespace std;

void insertionSort(int arr[], int length);
void printArray(int array[],int size);
int* insertionsort(int *arr,int n);
//1.select the first unsorted element 
//2.swap the other element on right to create the correct position and shift the unsorted element 
//3.advance the marker to the right one element
int* insertionsort(int *arr,int n)
{

	int i,key,j;

    for(i=1;i<n;i++)
	{
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}
return arr;
}

 
void insertionSort(int *arr, int length) {
	int i, j ,tmp;
	for (i = 1; i < length; i++) {
		j = i;
 		while (j > 0 && arr[j - 1] > arr[j]) {
 			tmp = arr[j];
 			arr[j] = arr[j - 1];
 			arr[j - 1] = tmp;
 			j--;
 		}
	printArray(arr,length);
	}
}
 
void printArray(int *array, int size){ 
 	//cout<< "Sorting tha array using Insertion sort... ";
 	int j;
	for (j=0; j < size;j++)
 		for (j=0; j < size;j++)
 			cout<< array[j] <<" ";
 	cout << endl;
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    insertionSort(arr , n);
    return 0;
}

















//second code geeks for geeks
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <bits/stdc++.h>


using namespace std;

void insertionsort( int arr[],int length);
void printArray(int array[],int size);

void insertionsort(int *arr,int n)
{

	int i,key,j;

    for(i=1;i<n;i++)
	{
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}
printArray(arr,n);
}

void printArray(int *array, int size){ 
 	//cout<< "Sorting tha array using Insertion sort... ";
 	int j;
	for (j=0; j < size;j++)
 		for (j=0; j < size;j++)
 			cout<< array[j] <<" ";
 	cout << endl;
}
int main(void) {

    int N;
    
    scanf("%d", &N);
    int arr[N], i;
    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    insertionsort( arr,N);

    return 0;
}


