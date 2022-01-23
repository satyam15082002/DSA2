#include"dlist.h"
#include<iostream>
using std::cout;
using std::endl;


void dlist_display(Node* &head)
{
    Node* tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->data<<"->";
        tmp=tmp->next;
    }
    cout<<"NULL"<<endl;
}

void dlist_pushfront(Node* &head,int data)
{
    if(head==NULL)
    {
        head=new Node;
        head->data=data;
        head->next=NULL;
        head->prev=NULL;
    }
    else
    {
        Node* newnode=new Node;
        newnode->data=data;
        newnode->prev=NULL;
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}
void dlist_pushback(Node* &head,int data)
{
    if(head==NULL)
    {
        head=new Node;
        head->data=data;
        head->next=NULL;
        head->prev=NULL;
    }
    else
    {
        Node* newnode=new Node;
        newnode->data=data;
        newnode->next=NULL;
        Node* lastNode=head;
        while(lastNode->next!=NULL)
            lastNode=lastNode->next;
        lastNode->next=newnode;
        newnode->prev=lastNode;
    }
   
}
void dlist_popfront(Node* &head)
{
    if(head==NULL)
    {
        cout<<"NULL"<<endl;
        return;
    }
    else
    {
        Node* tmp=head;
        if(head->next!=NULL)
            head->next->prev=NULL;
        head=head->next;
        delete tmp;
    }
}
void dlist_popback(Node* &head)
{
    if(head==NULL)
        return;
    else if(head->next==NULL)
    {
        delete head;
        head=NULL;
    }
    else
    {
        Node* lastNode=head;
        while(lastNode->next!=NULL)
            lastNode=lastNode->next;
        lastNode->prev->next=NULL;
        delete lastNode;
    }   
}