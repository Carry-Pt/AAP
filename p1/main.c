#include <stdio.h>
#include <assert.h>

//#define CLEAR2CONTINUE
#include "include/traces.h"

// C'est dans le fichier elt.h qu'on doit choisir l'implémentation des T_elt
#include "include/elt.h"    //T_elt
#include "include/elt.c"
// implémentation des piles contigüe dynamique
//#include "include/stack_cd.h"
#include "include/stack_cd.c"
int main(int argc, char ** argv) {
    int input,rest,quo,base,i;
    T_stack t;
    printf("input number(10)\n");
    scanf("%d",&input);

    printf("input new base('0' for not second parameter)");
    scanf("%d",&base);
    if (base==0)
        base=2;
    quo=input;
    rest=quo%base;
    quo=quo/base;
    t= newStack(50);
    t.data[t.sp]=rest;
    while (quo!=0){
        rest=quo%base;
        quo=quo/base;
        push(rest,&t);
    }
    if (t.sp ==0)
        printf("Pile vide !\n"); // pile vide !
    for(i=t.sp-1;i>=0; i--)
        printf("%s ",toString(t.data[i]));
	return 0;
}







