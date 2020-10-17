#setup
def countingSort(a = []):

    finalList = [0] * len(a)

    maxVal = a[0]
    minVal = a[0]

    for i in range(1, len(a)):
        if a[i] > maxVal:
            maxVal = a[i]
        elif a[i] < minVal:
            minVal = a[i]

    k = maxVal - minVal + 1

    countList = [0]*k

    for i in range(0, len(a)):
        countList[a[i] - minVal] += 1
 
    for i in range(1, k):
        countList[i] += countList[i - 1]
 
    for i in range(0, len(a)):
        finalList[countList[a[i] - minVal] - 1] = a[i]
        countList[a[i] - minVal] -= 1
 
    for i in range(0, len(a)):
        a[i] = finalList[i]
#main

a = [1, 5, 2, 7, 3, 4, 4, 1, 5]
for i in range(len(a)):
    print(a[i], end = " ")
countingSort(a)
print()
for i in range(len(a)):
    print(a[i], end = " ")
