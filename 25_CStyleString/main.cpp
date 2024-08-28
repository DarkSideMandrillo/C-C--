#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    cout << "----------INIZIALIZZAZIONE SENZA LUNGHEZZA-----------------" << endl;

    char myName[]{"Frank"}; // [F,r,a,n,k,\0]
    cout << myName << endl;
    /*Size of variable CHAR*/
    cout << sizeof(char) << endl;
    /*Size of array of CHAR*/
    cout << sizeof(myName) << endl;
    /*Value of Standard C String*/
    for (unsigned int i{0}; i < sizeof(myName); i++)
        cout << "Valore: " << myName[i] << " - ascii: " << int(myName[i]) << " - Memory: " << &myName + (i * sizeof(char)) << endl;
    // Volessi usare Franky è un problema perchè dovrei sovrascrivere /0
    cout << "-----------INIZIALIZZAZIONE CON LUNGHEZZA----------------" << endl;

    /*Per avere più spazio di utilizzo devo usare*/
    char myName2[8]{"Frank"}; // [F,r,a,n,k,\0,\0,\0]
    cout << sizeof(char) << endl;
    /*Size of array of CHAR*/
    cout << sizeof(myName2) << endl;
    /*Value of Standard C String*/
    for (unsigned int i{0}; i < sizeof(myName2); i++)
        cout << "Valore: " << myName2[i] << " - ascii: " << int(myName2[i]) << " - Memory: " << &myName2 + (i * sizeof(char)) << endl;
    cout << "-----------DICHIARAZIONE E ASSEGNAZIONE----------------" << endl;

    /*PROBLEMI*/
    char myName3[8];
    // myName3 = "Frank"; ERROR
    strcpy(myName3, "Frank"); // Serve #include <cstring>
    cout << myName3 << endl;
    for (unsigned int i{0}; i < sizeof(myName3); i++)
        cout << "Valore: " << myName3[i] << " - ascii: " << int(myName3[i]) << " - Memory: " << &myName3 + (i * sizeof(char)) << endl;

/*
char str[80];

strcpy(str,"Hello "); COPY
strcat(str,"there "); CONCATENATE
cout << strlen(str); - 11
srecmp(str, "another");- >0



*/
}