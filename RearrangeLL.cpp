Given a singly linked list L0 -> L1 -> … -> Ln-1 -> Ln. Rearrange the nodes in the list so that the new formed list is : L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 …

You are required do this in-place without altering the nodes’ values.

Examples:
Input:  1 -> 2 -> 3 -> 4
Output: 1 -> 4 -> 2 -> 3

Input:  1 -> 2 -> 3 -> 4 -> 5
Output: 1 -> 5 -> 2 -> 4 -> 3 




#include<iostream>
using namespace std;

class LinkedList{

private: 
struct node{
int data;
struct node*next;
};
struct node*head;
struct node*last;
struct node*current;
struct node*last1;
struct node*first;
struct node*next;
struct node*current1;
struct node*head1;
public:

LinkedList()
{
head=NULL;
current=head;
last=current;
}
void CreateLL(int n)
{
if(n==0)
{return;}
for(int i=1;i<=n;i++)
{
if (head==NULL)
{
head=new node();//Remember to create head!!
head->data=i;
head->next=NULL;
current=head;
last=current;
first=head;
}
else
{
struct node*newnode;
newnode= new node();
newnode->data=i;
newnode->next=NULL;
current->next=newnode;
current=newnode;
}//end else

}//end for loop
last=current;
}//end createLL()

void printLL()
{
current=head;
if(current==NULL)
{
cout<<"Linked List is empty";
}
while(current!=NULL)
{
cout<< current->data << " ";
current=current->next;
}
cout<<endl;

}//end printLL()

void Rearrange()//With Complexity N^2 :(
{ current=head;
while(current->next->next!=NULL)
{
while(current->next->next!=NULL)
{
current=current->next;
}//end while1
last1=current;
last1->next=NULL;
current=first;
next=current->next;
current->next=last;
last->next=next;
last=last1;
first=next;
current=first;
}//end while2
}//end Rearrange()

void rearrange()
{
struct node*ptr1;
struct node*ptr2;

ptr1=head;
ptr2=head;
while( ptr2!=NULL && ptr2->next!=NULL)//finding the mid point !!!! considering odd and even both!
{
ptr1=ptr1->next;
ptr2=ptr2->next->next;
}
//cout<<ptr1->data;
current1=ptr1->next;
ptr1->next=NULL;
reverse();
}//end rearrange()

void reverse()
{
struct node*prev;
struct node*next1;
prev=NULL;
head1=current1;
next1=current1->next;
while(next1!=NULL)
{
next1=current1->next;
current1->next=prev;
prev=current1;
current1=next1;
next1=next1->next;
}
current1->next=prev;
prev=current1;
head1=prev;

merge();

}//end reverse()
void merge()
{
struct node*next1;
struct node*next2;
current=head;
current1=head1;
next1=current->next;
next2=current1->next;
while(current!=NULL && current1!=NULL)
{
next1=current->next;
next2=current1->next;
current->next=current1;
current1->next=next1;
current=current1->next;
current1=next2;
}
if(current1==NULL)
{
while(current!=NULL)
{
current=current->next;
}
}
else
{
while(current1!=NULL)
{
current1=current1->next;
}
}


//printLL();
}//end merge()
};//end class

int main()
{
LinkedList ll;
ll.CreateLL(9);
ll.printLL();
//ll.Rearrange();
ll.rearrange();
ll.printLL();

return 0;
}


