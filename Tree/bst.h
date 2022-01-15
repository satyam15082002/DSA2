#pragma once

typedef struct Node
{
    int data;
    struct Node* L;
    struct    Node* R;
}Node;

Node* bst_insert(Node*,int);
Node* bst_delete(Node*,int);
Node* bst_search(Node*,int);
void bst_clear(Node*); //delete full tree;
Node* bst_copy(Node*); //copy a full tree and return root

int bst_equal(Node*,Node*); //check tree are equal or not 1->equal else ->0
int bst_height(Node*); //return height of node 

Node* inorderSuccessor(Node*);
Node* inorderPredecessor(Node*);

//Traversal
void bst_inorder(Node*);
void bst_preorder(Node*);
void bst_postorder(Node*);
void bst_dfs(Node*);
void bst_bfs(Node*);

void mirror(Node*);


