/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <iostream>
using namespace std;
class BinaryTree ;
class BinTreeNode { //�����Ķ���
friend class BinaryTree;
public:
  BinTreeNode ( char x,BinTreeNode *left = NULL,BinTreeNode *right = NULL ) : data (x), leftChild (left), rightChild(right) { } //���캯��
  ~BinTreeNode ( ) { } //��������
private:
  BinTreeNode *leftChild, *rightChild; //������Ů����
  char data; //������
};
class BinaryTree {
public:
  BinaryTree ( char value ) { RefValue =value;root =NULL; }
  ~BinaryTree(){ destroy ( root );}
  void CreateBinTree( ) { CreateBinTree(root);}
  int getNode( )  {return getNode(root); }    //�ڵ����
private:
  BinTreeNode *root; //�������ĸ�ָ��
  char RefValue; //��������ֹͣ��־
  void CreateBinTree( BinTreeNode * & subTree) ;
  void destroy(BinTreeNode* &subTree){};
  int getNode(BinTreeNode *subTree); //�ڵ����

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
void BinaryTree::CreateBinTree(BinTreeNode* & subTree) {//˽�к���: ������ΪsubTree������
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
