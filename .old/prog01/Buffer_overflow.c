/* Buffer Overflow */
int main()
{
char buffer2[5];
char buffer1[4];
int i;

for (i=0;i<9;i++){
    buffer1[i]='A';
}
return 0;
}

