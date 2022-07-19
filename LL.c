void PrintReverseLL (struct Node *p)
{
  if (ptr == NULL)
  {
    printf("Unf");
    return;
  }
  //If LL contains only one node
  if (ptr->link == NULL)
  {
    printf("\n%d\n", ptr->info);
    return;
  }
  else
  {
    PrintReverseLL(ptr->link);
    printf("\n%d\n", ptr->info);
  }
}

void Reverse(struct list *lp)
{
  struct Node *p = lp->start;
  struct Node *q = NULL;
  struct Node *r;
  while (p != NULL)
  {
    r=q;
    q=p;
    p=p->link;
    q->link=r;
  }
  lp->start=q;
}

void ConcateLL(struct list *l1, struct list *l2)
{
  struct Node *ptr = lp1->start;
  while (ptr->link != NULL)
  {
    ptr = ptr->link;
  }
  ptr->link = lp2->start;
}

void UnionLL(struct list *l1, struct list *l2)
{
  struct Node *p1 = lp1->start;
  struct Node *p2 = lp2->start;
  struct link a;
  while (p1 != NULL)
  {
    while (p2 != NULL)
    {
      if (p1->info == p2->info)
      {
        //struct Node *newnode = (struct Node *)malloc(sizeof(struct Node))
        p2=p2->link;
      }
      else
      {

      }
    }
  }
}

void IntersectionLL(struct list *l1, struct list *l2)
{

}

void PolyAddLL(struct list *l1, struct list *l2)
{

}
