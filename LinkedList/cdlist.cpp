#include"cdlist.h"
#include<iostream>
using std::cout;
using std::endl;


void cdlist_display(Node* &head)
{
    if(head==NULL)
    {
        cout<<"NULL"<<endl;
    }
    else
    {
        Node* tmp=head->next;
        cout<<head->data<<"->";   
        while(tmp!=head)
        {
            cout<<tmp->data<<"->";
            tmp=tmp->next;
        }
        cout<<"NULL"<<endl;
    }
}

void cdlist_pushfront(Node* &head,int data)
{
    if(head==NULL)
    {
        head=new Node;
        head->data=data;
        head->next=head;
        head->prev=head;
    }
    else
    {
        Node* newnode=new Node;
        newnode->data=data;
        newnode->prev=head->prev;
        newnode->next=head;
        head->prev->next=newnode;
        head->prev=newnode;
        head=newnode;
    }
}
void cdlist_pushback(Node* &head,int data)
{
    if(head==NULL)
    {
        head=new Node;
        head->data=data;
        head->next=head;
        head->prev=head;
    }
    else
    {
        Node* newnode=new Node;
        newnode->data=data;
        newnode->prev=head->prev;
        newnode->next=head;
        head->prev->next=newnode;
        head->prev=newnode;
    }   
}
void cdlist_popfront(Node* &head)
{
    if(head==NULL)
    {
        cout<<"NULL"<<endl;
        return;
    }
    else if(head==head->next)
    {
        delete head;
        head=NULL;
    }
    else
    {
        Node* tmp=head;
        head->prev->next=head->next;
        head->next->prev=head->prev;
        head=head->next;
        delete tmp;
    }
}
void cdlist_popback(Node* &head)
{
    if(head==NULL)
        return;
    else if(head->next==head)
    {
        delete head;
        head=NULL;
    }
    else
    {
        Node* tmp=head->prev;
        head->prev->prev->next=head;
        head->prev=head->prev->prev;
        delete tmp;
    }   
}