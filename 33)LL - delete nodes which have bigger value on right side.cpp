#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
		int data;
		Node* next;
		Node* prev;
};
Node* newNode(int data)
{
	Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}
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
void reverse(Node** head)
{
	Node* temp = *head;
	Node* prev = NULL;
	Node* next1 = NULL;
	
	while(temp!=NULL)
	{
		next1 = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next1;
	}
	*head = prev;
}
void simple(Node** head)
{
	Node* temp = *head;
	Node* prev = NULL;
	while(temp->next!=NULL)
	{
		Node* temp1 = temp->next;
		while(temp1!=NULL)
		{
			if(temp1->data>temp->data)
			{
				Node* temp3 = temp->next;
				free(temp);
				if(prev!=NULL)
				{
					prev->next = temp3;
					temp = prev;
				}
				else
				{
					*head = temp3;
					temp = *head;
				}
				break;
			}
			temp1 = temp1->next;
		}
		prev = temp;
		temp = temp->next;
	}
}
void efficient(Node** head)
{
	reverse(head);
	
	Node* temp = *head;
	Node* maxi = *head;
	Node* temp1;
	
	while(temp!=NULL&&temp->next!=NULL)
	{
		if(temp->next->data<maxi->data)
		{
			temp1 = temp->next;
			temp->next = temp1->next;
			free(temp1);
		}
		else
		{
			temp = temp->next;
			maxi = temp;
		}
	}
	
	reverse(head);
}
void efficient_1(Node** head)
{
	Node* temp = *head;
	while(temp!=NULL&&temp->next!=NULL)
	{
		if(temp->data<temp->next->data)
		{
			temp->data = temp->next->data;
			temp->next = temp->next->next;
		}
		else
		{
			temp = temp->next;
		}
	}
}
int main()
{
	Node* head = NULL;
	addfront(&head,3);
	addfront(&head,2);
	addfront(&head,6);
	addfront(&head,5);
	addfront(&head,11);
	addfront(&head,10);
	addfront(&head,15);
	addfront(&head,12);
	printlist(head);
	//simple(&head);
	//efficient(&head);
	efficient_1(&head);
	printlist(head);
}
