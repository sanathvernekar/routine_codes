
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

int count=0;
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
    int n, data, choice=1,left_val=0,right_val=0,i;
    int val1,val2;

    head = NULL;
    last = NULL;


 
		
		scanf("%d",&n);
		
		createList(n);
		displayList();
		
		   while(count>2){
		       val1=head->data;
		        val2=last->data;
		    
		if(val1>val2){
		left_val=left_val+val1;
		deleteFromBeginning();
		
		}
		else{
			left_val=left_val+val2;
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
		   
		   if(head->data>last->data){
		       left_val=left_val+head->data;
		       right_val=right_val+last->data;
		   }
		   else{
		       left_val=left_val+last->data;
		       right_val=right_val+head->data;
		   }
		
		
		
		
		if(left_val>right_val)
			printf("%d",left_val);
		else
			printf("%d",right_val);
        
		
		//displayList();
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
        count++;
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            //printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->prev = last; 
            newNode->next = NULL;

            last->next = newNode; 
            last = newNode; 
            count++;
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
        count--;
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
        count--;
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



