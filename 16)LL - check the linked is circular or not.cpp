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
int main()
{
	 Node* head = new Node();
	 Node* temp = new Node();
	 Node* temp1 = new Node();
	 
	 head->data = 1;
	 head->next = temp;
	 temp->data = 2;
	 temp->next = temp1;
	 temp1->data = 3;
	 temp1->next = head;
	 
     bool ans = check(head);
     cout<<ans<<endl;
}
