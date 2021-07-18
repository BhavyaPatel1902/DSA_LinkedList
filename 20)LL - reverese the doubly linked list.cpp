#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
		int data;
		Node* next;
		Node* prev;
};
void addfront(Node** n,int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = *n;
	temp->prev = NULL;
	if((*n)!=NULL)
	    (*n)->prev = temp;
	*n = temp;
}
void addafter(Node* n,int key,int data)
{
	Node* temp = n;
	Node* temp1 = new Node();
	temp1->data = data;
	while(temp->data!=key)
	{
		temp = temp->next;
	}
	temp1->next = temp->next;
	temp1->prev = temp;
	temp->next = temp1;
	if(temp1->next!=NULL)
	   temp1->next->prev = temp1;
}
void addend(Node** n,int data)
{
	Node* temp = *n;
	Node* temp1 = new Node();
	temp1->data = data;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = temp1;
	temp1->prev = temp;
	temp1->next = NULL;
}
void addbefore(Node** n,int key,int data)
{
	Node* temp = *n;
	Node* temp1 = new Node();
	temp1->data = data;
	while(temp->data!=key)
	{
		temp = temp->next;
	}
	temp1->prev = temp->prev;
	temp1->next = temp;
	temp->prev = temp1;
	if(temp1->prev!=NULL)
	{
		temp1->prev->next = temp1;
	}
	else
	{
		*n = temp1;
	}
}
void reverse(Node** n)
{
	Node* temp = *n;
	Node* temp1 = NULL;
	while(temp!=NULL)
	{
		temp1 = temp->prev;
		temp->prev = temp->next;
		temp->next = temp1;
		temp = temp->prev;
	}
	if(temp1!=NULL)
	{
		*n = temp1->prev;
	}
}
void printlist(Node* n)
{
	if(n==NULL)return;
	Node* temp = n;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
int main()
{
	Node* head = NULL;
	addfront(&head,1);
	addfront(&head,2);
	addfront(&head,3);
	addafter(head,1,4);
	addafter(head,2,5);
	addend(&head,6);
	addend(&head,7);
	addbefore(&head,6,8);
	addbefore(&head,3,9);
	printlist(head);
	reverse(&head);
	printlist(head);
}
