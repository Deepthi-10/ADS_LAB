
#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* npx;
};
Node* XOR(Node* a,Node* b)
{
    return (Node*)((uintptr_t)(a)^(uintptr_t)(b));
}
void inserthead(Node** head,int data)
{
    Node* new_node=new Node();
    new_node->data=data;
    new_node->npx=*head;
    if(*head!=NULL)
    {
        (*head)->npx=XOR(new_node,(*head)->npx);
    }
    (*head)=new_node;
}
void insertend(Node** head,int data)
{
    Node* new_node=new Node();
    new_node->data=data;
    if(*head==NULL)
    {
        new_node->npx=*head;
        *head=new_node;
    }
    
    else
    {
        Node* curr=*head;
        Node* prev=NULL;
        Node* next;
        while(XOR(prev,curr->npx))
        {
            next=XOR(prev,curr->npx);
            prev=curr;
            curr=next;
        }
        new_node->npx=curr;
        curr->npx=XOR(prev,new_node);
    }
}
void printlist(Node* head)
{
    Node* curr=head;
    Node* prev=NULL;
    Node* next;
    if(head==NULL)
    {
        cout<<"empty XOR linked list"<<endl;
        return;
    }
    cout<<"Following are the nodes of the XOR linked list:"<<endl;
    while(curr!=NULL)
    {
        cout<< curr->data<<" ";
        next=XOR(prev, curr->npx);
        prev=curr;
        curr=next;
    }
    cout<<endl;
}
int main()
{
    int choice,ele;
    char ch;
    Node* head=NULL;
    cout<<"1.insert at the begininng\n 2.insert at the end\n 3.display list\n 4.exit"<<endl;
    do{
        cout<<"enter option:"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"enter an integer to insert at beginning : ";
            cin>>ele;
            inserthead(&head,ele);
            break;
            case 2:
            cout<<" enter an element to be inserted at the end: ";
            cin>>ele;
            insertend(&head,ele);
            break;
            case 3:
            printlist(head);
            break;
            default: exit(0);
        }
        cout<<"do  want to continue?(y/n)"<<endl;
        cin>>ch;
    }while(ch=='y');
}
