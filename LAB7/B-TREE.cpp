#include <bits/stdc++.h>
using namespace std;
class BTreeNode
{
int *keys;
BTreeNode **child;
int t;
int n;
bool leaf;
public:
BTreeNode(int t, bool leaf);
void traverse();
void insertNonFull(int k);
void splitChild(int i, BTreeNode *y);
friend class BTree;
};
class BTree
{
BTreeNode *root;
int t;
public:
BTree(int _t){
root = NULL;
t = _t;
}
void traverse()
{
if(root != NULL)
root->traverse();
}
void insert(int k);
};
BTreeNode::BTreeNode(int t1, bool leaf1)
{
t = t1;
leaf = leaf1;
keys = new int[2*t-1];
child = new BTreeNode *[2*t];
n = 0;
}


int main()
{
int d;
cout<<"Enter the degree: ";
cin>>d;
BTree t(d);
int n,k;
cout<<"Enter the no. of elements"<<endl;
cin>>n;
cout<<"Enter the keys"<<endl;
for(int i=0; i<n; i++)
{
cin>>k;
t.insert(k);
}
cout << "Traversal of tree constructed is\n";
t.traverse();
cout<<endl;
return 0;
}
