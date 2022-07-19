#include <iostream>
#include <process.h>
using namespace std;
struct Node
{
	int info;
	Node *link;
};

struct list
{
	Node *start;
};

void Insert_FirstNode(list *lp, int item)
{
	Node *newnode = new Node;
	newnode->info = item;
	newnode->link = lp->start;
	lp->start = newnode;
	cout <<"\n" << item <<" Inserted Successfully";
}

void Insert_LastNode(list *lp, int item)
{
	Node *newnode = new Node;
	newnode->info = item;
	newnode->link = NULL;
	// LL is empty
	if (lp->start == NULL)
	{
		lp->start = newnode;
		cout <<"\n" << item <<" Inserted Successfully";
		return;
	}
	//LL is not empty
	Node *ptr = lp->start;
	while (ptr ->link != NULL)
		ptr = ptr->link;
	ptr->link = newnode;
	cout <<"\n" << item <<" Inserted Successfully";
}

void Delete_FirstNode(list *lp)
{
	if (lp->start == NULL)
	{
		cout <<"\n Underflow";
		return;
	}
 	Node *ptr = lp->start;
	lp->start = lp->start->link;
	cout<<"\nDeleted item is "<<ptr->info;
	delete ptr;
}

void Delete_LastNode(list *lp)
{
	if (lp->start == NULL)
	{
		cout <<"\n Underflow";
		return;
	}
	//If LL contains only one node
	if (lp->start->link == NULL)
	{
 		Node *ptr = lp->start;
		lp->start = NULL;
		cout<<"\nDeleted item is "<<ptr->info;
		delete ptr;
		return;
	}
	//If LL contains more than one node
	Node *save = lp->start;
	Node *ptr = lp->start->link;
	while (ptr->link != NULL)
	{
		save = ptr;
		ptr = ptr->link;
	}
	save->link = NULL;
	cout<<"\nDeleted item is "<<ptr->info;
	delete ptr;
}

void Insert_Y_After_X(list *lp, int X, int Y)
{
	Node *newnode = new Node;
	Node *p;
	Node *ptr;
	newnode->info = Y;
	if (lp->start == NULL)
	{
		cout << "\n LL is empty";
		return;
	}
	ptr=lp->start;
	while (ptr->info != X && ptr->link != NULL)
		ptr=ptr->link;
	if (ptr->info == X)
	{
		newnode->link = ptr->link;
		ptr->link = newnode;
		ptr = NULL;
		newnode = NULL;
		cout <<"\n" << Y <<" Inserted Successfully";
	}
	else cout << "\n" << X << " is not present";
}

void Insert_Y_After_X_Node(list *lp, int X, int Y)
{
	int count=0;
	Node *newnode = new Node;
	Node *p;
	Node *ptr;
	newnode->info = Y;
	if (lp->start == NULL)
	{
		cout << "\n LL is empty";
		return;
	}
	ptr=lp->start;
	while (ptr != NULL)
	{
		count=count+1;
		if (count == X)
		{
			newnode->link = ptr->link;
			ptr->link = newnode;
			cout <<"\n" << Y <<" Inserted Successfully";
			return;
		}

		ptr=ptr->link;
	}
}

void Insert_Y_Before_X(list *lp, int X, int Y)
{
	Node *newnode = new Node;
	Node *p;
	Node *ptr;
	newnode->info = Y;
	if (lp->start == NULL)
	{
		cout << "\n LL is empty";
		return;
	}
	p=lp->start;
	// if first node contains X
	if (lp->start->info == X)
	{
		newnode->link = lp->start;
		lp->start = newnode;
		newnode = NULL;
		cout <<"\n" << Y <<" Inserted Successfully";
		return;
	}
	//// if LL contains more than 1 node
	ptr=lp->start->link;
	while (ptr->info != X && ptr->link != NULL)
	{
		p=ptr;
		ptr=ptr->link;
	}
	if (ptr->info == X)
	{
		newnode->link = p->link;
		p->link = newnode;
		p = NULL;
		newnode = NULL;
		cout <<"\n" << Y <<" Inserted Successfully";
	}
	else cout << "\n" << X << " is not present";
}

