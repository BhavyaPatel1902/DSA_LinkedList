#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
 
// 'compare' function used to build up the
// priority queue
struct compare {
    bool operator()(struct Node* p1, struct Node* p2)
    {
        return p1->data > p2->data;
    }
};
void push(struct Node** head_ref, int new_data)
{
    // allocate node
    struct Node* new_node = 
          (struct Node*)malloc(sizeof(struct Node));
 
    // put in the data
    new_node->data = new_data;
 
    // since we are adding at the beginning,
    // prev is always NULL
    new_node->prev = NULL;
 
    // link the old list off the new node
    new_node->next = (*head_ref);
 
    // change prev of head node to new node
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    // move the head to point to the new node
    (*head_ref) = new_node;
}
 
// Function to print nodes in a given doubly linked list
void printList(struct Node* head)
{
    // if list is empty
    if (head == NULL)
        cout << "Doubly Linked list empty";
 
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
Node* sortAKSortedDLL(Node* head,int k)
{
	if(head==NULL)return head;
	
	priority_queue <Node* , vector <Node*> , compare > q;
	
	struct Node* newHead = NULL;
	struct Node* last;
	
	for(int i=0;head!=NULL&&i<=k;i++)
	{
		q.push(head);
		
		head = head->next;
	}
	
	while(!q.empty())
	{
		if(newHead==NULL)
		{
			newHead = q.top();
			newHead->prev = NULL;
			last = newHead;
		}
		else
		{
			last->next = q.top();
			q.top()->prev = last;
			last = q.top();
		}
		q.pop();
		
		if(head!=NULL)
		{
			q.push(head);
			
			head = head->next;
		}
	}
	
	last->next = NULL;
	
	return newHead;
}
int main()
{
    struct Node* head = NULL;
 
    // Create the doubly linked list:
    // 3<->6<->2<->12<->56<->8
    push(&head, 8);
    push(&head, 56);
    push(&head, 12);
    push(&head, 2);
    push(&head, 6);
    push(&head, 3);
 
    int k = 2;
 
    cout << "Original Doubly linked list:n";
    printList(head);
 
    // sort the biotonic DLL
    head = sortAKSortedDLL(head, k);
 
    cout << "\nDoubly linked list after sorting:n";
    printList(head);
 
    return 0;
}
