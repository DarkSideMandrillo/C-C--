#include <stdio.h>
#include <stdlib.h>

void printArray(int a[], int dim);

int main(){

    /* allocazione FISSA */
    int a[]={1,2,3,4,5};
    int dimA=5;

    printf("Array statico di %d elementi", dimA);
    printArray(a,dimA);

/* Array dinamici */
    int numElem = 10;
    printf("\n\nnumero elementi: %d\n\n",numElem);
    int *p;

    /* MALLOC ->malloc(numByte); usa la mem dinamica senza inizializzarla*/
    p = malloc(numElem * sizeof(int));
        /*Creo l'array con un for*/
    for (int i=0;i<numElem;++i){
        p[i]=i;
    }
    printf("Array dinamico con malloc \n");
    printArray(p,numElem);

    /*CALLOC -> calloc(numElem, dimSingoloElem)*/
    p = calloc(numElem,sizeof(int));
        /*Creo l'array con un for*/
    for (int i=0;i<numElem;++i){
        p[i]=i;
    }
    printf("Array dinamico con calloc \n");
    printArray(p,numElem);    

}

/*Funzione stampa array*/
void printArray (int a[], int dim){
    printf("\n\t[");

    for (int i=0;i<dim;++i)
        printf("%d ",a[i]);

    printf("] \n\n");
    
}