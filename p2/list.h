#include "elt.h" // T_elt 

#ifndef _LIST_H_
#define _LIST_H_
//#define DEBUG
typedef struct node {
	T_elt data;
	struct node *pNext;
} T_node, * T_list;

T_node * addNode (T_elt e, T_node * n);
void showList(T_list l);
void freeList(T_list l);
void destroynode(T_node *n);
T_elt getFirstElt(T_list l);
T_list removeFirstNode(T_list l);
void showList_rec(T_list l);
void showList_inv_rec(T_list l);
void freeList_rec(T_list l);
unsigned int getSize(const T_list l,unsigned int mycount);
T_list tailAddNode(T_elt e, T_list l);
T_list sortAddNode(T_elt e, T_list l);
int inList(T_elt e, const T_list l);
T_list  removeDuplicates (T_list l);
void testlistfunction();
#endif 


