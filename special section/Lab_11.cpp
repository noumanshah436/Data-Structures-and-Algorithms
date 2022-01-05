#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
using namespace std;
#define pow2(n) (1 << (n))

struct avl_node {

    int data;
    struct avl_node* left;
    struct avl_node* right;

}*root;

class avlTree {

public:
    avlTree();
    avl_node* rr_rotation(avl_node*);
    avl_node* ll_rotation(avl_node*);
    avl_node* lr_rotation(avl_node*);
    avl_node* rl_rotation(avl_node*);
    avl_node* balance(avl_node*);
    avl_node* insert(avl_node*, int);
    avl_node* Delete(avl_node*, int);
    void update(int, int);
    void display(avl_node*, int);
    void inorder(avl_node*);
    void preorder(avl_node*);
    void postorder(avl_node*);
    int getMaxValue(avl_node*);
    int getMinValue(avl_node*);
    int height(avl_node*);
    int diff(avl_node*);
    bool find(int);
    bool isEmpty();
};

int main()
{
    avlTree avl;

    ///////////////////////////////INSERT///////////////////////////////
    root = avl.insert(root, 20); root = avl.insert(root, 21); root = avl.insert(root, 66); root = avl.insert(root, 82);
    root = avl.insert(root, 25); root = avl.insert(root, 89); root = avl.insert(root, 45); root = avl.insert(root, 39);
    root = avl.insert(root, 35); root = avl.insert(root, 79); root = avl.insert(root, 67); root = avl.insert(root, 94);
    cout << "Balanced AVL Tree (After Inserting):" << endl; avl.display(root, 1);

    ///////////////////////////////UPDATE///////////////////////////////
    avl.update(82, 80); avl.update(67, 78); avl.update(66, 77); avl.update(94, 99); avl.update(39, 36);
    cout << "\nBalanced AVL Tree (After Updating):" << endl; avl.display(root, 1);

    ///////////////////////////////DELETE///////////////////////////////
    avl.Delete(root, 89); avl.Delete(root, 25); avl.Delete(root, 79); avl.Delete(root, 39); avl.Delete(root, 94);
    cout << "\nBalanced AVL Tree (After Deleting):" << endl; avl.display(root, 1);

    ///////////////////////////////MINIMUM VALUE///////////////////////////////
    cout << "\nMinimum Value :" << avl.getMinValue(root);

    ///////////////////////////////MAXIMUM VALUE///////////////////////////////
    cout << "\nMaximum Value :" << avl.getMaxValue(root);

    return 0;
}

