#include "assert.h"
#include <iostream>
using namespace std;
class BinaryTree ;
class BinTreeNode
{ //结点类的定义
  friend class BinaryTree;
  public:
    BinTreeNode ( ) {leftChild =NULL; rightChild =NULL;}
    BinTreeNode ( char x,BinTreeNode *left = NULL,BinTreeNode *right = NULL ) {
        data=x;
    leftChild=left;
    rightChild=right;
    };

 ~BinTreeNode ( ) { } //析构函数
  private:
 BinTreeNode *leftChild, *rightChild; //左、右子女链域
 char data; //数据域
};
class SeqQueue
{
  friend class BinaryTree;
  int rear, front; //队尾与队头指针
  BinTreeNode **elements; //队列存放数组
  int maxSize; //队列最大容量
  public:
 SeqQueue(int sz = 100); //构造函数
 ~SeqQueue() { } //析构函数
 int EnQueue(BinTreeNode *x); //新元素进队列
    BinTreeNode * DeQueue(); //退出队头元素
 int getFront(int& x); //取队头元素值
 void makeEmpty() { front = rear = 0; }
 int IsEmpty() const { return front == rear; }
 int IsFull() const { return ((rear+1)% maxSize == front); }
 int getSize() const { return (rear-front+maxSize) % maxSize; } };
    SeqQueue::SeqQueue(int sz)
 { //构造函数
   front=0; rear=0; maxSize=sz;
   elements = new BinTreeNode*[maxSize];
   assert ( elements != NULL );
 };
  int SeqQueue::EnQueue(BinTreeNode *x)
  { //若队列不满, 则将x插入到该队列队尾, 否则返回
   if (IsFull()) return 0;
   elements[rear] = x; //先存入
      rear = (rear+1) % maxSize; //尾指针加一
   return 1;
  };
  BinTreeNode * SeqQueue::DeQueue()
  { //若队列不空则函数退队头元素并返回其值
      if (IsEmpty()) return NULL;
   BinTreeNode *x;
   x = elements[front]; //先取队头
   front = (front+1) % maxSize; //再队头指针加一
   return x;
  };
 class BinaryTree
 {
   public:
   BinaryTree(): root (NULL) { };
   BinaryTree ( char value ) { RefValue =value;root =NULL; }
   void CreateBinTree( )
   { CreateBinTree(root);}
   void levelOrder( ) ; //层序遍历
   private: BinTreeNode *root; //二叉树的根指针
      char RefValue; //数据输入停止标志
      void CreateBinTree( BinTreeNode * & subTree) ;
    };
   void BinaryTree ::CreateBinTree(BinTreeNode* & subTree)
   {//私有函数: 建立根为subTree的子树
   char item;
         cin>> item;
   if (item != RefValue)
   { subTree = new BinTreeNode (item);
     CreateBinTree( subTree->leftChild);
     CreateBinTree( subTree->rightChild);
   }
        else
   subTree = NULL;
   };
void BinaryTree::levelOrder()
{
    SeqQueue S(100);
   BinTreeNode *p=root;
  S.EnQueue(p);
  while (!S.IsEmpty())
  { p=S.DeQueue();
    cout<<p->data;
 if(p->leftChild!=NULL){S.EnQueue(p->leftChild);}
 if(p->rightChild!=NULL){S.EnQueue(p->rightChild);}
  }
  cout<<endl;
};
int main()
{ BinaryTree tree('@');
  tree.CreateBinTree();
  tree.levelOrder();
  return 0;
}
