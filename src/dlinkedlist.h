/**
 * Double Linked List Header
 *
 * @author João Pinho
 */

#ifndef _DLINKEDLIST_
#define _DLINKEDLIST_
#define DUMMY_NVALUE -1000

typedef struct ll_node{
    int data;
    struct ll_node *next;
    struct ll_node *prev;
} ll_node;

ll_node* ll_create();
ll_node* ll_appendNode(ll_node*, int);
int ll_getValue(ll_node*);
void ll_setValue(ll_node*, int);

void ll_printi(ll_node*);
void ll_printc(ll_node*);
void _ll_print(ll_node*, const char* format);

#endif
