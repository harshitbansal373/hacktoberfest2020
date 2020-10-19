# Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.
# Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

# Input: [4,2,5,7]
# Output: [4,5,2,7]
# Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted


def sortArrayByParityII(int_list):
    ret = int_list.copy()
    posEven, posOdd = 0, 1
    for v in int_list:
        if v % 2 != 0:
            ret[posOdd] = v
            posOdd += 2
        else:
            ret[posEven] = v
            posEven += 2
    return ret
