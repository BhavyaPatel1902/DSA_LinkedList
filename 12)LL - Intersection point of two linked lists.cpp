#include <bits/stdc++.h> 
using namespace std; 
//using two loop
//using hashset
//using visited flag
class Node 
{ 
 public: 
	int data; 
	Node* next; 
}; 
int getnode(Node* t1,Node* t2,int diff)
{
      Node* temp1 = t1;
      Node* temp2 = t2;
      
      for(int i=0;i<diff;i++)
      {
      	  if(temp1==NULL)return -1;
      	  temp1 = temp1->next;
	  }
	  
	  while(temp1!=NULL&&temp2!=NULL)
	  {
	  	  if(temp1==temp2)return temp1->data;
	  	  temp1 = temp1->next;
	  	  temp2 = temp2->next;
	  }
	  return -1;
}
int getIntersectionNode(Node* n1,Node* n2)
{
    Node* temp1 = n1;
    Node* temp2 = n2;
    int c1 = 0;
    int c2 = 0;
    
    while(temp1!=NULL)
    {
    	temp1 = temp1->next;
    	c1++;
	}
	
	while(temp2!=NULL)
	{
		temp2 = temp2->next;
		c2++;
	}
	
	if(c1>c2)return getnode(n1,n2,(c1-c2));
	else return getnode(n2,n1,(c2-c1));
}
int main() 
{ 
	Node* newNode; 
	Node* head1 = new Node(); 
	head1->data = 10; 

	Node* head2 = new Node(); 
	head2->data = 3; 

	newNode = new Node(); 
	newNode->data = 6; 
	head2->next = newNode; 

	newNode = new Node(); 
	newNode->data = 9; 
	head2->next->next = newNode; 

	newNode = new Node(); 
	newNode->data = 15; 
	head1->next = newNode; 
	head2->next->next->next = newNode; 

	newNode = new Node(); 
	newNode->data = 30; 
	head1->next->next = newNode; 

	head1->next->next->next = NULL; 

	cout << "The node of intersection is " << getIntersectionNode(head1, head2); 
} 