avlTree::avlTree()
{
    root = NULL;
}
avl_node* avlTree::rr_rotation(avl_node* parent)
{
    avl_node* temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
avl_node* avlTree::ll_rotation(avl_node* parent)
{
    avl_node* temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
avl_node* avlTree::lr_rotation(avl_node* parent)
{
    avl_node* temp;
    temp = parent->left;
    parent->left = rr_rotation(temp);
    return ll_rotation(parent);
}
avl_node* avlTree::rl_rotation(avl_node* parent)
{
    avl_node* temp;
    temp = parent->right;
    parent->right = ll_rotation(temp);
    return rr_rotation(parent);
}
avl_node* avlTree::balance(avl_node* temp)
{
    int bal_factor = diff(temp);
    if (bal_factor > 1)
    {
        if (diff(temp->left) > 0)
            temp = ll_rotation(temp);
        else
            temp = lr_rotation(temp);
    }
    else if (bal_factor < -1)
    {
        if (diff(temp->right) > 0)
            temp = rl_rotation(temp);
        else
            temp = rr_rotation(temp);
    }
    return temp;
}
avl_node* avlTree::insert(avl_node* root, int value)
{
    if (find(value))
        return root;

    if (root == NULL)
    {
        root = new avl_node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
        root = balance(root);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
        root = balance(root);
    }
    return root;
}
avl_node* avlTree::Delete(avl_node* tempNode, int value)
{
    avl_node* temp;
    if (tempNode == NULL)
    {
        return 0;
    }
    else
    {
        if (value > tempNode->data)
        {
            tempNode->right = Delete(tempNode->right, value);
            if (diff(tempNode) == 2)
            {
                if (diff(tempNode->left) >= 0)
                    tempNode = ll_rotation(tempNode);
                else
                    tempNode = lr_rotation(tempNode);
            }
        }
        else if (value < tempNode->data)
        {
            tempNode->left = Delete(tempNode->left, value);
            if (diff(tempNode) == -2)
            {
                if (diff(tempNode->right) <= 0)
                    tempNode = rr_rotation(tempNode);
                else
                    tempNode = rl_rotation(tempNode);
            }
        }
        else
        {
            if (tempNode->right != NULL)
            {
                temp = tempNode->right;
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }
                tempNode->data = temp->data;
                tempNode->right = Delete(tempNode->right, temp->data);
                if (diff(tempNode) == 2)
                {
                    if (diff(tempNode->left) >= 0)
                        tempNode = ll_rotation(tempNode);
                    else
                        tempNode = lr_rotation(tempNode);
                }
            }
            else
            {
                return tempNode->left;
            }
        }
    }
    return tempNode;
}
void avlTree::update(int data, int updatedData)
{
    if (!find(data))
        return;

    if (find(updatedData))
        return;

    avl_node* currentNode = root;
    while (currentNode != NULL)
    {
        if (data == currentNode->data)
            break;
        else if (data < currentNode->data)
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;
    }
    int getLeft, getRight;

    if (currentNode->left != NULL)
        getLeft = getMaxValue(currentNode->left);
    else
        getLeft = updatedData - 1;

    if (currentNode->right != NULL)
        getRight = getMinValue(currentNode->right);
    else
        getRight = updatedData + 1;

    int save = currentNode->data;

    if (getLeft<updatedData && getRight>updatedData)
        currentNode->data = updatedData;

    if (!find(updatedData))
        currentNode->data = save;
}
void avlTree::display(avl_node* ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");

        if (ptr == root)
            cout << "Root -> ";

        for (i = 0; i < level && ptr != root; i++)
            cout << "        ";

        cout << ptr->data;
        display(ptr->left, level + 1);
    }
}
void avlTree::inorder(avl_node* tree)
{
    if (tree == NULL)
        return;

    inorder(tree->left);
    cout << tree->data << "  ";
    inorder(tree->right);
}
void avlTree::preorder(avl_node* tree)
{
    if (tree == NULL)
        return;

    cout << tree->data << "  ";
    preorder(tree->left);
    preorder(tree->right);
}
void avlTree::postorder(avl_node* tree)
{
    if (tree == NULL)
        return;

    postorder(tree->left);
    postorder(tree->right);
    cout << tree->data << "  ";
}
int avlTree::getMaxValue(avl_node* root)
{
    if (root == NULL)
        return INT_MIN;

    int value = root->data;
    int left = getMaxValue(root->left);
    int right = getMaxValue(root->right);

    if (left > value)
        value = left;

    if (right > value)
        value = right;

    return value;
}
int avlTree::getMinValue(avl_node* root)
{
    if (root == NULL)
        return INT_MAX;

    int value = root->data;
    int left = getMinValue(root->left);
    int right = getMinValue(root->right);

    if (left < value)
        value = left;

    if (right < value)
        value = right;

    return value;
}
int avlTree::height(avl_node* temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height(temp->left);
        int r_height = height(temp->right);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
int avlTree::diff(avl_node* temp)
{
    int l_height = height(temp->left);
    int r_height = height(temp->right);
    int b_factor = l_height - r_height;
    return b_factor;
}
bool avlTree::find(int value)
{
    avl_node* currentNode = root;
    while (currentNode != NULL)
    {
        if (value == currentNode->data)
            return 1;
        else if (value < currentNode->data)
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;
    }
    return 0;
}
bool avlTree::isEmpty()
{
    if (root == NULL)
        return true;
    else
        return false;
}