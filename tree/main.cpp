#include <iostream>
#include <math.h>
#include<stdio.h>
using namespace std;

class BinaryTree;
class BinaryNode
{
    friend class BinaryTree;
private:
    BinaryNode *leftchild;
    BinaryNode *rightchild;
    char date;
public:
    BinaryNode()
    {
        leftchild=NULL;
        rightchild=NULL;
    }
    BinaryNode(char a,BinaryNode *left=NULL,BinaryNode *right=NULL)
    {
        date=a;
        leftchild=left;
        rightchild=right;
    }
    char getdate()
    {
        return date;
    }
    void setdate(char date)
    {
        this->date=date;
    }
};
class BinaryTree
{
private:
    BinaryNode *root;
    void createtree(BinaryNode* &root)
    {
        char a;
        cin>>a;
        if(a!='#')
        {
            root=new BinaryNode(a);
            createtree(root->leftchild);
            createtree(root->rightchild);
        }
        else
        {
            root=NULL;
        }
    }
    void preorder(BinaryNode *root)
    {
        if(root!=NULL)
        {
            cout<<root->date<<' ';
            preorder(root->leftchild);
            preorder(root->rightchild);
        }
    }
    void inorder(BinaryNode *root)
    {
        if(root!=NULL)
        {
            inorder(root->leftchild);
            cout<<root->date<<' ';
            inorder(root->rightchild);
        }
    }
    void postorder(BinaryNode *root)
    {
        if(root!=NULL)
        {
            postorder(root->leftchild);
            postorder(root->rightchild);
            cout<<root->date<<' ';
        }
    }
    int depth(BinaryNode *root)
    {
        if(root!=NULL)
        {
            return max(depth(root->leftchild),depth(root->rightchild))+1;
        }
        else return 0;
    }
    int countleaf(BinaryNode *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        else if(root->leftchild!=NULL||root->rightchild!=NULL)
        {
            return countleaf(root->leftchild)+countleaf(root->rightchild);
        }
        else return 1;
    }
    int Size(BinaryNode *root)
    {
        if(root==NULL) return 0;
        else return Size(root->leftchild)+Size(root->rightchild)+1;
    }
    int findleaf(BinaryNode *root,char a)
    {
        if(root==NULL) return 0;
        else if(root->date==a) return 1;
        else return findleaf(root->leftchild,a)+findleaf(root->rightchild,a);
    }

    void output(BinaryNode *root,int &a)
    {
        if(root!=NULL)
        {
            for(int i=0; i<a; i++)
            {
                cout<<"  ";
            }
            cout<<root->date<<endl;
            a++;
            if (root->leftchild!=NULL)
            {
                output(root->leftchild,a);
                a--;
            }
            if(root->rightchild!=NULL)
            {
                output(root->rightchild,a);
                a--;
            }
        }
    }
public:
    BinaryTree()
    {
        root=NULL;
    }
    void createtree()
    {
        createtree(root);
        cout<<"Created success!"<<endl;
    }

    void preorder()
    {
        cout<<"Preorder is:";
        preorder(root);
        cout<<"."<<endl;
    }
    void inorder()
    {
        cout<<"Inorder is:";
        inorder(root);
        cout<<"."<<endl;
    }
    void postorder()
    {
        cout<<"Postorder is:";
        postorder(root);
        cout<<"."<<endl;
    }

    void depth()
    {
        cout<<"Height=";
        cout<<depth(root);
        cout<<"."<<endl;
    }

    void countleaf()
    {
        cout<<"Leaf=";
        cout<<countleaf(root);
        cout<<"."<<endl;
    }

    void Size()
    {
        cout<<"Nodes=";
        cout<<Size(root);
        cout<<"."<<endl;
    }

    void findleaf()
    {
        char a;
        cin>>a;
        cout<<"The count of "<<a<<" is ";
        cout<<findleaf(root,a);
        cout<<"."<<endl;
    }

    void output()
    {
        int a=0;
        cout<<"The tree is:"<<endl;
        output(root,a);
    }

};

int main()
{
    char x;
    BinaryTree *tree = new BinaryTree();
    cin>>x;
    while(x!='P')
    {

        if(x=='C')
        {
            tree->createtree();

        }
        else if(x=='H')
        {
            tree->depth();
        }
        else if(x=='L')
        {
            tree->countleaf();

        }
        else if(x=='N')
        {
            tree->Size();

        }
        else if(x=='1')
        {
            tree->preorder();

        }
        else if(x=='2')
        {
            tree->inorder();
        }
        else if(x=='3')
        {
            tree->postorder();
        }
        else if(x=='F')
        {

            tree->findleaf();
        }
        cin>>x;
    }
    tree->output();
    return 0;
}
