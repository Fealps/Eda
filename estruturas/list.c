#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 26
#define f_type char *
#define s_type char
#define copy_f strcpy(node->data,"")
#define copy_mec strcpy(new_node->data,info)
//------------- Char list -----------------
/*
    Char list in c
    if you need to change the type of the list
    use the define.
    f_type is the function type
    s_type is the struct type
    copy_f is the copy mechanism on the node initialization
    copy_mec is the copy mechanis on the push funtion
    to use on a int for example 
    copy_f should be blank and copy_mec should be new_node->data = info;
*/

typedef struct node{
    s_type data[MAX];
    struct node *next;
}Node;

typedef struct list{
    Node * head;
    Node * tail;
}List;

List * create_list ();

Node * create_node ();

int    isEmpty     (List * list);

f_type  front      (List * list);
f_type  back       (List * list);

void   pop_front   (List * list);
void   push_back   (List * list, f_type info);
void   push_front  (List * list, f_type info);

List * create_list (){
    List * list = (List *) malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

Node * create_node (){
    struct node * node = (struct node *)malloc(sizeof(struct node));
    node->next = NULL;
    copy_f;
    return node;
}

int    isEmpty     (List * list){
    return(list->head == NULL);
}

f_type  front       (List * list){
    return(list->head->data);
}

f_type  back        (List * list){
    return(list->tail->data);
}

void   pop_front   (List * list){
    Node * temp;
    if(!isEmpty(list)){
        temp = list->head;
        list->head = temp->next;
        free(temp);
    }    
}

void   push_back   (List * list, f_type info){
    Node * new_node;
    Node * p;
    new_node = create_node();
    copy_mec;
    if(list->head == NULL){
        list->head = new_node;
        list->tail = new_node;
    }else
    {
        p = list->tail;
        p->next = new_node;
        list->tail = new_node;
    }  
}

void   push_front   (List * list, f_type info){
    Node * new_node;
    Node * p;
    new_node = create_node();
    copy_mec;
    if(list->head == NULL){
        list->head = new_node;
        list->tail = new_node;
    }else
    {
        p = list->head; 
        new_node->next = p;
        list->head = new_node;
    }
}


int main(){

    List * lista = create_list();

    push_back(lista, "cidade");
    push_front(lista,"abacate");
   
    printf("front: %s\n",front(lista));
    printf("back: %s\n", back(lista));
    
    pop_front(lista);

    printf("front: %s\n",front(lista));
    printf("back: %s\n", back(lista));
    
}