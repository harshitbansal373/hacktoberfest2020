# Returns the square root of n. 
# Note that the function 
def squareRoot(n): 

	# We are using n itself as 
	# initial approximation This 
	# can definitely be improved 
		x = n 
		y = 1
		
		# e decides the accuracy level 
		e = 0.000001
		while(x - y > e): 
	
			x = (x + y)/2
			y = n / x 
	
		return x 

# Driver program to test 
# above function 
n = 50

print("Square root of", n, "is", 
			round(squareRoot(n), 6)) 

# This code is contributed by 
# Smitha Dinesh Semwal 
