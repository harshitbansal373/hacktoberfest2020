def Merge(arr, l, m, r, Index):
	n1 = m - l + 1
	n2 = r - m
	L = [0]*n1
	R = [0]*n2
	Ls = [0]*n1
	Rs = [0]*n2

	i = 0
	while(i < n1):
		L[i] = arr[l + i]
		Ls[i] = Index[l + i] 
		i += 1

	j = 0
	while(j < n2):
		R[j] = arr[m + 1 + j]
		Rs[j] = Index[m + 1 + j]
		j += 1

	i = 0     
	j = 0     
	k = l    
 
	while(i < n1 and j < n2):
		if(L[i] <= R[j]):
			arr[k] = L[i]
			Index[k] = Ls[i]
			i += 1
		else:
			arr[k] = R[j]
			Index[k] = Rs[j]
			j += 1
		k += 1

	while(i < n1):
		arr[k] = L[i]
		Index[k] = Ls[i]
		i += 1
		k += 1

	while(j < n2):
		arr[k] = R[j]
		Index[k] = Rs[j]
		j += 1
		k += 1

def MergeSort(arr,l,r,Index):
	if(l < r):
		m = (l+(r-1))//2
		MergeSort(arr, l, m,Index)
		MergeSort(arr, m+1, r,Index)
		Merge(arr, l, m, r,Index)
	
N = int(input())
l = list(map(int, input().split()))
MergeSort(l,0,N-1,[i for i in range(N)])
print(l)

