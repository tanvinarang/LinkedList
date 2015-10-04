#include<iostream>
using namespace std;
struct node{
int data;
struct node*next;
};
class LinkedList
{
private:
struct node*head;
struct node*current;
struct node*slow_ptr;
struct node*fast_ptr;
struct node*loop;

public:
LinkedList()
{
head=NULL;
current=head;
}
struct node* push(struct node**head1,int data)
{
struct node*new_node;
new_node = new node();
new_node->data=data;
new_node->next=*head1;
*head1=new_node;

return *head1;
}

void printLL(struct node*head)
{
current=head;
while(current!=NULL)
{
cout<<current->data<<" ";
current=current->next;
}
}

void DetectLoop(struct node*head)
{
current=head;

slow_ptr=current->next;
fast_ptr=current->next->next;
current=current->next;
while(slow_ptr!=fast_ptr)
{
slow_ptr=current->next;
fast_ptr=fast_ptr->next->next;
current=current->next;

if(slow_ptr==fast_ptr)
{
loop=fast_ptr;
cout<<"loop detected";
RemoveLoop(head);
}
}//end while

}//end DEtectLoop()
void RemoveLoop(struct node*head)
{
current=head;
struct node*ptr1=head;
struct node*ptr2;
while(1)
{
ptr2=loop;
while(ptr2->next!=loop && ptr2->next!=ptr1)
{
ptr2=ptr2->next;
}
if (ptr2->next==ptr1)

{break;}

else
{
ptr1=ptr1->next;
}

}

ptr2->next=NULL;

printLL(head);
}//end RemoveLoop()

};//end class

int main()
{
struct node*start;
start=NULL;
LinkedList ll;
start=ll.push(&start,5);
start=ll.push(&start,15);
start=ll.push(&start,25);
start=ll.push(&start,35);
start=ll.push(&start,35);
//creating a loop for testing
start->next->next->next->next= start->next;
//ll.printLL(start);
ll.DetectLoop(start);
return 0;
}


