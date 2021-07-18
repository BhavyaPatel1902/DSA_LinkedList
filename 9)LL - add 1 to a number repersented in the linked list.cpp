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
Node* add(Node* n)
{
	Node* res = n;
	Node* temp = NULL;
	Node* temp1 = NULL;
	
	int carry = 1;
	int sum = 0;
	
	while(n!=NULL)
	{
		sum = carry + n->data;
		carry = sum>=10?1:0;
		sum = sum%10;
		n->data = sum;
		temp = n;
		n = n->next;
	}
	if(carry>0)
	{
		temp1->data = carry;
		temp1->next = NULL;
		temp->next = temp1;
	}
	return res;
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
int main()
{
     Node* head = NULL;
     append(&head,1);
     append(&head,9);
     append(&head,9);
     append(&head,9);
     printlist(head);
     reverse(&head);
     Node* temp = add(head);
     reverse(&temp);
     printlist(temp);
}
