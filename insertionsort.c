#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

void print(int *ar,int high){
   for(int i=0;i<=high;i++){
       if(i>0) printf(" ");
       printf("%d",ar[i]);
   }
    printf("\n");
}

void insertion (int *ar, int low, int high) {
  int loc;
  for (loc = low+1; loc <= high; loc++) {
    int i = loc-1;
    int value = ar[loc];
    while (i >= 0 && ar[i] > value) {
      ar[i+1] = ar[i];
      i--;
    } 

  ar[i+1] = value;
  print(ar,high);
  }
}

int main(){
    int ar[100];
    int low=0,high;
    
    scanf("%d",&high);
    for(int i=0;i<high;i++) scanf("%d",&ar[i]);
    
    insertion(ar,low,high);
    print(ar,high);
    
    return 0;
}
