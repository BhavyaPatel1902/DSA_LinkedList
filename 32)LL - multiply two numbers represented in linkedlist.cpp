#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
      int data;
      Node* next;
};
Node* newNode(int data)
{
	Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void append(Node** n,Node* t)
{
    if((*n)==NULL)
    {
        *n = t;
        return;
    }
    Node* temp1 = *n;
    while(temp1->next!=NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = t;
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
int multiply(Node* n1,Node* n2)
{
	int num1 = 0;
	int num2 = 0;
	
	while(n1!=NULL||n2!=NULL)
	{
		if(n1)
		{
			num1 = (num1*10 + n1->data)%1000000007;
			n1 = n1->next;
		}
		if(n2)
		{
			num2 = (num2*10 + n2->data)%1000000007;
			n2 = n2->next;
		}
	}
	return num1*num2%1000000007;
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
     Node* head1 = NULL;
     Node* head2 =NULL;
     append(&head1,newNode(4));
     append(&head1,newNode(5));
     append(&head1,newNode(9));
     append(&head2,newNode(3));
     append(&head2,newNode(4));
     append(&head2,newNode(5));
     printlist(head1);
     printlist(head2);
     int res = multiply(head1,head2);
     cout<<res<<endl;
}
