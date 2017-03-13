#include <iostream>
using namespace std;


class List;

class LinkNode {
    friend class List;
private:
    int data;
    LinkNode *link;
public:
    LinkNode(LinkNode *ptr = NULL){
       link = ptr;
    }
    LinkNode(int d,LinkNode *ptr = NULL){
        this->data = d;
        link = ptr;
    }

};
class List{
private:
    LinkNode *first;
    int length;
public:
    int getLength(){
       return length;
    }
    List(){
        first = new LinkNode();
        }
    void setLength(int l){length = l;}
    void Input(){
        int i,a;
      for (i=0;i<length;i++){
        cin>>a;

        LinkNode *newNode = new LinkNode(a);
        newNode->link = first;
        first = newNode;
      }
    }
    void Output(){
    int i=0;
    LinkNode *current = new LinkNode;
    current = first;
    for (i=0;i<length;i++){
        cout<<current->data<<endl;
        current = current->link;
    }
    }
    void Sort(){
    int i,j,d;
    LinkNode *node1 = new LinkNode();
    LinkNode *node2 = new LinkNode();
    node1=first;
    for (i=0;i<length;i++){
        node2 = first;
        for (j=0;j<length;j++){
            if (node1->data<node2->data){
               d=node2->data;
               node2->data = node1->data;
               node1->data = d;
            }
            node2=node2->link;
        }
        node1=node1->link;
    }
    }
    int Find(int a){
    LinkNode *current = new LinkNode();
    current = first;
    int i,f=0;
    for (i=0;i<length;i++){
        if (current->data == a){
            f = 1;
            break;
        }
        current = current->link;
    }
    if (f==0 && i==length){
        return 0;
    }
    else
        return 1;
    }
    void hebing(List list){
       int j;
       LinkNode *current = new LinkNode();
        current = list.first;
           for (j=0;j<list.getLength();j++){

            if (this->Find(current->data)==0){
                LinkNode *newNode = new LinkNode(current->data);
                newNode->link = this->first;
                this->first = newNode;
                this->length++;
            }
            current = current->link;
           }
    }

};

int main()
{
    int l;
    cin>>l;
    List list1,list2;
    list1.setLength(l);
    list1.Input();
    cin>>l;
    list2.setLength(l);
    list2.Input();
    //list1.Output();
   // list2.Output();
    list1.hebing(list2);
    list1.Sort();
    list1.Output();
    return 0;
}