void Delete_X(list *lp, int X)
{
	Node *p;
	Node *ptr;
	if (lp->start == NULL)
	{
		cout << "\n Underflow";
		return;
	}
	ptr=lp->start;
	//If first node contains info X
	if (lp->start->info == X)
	{
		lp->start=ptr->link;
		cout << "\nDeleted item is "<< ptr->info;
		delete ptr;
		return;
	}
	// If LL contains more than one node
	while (ptr->info != X && ptr->link != NULL)
	{
		p=ptr;
		ptr=ptr->link;
	}
	if (ptr->info == X)
	{
		p->link=ptr->link;
		cout << "\nDeleted item is "<< ptr->info;
		delete ptr;
	}
	else  cout << "\n" << X << " is not present";
}

void Delete_Node_After_X(list *lp, int X)
{
	Node *p;
	Node *ptr;
	if (lp->start == NULL)
	{
		cout << "\n Underflow";
		return;
	}
	ptr=lp->start;
	while (ptr->info != X && ptr->link != NULL)
		ptr=ptr->link;
	if (ptr->info == X)
	{
		if (ptr->link != NULL)
		{
			p=ptr->link;
			ptr->link = p->link;
			cout << "\nDeleted item is "<< p->info;
			delete p;
		} else cout << "\nNo entry is present";
	}
	else cout << "\n" << X << " is not present";
}

void Delete_Node_Before_X (list *lp, int X)
{
	Node *p;
	Node *ptr;
	if (lp->start == NULL)
	{
		cout << "\n Underflow";
		return;
	}
	ptr=lp->start;
	//If first node contains info X
	if (ptr->info == X)
	{
		cout << "No node is present";
		return;
	}
	else if (lp->start->link->info == X)
	{
		lp->start=lp->start->link;
		cout << "\nDeleted item is "<< ptr->info;
		delete ptr;
		return;
	}
	while (ptr->link->info != X && ptr->link->link != NULL)
	{
        p=ptr;
        ptr=ptr->link;
    }
	if (ptr->link->info == X)
	{
		p->link=ptr->link;
		cout << "\nDeleted item is "<< ptr->info;
		delete ptr;
	}
	else cout << "\n" << X << " is not present";
}

void display(list lo)
{
	if (lo.start == NULL)
	{
		cout << "\n LL is Empty";
		return;
	}
	Node *ptr = lo.start;
	while (ptr != NULL)
	{
		cout << "\n" << ptr->info;
		ptr = ptr->link;
	}
}

