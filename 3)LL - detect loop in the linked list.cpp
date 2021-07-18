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
bool detect_loop(Node* head)
{
	Node* fast = head;
	Node* slow = head;
	
	while(fast!=NULL&&fast->next!=NULL&&slow!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		
		if(fast==slow)return true;
	}
	return false;
}
int main()
{
    Node* head = NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);
    head->next->next->next->next->next = head; //add loop
    int ans = detectloop(head);
    cout<<ans<<endl;
    cout<<detect_loop(head);
}
