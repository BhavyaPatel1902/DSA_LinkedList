#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
     Node* next;
     int data;
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
bool palin(Node* n)
{
	stack <Node*> s;
    Node* temp = n;
    while(temp!=NULL)
    {
    	s.push(temp);
    	temp = temp->next;
	}
	
	temp = n;
	while(temp!=NULL)
	{
		int t = (s.top())->data;
		if(temp->data!=t)
		{
			return false;
		}
		s.pop();
		temp = temp->next;
	}
	return true;
}
void reverse(struct Node** head_ref) 
{ 
    Node* prev = NULL; 
    Node* current = *head_ref; 
    Node* next; 
    while (current != NULL) 
	{ 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    *head_ref = prev; 
} 
bool efficient(Node* n)
{
	Node* first = n;
	Node* slow = n;
	Node* second=n;
	Node* prev_slow = n;
	Node* mid = NULL;
	bool res=false;
	
	if(n!=NULL&&n->next!=NULL)
	{
		while(first!=NULL&&first->next!=NULL)
		{
			first = first->next->next;
			prev_slow = slow;
			slow = slow->next;
		}
	}
	
	//for odd and even case
	
	if(first!=NULL)
	{
		mid = slow;
		slow = slow->next;
	}
	
	second = slow;
	prev_slow->next = NULL;
	reverse(&second);
	
	
	Node* temp1 = n;
	Node* temp2 = second;
	
	while(temp1!=NULL&&temp2!=NULL)
	{
		if(temp1->data==temp2->data)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else
		{
			res = false;
			break;
		}
	}
	if(temp1==NULL&&temp2==NULL)res = true;
	
	reverse(&second);
	
	if(mid!=NULL)
	{
		prev_slow->next = mid;
		mid->next = second;
	}
	else
	{
		prev_slow->next = second;
	}
	return res;
}
int main()
{
    Node* head1 = NULL;
    append(&head1,1);
    append(&head1,2);
    append(&head1,3);
    append(&head1,2);
    append(&head1,1);
    //bool p = palin(head1);
    //cout<<p;
    bool p = efficient(head1);
    cout<<p;
    return 0;
}
