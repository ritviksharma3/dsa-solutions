#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int low, int high, int target)
{
	if (high >= low) {
		int mid = low + (high - low) / 2;
		if (arr[mid] == target)
			return mid;
		if (arr[mid] > target)
			return binarySearch(arr, low, mid - 1, target);
		return binarySearch(arr, mid + 1, high, target);
	}
	return -1;
}

int main(void)
{
	int arr[] = { 2, 4, 5, 7, 10 };
	int x = 7;
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1)
		? cout << "Target is not in array"
		: cout << "Target is at index " << result;
	return 0;
}
