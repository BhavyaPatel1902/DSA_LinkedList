#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
     Node* next;
     int data;
};
bool detectloop(Node* n)
{
    Node* temp = n;
    set <Node*> s;
    while(n!=NULL)
    {
        if(s.find(n)!=s.end())
            return true;
        s.insert(n);
        n = n->next;
    }
    return false;
}
void push(Node** n,int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->next = *n;
    *n = temp;
}
void deleteloop(Node* head)
{
	Node* fast = head;
	Node* slow = head;
	while(fast!=NULL&&fast->next!=NULL&&slow!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		
		if(fast==slow)
		{
			break;
		}
	}
	if(fast == slow)
	{
		slow = head;
		if(fast==slow)
		{
			while(fast->next!=slow)fast = fast->next;
		}
		else
		{
			while(slow->next!=fast->next)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		fast->next = NULL;
	}
}
int main()
{
    Node* head = NULL;
    push(&head,10);
    push(&head,4);
    push(&head,15);
    push(&head,20);
    push(&head,50);
    head->next->next->next->next->next = head->next->next; //add loop
    deleteloop(head);
}
