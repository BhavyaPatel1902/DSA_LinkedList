#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
      int data;
      Node* next;
};
Node* reverse(Node** n,int k)
{
	Node* temp = *n;
	Node* next1 = NULL;
	Node* prev = NULL;
	int ct = 0;
	
	while(temp!=NULL&&ct<k)
	{
		next1 = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next1;
		ct++;
	}
	
	if(next1!=NULL)
	{
		(*n)->next = reverse(&next1,k);
	}
	return prev;
}
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
Node* tail(Node *head)
{
	while(head!=NULL&&head->next!=NULL)head = head->next;
	return head;
}
Node* recur(Node* start,Node* end)
{
	if(!start||start==end)return start;
	
	Node* pivot = partition()
}
void quick_sort(Node** head)
{
	*head = recur(*head,tail(*head));
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
     quick_sort(&head);
     printlist(temp);
}
