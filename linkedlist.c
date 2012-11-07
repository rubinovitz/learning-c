/*							     */
/* assign3.c 					     */
/* Dynamic pointer list with bubblesort                 */

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define EMPTY 0

struct listelement_struct
{
  int    dataitem;
  struct listelement_struct *next;
};

typedef struct listelement_struct listelement;

void Menu(int *);
listelement *AddItem(listelement *, int);
listelement *RemoveItem(listelement *);
void PrintQueue(listelement *);
void ClearQueue(listelement *);
void Bubblesort(listelement *);

int main()
{
  listelement *listpointer;
  int data, choice;

  listpointer = EMPTY;
  do
  {
    Menu(&choice);
    switch (choice)
    {
      case 1: 
        printf("\nEnter data item value to add: ");
        scanf("%d", &data);
        listpointer = AddItem(listpointer, data);
        break;
      case 2: 
        if (listpointer == EMPTY)
        { printf("\nQueue empty!\n"); }
        else
        { listpointer = RemoveItem(listpointer); }
  	break;
      case 3: 
        PrintQueue(listpointer);
        break;
      case 4:
        Bubblesort(listpointer);
        break;				
      case 5: 
        break;
      default: 
        printf("\nInvalid menu choice (%d) - try again\n", choice);
        char dummy = getchar(); // Eats up our bad menu choice
        break;
    }
  } while (choice != 5);
  ClearQueue(listpointer);
  exit(0);
}				/* main */

void Menu(int *choice)
{
  int num;
  printf("\nEnter\t1 to add item\n\t2 to remove item\n");
  printf("\t3 to print queue\n\t4 to sort\n\t5 to quit\n");
  scanf("%d", &num);
  *choice = num;
}

listelement *AddItem(listelement *listpointer, int data)
{
  if (listpointer != EMPTY)
  {
    listelement *lp = listpointer;
    while (listpointer->next != EMPTY)
    { listpointer = listpointer->next; }
    listpointer->next = (listelement *) malloc(sizeof(listelement));
    listpointer = listpointer->next;
    listpointer->next = EMPTY;
    listpointer->dataitem = data;
    return lp;
  }
  else
  {
    listpointer = (listelement *) malloc(sizeof(listelement));
    listpointer->next = EMPTY;
    listpointer->dataitem = data;
    return listpointer;
  }
}

listelement *RemoveItem(listelement *listpointer)
{
  listelement *tempp;
  printf("\nElement removed is %d\n", listpointer->dataitem);
  tempp = listpointer->next;
  free(listpointer);
  return tempp;
}

void PrintQueue(listelement *listpointer)
{
  if (listpointer == EMPTY)
  { printf("\nqueue is empty!\n"); }
  else
  {
    printf("\nQueue Contents: ");
    while (listpointer != EMPTY)
    {
      printf("%d  ", listpointer->dataitem);
      listpointer = listpointer->next;
    }
  }
  printf("\n");
}

void ClearQueue(listelement *listpointer)
{
  while (listpointer != EMPTY)
  {
    listpointer = RemoveItem(listpointer);
  }
}
//sort list from least to greatest
void Bubblesort(listelement *listpointer)
{
    listelement *current;
    listelement *start;
    int swapped;
    int temp;

    // store initial listpointer
    start = listpointer;

    // set swapped to 1 to enter while loop 
    swapped = 1;

    while (swapped == 1){
        // change swapped to 0 to stop reentry of loop until swap
        swapped = 0;
        // set listpointer to current start listpointer
        listpointer = start;
        // while not at the end of listpointer 
            while (listpointer != EMPTY){
            // while the next item of list exists
                if (listpointer->next != EMPTY){ 
                    // if current dataitem is greater than the next dataitem
                    if (listpointer->dataitem > listpointer->next->dataitem){
                        // store the current dataitem
                        temp = listpointer->dataitem;
                        // make the current dataitem the next dataitem 
                        listpointer->dataitem = listpointer->next->dataitem;
                        /* make the next listpointer dataitem the old listpointer->dataitem */ 
                        listpointer->next->dataitem = temp;
                        /* set swapped to 1 so loop can begin again to check if dataitem is still greater than ->next->dataitem, and if so, repeat */
                        swapped = 1;
                    }
                }  
          // go to next item on list
          listpointer = listpointer->next;
          }

   }    


}

