#include <assert.h>
#include <string.h>
//#define CLEAR2CONTINUE
#include "include/traces.h"

#define DEBUG 1
#include "include/check.h"

#include "elt.h" // T_elt
#include "list.h" // prototypes

/*
typedef struct node {
	T_elt data;
	struct node *pNext;
} T_node, * T_list;
*/

static T_node * newNode(T_elt e) {
	// Créer une nouvelle cellule contenant l'élément e

	T_node * pNode;
	CHECK_IF(pNode = malloc(sizeof(T_node)), NULL, "malloc allocateNode");
	pNode->data = e;
	pNode->pNext = NULL;

	return pNode;
}

T_node * addNode (T_elt e, T_node * n) {
	// Créer une maille (node), la remplir
	// et l'accrocher en tête d'une liste existante (ou vide)
	// Renvoyer la nouvelle tête

	T_node * pNode;
	pNode = newNode(e);
	pNode->pNext = n;
	return pNode;
}

void showList(T_list l) {
	// Afficher la liste en commençant par sa tête
	// A faire en itératif

	if (l==NULL) {
		printf("Liste Vide !\n");
		return;
	}

	while(l != NULL) {
		printf("%s ", toString(l->data));
		l = l->pNext;
	}
}

void freeList(T_list l) {
	// Libérer la mémoire de toutes les cellules de la liste l
	// A faire en itératif

	T_node * pAux;
	// Il faut un pointeur auxiliaire :
	// on ne doit libérer qu'après avoir enregistré quelque part
	// l'adresse de la maille suivante

	assert(l != NULL);

	while(l != NULL) {
		printf("Libération de %s\n", toString(l->data));
		pAux = l->pNext;
		free(l);
		l = pAux;
	}
}
void destroynode(T_node *n){
    if (n!=NULL){
        if(DEBUG==1){
            printf("delete list node: %s \n", toString(n->data));
        }
        free(n);
    }
}

T_elt getFirstElt(T_list l) {
	// Renvoyer l'élément contenu dans la cellule de tête de la liste

	assert(l != NULL);

	return l->data;
}

T_list removeFirstNode(T_list l) {
	// Supprimer la tête de la liste
	// Renvoyer la nouvelle liste privée de sa première cellule

	assert(l!= NULL);
	T_node * p =l->pNext;
	free(l);
	return p;
}

// A produire en version récursive (+ tard dans le sujet)

void showList_rec(T_list l) {
	// Afficher la liste en commençant par sa tête
	// A faire en récursif

	if (l == NULL) {
		// case de base
		return;
	} else {
		// cas général
		printf("%s ", toString(l->data));
		showList_rec(l->pNext);
	}
}

void showList_inv_rec(T_list l) {
	// Afficher la liste en commençant par sa queue
	// A faire en récursif

	if (l == NULL) {
		// case de base
		return;
	} else {
		// cas général
		showList_inv_rec(l->pNext);
		printf("%s ", toString(l->data));
	}
}

void freeList_rec(T_list l) {
	// Libérer la mémoire de toutes les cellules de la liste l
	// A faire en récursif

	if (l == NULL) {
		return;
	} else {
		freeList_rec(l->pNext);
		printf("Libération de %s\n",toString(l->data));
		free(l);
	}
}

unsigned int getSize(const T_list l, unsigned int mycount){
//    Do not input head point of the list in this function !!!
    if (l!=NULL){
        mycount++;
        return getSize(l->pNext,mycount);
    }
    return mycount;
}

T_list tailAddNode(T_elt e, T_list l){
    T_node * pNode;
    pNode = newNode(e);
    l->pNext=pNode;
    return pNode;
}

T_list sortAddNode(T_elt e, T_list l){

    T_node * pNode,*temp,*pre;
    pNode = newNode(e);
    pre=temp=l;
    //add <head
    if(compare(e,temp->data)>=0){
        pNode->pNext=temp;
        l->pNext=pNode;
    }
    while (compare(temp->data,e)>0&&temp!=NULL) {
        pre=temp;
        temp = temp->pNext;
    }
    if(temp==NULL){
        temp->pNext=pNode;
    }
    else {
        pNode->pNext = temp;
        pre->pNext = pNode;
    }
    return  l;
}
int inList(T_elt e, const T_list l){
    T_node *temp=l;
    while (temp!=NULL&& compare(e,temp->data)!=0)
        temp=temp->pNext;
    if(temp==NULL)
        return 0;
    else if (compare(e,temp->data)==0)
        return 1;
    else
        exit(0);
}

T_list  removeDuplicates (T_list l){
    if(l==NULL)
        return NULL;
    int count=0;
    T_node *temp,*pre,*del=NULL;
    pre=l;
    while (pre!=NULL){
        temp=pre;
        while (temp->pNext!=NULL) {
            if (temp->pNext->data == pre->data) {
                del=temp->pNext;
                temp->pNext=del->pNext;
                destroynode(del);
                count++;
            }
            else
                temp = temp->pNext;
        }
        pre=pre->pNext;
    }
    printf("%d same value \n",count);
    return l;
}

void testlistfunction(){
    T_elt t=0,add1=7,add2=8,test1=4,test2=-1;
    T_node * head,*now,*temp;
    head=now = newNode(t);
    for (int i = 2; i < 10; i=i+2) {
        now = tailAddNode(i, now);
    }

    temp=head;
    showList(temp);

    temp=head;
    unsigned int mycount=0;
    printf("\nsize of list is: %d\n", getSize(temp,mycount));

    temp=head;
    // scanf depend on T_elt
    head= sortAddNode(add1,temp);

    temp=head;
    showList((temp));

    temp=head;
    head= sortAddNode(add2,temp);

    temp=head;
    showList(temp);

    temp=head;
    if(inList(test1,temp)==0)
        printf("\n%s is not in list\n",toString(test1));
    else
        printf("\n%s is in list\n", toString(test1));

    temp=head;
    if(inList(test2,temp)==0)
        printf("\n%s is not in list\n",toString(test2));
    else
        printf("\n%s is in list\n", toString(test2));

    head= removeDuplicates(head);

    temp=head;
    showList(temp);
}