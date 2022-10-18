// Hello Viewers! here i am sharing my thought on my own way

// When you think of Quicksort, think of a pivot and recursive.

// You choose a pivot (you decide how, you can take the median between the first, mid and last. We will take it randomly)
// You iterate over the slice and move all values smaller than the pivot to the left and keep in memory the location of the last value that is smaller
// Once you iterated on all the slice, you move the pivot after the last value that was smaller
// You now know that all values at the left of the pivot are smaller than the pivot and the values at the right are bigger, so you can recursively quick sort 
// // the slice at its left and sort the slice at its right


// program:

#include
using namespace std;

void swap(int arr[] , int pos1, int pos2){
	int temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

int partition(int arr[], int low, int high, int pivot){
	int i = low;
	int j = low;
	while( i <= high){
		if(arr[i] > pivot){
			i++;
		}
		else{
			swap(arr,i,j);
			i++;
			j++;
		}
	}
	return j-1;
}

void quickSort(int arr[], int low, int high){
	if(low < high){
	int pivot = arr[high];
	int pos = partition(arr, low, high, pivot);
	
	quickSort(arr, low, pos-1);
	quickSort(arr, pos+1, high);
	}
}

int main()
{
	int n ;
	cout << " enter the size of array";
	cin>>n;
	int arr[n];
	for( int i = 0 ; i < n; i++){
		cin>> arr[i];
	}
	quickSort(arr, 0 , n-1);
	cout<<"The sorted array is: ";
	for( int i = 0 ; i < n; i++){
		cout<< arr[i]<<"\t";
	}
	
}


// Time Complexity:O(n*logn)
// Happy Coding.
