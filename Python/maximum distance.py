def maxHamming( arr , n ): 
	brr = [0] * (2 * n + 1) 
	for i in range(n): 
		brr[i] = arr[i] 
	for i in range(n): 
		brr[n+i] = arr[i] 
	
	maxHam = 0
	
	for i in range(1, n): 
		currHam = 0
		k = 0
		for j in range(i, i + n): 
			if brr[j] != arr[k]: 
				currHam += 1
				k = k + 1
		
		if currHam == n: 
			return n 
		
		maxHam = max(maxHam, currHam) 
	
	return maxHam 

arr = [2, 4, 6, 8] 
n = len(arr) 
print(maxHamming(arr, n)) 
