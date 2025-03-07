#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
  // base case
  if(head == NULL)
  {
    larger = NULL;
    smaller = NULL;
    return;
  }
  // puts all vals larger than pivot into larger ll
  if(head->val > pivot)
  {
    larger = head;
    head = head->next;
    llpivot(head, smaller, larger->next, pivot);
  }
  else // puts all vals smaller than pivot into smaller ll
  {
    smaller = head;
    head = head->next;
    llpivot(head, smaller->next, larger, pivot);
  }
}
