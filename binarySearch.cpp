//This is a program of Binary Search
// #include<iostream>
#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l)   // r is max range and l is min range
	{
		int mid = l + (r - l) / 2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x); // goes to search in left side of array.
		return binarySearch(arr, mid + 1, r, x);	// goes to search in right side of array.
	}
	return -1;
}
int main()
{
	int arr[] = {10, 20, 40, 80, 100, 130};
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = binarySearch(arr, 0, n - 1, x);
	(result == 1) ? cout << "Element is present in Index " : cout << "Element is not present in array ";

	return 0;
}
