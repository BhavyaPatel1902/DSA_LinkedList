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
/*
Node* reverse(Node** n, int k) 
{ 
    // Create a stack of Node* 
    stack<Node*> mystack; 
    struct Node* cur = *n; 
    struct Node* prev = NULL; 
    
    while (cur != NULL) 
	{ 
        // Terminate the loop whichever comes first 
        // either current == NULL or count >= k 
        int count = 0; 
        while(cur!= NULL && count < k) 
		{ 
            mystack.push(cur); 
            cur = cur->next; 
            count++; 
        } 
        // Now pop the elements of stack one by one 
        while (mystack.size()>0) 
		{ 
            // If final list has not been started yet. 
            if (prev == NULL) 
			{ 
                prev = mystack.top(); 
                head = prev; 
                mystack.pop(); 
            } 
			else 
			{ 
                prev->next = mystack.top(); 
                prev = prev->next; 
                mystack.pop(); 
            } 
        } 
    } 
  
    // Next of last element will point to NULL. 
    prev->next = NULL; 
  
    return head; 
} 
*/
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
     Node* temp = reverse(&head,3);
     printlist(temp);
}
