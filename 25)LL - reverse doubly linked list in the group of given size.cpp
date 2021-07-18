#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
		int data;
		Node* next;
		Node* prev;
};
void add(Node** n,int data)
{
	Node* temp = *n;
	Node* temp1 = new Node();
	
	temp1->data = data;
	temp1->next = NULL;
	temp1->prev = NULL;
	
	if((*n)==NULL)
	{
	   (*n) = temp1;
	   return;
    }
	
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = temp1;
	temp1->prev = temp;
	temp1->next = NULL;
}
void push(Node** n,Node* newnode)
{
    newnode->prev = NULL;
    
    newnode->next = *n;
    
    if((*n)!=NULL)(*n)->prev = newnode;
    
    *n = newnode;
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
Node* reverse(Node* head,int k)
{
	Node* temp = head;
	Node* next1 = NULL;
	Node* newhead  = NULL;
	
	int ct = 0;
	
	while(temp!=NULL&&ct<k)
	{
		next1 = temp->next;
		push(&newhead,temp);
		temp = next1;
		ct++;
	}
	
	if(next1!=NULL)
	{
		head->next = reverse(next1,k);
		head->next->prev = head;
	}
	
	return newhead;
}
int main()
{
     Node* head = NULL;
     add(&head,1);
     add(&head,2);
     add(&head,3);
     add(&head,4);
     add(&head,5);
     add(&head,6);
     printlist(head);
     Node* temp = reverse(head,2);
     printlist(temp);
}
