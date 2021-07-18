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
Node* add(Node* n1,Node* n2)
{
	Node* res = NULL;
	Node* temp = NULL;
	
	reverse(&n1);
	reverse(&n2);
	
	int carry=0;
	int sum = 0;
	
	while(n1!=NULL||n2!=NULL)
	{
		sum = carry + (n1?n1->data:0) + (n2?n2->data:0);
		carry = (sum>=10?1:0);
		sum = sum%10;
		temp = newNode(sum);
		append(&res,temp);
		if(n1)n1=n1->next;
		if(n2)n2=n2->next;
	}
	if(carry>0)
	{
		append(&res,newNode(carry));
	}
	reverse(&res);
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
     Node* head1 = NULL;
     Node* head2 =NULL;
     append(&head1,newNode(4));
     append(&head1,newNode(5));
     //append(&head1,newNode(9));
     append(&head2,newNode(3));
     append(&head2,newNode(4));
     append(&head2,newNode(5));
     printlist(head1);
     printlist(head2);
     Node* res = add(head1,head2);
     printlist(res);
}
