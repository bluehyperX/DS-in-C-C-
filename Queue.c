#include <stdio.h>
#include <process.h>
#define max 5

struct queue
{
	int a[max];
	int front;
	int rear;
};

void enqueue (struct queue *qp, int item)
{
	if (qp->rear == max-1)
	{
		printf("overflow");
		return;
	}
	qp->rear = qp->rear+1;
	qp->a[qp->rear] = item;
	if (qp->front == -1)
	qp->front = qp->front+1;
	printf ("\n Successfully inserted");
}

void dequeue (struct queue *qp)
{
	int item;
	if (qp->front == -1)
	{
		printf ("underflow");
		return;
	}
	item = qp->a[qp->front];
	if (qp->front == qp->rear)
	{
		qp->front = -1;
		qp->rear = -1;
	}
	else qp->front = qp->front+1;
	printf("\n Deleted item is %d",item);
}

void display (struct queue qo)
{
	int i;
	if (qo.front == -1)
	{
		printf("underflow");
		return;
	}
	for (i=qo.front; i<=qo.rear; i++)
	printf("\n %d", qo.a[i]);
}

void main ()
{
	int ch, item;
	struct queue q;
	q.front = -1;
	q.rear = -1;
	while (1)
	{
		printf("\n Queue Menu \n");
		printf("\n 1. Enqueue \n 2. Dequeue \n 3. Display \n 4. Exit ");
		printf("\n Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1: printf("\n enter the item\n");
			scanf("%d",&item);
			enqueue(&q,item);
			break;
		case 2: dequeue(&q); break;
		case 3: display(q); break;
		case 4: exit(0);
		default: printf("\n Sorry Wrong Choice. Try Again\n");
		}
	}
}
