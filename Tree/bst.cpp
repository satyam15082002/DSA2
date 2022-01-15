#include"bst.h"
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
Node* bst_insert(Node* root,int data)
{
    if(root==NULL)
    {
        root=(Node*)malloc(sizeof(Node));
        root->L=root->R=NULL;
        root->data=data;
    }
    else if(data>root->data)
        root->R=bst_insert(root->R,data);
    else
        root->L=bst_insert(root->L,data);
    return root;
}

Node* bst_delete(Node* root,int key)
{
    if(root==NULL)
        return root;
    else if(key<root->data)
        root->L=bst_delete(root->L,key);
    else if(key>root->data)
        root->R=bst_delete(root->R,key);
    else if(root->L==NULL||root->R==NULL)
    {
        Node* tmp=root->L!=NULL?root->L:root->R;
        if(tmp==NULL) //No child
        {
            tmp=root;
            root=NULL;
        }
        else
            *root=*tmp;
        free(tmp);
    }
    else
    {
        Node* tmp=inorderSuccessor(root->R);
        root->data=tmp->data;
        root->R=bst_delete(root->R,tmp->data);
    }
    return root;
}
Node* bst_search(Node* root,int target)
{
    if(root==NULL)
        return root;
    else if(root->data==target)
        return root;
    else if(target<root->data)
        return bst_search(root->L,target);
    else
        return bst_search(root->R,target);
}
void bst_clear(Node* root) //delete full tree
{
    if(root==NULL)
        return;
    bst_clear(root->L);
    bst_clear(root->R);
    free(root);
}
Node* bst_copy(Node* root) //copy a full tree and return root
{
    if(root==NULL)
        return root;
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=root->data;
    newnode->L=bst_copy(root->L);
    newnode->R=bst_copy(root->R);
    return newnode;
}

int bst_equal(Node* root1,Node* root2) //check tree are equal or not 1->equal else ->0
{
    if(root1==NULL&&root2==NULL)
        return 1;
    return (root1&&root2)&&
            (root1->data==root2->data)&&
                bst_equal(root1->L,root2->L)&&
                bst_equal(root1->R,root2->R);
}
int bst_height(Node* root) //return height of node 
{
    if(root==NULL)
        return 0;
    if(root->L==NULL&&root->R==NULL)
        return 0;
    int hL=bst_height(root->L);
    int hR=bst_height(root->R);
    return 1+(hL>hR?hL:hR);
}

Node* inorderSuccessor(Node* root)
{
    if(root==NULL)
        return root;
    Node* tmp=root;
    while(tmp->L!=NULL)
        tmp=tmp->L;
    return tmp;
}
Node* inorderPredecessor(Node* root)
{
    if(root==NULL)
        return root;
    Node* tmp=root;
    while(tmp->R!=NULL)
        tmp=tmp->R;
    return tmp;
}


void bst_inorder(Node* root)
{
    if(root==NULL)
        return;
    bst_inorder(root->L);   
    printf("%d\t",root->data);
    bst_inorder(root->R);
}
void bst_preorder(Node* root)
{
    if(root==NULL)
        return;
    printf("%d\t",root->data);
    bst_preorder(root->L);   
    bst_preorder(root->R);
}
void bst_postorder(Node* root)
{
    if(root==NULL)
        return;
    bst_postorder(root->L);   
    bst_postorder(root->R);
    printf("%d\t",root->data);
}
void bst_dfs(Node* root)
{
    if(root==NULL)
        return;
    std::stack<Node*> st;
    Node* tmp=root;
    while(1)
    {
        printf("%d\t",tmp->data);
        if(tmp->R!=NULL)
            st.push(tmp->R);
        if(tmp->L!=NULL)
            st.push(tmp->L);
        if(st.empty())
            break;
        tmp=st.top();
        st.pop();
    }
}
void bst_bfs(Node* root)
{
    if(root==NULL)
        return;
    std::queue<Node*> q;
    Node* tmp=root;
    while(1)
    {
        printf("%d\t",tmp->data);
        if(tmp->R!=NULL)
            q.push(tmp->R);
        if(tmp->L!=NULL)
            q.push(tmp->L);
        if(q.empty())
            break;
        tmp=q.front();
        q.pop();
    }
}
void mirror(Node* root)
{
    if(root==NULL)
        return;
    Node* tmp=root->L;
    root->L=root->R;
    root->R=tmp;
    mirror(root->L);
    mirror(root->R);
}