

"""
Logic of the program: It prints the number of '1' in all the numbers in the range from 1 to the given number.
example : for input 13 : output is 6
[1],2,3,4,5,6,7,8,9,[10],[11] <- "here 2 times" ,[12],[13]
"""


def no_of_ones(n):
	
	count = 0
	for i in range(1,n+1):
		count += str(i).count('1')
	return count

if __name__ == "__main__":
	num = int(input())
	print("No. of ones in previous numbers are: ",no_of_ones(num))