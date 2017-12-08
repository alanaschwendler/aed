#include <stdlib.h>
#include <stdio.h>

/**
 * Prints a given array
 * *vet - the array
 * s - index start
 * f - index final
 */
void print(int *vet, int s, int f){
  for(int i=s ; i<=f ; ++i)
    printf("array[%d] = %d\n", i, vet[i]);

  printf("--------------------------------\n");
}

/**
 * The conquer part
 * *vet - the array to sort
 * b - is the beginning
 * m - the middle
 * e - the end (inclusive)
 * *res - a auxiliar vector, this could be allocated inside the function with only (e - b + 1) elements
 */
void merge(int *vet, int b, int m, int e, int *res){
  // Left side array [b, m]
  int fst = b;      // fst marks the current element on left side array, must go no higher thatn m (inclusive)
  // Right side array [m+1, e]
  int snd = m + 1;  // snd marks the current element on the right side array, must be no higher thatn e (inclusive)
  int k = b;        // used to mark the res[] array position, must be no higher thatn e (inclusive)


  while((fst <= m) && (snd <= e)){ // is there is still element on both array
    // see wich one is higher, and copy to res[]
    if(vet[fst] < vet[snd]){ 
      res[k] = vet[fst];
      ++fst; //increment left side counter (++fst)
    }else{
      res[k] = vet[snd];
      ++snd; //increment right side counter (++snd)
    }
    ++k; // doensn't matter from wich side it came, but there is a new element on res[], so increment its counter (++k)
  }

  // if the LEFT side is not over, than its counter is less equal than the middle, remember this array is [b, m]
  while(fst <= m){ // if there is any element left on the LEFT side, copy it to res[]
    res[k] = vet[fst];
    ++fst;
    ++k;
  }

  // if the RIGHT side is not over, than its counter is less equal than the end, remember this array is [m+1, e]
  while(snd <= e){ // if there is any element left on the RIGHT side, copy it to res[]
    res[k] = vet[snd];
    ++snd;
    ++k;
  }

  for(k=b;k<=e;++k) // now, copy it all back to the original array
      vet[k] = res[k];

}

void mergesort(int *vet, int b, int e, int *res){
  if(e <= b) return; // if there is just one element on the array, there is nothing to do, it is considered ordenated

  mergesort(vet, b, (b+e)/2, res); // divide the left side
  mergesort(vet, (b+e)/2+1, e, res); // divide the right side


  // NOTE that when the program reach this point it means that the left side and right side are ordenated 
  // even if they are one element only, they are considerated ordenated
  //
  // Now, just merge them into one
  merge(vet, b, (b+e)/2, e, res);
}

int main(){

  int vet[] = {5,3,4,2,1,6,8,9,7,0}; // the array
  int *res = malloc(40);             // same size auxiliar array

  print(vet, 0,9);

  mergesort(vet, 0, 9, res);

  print(vet, 0,9); // Just prints the array
  free(res);

  return 0;
}
