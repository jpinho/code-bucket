/**
 *  Question: 
 *  - Implement an algorithm to delete a node in the middle of a singly linked list, 
 *    given only access to that node.
 *    
 *    EXAMPLE
 *    Input: the node c from the linked list a->b->c->d->e
 *    
 *    Result: nothing is returned, but the new linked list looks like a->b->d->e
 *
 *  @author João Pinho
 */

#include <stdio.h>
#include <stdlib.h>
#include "dlinkedlist.h"

void deleteNode(ll_node*);

/**
 * My idea for this one is: if you only see whats in front of you, and you dont matter no more,
 * then give (recursively) your place to the nodes standing in front of you, and pass the message
 * to then, saying the should do the same. In the end, the last element, should clean up the extra
 * space lef calling free upon is old place.
 *
 * Note: I'm using Double Linked List without using the pointer prev, so it's like using SingleLL.
 */
int main(int argc, char* argv[]){
    ll_node* list = ll_create();

    ll_setValue(list, 'a');
    ll_appendNode(list, 'b');

    ll_node* nodeC = ll_appendNode(list, 'c');
    
    ll_appendNode(list, 'd');
    ll_appendNode(list, 'e');
    ll_appendNode(list, 'f');
    ll_printc(list);
 
    deleteNode(nodeC);
    ll_printc(list);
    
    return 0;
}

void deleteNode(ll_node* nd){
    if(nd==NULL) return;
    
    if(nd->next == NULL){
        nd->data = DUMMY_NVALUE;
        return;
    }
    
    ll_setValue(nd, ll_getValue(nd->next));
    nd->next = nd->next->next;
    free(nd->next);
}