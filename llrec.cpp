#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot)
{
    //end of list has been reached
    if(head == NULL)
    {
        smaller = NULL;
        larger = NULL;
        return;
    }

    Node* next = head->next;
    //smaller list
    if(head->val <= pivot)
    {
        smaller = head;
        larger = NULL;
        head->next = NULL;
        llpivot(next, smaller->next, larger, pivot);
    }

    //larger list
    else
    {
        larger = head;
        smaller = NULL;
        head->next = NULL;
        llpivot(next, smaller, larger->next, pivot);
    }

    head = NULL;


}
