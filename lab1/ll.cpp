/* First implementation of linked list. Buggy. Only an idiot would use this. */

ll:ll()
{
  *head = NULL;
}

ll:addtail(int data)
{
  /* Test if empty list */

  if (*head = NULL)
  {
    node *temp;
    temp.someValue = data;
    temp.next = NULL;
    head = temp;
    return;
  }

  /* add to tail */

  node *temp;
  temp = head;
  while(*temp.next != NULL)
  {
    temp = *temp.next;
  }

  node *temp2;
  *temp2.someValue = temp;
  *temp2.next = NULL;

  *temp.next = temp2;
  return;
}
