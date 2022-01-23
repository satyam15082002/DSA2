#include"slist.h"
void slist_display(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
void slist_pushfront(Node* &head,int data)
{
    if(head==NULL)
    {
        head=new Node;
        head->data=data;
        head->next=NULL;
    }
    else
    {
        Node* newnode=new Node;
        newnode->data=data;
        newnode->next=head;
        head=newnode;
    }
}
void slist_pushback(Node* &head,int data)
{
    if(head==NULL)
    {
        head=new Node;
        head->data=data;
        head->next=NULL;
    }
    else
    {
        Node* lastNode=head;
        while(lastNode->next!=NULL)
            lastNode=lastNode->next;
        Node* newnode=new Node;
        newnode->data=data;
        newnode->next=NULL;
        lastNode->next=newnode;
    }
}
void slist_popfront(Node* &head)
{
    if(head==NULL)
        return;
    else
    {
        Node* tmp=head;
        head=head->next;
        delete tmp;
    }
}
void slist_popback(Node* &head)
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
        Node* lsecondNode=head;
        while(lsecondNode->next->next!=NULL)
        {
            lsecondNode=lsecondNode->next;
        }
        delete lsecondNode->next;
        lsecondNode->next=NULL;
    }
}
Node* slist_search(Node* &head,int key)
{
    if(head==NULL)
        return head;
    else
    {
        Node* tmp=head;
        while(tmp!=NULL)
        {
            if(tmp->data==key)
                return tmp;
            tmp=tmp->next;
        }
    }
    return NULL;
}
void slist_reverse(Node* &head)
{
    Node* prev=NULL;
    Node* curr=head;
    Node* next;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}
void slist_append(Node* &head1,Node* &head2)
{
    if(head2==NULL)
        return;
    else if(head1==NULL)
        head1=head2;
    else
    {
        Node* lastNode=head1;
        while(lastNode->next!=NULL)
            lastNode=lastNode->next;
        lastNode->next=head2;
    }
}