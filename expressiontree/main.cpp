#include <iostream>

using namespace std;
class BinaryTree;
class BinaryNode
{
    friend class BinaryTree;
private:
    char date;
    BinaryNode *rightchild;
    BinaryNode *leftchild;
public:
    BinaryNode()
    {
        rightchild=NULL;
        leftchild=NULL;
    }
    BinaryNode(char a,BinaryNode *left=NULL,BinaryNode *right=NULL)
    {
        date=a;
        leftchild=left;
        rightchild=right;
    }

};
class BinaryTree
{
private:
    BinaryNode *root;

    void createTree(BinaryNode* &root)
    {
        char a;
        cin>>a;

        if(a!='@')
        {
            root=new BinaryNode(a);
            createTree(root->leftchild);
            createTree(root->rightchild);
        }
        else
            root=NULL;
    }

    void showexpression(BinaryNode *root)
    {
        if(root!=NULL)
        {
            if(root->date=='*' || root->date=='/')
            {
                if(root->leftchild->date=='-' ||root->leftchild->date=='+')
                {
                    cout<<'(';
                    showexpression(root->leftchild);
                    cout<<')';
                }
                else
                {
                    showexpression(root->leftchild);
                }
            }
            else
            {
                showexpression(root->leftchild);
            }
            cout<<root->date;
            if(root->date=='*' || root->date=='/')
            {
                if(root->rightchild->date=='-' ||root->rightchild->date=='+')
                {
                    cout<<'(';
                    showexpression(root->rightchild);
                    cout<<')';
                }
                else
                {
                    showexpression(root->rightchild);
                }
            }
            else
            {
                showexpression(root->rightchild);
            }
        }
    }

    int jisuan(BinaryNode *root){
    if(root!=NULL){
        if(root->date=='+'){
            return jisuan(root->leftchild)+jisuan(root->rightchild);
        }
        else if(root->date=='-'){
            return jisuan(root->leftchild)-jisuan(root->rightchild);
        }
        else if(root->date=='*'){
            return jisuan(root->leftchild)*jisuan(root->rightchild);
        }
        else if(root->date=='/'){
            return jisuan(root->leftchild)/jisuan(root->rightchild);
        }
        else return root->date-'0';
    }
    }
public:
    BinaryTree()
    {
        root=NULL;
    }
    void createTree()
    {
        createTree(root);
    }
    void showexpression()
    {
        showexpression(root);
    }
    void jisuan(){
        cout<<'=';
    cout<<jisuan(root)<<endl;
    }
};

int main()
{
    BinaryTree *tree=new BinaryTree();
    tree->createTree();
    tree->showexpression();
    tree->jisuan();
    return 0;
}

