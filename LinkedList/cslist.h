#pragma once
struct Node
{
    int data;
    Node* next;
};

void cslist_display(Node* &head);
void cslist_pushfront(Node* &head,int data);
void cslist_pushback(Node* &head,int data);
void cslist_popfront(Node* &head);
void cslist_popback(Node* &head);


