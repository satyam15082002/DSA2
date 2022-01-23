#include"cslist.h"
#include<iostream>
using std::cout;
using std::endl;
void cslist_display(Node* &head)
{
    if(head==NULL)
    {
        cout<<"NULL"<<endl;
        return;
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
void cslist_pushfront(Node* &head,int data)
{
    if(head==NULL)
    {
        head=new Node;
        head->data=data;
        head->next=head;
    }
    else
    {
        Node* newnode=new Node;
        newnode->data=data;
        newnode->next=head;
        Node* lastNode=head;
        while(lastNode->next!=head)
            lastNode=lastNode->next;
        lastNode->next=newnode;
        head=newnode;
    }
}

void cslist_pushback(Node* &head,int data)
{
    if(head==NULL)
    {
        head=new Node;
        head->data=data;
        head->next=head;
    }
    else
    {
        Node* newnode=new Node;
        newnode->data=data;
        newnode->next=head;
        Node* lastNode=head;
        while(lastNode->next!=head)
            lastNode=lastNode->next;
        lastNode->next=newnode;
    }
}
void cslist_popfront(Node* &head)
{
    if(head==NULL)
    {
        cout<<"NULL"<<endl;
    }
    else if(head==head->next)
    {
        delete head;
        head=NULL;
    }
    else
    {
        Node* lastNode=head;
        while(lastNode->next!=head)
            lastNode=lastNode->next;
        Node* tmp=head;
        head=head->next;
        lastNode->next=head;
        delete tmp;
    }
}
void cslist_popback(Node* &head)
{
    if(head==NULL)
    {
        cout<<"NULL"<<endl;
    }
    else if(head==head->next)
    {
        delete head;
        head=NULL;
    }   
    else
    {
        Node* lastNode=head;
        while(lastNode->next->next!=head)
            lastNode=lastNode->next;
        delete lastNode->next;
        lastNode->next=head;
    }
}