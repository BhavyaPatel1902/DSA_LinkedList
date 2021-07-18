#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
      int data;
      Node* next;
      Node* prev;
};
void append(Node** n,int data)
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
	Node* temp = n;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
void rotate(Node** head,int n)
{
	if(n==0)return;
	
	Node* temp = *head;
	
	int ct = 1;
	
	while(ct<n&&temp!=NULL)
	{
		temp = temp->next;
		ct++;
	}
	
	if(temp==NULL)return;
	
	Node* nth = temp;
	
	temp = *head;
	
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	
	temp->next = *head;
	
	(*head)->prev = temp;
	
	*head = nth->next;
	
	(*head)->prev = NULL;
	
	nth->next = NULL;
}
int main()
{
     Node* head = NULL;
     append(&head,1);
     append(&head,2);
     append(&head,3);
     append(&head,4);
     append(&head,5);
     append(&head,6);
     printlist(head);
     rotate(&head,3);
     printlist(head);
}
