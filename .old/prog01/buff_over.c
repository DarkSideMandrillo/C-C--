#include<stdio.h>


int main(){
    int cookie;
    char buffer[8];

    cookie=0;

    printf("buffer: 0x%08x cookie: 0x%08x\n", &buffer, &cookie);
    gets(buffer);

    printf("Current cookie value 0x%08x \n", cookie);
        if (cookie==0x41424344){
    printf("You win!\n");
        }
    return 0;
}