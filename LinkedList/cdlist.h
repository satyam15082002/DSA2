#pragma once
struct Node
{
    int data;
    Node* prev;
    Node* next;
};

void cdlist_display(Node* &head);
void cdlist_pushfront(Node* &head,int data);
void cdlist_pushback(Node* &head,int data);
void cdlist_popfront(Node* &head);
void cdlist_popback(Node* &head);


