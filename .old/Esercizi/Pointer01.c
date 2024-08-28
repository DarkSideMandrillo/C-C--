#include <stdio.h>



int main() {
   int var1 = 4, var2 = 3;
   int *p1, *p2;

   p1=&var1;
   p2=&var2;

   printf("\npuntatore var1: %p - Puntatore var2: %p\n\n",p1,p2);


   // printf("carattere: %c \n", a);



   return 0;
}