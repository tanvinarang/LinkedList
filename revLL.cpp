#include<iostream>
using namespace std;

class LinkedList{

public :

struct node{
int data;
struct node*next;
};
struct node*current;
struct node*tail;
struct node*head;
struct node*prev;

LinkedList()
{
head=NULL;
current=head;
tail=NULL;

}

void createLL(int n)
{
 if (n==0)
{return;}

else{
head= new node();
head->data=1;
head->next=NULL;
tail=head;

for(int i=2;i<=n;i++)
{
struct node*temp;
temp=new node();
temp->data=i;
temp->next=NULL;
tail->next=temp;
tail=temp;
}

}//end else

} //end createLL()

void printLL()
{
current=head;
if(current==NULL)
{
cout<<"Linked list is empty";
}
while(current!=NULL)
{
cout<<current->data;
current=current->next;
}
}//end printLL()

void revLL(struct node*head)
{
if(head->next==NULL)
{
return;
}

else{


prev=head;

revLL(head->next);
struct node*q=prev->next;
q->next=prev;
prev->next=NULL;

}
}//end revLL()

};//end class Linkedlist

int main()
{


LinkedList ll;
struct node*current;
struct node*head;
current=head;
ll.createLL(6);
ll.printLL();
ll.revLL(current);
}










