#pragma once
#include<iostream>
using std::cout;
using std::endl;

struct Node
{
    int data;
    Node* next;
};

void slist_display(Node* head);
void slist_pushfront(Node* &head,int data);
void slist_pushback(Node* &head,int data);
void slist_popfront(Node* &head);
void slist_popback(Node* &head);

Node* slist_search(Node* &head,int key);
void slist_reverse(Node* &head);
void slist_append(Node* &head1,Node* &head2);
