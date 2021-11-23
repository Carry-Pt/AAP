#include <stdio.h>
#include <assert.h>

//#define CLEAR2CONTINUE
#include "include/traces.h"
#include "D:/work/stable_windows_10_msbuild_Release_Win32_graphviz-2.49.3-win32/Graphviz/bin/dot.exe"
// C'est dans le fichier elt.h qu'on doit choisir l'implémentation des T_elt
#include "elt.h"
//#include "list.h"
//#include "stack_cld.h"
#include "list.c"
#include "elt.c"

void generatePNG(const T_list l, const char * filename){
system( "dot exemple.dot -T png -o exemple.png");
}

int main(int argc, char ** argv) {
    T_node *n;
    n= newNode(0);
    generatePNG(n, "example.dot");
    system( "dot exemple.dot -T png -o exemple.png");
	return 0;
}







