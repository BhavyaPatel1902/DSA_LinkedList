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
void seg(Node** head)
{
	Node* temp = *head;
	Node* prev = NULL;
	Node* curr = *head;
	
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	
	Node* new_end = temp;
	
	while(curr->data%2!=0&&curr!=temp)
	{
		new_end->next = curr;
		curr = curr->next;
		new_end->next->next = NULL;
		new_end = new_end->next;
	}
	
	if(curr->data%2==0)
	{
		*head = curr;
		
		while(curr!=temp)
		{
		if(curr->data%2==0)
		{
			prev = curr;
			curr = curr->next;
		}
		else
		{
			prev->next = curr->next;
			
			curr->next = NULL;
			
			new_end->next = curr;
			
			new_end = curr;
			
			curr = prev->next;
		}
	    }
	}
	else prev = curr;
	
	if(new_end!=temp&&temp->data%2!=0)
	{
		prev->next = temp->next;
		temp->next = NULL;
		new_end->next = temp;
	}
	
	return;
}
void seg_1(Node** head)
{
	Node* odds = NULL;
	Node* odde = NULL;
	Node* evens = NULL;
	Node* evene = NULL;
	
	Node* temp = *head;
	
	while(temp!=NULL)
	{
		int val = temp->data;
		
		if(val%2==0)
		{
			if(evens==NULL)
			{
				evens = temp;
				evene = evens;
			}
			else
			{
				evene->next = temp;
				evene = evene->next;
			}
		}
		else
		{
			if(odds==NULL)
			{
				odds = temp;
				odde = odds;
			}
			else
			{
				odde->next = temp;
				odde = odde->next;
			}
		}
		temp = temp->next;
	}
	
	if(odds==NULL||evens==NULL)return;
	
	evene->next = odds;
	odde->next = NULL;
	
	*head = evens;
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
     //seg(&head);
     seg_1(&head);
     printlist(head);  
}
