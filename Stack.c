#include <stdio.h>
#include <process.h>
#define max 5

struct stack
{
	int a[max];
	int top;
};

void push (struct stack *sp, int item)
{
	if (sp->top == max-1)
	{
		printf("overflow");
		return;
	}
	sp->top = sp->top+1;
	sp->a[sp->top] = item;
	printf("\n Successfully pushed");
}

void pop (struct stack *sp)
{
	int item;
	if (sp->top == -1)
	{
		printf("underflow");
		return;
	}
	item = sp->a[sp->top];
	sp->top = sp->top-1;
	printf("\n Popped item is %d",item);
}

void display (struct stack so)
{
	int i;
	if (so.top == -1)
	{
		printf("underflow");
		return;
	}
	for (i=so.top; i>=0; i--)
	printf("\n %d", so.a[i]);
}

void size (struct stack so)
{
	printf("\n No.of items in the stack is %d", so.top+1);
}

void main ()
{
	int ch, item;
	struct stack s;
	s.top = -1;
	while (1)
	{
		printf("\n Stack Menu");
		printf("\n 1. Push \n 2. Pop \n 3. Display \n 4. Size \n 5. Exit ");
		printf("\n Enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1: printf("\n enter the item");
			scanf("%d",&item);
			push(&s,item);
			break;
		case 2: pop(&s); break;
		case 3: display(s); break;
		case 4: size(s); break;
		case 5: exit(0);
		default: printf("\n Sorry Wrong Choice");
		}
	}
}
