#include <stdio.h>
#include <stdlib.h>

/* a node of the doubly linked list */

struct Node
{
int data;
struct Node *next;
struct Node *prev;
};

/* Function to delete a node in a Doubly Linked List.
head_ref --> pointer to head node pointer.
del --> pointer to node to be deleted. */
void deleteNode(struct Node **head_ref, struct Node *del)
{
/* base case */
if(*head_ref == NULL || del == NULL)
	return;

/* If node to be deleted is head node */
if(*head_ref == del)
	*head_ref = del->next;

/* Change next only if node to be deleted is NOT the last node */
if(del->next != NULL)
	del->next->prev = del->prev;

/* Change prev only if node to be deleted is NOT the first node */
if(del->prev != NULL)
	del->prev->next = del->next;	 

/* Finally, free the memory occupied by del*/
free(del);
return;
}	 

/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginning of the Doubly Linked List */
void push(struct Node** head_ref, int new_data)
{
/* allocate node */
struct Node* new_node =
	(struct Node*) malloc(sizeof(struct Node));

/* put in the data */
new_node->data = new_data;

/* since we are adding at the begining,
	prev is always NULL */
new_node->prev = NULL;

/* link the old list off the new node */
new_node->next = (*head_ref); 

/* change prev of head node to new node */
if((*head_ref) != NULL)
(*head_ref)->prev = new_node ; 

/* move the head to point to the new node */
(*head_ref) = new_node;
}

/* Function to print nodes in a given doubly linked list
This function is same as printList() of singly linked lsit */
void printList(struct Node *node)
{
while(node!=NULL)
{
printf("%d ", node->data);
node = node->next;
}
}

/* Drier program to test above functions*/
int main()
{
/* Start with the empty list */
struct Node* head = NULL;

/* Let us create the doubly linked list 10<->8<->4<->2 */
push(&head, 2);
push(&head, 4);
push(&head, 8);
push(&head, 10);

printf("\n Original Linked list ");
printList(head);

/* delete nodes from the doubly linked list */
deleteNode(&head, head); /*delete first node*/
deleteNode(&head, head->next); /*delete middle node*/
deleteNode(&head, head->next); /*delete last node*/

/* Modified linked list will be NULL<-8->NULL */
printf("\n Modified Linked list ");
printList(head);		 

getchar();
}

























#include <stdio.h>
#include <stdlib.h>


/*
 * Basic structure of Node
 */
struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head, *last;


/*
 * Functions used in this program
 */
void createList(int n);
void displayList();
void deleteFromBeginning();
void deleteFromEnd();
void deleteFromN(int position);

int main()
{
    int n, data, choice=1,left_val=0,right_val=0;

    head = NULL;
    last = NULL;


 
		
		scanf("%d",&n);
		
		createList(n);
		displayList();
		while(head!=NULL && last!=NULL){
		if(head->data>last->data){
		left_val=left_val+head->data;
		deleteFromBeginning();
		
		}
		else{
			left_val=left_val+last->data;
			deleteFromEnd();
		}
		if(head->data>last->data){
		right_val=right_val+head->data;
		deleteFromBeginning();
		
		}
		else{
			right_val=right_val+last->data;
			deleteFromEnd();
		}
		
		}
		if(left_val>right_val)
			printf("%d",left_val);
		else
			printf("%d",right_val);

		
		displayList();
		//deleteFromBeginning();
		//deleteFromEnd();
		//deleteFromN(1);
		//displayList();
		
        
        printf("\n\n\n\n\n");
    

    return 0;
}

void createList(int n)
{
    int i, data;
    struct node *newNode;

    if(n >= 1)
    {
        /*
         * Creates and links the head node
         */
        head = (struct node *)malloc(sizeof(struct node));

        //printf("Enter data of 1 node: ");
        scanf("%d", &data);

        head->data = data;
        head->prev = NULL;
        head->next = NULL;

        last = head;
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            //printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->prev = last; // Link new node with the previous node
            newNode->next = NULL;

            last->next = newNode; // Link previous node with the new node
            last = newNode; // Make new node as last node
        }

        //printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}

void displayList()
{
    struct node * temp;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;
        printf("DATA IN THE LIST:\n");

        while(temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);

            n++;

            /* Move the current pointer to next node */
            temp = temp->next;
        }
    }
}
void deleteFromBeginning()
{
    struct node * toDelete;

    if(head == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = head;

        head = head->next; // Move head pointer to 2 node
        head->prev = NULL; // Remove the link to previous node

        free(toDelete); // Delete the first node from memory
        printf("SUCCESSFULLY DELETED NODE FROM BEGINNING OF THE LIST.\n");
    }
}
void deleteFromEnd()
{
    struct node * toDelete;

    if(last == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = last;

        last = last->prev; // Move last pointer to 2nd last node
        last->next = NULL; // Remove link to of 2nd last node with last node

        free(toDelete);       // Delete the last node
        printf("SUCCESSFULLY DELETED NODE FROM END OF THE LIST.\n");
    }
}



void deleteFromN(int position)
{
    struct node *current;
    int i;

    current = head;
    for(i=1; i<position && current!=NULL; i++)
    {
        current = current->next;
    }

    if(position == 1)
    {
        deleteFromBeginning();
    }
    else if(current == last)
    {
        deleteFromEnd();
    }
    else if(current != NULL)
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;

        free(current); // Delete the n node

        printf("SUCCESSFULLY DELETED NODE FROM %d POSITION.\n", position);
    }
    else
    {
        printf("Invalid position!\n");
    }
}



