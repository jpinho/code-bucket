/**
 *  Question:
 *  - Write code to remove duplicates from an unsorted linked list.
 *
 *  Assumptions:
 *  - Solving assuming a temporary buffer is not allowed.
 *
 *  @author João Pinho
 */

#include <stdio.h>
#include <stdlib.h>
#include "dlinkedlist.h"

ll_node* removeDuplicates(ll_node*, ll_node*);

int main_3(int argc, char* argv[])
{
    ll_node* list = ll_create();
    ll_setValue(list, 9);
    ll_appendNode(list, 10);
    ll_appendNode(list, 10);
    ll_appendNode(list, 8);
    ll_appendNode(list, 7);
    ll_appendNode(list, 9);
    ll_appendNode(list, 11);
    ll_appendNode(list, 11);
    ll_printi(list);
    
    list = removeDuplicates(list, list);
    ll_printi(list);
    
    return 0;
}

/**
 * So the idead behind this simple recursive function is to, go from element to element, 
 * and for each recursion, the n-i, i € [1,n-1], are check to see if their are a duplicate 
 * of the i-th element.
 *
 * @param head the head of the double linked list.
 * @param elem the i-th element used to check for duplicates.
 */
ll_node* removeDuplicates(ll_node* head, ll_node* elem){
    if(elem == NULL)
        return head;
    
    ll_node* nd=elem->next;
    
    while(nd != NULL){
        ll_node* temp=NULL;
        
        if(ll_getValue(elem)==ll_getValue(nd)){
            nd->prev->next=nd->next;

            if(nd->next != NULL)
                nd->next->prev = nd->prev;
            
            temp = nd;
        }
        
        nd=nd->next;
        
        if(temp!=NULL) free(temp);
    }
    
    return removeDuplicates(head, elem->next);
}