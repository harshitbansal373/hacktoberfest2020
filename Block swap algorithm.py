def leftRotate(arr, d, n):
	leftRotateRec(arr, 0, d, n);

def leftRotateRec(arr, i, d, n):
	if (d == 0 or d == n):
		return;
	if (n - d == d):
		swap(arr, i, n - d + i, d);
		return;
	if (d < n - d):
		swap(arr, i, n - d + i, d);
		leftRotateRec(arr, i, d, n - d);
	else:
		swap(arr, i, d, n - d);
		leftRotateRec(arr, n - d + i, 2 * d - n, d); 

def printArray(arr, size):
	for i in range(size):
		print(arr[i], end = " ");
	print();

def swap(arr, fi, si, d):
	for i in range(d):
		temp = arr[fi + i];
		arr[fi + i] = arr[si + i];
		arr[si + i] = temp;

if __name__ == '__main__':
	arr = [1, 2, 3, 4, 5, 6, 7];
	leftRotate(arr, 2, 7);
	printArray(arr, 7);
