#pragma once
struct Node
{
    int data;
    Node* prev;
    Node* next;
};

void dlist_display(Node* &head);
void dlist_pushfront(Node* &head,int data);
void dlist_pushback(Node* &head,int data);
void dlist_popfront(Node* &head);
void dlist_popback(Node* &head);


