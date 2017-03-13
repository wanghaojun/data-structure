#include <iostream>

using namespace std;

class LinkNode
{
    friend class LinkedStack;
private:
    char c;
    LinkNode *next;
public:
    LinkNode(LinkNode *p = NULL)
    {
        next = p;
    }
    void setc(char a)
    {
        c=a;
    }
    char getc()
    {
        return c;
    }
};
class LinkedStack
{


private:
    LinkNode *top;
    int length;
public:
    int getlength(){return length;}
    LinkedStack()
    {
        top = new LinkNode();
        length = 0;
    }
    char gettop()
    {
        return top->getc();
    }
    void push(char x)
    {
        LinkNode *p;
        p=top;
        top = new LinkNode(p);
        top->setc(x);
        length++;
    }
    void Delete()
    {
        LinkNode *p = new LinkNode();
        p=top;
        top = top->next;
        length--;
        delete p;
    }
    void Output()
    {
        int i;

        LinkNode *current = new LinkNode();
        current = top;
        for(i=0; i<length; i++)
        {
            if(current->getc()=='{')
                cout<<"}";
            else if(current->getc()=='(')
                cout<<")";
            else if(current->getc()=='[')
                cout<<"]";
            else if(current->getc()=='<')
                cout<<">";
            current=current->next;
        }
    }


};

int main()
{
    LinkedStack l;
    char x;
    int flag=0,i=0;
    cin>>x;
    for(;x!='#';cin>>x)
    {
        i++;
        if(x=='<' || x=='[' || x=='{' || x=='(')
        {
            l.push(x);
        }
        if(x=='>' || x== ']' || x=='}' || x==')')
        {
            if(l.gettop()=='<' && x=='>')
            {
                l.Delete();
            }
            else if(l.gettop()=='[' && x==']')
            {
                l.Delete();
            }
            else if(l.gettop()=='{' && x=='}')
            {
                l.Delete();
            }
            else if(l.gettop()=='(' && x==')')
            {
                l.Delete();
            }
            else{
                flag=1;
                break;
            }
        }
    }
    if (l.getlength()!=0){
        cout<<"loss of right character ";
        l.Output();
        cout<<"."<<endl;
    }
    else if (flag==1){
            cout<<"The "<<i<<" character '"<<x<<"' is wrong."<<endl;
        }
    else if (flag==0){
        cout<<"right"<<endl;
    }
    return 0;
}
