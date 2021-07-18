#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
	 Node* next;
     int data;
};

void push(Node** n,int data)
{
	Node* temp = new Node();
	Node* temp1 = *n;
	temp->data = data;
	temp->next = *n;
	
	if(*n!=NULL)
	{
		while(temp1->next!=*n)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp;
	}
	else
	{
		temp->next = temp;
	}
	*n = temp;
}
void printlist(Node* n)
{
	Node* temp = n;
	if(n!=NULL)
	{
		do
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		while(temp!=n);
	}
	cout<<endl;
}
void split(Node* n,Node **n1,Node **n2)
{
	if(n==NULL)return;
	Node* first = n;
	Node* slow = n;
	
	while(first->next!=n&&first->next->next!=n)
	{
		first = first->next->next;
		slow = slow->next;
	}
	
	if(first->next->next==n)
	{
		first = first->next;
	}
	
	*n1 = n;
	
	if(n->next!=n)*n2 = slow->next;
	
	first->next = slow->next;
	slow->next = n;
}
int main()
{
	Node* head = NULL;
	Node* head1 = NULL;
	Node* head2 = NULL;
	push(&head,6);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	printlist(head);
	split(head,&head1,&head2);
	printlist(head1);
	printlist(head2);
}
