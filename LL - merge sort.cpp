#include<bits/stdc++.h>
using namespace std;
class Node { 
public: 
    int data; 
    Node* next; 
};
void split(Node* head,Node** a,Node** b)
{
	Node* slow = head;
	Node* fast = head->next;
	
	while(fast!=NULL)
	{
		fast = fast->next;
		if(fast!=NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}
	
	*a = head;
	*b = slow->next;
	
	slow->next = NULL; 
}
Node* merge(Node* a,Node* b)
{
	Node* res = NULL;
	
	if(a==NULL)return b;
	
	if(b==NULL)return a;
	
	if(a->data<=b->data)
	{
		res = a;
		res->next = merge(a->next,b);
	}
	else
	{
		res = b;
		res->next = merge(a,b->next);
	}
	
	return res;
}
void MergeSort(Node** headref)
{
	Node* head = *headref;
	
	Node* a;
	Node* b;
	
	if((head==NULL)||(head->next==NULL))return;
	
	split(head,&a,&b);
	
	MergeSort(&a);
	MergeSort(&b);
	
	*headref = merge(a,b);
}
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data << " "; 
        node = node->next; 
    } 
} 
  
/* Function to insert a node at the beginging of the linked list */
void push(Node** head_ref, int new_data) 
{ 
    /* allocate node */
    Node* new_node = new Node(); 
  
    /* put in the data */
    new_node->data = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
}
int main() 
{ 
    /* Start with the empty list */
    Node* res = NULL; 
    Node* a = NULL; 
  
    /* Let us create a unsorted linked lists to test the functions  
Created lists shall be a: 2->3->20->5->10->15 */
    push(&a, 15); 
    push(&a, 10); 
    push(&a, 5); 
    push(&a, 20); 
    push(&a, 3); 
    push(&a, 2); 
  
    /* Sort the above created Linked List */
    MergeSort(&a); 
  
    cout << "Sorted Linked List is: \n"; 
    printList(a); 
  
    return 0; 
} 
