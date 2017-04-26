/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <iostream>
using namespace std;
class BinaryTree ;
class BinTreeNode { //结点类的定义
friend class BinaryTree;
public:
  BinTreeNode ( char x,BinTreeNode *left = NULL,BinTreeNode *right = NULL ) : data (x), leftChild (left), rightChild(right) { } //构造函数
  ~BinTreeNode ( ) { } //析构函数
private:
  BinTreeNode *leftChild, *rightChild; //左、右子女链域
  char data; //数据域
};
class BinaryTree {
public:
  BinaryTree ( char value ) { RefValue =value;root =NULL; }
  ~BinaryTree(){ destroy ( root );}
  void CreateBinTree( ) { CreateBinTree(root);}
  int getNode( )  {return getNode(root); }    //节点个数
private:
  BinTreeNode *root; //二叉树的根指针
  char RefValue; //数据输入停止标志
  void CreateBinTree( BinTreeNode * & subTree) ;
  void destroy(BinTreeNode* &subTree){};
  int getNode(BinTreeNode *subTree); //节点个数

};
int BinaryTree::getNode(BinTreeNode *subTree){
    if(subTree==NULL){
        return 0;
    }
    else
    {
        return getNode(subTree->leftChild)+getNode(subTree->rightChild)+1;
    }

}
void BinaryTree::CreateBinTree(BinTreeNode* & subTree) {//私有函数: 建立根为subTree的子树
  char item; cin>> item;
  if (item != RefValue)
  {
    subTree = new BinTreeNode (item);
    CreateBinTree( subTree->leftChild);
    CreateBinTree( subTree->rightChild);
  }
else
  subTree = NULL;
};

int main()
{
BinaryTree a=BinaryTree('@');
a.CreateBinTree();
cout<<"The count of the nodes is "<<a.getNode()<<endl;
return 1;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
