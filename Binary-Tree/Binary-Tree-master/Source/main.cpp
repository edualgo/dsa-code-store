#include<bits/stdc++.h>
using namespace std;

/// generating type data T
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T data)
    {
        this -> data = data;
        left = nullptr;
        right = nullptr;
    }

    ~ BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};
void printTree(BinaryTreeNode<int>* root)
{
    if(root == nullptr)
    {
        return;
    }
    cout << root -> data << " : ";
    if(root -> left)
    {
        cout << "L " << root -> left -> data << ", ";
    }
    if(root -> right)
    {
        cout << "R " << root -> right -> data;
    }
    cout << endl;
    printTree(root -> left);
    printTree(root -> right);
}
BinaryTreeNode<int>* take_input()
{
    int rootdata;
    cout << "Enter data: " << endl;
    cin >> rootdata;
    if(rootdata == -1)
    {
        return nullptr;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
    BinaryTreeNode<int>* leftnode = take_input();
    BinaryTreeNode<int>* rightnode = take_input();
    root -> left = leftnode;
    root -> right = rightnode;
    return root;
}
BinaryTreeNode<int>* take_input_levelwise()
{
    int rootdata;
    cout << "Enter root data: " << endl;
    cin >> rootdata;
    if(rootdata == -1)
    {
        return nullptr;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int>*> pending_nodes;
    pending_nodes.push(root);
    while(!pending_nodes.empty())
    {
        BinaryTreeNode<int>* front = pending_nodes.front();
        pending_nodes.pop();
        cout << "Enter the left child of " << front -> data << endl;
        int leftchild;
        cin >> leftchild;
        if(leftchild != -1)
        {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftchild);
            front -> left = child;
            pending_nodes.push(child);
        }
        cout << "Enter the right child of " << front -> data << endl;
        int rightchild;
        cin >> rightchild;
        if(rightchild != -1)
        {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightchild);
            front -> right = child;
            pending_nodes.push(child);
        }
    }
    return root;
}
void printLevelWise(BinaryTreeNode<int>* root)
{
    if(root == nullptr)
        return;
    queue<BinaryTreeNode<int>*> pending_nodes2;
    pending_nodes2.push(root);
    while(!pending_nodes2.empty())
    {
        BinaryTreeNode<int>* front = pending_nodes2.front();
        pending_nodes2.pop();
        cout << front -> data << ":";
        if(front -> left)
        {
            cout << "L:" << front -> left -> data << ",";
            pending_nodes2.push(front -> left);
        }
        else
        {
            cout << "L:" << -1 << ",";
        }
        if(front -> right)
        {
            cout << "R:" << front -> right -> data;
            pending_nodes2.push(front -> right);
        }
        else
        {
             cout << "R:" << -1;
        }
        cout << endl;
    }
}
int numNodes(BinaryTreeNode<int>* root)
{
    if(root == nullptr)
    {
        return 0;
    }
    int ans = 1;
    return ans+numNodes(root -> left)+numNodes(root -> right);
}
bool isNodePresent(BinaryTreeNode<int>* root, int x)
{
    if(root == nullptr)
    {
        return false;
    }
    if(root -> data == x)
    {
        return true;
    }
    bool left,right;
    if(root -> left)
    {
        left = isNodePresent(root -> left,x);
    }
    if(root->right)
    {
        right = isNodePresent(root -> right,x);
    }
    if(left || right)
    {
        return true;
    }
    return false;
}
int height(BinaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return 0;
    }
    int left_height = 0;
    int right_height = 0;
    if(root -> left)
    {
        left_height+=height(root -> left);
    }
    if(root -> right)
    {
        right_height+=height(root -> right);
    }
    return left_height > right_height ? left_height+1 : right_height+1;
}
void mirrorBinaryTree(BinaryTreeNode<int>* root)
{
    if(root == nullptr)
    {
        return;
    }
    if(root -> left)
    {
        mirrorBinaryTree(root -> left);
    }
    if(root -> right)
    {
        mirrorBinaryTree(root -> right);
    }
    BinaryTreeNode<int>* temp = root -> right;
    root -> right = root -> left;
    root -> left = temp;
}
int main()
{
    BinaryTreeNode<int>* root = take_input_levelwise();
    printLevelWise(root);
    //cout << "Number of nodes is: " << numNodes(root) << endl;
    //cout << "Height of the binary tree is " << height(root) << endl;
    mirrorBinaryTree(root);
    cout << " ------------------------- " << endl;
    printLevelWise(root);
}






















