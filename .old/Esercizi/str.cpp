#include <iostream>
using namespace std;

int main()
{
    char str[100];
    int i;



    cout << "Enter string: ";
    cin >> str;
    cout << "You entered: "<<str<<endl;
    str[9]='\0';

    for(i=0;i<100;i++){
          printf("\n-%d",str[i]);
     };


    return 0;
}