#include <stdio.h>
#include <assert.h>

//#define CLEAR2CONTINUE
#include "include/traces.h"

// C'est dans le fichier elt.h qu'on doit choisir l'implémentation des T_elt
#include "elt.h"
//#include "list.h"
//#include "stack_cld.h"
#include "list.c"
#include "elt.c"
int main(int argc, char ** argv) {

 	testlistfunction();
    printf("success");
	return 0;
}







