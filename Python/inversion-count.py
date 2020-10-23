# Function to find inversion count of the given list
def getInversionCount(A):

	inversionCount = 0
	for i in range(len(A) - 1):
		for j in range(i + 1, len(A)):
			if A[i] > A[j]:
				inversionCount = inversionCount + 1

	return inversionCount


if __name__ == '__main__':

	A = [1, 9, 6, 4, 5]
	print("Inversion count is", getInversionCount(A))
