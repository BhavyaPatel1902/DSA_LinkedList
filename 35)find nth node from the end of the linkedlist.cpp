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
void simple(Node* head,int n)
{
	Node* temp = head;
	int len = 0;
	while(temp!=NULL)
	{
		temp = temp->next;
		len++;
	}
	temp = head;
	int ct = 0;
	int flag = len-n;
	
	while(temp!=NULL)
	{
		if(ct==flag)
		{
			cout<<temp->data<<endl;
			return;
		}
		temp = temp->next;
		ct++;
	}
	cout<<-1<<endl;
}
void twopointer(Node* head,int n)
{
	Node* slow = head;
	Node* fast = head;
	
	int ct = 0;
	if(head!=NULL)
	{
		while(ct<n)
		{
			if(fast==NULL)
			{
				cout<<-1<<endl;
				return;
			}
			fast = fast->next;
			ct++;
		}
	}
	
	if(fast==NULL)
	{
		head = head->next;
		if(head!=NULL)
		{
			cout<<slow->data;
			return;
		}
	}
	else
	{
		while(fast!=NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
		cout<<slow->data;
	}
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
     simple(head,3);
     twopointer(head,3);
}
