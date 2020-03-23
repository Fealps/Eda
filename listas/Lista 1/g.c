#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node{
  char data[26];
  struct node *next;
}Node;

typedef struct list{
  Node * head;
  Node * tail;
}List;


List * create_list ();
Node * create_node ();
int    isEmpty     (List * list);
char   last_letter (char * word);
char*  front       (List * list);
char*  back        (List * list);
void   pop_front   (List * list);
void   push_back   (List * list, char * info);

List * create_list (){
  List * list = (List *) malloc(sizeof(List));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

Node * create_node (){
  struct node * node = (struct node *)malloc(sizeof(struct node));
  node->next = NULL;
  strcpy(node->data,"");
  return node;
}

int    isEmpty     (List * list){
  return(list->head == NULL);
}

char*  front       (List * list){
  return(list->head->data);
}

char*  back        (List * list){
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

void   push_back   (List * list, char * info){
  Node * new_node;
  Node * p;
  new_node = create_node();
  strcpy(new_node->data,info);
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

char last_letter(char * word){
  int size = strlen(word);
  char last = word[size-1];
  return last;
}

char first_letter(char * word){;
  char first = word[0];
  return first;
}

int main(){
  List * listaCidades = create_list();
  Node * node;
  char cidade[26] = "";
  char prox_c[26] = "";
  char last, first;

  while(scanf("%s", cidade) != EOF){
    push_back(listaCidades, cidade);
    strcmp(cidade,"");
  }
  
  strcpy(cidade,front(listaCidades));
  last = last_letter(cidade);
  printf("%s\n",cidade);
  pop_front(listaCidades);
  
  while(!isEmpty(listaCidades)){
    strcpy(cidade,front(listaCidades));
    first = first_letter(cidade);
      if (toupper(first) == toupper(last)){
        push_back(listaCidades, cidade);
        pop_front(listaCidades);
      }
      strcpy(cidade,front(listaCidades));
      last = last_letter(cidade);
      printf("%s\n",cidade);
      pop_front(listaCidades);
  }
}