#include "assert.h"
#include <iostream>
using namespace std;
class BinaryTree ;
class BinTreeNode
{ //�����Ķ���
  friend class BinaryTree;
  public:
    BinTreeNode ( ) {leftChild =NULL; rightChild =NULL;}
    BinTreeNode ( char x,BinTreeNode *left = NULL,BinTreeNode *right = NULL ) {
        data=x;
    leftChild=left;
    rightChild=right;
    };

 ~BinTreeNode ( ) { } //��������
  private:
 BinTreeNode *leftChild, *rightChild; //������Ů����
 char data; //������
};
class SeqQueue
{
  friend class BinaryTree;
  int rear, front; //��β���ͷָ��
  BinTreeNode **elements; //���д������
  int maxSize; //�����������
  public:
 SeqQueue(int sz = 100); //���캯��
 ~SeqQueue() { } //��������
 int EnQueue(BinTreeNode *x); //��Ԫ�ؽ�����
    BinTreeNode * DeQueue(); //�˳���ͷԪ��
 int getFront(int& x); //ȡ��ͷԪ��ֵ
 void makeEmpty() { front = rear = 0; }
 int IsEmpty() const { return front == rear; }
 int IsFull() const { return ((rear+1)% maxSize == front); }
 int getSize() const { return (rear-front+maxSize) % maxSize; } };
    SeqQueue::SeqQueue(int sz)
 { //���캯��
   front=0; rear=0; maxSize=sz;
   elements = new BinTreeNode*[maxSize];
   assert ( elements != NULL );
 };
  int SeqQueue::EnQueue(BinTreeNode *x)
  { //�����в���, ��x���뵽�ö��ж�β, ���򷵻�
   if (IsFull()) return 0;
   elements[rear] = x; //�ȴ���
      rear = (rear+1) % maxSize; //βָ���һ
   return 1;
  };
  BinTreeNode * SeqQueue::DeQueue()
  { //�����в��������˶�ͷԪ�ز�������ֵ
      if (IsEmpty()) return NULL;
   BinTreeNode *x;
   x = elements[front]; //��ȡ��ͷ
   front = (front+1) % maxSize; //�ٶ�ͷָ���һ
   return x;
  };
 class BinaryTree
 {
   public:
   BinaryTree(): root (NULL) { };
   BinaryTree ( char value ) { RefValue =value;root =NULL; }
   void CreateBinTree( )
   { CreateBinTree(root);}
   void levelOrder( ) ; //�������
   private: BinTreeNode *root; //�������ĸ�ָ��
      char RefValue; //��������ֹͣ��־
      void CreateBinTree( BinTreeNode * & subTree) ;
    };
   void BinaryTree ::CreateBinTree(BinTreeNode* & subTree)
   {//˽�к���: ������ΪsubTree������
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
