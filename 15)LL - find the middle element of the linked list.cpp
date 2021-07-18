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
bool check(Node* n)
{
	if(n==NULL)return true;
	Node* temp = n->next;
	
	while(temp!=NULL&&temp!=n)
	{
		temp = temp->next;
	}
	return (temp==n);
}
void move(Node **n)
{
	Node* temp = *n;
	Node* prev = NULL;
	
	if(temp==NULL||temp->next==NULL)return;
	
	while(temp->next!=NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	
	temp->next = *n;
	
	prev->next = NULL;
	
	*n = temp;
}
void simple(Node* n)
{
	Node* temp = n;
	int ct = 0;
	while(temp!=NULL)
	{
		ct++;
		temp = temp->next;
	}

	int k = 0;
	temp = n;
	while(temp->next!=NULL&&k!=(ct/2))
	{
		temp = temp->next;
		k++;
	}
	cout<<temp->data<<endl;
}
void twopointer(Node* n)
{
	Node* fast = n;
	Node* slow = n;
	
	while(fast->next!=NULL&&fast!=NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	cout<<slow->data<<endl;
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
	 simple(head);
	 twopointer(head);
}
