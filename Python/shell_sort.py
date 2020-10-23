"""
Author: Kadhirash Sivakumar
Python program implementing Shell Sort

Shell Sort: Similar to Insertion Sort except allows for exchange with farther indexes.

Make the array 'h' -sorted for a large 'h' value, and keep reducing 'h' by 1. 

Array is 'h' sorted if all subarrays of every h'th element is sorted!


Time Complexity: O(n(log(n))^2)
Space Complexity: O(1)
"""
import typing
from typing import List


def shell_sort(arr: List[int]) -> List[int]:

    size = len(arr)
    gap = size // 2

    # gapped insertion sort: keep adding until array is gap sorted
    while gap > 0:
        for i in range(gap, size):
            temp = arr[i]  # save position of arr[i]

            # shift earlier elements until the correct location
            j = i

            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap

            arr[j] = temp  # swap back

        gap //= 2  # reduce the gap and repeat


# testing


def main():
    arr = [5, 3000, -10, 65.2, 200000]
    size = len(arr)

    print("Before shell sort:")
    print(*arr, sep=", ")

    shell_sort(arr)
    print("\n")

    print("After shell sort:")
    print(*arr, sep=", ")


if __name__ == "__main__":
    main()

