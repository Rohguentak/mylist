#include <stdlib.h>
#include <stdio.h>
#include "mylist.h"

void mylist_init(struct mylist* l)
{
  l->Head = NULL;
  l->before = NULL;
  l->cur = NULL;
}

void mylist_destroy(struct mylist* l)
{
 
   //struct mylist_node* deln;
   for (struct mylist_node* pointer = l->Head; pointer != NULL; pointer = pointer->nextnode)
  {
    /* deln = l->Head;
    l->Head = deln->nextnode;
    free(deln);*/
    mylist_remove(l,pointer);
  }
  
}

void mylist_insert(struct mylist* l, struct mylist_node* before, int data)
{
  struct mylist_node * newnd = (struct mylist_node *)malloc(sizeof(struct mylist_node));
  newnd->data = data;
  newnd->nextnode = NULL;
  if(before == NULL){
    newnd->nextnode = l->Head;
    l->Head = newnd;
  }
  else{
    newnd->nextnode = before->nextnode;
    before->nextnode = newnd;
  }
}

void mylist_remove(struct mylist* l,struct mylist_node* target)
{
  if (target == NULL){
    exit(-1);
  }
  else if(target ==l->Head){
    l->Head = target->nextnode;
    free(target);
  }
  else
  {
   mylist_find(l,target->data);
   l->before->nextnode =  target->nextnode;
   free(target);
  }
}

struct mylist_node* mylist_find(struct mylist* l, int target)
{
  l->cur = l->Head;
  while (1){
    if (l->cur->data == target ||l->cur ==NULL){
      return l->cur;
    }
    l->before = l->cur;
    l->cur = l->cur->nextnode;
  }

  return NULL; // If not found
}

struct mylist_node* mylist_get_head(struct mylist* l)
{
  if(l->Head != NULL){
    return l->Head;
  }
  return NULL;
}

void mylist_print(const struct mylist* l)
{
  /*
   * HINT: Define structs referring comments
  for (struct mylist_node* pointer = l->head;
      pointer != NULL;
      pointer = pointer->next) {
    printf("%d\n", pointer->data);
  }
  */
 for (struct mylist_node* pointer = l->Head; pointer != NULL; pointer = pointer->nextnode)
  {
    printf("%d\n", pointer->data);
  }
  
}
