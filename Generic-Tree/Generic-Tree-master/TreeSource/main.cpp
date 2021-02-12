#include<bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(T data)
    {
        this -> data = data;
    }
};

TreeNode<int>* take_input_levelwise()
{
    int rootdata;
    cout << "Enter data : " << endl;
    cin >> rootdata;
    TreeNode<int>* root = new TreeNode<int>(rootdata);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter numbers of child node of "<< front -> data << " : " << endl;
        int numchild;
        cin >> numchild;
        for(int i=0;i<numchild;i++)
        {
            int child_data;
            cout << "Enter " << i << " th child of " << front -> data << endl;
            cin >> child_data;
            TreeNode<int>* child = new TreeNode<int>(child_data);
            front -> children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

TreeNode<int>* take_input()
{
    int root_data;
    cout << "Enter the root data :" << endl;
    cin >> root_data;
    TreeNode<int>* root = new TreeNode<int>(root_data);

    int n;
    cout << "Enter the number of children of the root data :" << endl;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        TreeNode<int>* child = take_input();
        root -> children.push_back(child);
    }
    return root;
}
void print_level_wise(TreeNode<int>* root)
{
   queue<TreeNode<int>*> pending_nodes;
   pending_nodes.push(root);
   while(!pending_nodes.empty())
   {
       TreeNode<int>* front = pending_nodes.front();
       pending_nodes.pop();
       cout << front -> data << " : ";
       for(int i=0;i<front -> children.size();i++)
       {
            if(i==front -> children.size()-1)
            {
                cout << front -> children[i] -> data;
            }
            else
            {
                cout << front -> children[i] -> data << " , ";
            }
            pending_nodes.push(front -> children[i]);
       }
       cout << endl;
   }
}

int numNode(TreeNode<int>* root)
{
    int sum = 0;
    for(int i=0;i<root -> children.size();i++)
    {
        sum+=numNode(root -> children[i]);
    }
    return sum+1;
}

int sumNode(TreeNode<int>* root)
{
    int sum = 0;
    for(int i=0;i<root -> children.size();i++)
    {
        sum+=sumNode(root -> children[i]);
    }
    return sum+root -> data;
}

int max_data_node(TreeNode<int>* root)
{
    int maxim = root -> data;
    int small_ans=0;
    for(int i=0;i<root -> children.size();i++)
    {
        small_ans = max_data_node(root -> children[i]);
        if(small_ans>maxim)
        {
            maxim = small_ans;
        }
    }
    return maxim;
}

int height(TreeNode<int>* root)
{
    int maxim = 0;
    for(int i=0;i<root -> children.size();i++)
    {
        int small_size = height(root -> children[i]);
        if(small_size > maxim)
        {
            maxim = small_size;
        }
    }
    return maxim+1;
}

void printTree(TreeNode<int>* root)
{
    if(root == nullptr)
    {
        return;
    }
    cout << root -> data << ": ";
    for(int i=0;i<root -> children.size();i++)
    {
        cout << root -> children[i] -> data << ", ";
    }
    cout << endl;
    for(int i=0;i<root -> children.size();i++)
    {
        printTree(root -> children[i]);
    }
}

void print_level_k(TreeNode<int>* root,int k)
{
    if(k==0)
    {
        cout << root -> data << " ";
        return;
    }
    for(int i=0;i<root -> children.size();i++)
    {
            print_level_k(root -> children[i],k-1);
    }
}

int count_leaf_nodes(TreeNode<int>* root)
{
    if(root -> children.size()==0)
    {
        return 1;
    }
    int sum = 0;
    for(int i=0;i<root -> children.size();i++)
    {
       sum+= count_leaf_nodes(root -> children[i]);
    }
    return sum;
}

void preorder_traversal(TreeNode<int>* root)
{
    if(root == nullptr)
    {
        return;
    }
    cout << root -> data << " ";
    for(int i=0;i < root -> children.size();i++)
    {
        preorder_traversal(root -> children[i]);
    }
}

void postorder_traversal(TreeNode<int>* root)
{
    if(root == nullptr)
    {
        return;
    }
    for(int i=0;i < root -> children.size();i++)
    {
        postorder_traversal(root -> children[i]);
    }
     cout << root -> data << " ";
}

bool is_present(TreeNode<int>* root, int x)
{
    if(root -> data == x)
    {
        return true;
    }
    for(int i=0;i<root -> children.size();i++)
    {
        if(is_present(root -> children[i],x))
        {
            return true;
        }
    }
    return false;
}

int nodesGreaterThanX(TreeNode<int> *root, int x)
{
    if(root == nullptr)
    {
        return false;
    }
    int count = 0;
    if(root -> data > x)
    {
        count++;
    }
    for(int i=0;i<root -> children.size();i++)
    {
        int p = nodesGreaterThanX(root -> children[i],x);
        count+=p;
    }
    return count;
}

TreeNode<int>* maxSumNode(TreeNode<int> *root)
{
    if(root == nullptr)
    {
        return nullptr;
    }
    TreeNode<int>* max_node = root;
    int maximum_value = root -> data;
    for(int i=0;i<root -> children.size();i++)
    {
        maximum_value += root -> children[i] -> data;
    }
    for(int i=0;i<root -> children.size();i++)
    {
        TreeNode<int>* small_max = maxSumNode(root -> children[i]);
        int p = small_max -> data;
        for(int i=0;i<small_max -> children.size();i++)
        {
            p += small_max -> children[i] -> data;
        }
        if(p > maximum_value)
        {
            maximum_value = p;
            max_node = small_max;
        }
    }
    return max_node;
}

bool isIdentical(TreeNode<int> *root1, TreeNode<int> * root2)
{
    if(root1 == nullptr || root2 == nullptr)
    {
        return false;
    }
    if(root1 -> data == root2 -> data)
    {
        for(int i=0;i<root1->children.size();i++)
        {
            return isIdentical(root1 -> children[i],root2 -> children[i]);
        }
    }
}

TreeNode<int>* nextLargerElement(TreeNode<int> *root, int n)
{
	if(root == nullptr)
    {
        return nullptr;
    }
    TreeNode<int>* ans = nullptr;
	if(root -> data > n)
    {
        ans = root;
    }
    for(int i=0;i<root -> children.size();i++)
    {
        TreeNode<int>* small_ans = nextLargerElement(root -> children[i],n);
        if(ans==nullptr && small_ans==nullptr)
        {
            continue;
        }
        else if(ans==nullptr)
        {
            ans = small_ans;
        }
        else if(ans && small_ans)
        {
            if(small_ans -> data < ans -> data)
            {
                ans = small_ans;
            }
        }
    }
    return ans;
}

template <typename T>
class Secondlargest_return
{
public:
    TreeNode<T>* largest;
    TreeNode<T>* secondlargest;
    Secondlargest_return(TreeNode<T>* first, TreeNode<T>* second)
    {
        this -> largest = first;
        this -> secondlargest = second;
    }
};

Secondlargest_return<int>* second_largest_helper(TreeNode<int>* root)
{
    if(root == NULL)
    {
        Secondlargest_return<int>* ans = new Secondlargest_return<int>(NULL,NULL);
        return ans;
    }
    Secondlargest_return<int>* ans = new Secondlargest_return<int>(root,NULL);
    for(int i=0;i<root -> children.size();i++)
    {
        Secondlargest_return<int>* small_ans = second_largest_helper(root -> children[i]);
        if(small_ans -> largest -> data > ans -> largest -> data)
        {
            if(small_ans -> secondlargest == NULL)
            {
                ans -> secondlargest = ans -> largest;
                ans -> largest = small_ans -> largest;
            }
            else
            {
                if(small_ans -> secondlargest -> data > ans -> largest -> data)
                {
                    ans -> secondlargest = small_ans -> secondlargest;
                    ans -> largest = small_ans -> largest;
                }
                else
                {
                    ans -> secondlargest = ans -> largest;
                    ans -> largest = small_ans -> largest;
                }
            }
        }
        else
        {
            if((ans -> largest -> data != small_ans -> largest -> data)&&
               (ans -> secondlargest == NULL || small_ans -> largest -> data > ans -> secondlargest -> data))
            {
                ans -> secondlargest = small_ans -> largest;
            }
        }
    }
    return ans;
}

TreeNode <int>* secondLargest(TreeNode<int> *root)
{
    return second_largest_helper(root) -> secondlargest;
}

void replace_helper(TreeNode<int>* root,int depth)
{
    root -> data =  depth;
    for(int i=0;i<root -> children.size();i++)
    {
        replace_helper(root,depth+1);
    }
    return;
}
void replaceWithDepthValue(TreeNode<int> *root)
{ 
    int depth = 0;
    replace_helper(root,depth);
    return;
}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main()
{
    /*TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);
    root -> children.push_back(node1);
    root -> children.push_back(node2);
    cout << max_data_node(root) << endl;
    cout << height(root) << endl;
    // print_level_k(root,1);
    // cout << count_leaf_nodes(root) << endl;*/
    TreeNode<int>* root = take_input_levelwise();
    print_level_wise(root);
    postorder_traversal(root);
}
