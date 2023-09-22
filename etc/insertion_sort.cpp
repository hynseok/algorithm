#include<stdio.h>
#define MAX_SIZE 500

int main(){
  int n;
  int A[MAX_SIZE];

  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%d ",&A[i]);
  }

  for(int i=0;i<n;i++){
    printf("%d ",A[i]);
  }
}
