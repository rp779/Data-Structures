#include <iostream>
#include "basicActions.h"
using namespace std;

Node *reverseNodes(Node *head, int k)
{
    Node *start = head;
    Node *p, *q, *r, *first;
    first = head;
    p = head;
    q = p->next;
    r = q->next;

    while (k != 1)
    {
        q->next = p;
        p = q;
        q = r;
        r = r->next;
        k--;

        if (k == 1)
        {
            q->next = p;
            first->next = r;
            head = q;
            return head;
        }
    }
}

int main()
{
    Node *head = NULL;
    int k;

    cin >> k;

    head = createNode(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);
    insertAtEnd(head, 7);
    insertAtEnd(head, 8);
    insertAtEnd(head, 9);

    head = reverseNodes(head, k - 1);
    displayNodes(head);
}