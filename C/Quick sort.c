//simple quick sort code in c
#include<stdio.h>
#include<conio.h>

#define MAX_SIZE 5

void quick_sort(int, int);
int arr_sort[MAX_SIZE];

int main() {
  int i;

  printf("Simple Quick Sort Example - Functions and Array\n");
  printf("\nEnter %d Elements for Sorting\n", MAX_SIZE);
  for (i = 0; i < MAX_SIZE; i++)
    scanf("%d", &arr_sort[i]);

  printf("\nYour Data   :");
  for (i = 0; i < MAX_SIZE; i++) {
    printf("\t%d", arr_sort[i]);
  }

  quick_sort(0, MAX_SIZE - 1);

  printf("\n\nSorted Data :");
  for (i = 0; i < MAX_SIZE; i++) {
    printf("\t%d", arr_sort[i]);
  }
  getch();

}

void quick_sort(int f, int l) {
  int i, j, t, p = 0;

  if (f < l) {
    p = f;
    i = f;
    j = l;

    while (i < j) {
      while (arr_sort[i] <= arr_sort[p] && i < l)
        i++;
      while (arr_sort[j] > arr_sort[p])
        j--;
      if (i < j) {
        t = arr_sort[i];
        arr_sort[i] = arr_sort[j];
        arr_sort[j] = t;
      }
    }

    t = arr_sort[p];
    arr_sort[p] = arr_sort[j];
    arr_sort[j] = t;
    quick_sort(f, j - 1);
    quick_sort(j + 1, l);
  }
}