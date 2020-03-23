#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *next;
}Node;

typedef struct list{
  Node * head;
  Node * tail;
}List;


List * create_list ();
Node * create_node ();
int    isEmpty     (List * list);
int    front       (List * list);
int    back        (List * list);
void   pop_front   (List * list);
void   push_back   (List * list, int info);
void   push_front  (List * list, int info);

List * create_list (){
  List * list = (List *) malloc(sizeof(List));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

Node * create_node (){
  struct node * node = (struct node *)malloc(sizeof(struct node));
  node->next = NULL;
  node->data = 0;
  return node;
}

int    isEmpty     (List * list){
  return(list->head == NULL);
}

int  front       (List * list){
  return(list->head->data);
}

int  back        (List * list){
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

void   push_back   (List * list, int info){
  Node * new_node;
  Node * p;
  new_node = create_node();
  new_node->data = info;
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

void   push_front   (List * list, int info){
  Node * new_node;
  Node * p;
  new_node = create_node();
  new_node->data = info;
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
    List * lista_a = create_list();
    List * lista_b = create_list();
 
    int c;
    int e;
    int count = 1;
    int controle = 0;

    scanf("%d", &c);
    for(int i =0; i < c; ++i){
        scanf("%d", &e);
        push_back(lista_a, e);
    }
    scanf("%d", &e);

    while(!isEmpty(lista_a) || !isEmpty(lista_b)){
        if(!isEmpty(lista_a)){
            if(front(lista_a) != count ){
                if (isEmpty(lista_b)){
                    push_front(lista_b,front(lista_a));
                    pop_front(lista_a);
                }else if(front(lista_b) == count){
                    pop_front(lista_b);
                    ++count;
                }else if(!isEmpty(lista_a)){
                    push_front(lista_b,front(lista_a));
                    pop_front(lista_a);
                }else{
                    controle = 1;
                    break;
                }
            }else {
                pop_front(lista_a);
                ++count;
            }
        }else if(!isEmpty(lista_b)){
            if(front(lista_b) == count){
                    pop_front(lista_b);
                    ++count;
            }else{
                controle = 1;
                break;
            }
        }   
    }

    if(controle){
       printf("no\n"); 
    }else{
        printf("yes\n");
    }
}