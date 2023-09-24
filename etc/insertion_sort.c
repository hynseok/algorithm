#include <stdio.h>
#define MAX_SIZE 500

void insertion_sort(int *A, int n)
{
  int i, j, key;
  for (i = 1; i < n; i++)
  {
    key = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > key)
    {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = key;
  }
}

int main()
{
  int n;
  int A[MAX_SIZE];

  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }

  insertion_sort(A, n);

  for (int i = 0; i < n; i++)
  {
    printf("%d ", A[i]);
  }
}
