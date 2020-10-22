def binary_search(list, key):
    
    begin = 0                       #assigning initial values
    end = len(list)
    while begin < end:
        mid = (begin + end)//2
        if list[mid] > key:
            end = mid
        elif list[mid] < key:
            begin = mid + 1
        else:
            return mid
    return -1
 
 
list = input('Enter the list of numbers(SORTED): ')
list = list.split()
list = [int(x) for x in list]
key = int(input('Enter number to search: '))       #value to search
 
index = binary_search(list, key)
if index < 0:
    print('{} was not found.'.format(key))
else:
    print('{} was found at index {}.'.format(key, index))
