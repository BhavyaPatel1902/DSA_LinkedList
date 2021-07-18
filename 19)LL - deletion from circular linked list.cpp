#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
	 Node* next;
     int data;
};

void push(Node** n,int data)
{
	Node* temp = new Node();
	Node* temp1 = *n;
	temp->data = data;
	temp->next = *n;
	
	if(*n!=NULL)
	{
		while(temp1->next!=*n)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp;
	}
	else
	{
		temp->next = temp;
	}
	*n = temp;
}
void printlist(Node* n)
{
	Node* temp = n->next;
	if(n!=NULL)
	{
		do
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		while(temp!=n->next);
	}
	cout<<endl;
}
void deleteNode(Node** n,int key)
{
	if(*n==NULL)return;
	
	if((*n)->data==key&&(*n)->next==(*n))
	{
		free(*n);
		*n = NULL;
		return;
	}
	
	Node* temp = *n;
	if((*n)->data==key)
	{
		while(temp->next!=*n)
		{
			temp = temp->next;
		}
		temp->next = (*n)->next;
		free(*n);
		*n = temp->next;	
	}
	
	Node* temp1;
	
	while(temp->next!=*n&&temp->next->data!=key)
	{
		temp = temp->next;
	}
	
	if(temp->next->data==key)
	{
		temp1 = temp->next;
		temp->next = temp1->next;
		free(temp1);
	}
	else
	{
		cout<<"Not Found";
	}
}
int main()
{
	Node* head = NULL;
	Node* head1 = NULL;
	Node* head2 = NULL;
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	printlist(head);
	deleteNode(&head,3);
    printlist(head);
}
