#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
	   int data;
	   Node* next;	
};
void append(Node** n,int data)
{
	Node* temp = new Node();
	temp->data = data;
	
	if((*n)==NULL)
	{
		*n = temp;
		return;
	}
	
	Node* temp1 = *n;
	while(temp1->next!=NULL)
	{
		temp1 = temp1->next;
	}
	temp1->next = temp;
}
void printlist(Node* n)
{
	Node* temp = n;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
void reverse(Node** n)
{
	Node* temp = *n;
	Node* prev = NULL;
	Node* next1 = NULL;
	
	while(temp!=NULL)
	{
		next1 = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next1;
	}
	*n = prev;
}
Node* reverse_1(Node* n)
{
	if(n==NULL||n->next==NULL)return n;
	
	Node* rest = reverse_1(n->next);
	
	n->next->next = n;
	
	n->next = NULL;
	
	return rest;
}
int main()
{
	 Node* head = NULL;
     append(&head,1);
     append(&head,2);
     append(&head,3);
     append(&head,4);
     append(&head,5);
     printlist(head);
     reverse(&head);
     printlist(head);
     Node* head1 = reverse_1(head);
     printlist(head1);
}
