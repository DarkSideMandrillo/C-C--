#include <stdio.h>

int main() {
   int var1 = 4;
   int *p1, *p2;

   p1=&var1;
   p2=p1+1;

   *p2=3;

   printf("\npuntatore var1: %p :%d - Puntatore var2: %p: %d\n\n",p1,var1,p2,*p2);


   // printf("carattere: %c \n", a);



   return 0;
}