//
//  Questions:
//  - Write a function that will swap  pairs of elements in a given singly-linked list.
//    Note that you have to  actually swap the elements, not just the values, and that you should
//    modify the list in place (i.e. you should not create a copy of the  list).
//    For instance, the list 1->2->3->4->5->6->…  becomes 2->1->4->3->6->5->…
//
//    IMPORTANT: Your implementation must also work for  circular lists where the tail is pointing
//    back to the head of the list. You do not have to check if the tail points to an intermediate
//    (non-head) element.
//
//  @author João Pinho
//

#include <stdio.h>
#include <stdlib.h>

struct list_node {
    int val;
    struct list_node *next;
};

struct list_node *swap_pairs(struct list_node *head) {
    if(head == NULL) return NULL;
    
    struct list_node* n = head;
    struct list_node* new_head = head->next;
    
    //assuming list with number pair of elements;
    //assuming list with more at leat two elements;
    
    while(n->next != NULL && n->next != head)
    {
        struct list_node* e2 = n->next;
        struct list_node* e2_next = e2->next;
        
        e2->next = n;
        
        if(e2_next != NULL && e2_next != head)
            n->next = e2_next->next;
        else{
            n->next = e2_next;
            break;
        }
        
        n = e2_next;
    }
    
    //prev loop stopped due to circular list end
    if(n->next == head){
        n->next = new_head;
    }
    
    return new_head;
}

int main_5(void){
    int i=1, list_sz=6;
    struct list_node *list = (struct list_node*)calloc(6, sizeof(struct list_node));
    struct list_node *node = list;
    struct list_node *list_end = list + list_sz;

    while(node != list_end){
        node->val = i++;
        node->next = node+1;
        node++;
    }
    
    //non-circular list
    (node-1)->next=NULL;
    
    //circular list
    //(node-1)->next=list;
    
    node = list;
    while(node != list_end){
        printf("%d -> ", node->val);
        node++;
    }
    printf("||\n");
    
    struct list_node *new_list = swap_pairs(list);
    node = new_list;
    
    while(node != NULL){
        printf("%d -> ", node->val);
        node = node->next;
        
        if(node == new_list){
            printf(" [Circular List] -> ... -> ");
            break;
        }
    }
    printf("||\n");
    
    return 0;
}