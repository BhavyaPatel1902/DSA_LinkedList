#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
     Node* next;
     int data;
};
void remove(Node* n)
{
	Node* p1 = n;
	Node* p2;
	Node* d;
	while(p1!=NULL&&p1->next!=NULL)
	{
		p2 = p1;
		while(p2->next!=NULL)
		{
			if(p1->data==p2->next->data)
			{
				d = p2->next;
				p2->next = p2->next->next;
				free(d);
			}
			else
			{
				p2 = p2->next;
			}
		}
		p1 = p1->next;
	}
}

void printlist(Node* n)
{
    while(n!=NULL)
    {
        cout<<n->data;
        if(n->next!=NULL)
            cout<<"->";
        n = n->next;
    }
    cout<<endl;
}

void push(Node** n,int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->next = *n;
    *n = temp;
}
void hashing(Node* n)
{
	unordered_set <int> s;
	
	Node* temp = n;
	Node* prev = NULL;
	
	while(temp!=NULL)
	{
		if(s.find(temp->data)!=s.end())
		{
			prev->next = temp->next;
			free(temp);
		}
		else
		{
			s.insert(temp->data);
			prev = temp;
		}
		temp = prev->next;
	}
}
int main()
{
    Node* head = NULL;
    push(&head,5);
    push(&head,1);
    push(&head,4);
    push(&head,2);
    push(&head,4);
    printlist(head);
    //remove(head);
    hashing(head);
    printlist(head);  
}
