#include <stdio.h>
// copia una stringa a un altra (casereccio)
int main() {
   char str1[10];
   char str2[10];
   char *pt_str1=str1;
   int i;

   printf("inserisci 10 caratteri");

   for(i=0;i<10;i++){
    scanf("%c",&str1[i]);
   };

   for(i=0;i<10;i++){
    str2[i]=*pt_str1+i;
   };


   printf("\n\nI caratteri inseriti sono");
   for(i=0;i<10;i++){
    printf("%c",str2[i]);
   };

   // printf("carattere: %c \n", a);



   return 0;
}