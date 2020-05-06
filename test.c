#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void displayMenu();
Node * InsertNodeBeginning(Node * head);
Node * InsertNodeEnd(Node * head);
Node * DeleteANode(Node * head);

int main()
{
  int done = 0, matches, intAnswer, c;
  Node * head = NULL;

  do
  {
    intAnswer = 0;
    displayMenu();

    matches =  scanf("%d", &intAnswer);
    
    if(matches == 0 || matches == EOF)
    {
      printf("Please enter a menu option.\n");
      while((c = getchar()) != '\n' && c != EOF);
    }
    
    switch (intAnswer)
    {
        case 1:
          head = InsertNodeBeginning(head);
          break;
        
        case 2:
          head = InsertNodeEnd(head);
          break;

        case 3:
          head = DeleteANode(head);
          break;

        case 4:
          List_destroy(head);
          head = NULL;
          break;

        case 5:
          List_print(head);
          break;

        case 6:
          done = 1;
          break;

        default:
          break;           
    }
    
    fflush(stdin);
      
  } while(!done);

  return 0;
}

void displayMenu()
{
  printf("1) Insert Head\n");
  printf("2) Insert Tail\n");
  printf("3) Delete a Node\n");
  printf("4) Delete All\n");
  printf("5) Display\n");
  printf("6) Exit\n"); 
}

Node * InsertNodeBeginning(Node * head)
{
  int intAnswer, matches, c;
  printf("Enter an integer to insert to the beginning:\n");

  matches =  scanf("%d", &intAnswer);

  if(matches == 0 || matches == EOF)
  {
    printf("Invalid value to insert.\n");
    while((c = getchar()) != '\n' && c != EOF);
    return head;
  }

  Node * newHead = List_insert(head, intAnswer);

  return newHead;
}

Node * InsertNodeEnd(Node * head)
{
  int intAnswer, matches, c;
  printf("Enter an integer to insert to the end:\n");

  matches =  scanf("%d", &intAnswer);

  if(matches == 0 || matches == EOF)
  {
    printf("Invalid value to insert.\n");
    while((c = getchar()) != '\n' && c != EOF);
    return head;
  }

  Node * newHead = List_insert_last(head, intAnswer);
  
  if(head == NULL)
  {
    return newHead;
  }
  
  else
  {
    return head;
  }
}

Node * DeleteANode(Node * head)
{
  int intAnswer, matches, c;
  printf("Enter an integer to delete a node for:\n");
  
  matches =  scanf("%d", &intAnswer);

  if(matches == 0 || matches == EOF)
  {
    printf("Invalid value to delete.\n");
    while((c = getchar()) != '\n' && c != EOF);
    return head;
  }

  Node * newHead = List_delete(head, intAnswer);

  return newHead;
}
