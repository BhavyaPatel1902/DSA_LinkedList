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
void find(Node* n,int sum)
{
	Node* temp = n;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	Node* high = temp;
	Node* low = n;
	bool found = false;
	while(low!=NULL&&high!=NULL&&low!=high&&high->next!=low)
	{
		if(low->data+high->data==sum)
		{
			cout<<low->data<<" "<<high->data<<endl;
			found = true;
			low = low->next;
			high = high->prev;
		}
		else if(low->data+high->data<sum)
		{
			low = low->next;
		}
		else
		{
			high = high->prev;
		}
	}
	if(found==false)cout<<"NOT FOUND"<<endl;
}
void simple(Node* head,int sum)
{
	Node* temp1 = head;
	Node* temp2;
	bool found = false;
	while(temp1!=NULL&&temp1->next!=NULL)
	{
		temp2 = temp1;
		while(temp2!=NULL)
		{
			if(temp1->data+temp2->data==sum)
			{
			   cout<<temp1->data<<" "<<temp2->data<<endl;
			   found = true;
		    }
		    temp2 = temp2->next;
		}
		temp1=temp1->next;
	}
	if(found==false)cout<<"NOT FOUND"<<endl;
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
	addfront(&head,9);
	addfront(&head,8);
	addfront(&head,7);
	addfront(&head,6);
	addfront(&head,5);
	addfront(&head,4);
	addfront(&head,3);
	addfront(&head,2);
	addfront(&head,1);
	find(head,10);
	simple(head,10);
}
