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
Node* find_first(Node* head)
{
	Node* fast = head;
	Node* slow = head;
	bool flag = 0;
	while(fast!=NULL&&fast->next!=NULL&&slow!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		
		if(fast==slow)
		{
			flag = 1;
			break;
		}
	}
	if(flag==1)
	{
		slow = head;
		while(slow!=fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
	else
	{
		return NULL;
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
    Node* ans = find_first(head);
    cout<<ans->data<<endl;
}
