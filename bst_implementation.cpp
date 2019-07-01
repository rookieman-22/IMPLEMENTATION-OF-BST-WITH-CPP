#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *root;
node* getnewnode(int x)
{
    node *temp=new node[4];
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
node* insert(node *root,int data)
{
    if(root==NULL)
    {
        root=getnewnode(data);
        return root;
    }
    else
    {
        if(data<=root->data)
        {
            root->left=insert(root->left,data);
            return root;
        }
        else
        {
            root->right=insert(root->right,data);
            return root;
        }
    }
}
bool search(node *root,int x)
{
    if(root==NULL)
    {
        return false;
    }
    else
    {
        if(x==root->data)
            return true;
        else if(x<=root->data)
            return search(root->left,x);
        else
            return search(root->right,x);
    }
}
int findmin(node *root)
{
    if(root->left==NULL)
       return root->data;
    else return findmin(root->left);
}
int findmax(node *root)
{
    if(root->right==NULL)
    {
        return root->data;
    }
    else return findmax(root->right);
}
int findheight(node *root)
{
    int l,r;
    if(root==NULL)
        return 0;
    else
         l=findheight(root->left);
         r=findheight(root->right);
        if (l > r)
            return(l + 1);
        else return(r + 1);
}
int main()
{
    int x;bool y;
    root = insert(root,15);
	root = insert(root,10);
	root = insert(root,20);
	root = insert(root,25);
	root = insert(root,8);
	root = insert(root,12);
    int i=2;
    cout<<"Enter element that you want to search: ";
    cin>>x;
    y=search(root,x);
    if(y==1)
        cout<<"Element is present in tree"<<"\n";
    else
        cout<<"Element is not present in tree"<<"\n";
    int a=findmin(root);
    cout<<a<<" is the  minimum element in the tree\n";
    a=findmax(root);
    cout<<a<<" is the maximum element in tree\n";
    a=findheight(root);
    cout<<"Height of the binary search tree is: "<<a;

}
