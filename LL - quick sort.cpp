#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};
 
/* A utility function to insert a node at the beginning of
 * linked list */
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node = new Node;
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* A utility function to print linked list */
void printList(struct Node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
 
// Returns the last node of the list
struct Node* getTail(struct Node* cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}
struct Node* partition(struct Node* head,struct Node* end,struct Node **newHead,struct Node **newEnd)
{
	struct  Node* pivot = end;
	struct Node *prev = NULL,*curr = head,*tail = pivot;
	
	while(curr!=pivot)
	{
		if(curr->data<pivot->data)
		{
			if((*newHead)==NULL)
			{
				*newHead = curr;
			}
			
			prev = curr;
			curr = curr->next;
		}
		else
		{
			if(prev)prev->next = curr->next;
			
			struct Node* temp = curr->next;
			curr->next = NULL;
			tail->next = curr;
			tail = curr;
			curr = temp;
		}
	}
	
	if((*newHead)==NULL)*newHead = pivot;
	
	(*newEnd) = tail;
	
	return pivot;
}
struct Node* quick(struct Node* head,struct Node* end)
{
	if(head==NULL||head==end)return head;
	
	Node* newHead = NULL;
	Node* newEnd = NULL;
	
	struct Node* pivot = partition(head,end,&newHead,&newEnd);
	
	if(newHead!=pivot)
	{
		struct Node* temp = newHead;
		
		while(temp->next!=pivot)
		{
			temp = temp->next;
		}
		temp->next = NULL;
		
		newHead = quick(newHead,temp);
		
		temp = getTail(newHead);
		temp->next = pivot;
	}
	pivot->next = quick(pivot->next,newEnd);
	
	return newHead;
}
void quicksort(Node **headref)
{
	(*headref) = quick(*headref,getTail(*headref));
	return;
}
int main()
{
    struct Node* a = NULL;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);
 
    cout << "Linked List before sorting \n";
    printList(a);
 
    quicksort(&a);
 
    cout << "Linked List after sorting \n";
    printList(a);
 
    return 0;
}
