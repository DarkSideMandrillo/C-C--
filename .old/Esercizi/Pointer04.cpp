#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
     char st[10]={1,1,1,1,1,1,1,1,1,1};
     char st2[10];
     char *p,*j;
     int i;

     cout<<"inserisci st\n:";
     cin>>st; //non fa controlli ma inserisce /0

     for(i=0;i<10;i++){
          printf("\n-%d",st[i]);
     };

     p=&st[0];
     j=&st2[0];

     do{
          *j=*p;
          p++;j++;
     }while(*p!='\0');

     *j='\0';
     cout<<"\n"<<st2;
     } //fine main