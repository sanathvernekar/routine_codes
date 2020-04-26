#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node *ptr;
}*front,*rear,*temp,*front1,*rear1;
 
int frontelement();
int rearelement();
void enq(int data);
void deq();
void pop();
void empty();
void display();
void create();
void queuesize();
 
int count = 0;
 
int  main()
{
    int no, ch, e,n,i;
    create();
			scanf("%d",&n);
			for(i=0;i<n;i++){
			scanf("%d", &no);
            enq(no);
			}

			display();
			deq();
			pop();
			

			e = frontelement();
			

            if (e != 0)
                printf("Front element : %d", e);
            else
                printf("\n No front element in Queue as queue is empty");
			e=rearelement();
			if (e != 0)
                printf("rear  element : %d", e);
            else
                printf("\n No rear element in Queue as queue is empty");

			empty();
			

			display();

			queuesize();
        return 0;
    
}

void create()
{
    front = rear = NULL;
}
 
/* Returns queue size */
void queuesize()
{
    printf("\n Queue size : %d", count);
}
 
/* Enqueing the queue */
void enq(int data)
{
    if (rear == NULL)
    {
        
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;
		
 
        rear = temp;
    }
    count++;
}
 
/* Displaying the queue elements */
void display()
{
    front1 = front;
 
    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (front1 != rear)
    {
        printf(" %d ", front1->info);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf(" %d ", front1->info);
}
 
/* Dequeing the queue */
void deq()
{
    front1 = front;
 
    if (front1 == NULL)
    {
        printf("\n Error: Trying to display elements from empty queue");
        return;
    }
    else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            //printf("\n Dequed value : %d ", front->info);
            free(front);
            front = front1;
        }
        else
        {
            //printf("\n Dequed value : %d", front->info);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}

void pop(){
	//rear1=rear;
	if(rear==NULL)
	{
		printf("ERROR");
		return;
	}
	else if(rear->ptr !=NULL)
	{
		rear=rear->ptr;
		free(rear);
		//rear=rear1;
	}
	else{
		free(rear);
		front=NULL;
		rear=NULL;
	}
	count--;
}
		



}

 
/* Returns the front element of queue */
int frontelement()
{
    if ((front != NULL) && (rear != NULL))
        return(front->info);
    else
        return 0;
}
int rearelement()
{
if((front !=NULL) && (rear!=NULL))
	return(rear->info);
else
	return 0;
}
 
/* Display if queue is empty or not */
void empty()
{
     if ((front == NULL) && (rear == NULL))
        printf("\n Queue empty");
    else
       printf("Queue not empty");
}
