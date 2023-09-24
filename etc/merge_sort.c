#include <stdio.h>
#define MAX_SIZE 500

void merge(int *A, int start, int mid, int end)
{
  int length_left = mid - start + 1;
  int length_right = end - mid;

  int i, j, k;
  int L[length_left], R[length_right];

  for (i = 0; i < length_left; i++)
  {
    L[i] = A[start + i];
  }
  for (j = 0; j < length_right; j++)
  {
    R[j] = A[mid + j + 1];
  }

  i = 0;
  j = 0;
  k = start;

  while (i < length_left && j < length_right)
  {
    if (L[i] <= R[j])
    {
      A[k] = L[i];
      i++;
    }
    else
    {
      A[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < length_left)
  {
    A[k] = L[i];
    i++;
    k++;
  }

  while (j < length_right)
  {
    A[k] = R[j];
    j++;
    k++;
  }
}

void merge_sort(int *A, int start, int end)
{
  if (start >= end)
    return;

  int mid = (start + end) / 2;
  merge_sort(A, start, mid);
  merge_sort(A, mid + 1, end);
  merge(A, start, mid, end);
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

  merge_sort(A, 0, n - 1);

  for (int i = 0; i < n; i++)
  {
    printf("%d ", A[i]);
  }
}