void search_X(list lo, int X)
{
    if (lo.start == NULL)
    {
        cout << "\n LL is Empty";
        return;
    }
    Node *ptr = lo.start;
    while (ptr->info != X && ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    if (ptr->info == X)
        cout << "\n" << X <<" is present";
    else cout << "\n" << X <<" is not present";
}

void count_X(list lo, int X)
{
		int count = 0;
    if (lo.start == NULL)
    {
        cout << "\n LL is Empty";
        return;
    }
    Node *ptr = lo.start;
    while (ptr != NULL)
    {
				if (ptr->info == X)
					count=count+1;
        ptr = ptr->link;
    }
    if (count == 0)
				cout << "\n" << X <<" is not present";
		else
        cout << "\n" << count << " \"" << X <<"\" is/are present";
}

void count_nodes(list lo)
{
	int count=0;
	if (lo.start == NULL)
	{
		cout << "\n LL is Empty";
		return;
	}
	Node *ptr = lo.start;
	while (ptr != NULL)
	{
		count=count+1;
		ptr = ptr->link;
	}
	cout << "\n" << count << " node is/are present";
}

int main()
{
	int ch, item, X, Y;
	list l;
	l.start = NULL;
	Insert_FirstNode (&l, 5);
	Delete_FirstNode(&l);
	Insert_LastNode (&l, 10);
	Insert_LastNode (&l, 10);
	Insert_LastNode (&l, 20);
	Insert_LastNode (&l, 30);
	Insert_LastNode (&l, 40);
	Insert_LastNode (&l, 50);
	Insert_LastNode (&l, 50);
	Insert_LastNode (&l, 50);
	Insert_LastNode (&l, 50);
	Insert_LastNode (&l, 50);
	Insert_LastNode (&l, 50);
	Insert_LastNode (&l, 50);
	Insert_LastNode (&l, 60);
	Insert_LastNode (&l, 70);
	Insert_LastNode (&l, 80);
	Insert_Y_After_X (&l, 30, 35);
	Insert_Y_Before_X (&l, 30, 25);
	Delete_X(&l,80);
	Delete_LastNode(&l);
	Delete_Node_Before_X (&l, 50);
	Delete_Node_After_X (&l, 50);
	Insert_Y_After_X_Node (&l,1,12);
	display (l);
	search_X (l, 10);
	count_X (l, 50);
	count_nodes(l);

// 	printf("\n\n\tLinkedList Menu\n\n");
// 	printf("This program creats a list of objects which can both numbers and alphabets. Select a choice from below.\n\n" );
// 	printf(" 1. Insert First Entry\n 2. Insert Next Entry\n 3. Delete First Entry\n 4. Delete Last Entry\n 5. Insert Y After X\n 6. Insert Y Before X\n 7. Delete X\n 8. Delete Entry After X\n 9. Delete Entry Before X\n 10. Display All Entries\n 11. Search X\n 12. Count X\n 13. Count Entries\n 14. Exit\n");
// 	while (1)
// 	{
// 	printf("\n\n\tEnter Your Choice\n");
// 	scanf("%d",&ch);
// 	//printf("Your Choice is %d\n",ch);
// 	switch (ch) {
// 		case 1:	printf("Enter the item \n");
// 						scanf("%d",&item);
// 						Insert_FirstNode (&l, item);
// 						break;
// 	  case 2:	printf("Enter the item \n");
// 				 		scanf("%d",&item);
// 				 		Insert_LastNode (&l, item);
// 				 		break;
// 		case 3: Delete_FirstNode(&l); break;
// 		case 4:	Delete_LastNode (&l); break;
// 		case 5:	printf("Enter X\n");
// 						scanf("%d",&X);
// 						printf("Enter Y\n");
// 						scanf("%d",&Y);
// 						Insert_Y_After_X (&l, X, Y);
// 						break;
// 		case 6: printf("Enter X\n");
// 						scanf("%d",&X);
// 						printf("Enter Y\n");
// 						scanf("%d",&Y);
// 						Insert_Y_Before_X (&l, X, Y);
// 						break;
// 		case 7: printf("Enter X\n");
// 						scanf("%d",&X);
// 						Delete_X (&l, X);
// 						break;
// 		case 8: printf("Enter X\n");
// 						scanf("%d",&X);
// 						Delete_Node_After_X (&l, X);
// 						break;
// 		case 9: printf("Enter X\n");
// 						scanf("%d",&X);
// 						Delete_Node_Before_X (&l, X);
// 						break;
// 		case 10: display(l); break;
// 		case 11: printf("Enter X\n");
// 						scanf("%d",&X);
// 						search_X (l, X);
// 						break;
// 		case 12: printf("Enter X\n");
// 						scanf("%d",&X);
// 						count_X (l, X);
// 						break;
// 		case 13: count_nodes(l); break;
// 		case 14: exit(0);
// 		default: printf("\nSorry Wrong Choice. Try Again\n"); printf("\n 1. Insert First Entry\n 2. Insert Next Entry\n 3. Delete First Entry\n 4. Delete Last Entry\n 5. Insert Y After X\n 6. Insert Y Before X\n 7. Delete X\n 8. Delete Entry After X\n 9. Delete Entry Before X\n 10. Display All Entries\n 11. Search X\n 12. Count X\n 13. Count Entries\n 14. Exit\n");
//  break;
// 	}
// }
return 0;
}
