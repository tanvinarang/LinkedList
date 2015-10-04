#include<iostream>
using namespace std;

class Linkedlist
{

private:
struct node{
int data;
struct node*next;
};
struct node*head;
struct node*current;
struct node*next;
struct node*head1;
struct node*current1;

public:

Linkedlist()
{
head=NULL;
current=head;
}

void CreateLL(int n)
{

if (n==0)
{return;}

for(int i=1;i<=n;i++)
{
if (head==NULL)
{
head=new node();
head->data=i;
head->next=NULL;
current=head;
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

}//end CreateLL()

void PrintLL(node*head)
{

current=head;
while(current!=NULL)
{
cout<<current->data<<" ";
current=current->next;
}

}//end PrintLL()

void arrange()
{
current=head;
next=current->next;
head1=next;
current1=head1;
current->next=current->next->next;
current=current->next;

while(current->next!=NULL)
{
next=current->next;
current1->next=next;
current->next=current->next->next;
current=current->next;
current1=current1->next;
}
current1->next=NULL;

Printnew();
}// end arrange()

void Printnew()
{
current1=head1;
while(current1!=NULL)
{
cout<<current1->data<<" ";
current1=current1->next;
}
cout<<endl;
}//end Printnew()



};//end Class

int main()
{
Linkedlist ll;
ll.CreateLL(7);
ll.arrange();
ll.PrintLL();
return 0;
}






























