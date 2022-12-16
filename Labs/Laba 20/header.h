#include <iostream>

using namespace std;

int c;

struct tree
{
    int data;
    tree *left;
    tree *right;
};

class btree
{
    tree *root;
    tree *insert(tree *&leaf, int element)
    {
        if (leaf == NULL)
        {
            tree *leaf_new = new tree;
            leaf_new->data = element;
            leaf_new->left = NULL;
            leaf_new->right = NULL;
            return leaf_new;
        }
        if (element < leaf->data)
            leaf->left = insert(leaf->left, element);
        if (element > leaf->data)
            leaf->right = insert(leaf->right, element);
        return leaf;
    }
    void print(tree *l)
    {
        if (l == NULL)
            return;
        cout << l->data << " ";
        print(l->left);
        print(l->right);
        c++;
    }

public:
    btree();
    ~btree()
    {
        delete root;
    };

    void insert(int element)
    {
        root = insert(root, element);
    }
    void print();
    void count();
};

btree::btree()
{
    root = NULL;
}

void btree::print()
{
    print(root);
}

void btree::count()
{
    cout << "Count: " << c << endl;
}