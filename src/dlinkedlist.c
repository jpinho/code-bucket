/**
 * Double Linked List Implementation
 *
 * @author João Pinho
 */

#include <stdio.h>
#include <stdlib.h>
#include "dlinkedlist.h"

ll_node* ll_create(){
    ll_node* head = (ll_node*)malloc(sizeof(ll_node));
    
    if(head==NULL){
        perror("Out of memory exception ocurred in ll_create.");
        exit(1);
    }
    
    head->data = 0;
    head->prev = head->next = NULL;
    return head;
}

ll_node* ll_appendNode(ll_node *head, int data){
    ll_node *nd = ll_create();
    nd->data = data;
    
    if(head->next==NULL){
        head->prev=nd;
        head->next=nd;
        nd->prev=head;
        return nd;
    }
    
    head->prev->next=nd;
    nd->prev = head->prev;
    head->prev = nd;
    
    return nd;
}

void ll_setValue(ll_node* node, int value){
    if(node==NULL) return;
    node->data=value;
}

int ll_getValue(ll_node* node){
    if(node==NULL) return -1;
    return node->data;
}

void ll_printi(ll_node* head){
    _ll_print(head, "%d");
}

void ll_printc(ll_node* head){
    _ll_print(head, "%c");
}

void _ll_print(ll_node* head, const char* format){
    ll_node* nd = head;
    if(head==NULL) return;
    
    while(nd != NULL){
        printf(format,nd->data);
        if(nd->next != NULL) printf("->");
        nd = nd->next;
    }
    
    printf("\n");
}