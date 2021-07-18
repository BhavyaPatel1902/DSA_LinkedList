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

Node* simple(Node* n1,Node* n2)
{
	Node* res = NULL;
	Node* temp1 = n1;
	Node* temp2 = n2;
	Node* prev = NULL;
	while(temp1!=NULL)
	{
		if(prev!=NULL&&temp1->data==prev->data)
		{
			prev = temp1;
			temp1=temp1->next;
		}
		else
		{
		   temp2 = n2;
		   while(temp2!=NULL)
		   {   
		    	if(temp1->data==temp2->data)
			    {
				   append(&res,temp1->data);
				   break;
			    }
			    temp2 = temp2->next;
		   }
		   prev = temp1;
		   temp1 = temp1->next;
	    }
	}
	return res;
}
void remove(Node* n)
{
	Node* temp = n;
	Node* r;
	if(temp==NULL)return;
	
	while(temp->next!=NULL)
	{
		if(temp->data==temp->next->data)
		{
			r = temp->next->next;
			free(temp->next);
			temp->next = r;
		}
		else
		{
			temp = temp->next;
		}
	}
}
Node* intersect(Node* n1,Node* n2)
{
	Node* res = NULL;
	Node* temp1 = n1;
	Node* temp2 = n2;
	
	remove(temp1);
	remove(temp2);
	
	while(temp1!=NULL&&temp2!=NULL)
	{
		if(temp1->data==temp2->data)
		{
			append(&res,temp1->data);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else if(temp1->data>temp2->data)
		{
			temp2 = temp2->next;
		}
		else
		{
			temp1 = temp1->next;
		}
	}	
	return res;
}

Node* hashing(Node* n1,Node* n2)
{
	unordered_set <int> s;
	Node* temp1 = n1;
	Node* temp2 = n2;
	
	Node* res=NULL;
	
	while(temp1!=NULL)
	{
		s.insert(temp1->data);
		temp1 = temp1->next;
	}
	
	while(temp2!=NULL)
	{
		if(s.find(temp2->data)!=s.end())
		{
			append(&res,temp2->data);
		}
		temp2 = temp2->next;
	}
	return res;
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

int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    append(&head1,1);
    append(&head1,2);
    append(&head1,2);
    append(&head1,4);
    append(&head1,5);
    
    printlist(head1);
    
    append(&head2,1);
    append(&head2,2);
    append(&head2,2);
    append(&head2,6);
    append(&head2,8);
    
    printlist(head2);
    
    //Node* head = simple(head1,head2);
    //Node* head = intersect(head1,head2);
    Node* head = hashing(head1,head2);
    printlist(head);
}
