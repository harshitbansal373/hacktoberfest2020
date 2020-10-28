def insertion_sort(lst):
    """
    Insertion sort function
    :param lst: lst of unsorted integers
    """

    # Traverse through 1 to len(lst)
    for i in range(1, len(lst)):

        key = lst[i]

        # Move elements of lst greater than key, to one position ahead
        j = i - 1
        while j >= 0 and key < lst[j]:
            lst[j + 1] = lst[j]
            j -= 1
        lst[j + 1] = key


# Driver code to test above
if __name__ == '__main__':

    lst = [3, 2, 1, 5, 4]
    insertion_sort(lst)  # Calling insertion sort function

    print("Sorted list is: ", lst)
