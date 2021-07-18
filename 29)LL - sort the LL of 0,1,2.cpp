#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
		int data;
		Node* next;
		Node* prev;
};
Node* newNode(int data)
{
	Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void addfront(Node** n,int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = *n;
	temp->prev = NULL;
	if((*n)!=NULL)
	    (*n)->prev = temp;
	*n = temp;
}
void addend(Node** n,int data)
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
	if(n==NULL)return;
	Node* temp = n;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
void sort_1(Node* head)
{
	int ct[3]={0,0,0};
	Node* temp = head;
	
	while(temp!=NULL)
	{
		ct[temp->data]++;
		temp = temp->next;
	}
	
	int i = 0;
	temp = head;
	
	while(temp!=NULL)
	{
		if(ct[i]==0)i++;
		else
		{
			temp->data = i;
			ct[i]--;
			temp=temp->next;
		}
	}
}
Node* sort_2(Node* head)
{
	Node* zerod = newNode(0);	
	Node* oned = newNode(0);	
	Node* twod = newNode(0);	
	
	Node* zero = zerod;
	Node* one = oned;
	Node* two = twod;
	
	Node* temp = head;
	
	while(temp!=NULL)
	{
		if(temp->data==0)
		{
			zero->next = temp;
			zero = zero->next;
			temp = temp->next;
		}
		else if(temp->data==1)
		{
			one->next = temp;
			one = one->next;
			temp = temp->next;
		}
		else
		{
			two->next = temp;
			two = two->next;
			temp = temp->next;
		}
	}
	
	zero->next = (oned->next)?(oned->next):(twod->next);
	one->next = twod->next;
	two->next = NULL;
	
	Node* temp1 = zerod->next;

	return temp1;
}
int main()
{
	Node* head = NULL;
	addfront(&head,0);
	addfront(&head,1);
	addfront(&head,2);
	addfront(&head,0);
	addfront(&head,0);
	addfront(&head,2);
	addfront(&head,2);
	addfront(&head,1);
	addfront(&head,1);
	addfront(&head,0);
	printlist(head);
	//sort_1(head);
	//printlist(head);
	Node* temp = sort_2(head);
    printlist(temp);
}
