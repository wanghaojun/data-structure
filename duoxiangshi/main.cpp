#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;


class List;
class LinkNode
{
    friend class List;
private:
    int a;//xishu
    int b;//cishu
    LinkNode *next;
public:
    LinkNode(LinkNode *ptr=NULL)
    {
        next = ptr;
    }
    void setA(int a)
    {
        this->a=a;
    }
    void setB(int b)
    {
        this->b=b;
    }
    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }

};
class List
{
private:
    int length;
    LinkNode *first;
public:
    List()
    {
        first = new LinkNode();
    }
    int getlength()
    {
        return length;
    }
    void setlength(int l)
    {
        length = l;
    }
    void Input()
    {
        int l,a,b;
        l=0;
        LinkNode *current = new LinkNode();
        cin>>a;
        while(a!=0)
        {
            LinkNode *newnode = new LinkNode();
            newnode->setA(a);
            cin>>b;
            newnode->setB(b);
            if (l==0)
            {
                first = newnode;
                current = newnode;
                l++;
            }
            else
            {
                current->next = newnode;
                current = newnode;
                l++;
            }
            cin>>a;
        }

        length = l;
    }
    void Output()
    {
        int i;
        LinkNode *current = new LinkNode();
        current = first;

        for (i=0; i<length; i++)
        {
            if (current->getA()==0){
                current = current->next;
                continue;
            }
            if (current->getA()==1 && current->getB()!=0)
            {
                cout<<"x";
                if(current->getB()!=1)
                {
                    cout<<"^"<<current->getB();
                }
                if (i<length-1)
                {
                    if(current->next->getA()>=0)
                    {
                        cout<<"+";
                    }
                }
            }
            else if(current->getB()==0)
            {
                cout<<current->getA();
                if (i<length-1)
                {
                    if(current->next->getA()>=0)
                    {
                        cout<<"+";
                    }
                }

            }
            else
            {
                cout<<current->getA()<<"x";
                if(current->getB()!=1)
                {
                    cout<<"^"<<current->getB();
                }
                if (i<length-1)
                {
                    if(current->next->getA()>=0)
                    {
                        cout<<"+";
                    }
                }
            }
            current=current->next;
        }
        cout<<endl;
    }
    LinkNode* findone(int b)
    {
        int i=0;
        LinkNode *current = new LinkNode();
        current = first;
        for (i=0; i<length; i++)
        {
            if (current->getB()==b)
            {
                return current;
                break;
            }
            else
            {
                current= current->next;
            }
            if (i==length)
            {
                return NULL;
            }
        }
    }
    void hebing()
    {
        int i,j;
        LinkNode *current1 = new LinkNode();
        current1 = first;
        LinkNode *current2 = new LinkNode();
        current2 = first;
        LinkNode *p = new LinkNode();

        for(i=0; i<length; i++)
        {
            current2=first;
            for(j=0; j<length; j++)
            {
                if (current1->getB()==current2->getB() && (current1!=current2))
                {
                    current1->setA(current1->getA()+current2->getA());
                    p=current2->next;
                    Delete(current2);
                    current2=p;
                }
                else
                {
                    current2= current2->next;
                }

            }
            current1=current1->next;

        }
    }
    void Delete(LinkNode *node)
    {
        int i=0;
        LinkNode *current = new LinkNode();
        LinkNode *p = new LinkNode();
        current = first;
        for (i=0; i<length; i++)
        {
            if(current->next==node)
            {
                break;
            }
            current=current->next;
        }
        p=current->next;
        current->next = p->next;
        delete p;
        length--;
    }
    void Sort()
    {
        int i,j,a,b;
        LinkNode *current1 = new LinkNode();
        current1 = first;
        LinkNode *current2 = new LinkNode();

        for(i=0; i<length; i++)
        {
            current2 = first;
            for(j=0; j<length; j++)
            {

                if (current1->getB()<current2->getB())
                {
                    a=current2->getA();
                    b=current2->getB();
                    current2->setA(current1->getA());
                    current2->setB(current1->getB());
                    current1->setA(a);
                    current1->setB(b);
                }
                current2=current2->next;
            }
            current1=current1->next;

        }
    }
    void reduce(List a,List b)
    {
        int i,l;
        l=0;
        LinkNode *currentc = new LinkNode();
        currentc = this->first;
        LinkNode *currenta = new LinkNode();
        currenta = a.first;
        LinkNode *currentb = new LinkNode();
        currentb = b.first;
        for (i=0; i<a.length; i++)
        {
            LinkNode *newnode =  new LinkNode();
            newnode->setA(currenta->getA());
            newnode->setB(currenta->getB());
            if (l==0)
            {
                first = newnode;
                currentc = newnode;
                l++;
            }
            else
            {
                currentc->next = newnode;
                currentc = newnode;
                l++;
            }
            currenta=currenta->next;
        }
        for (i=0; i<b.length; i++)
        {
            LinkNode *newnode =  new LinkNode();
            newnode->setA(-currentb->getA());
            newnode->setB(currentb->getB());
            if (l==0)
            {
                first = newnode;
                currentc = newnode;
                l++;
            }
            else
            {
                currentc->next = newnode;
                currentc = newnode;
                l++;
            }
            currentb=currentb->next;
        }
        length =l;
        this->Sort();
        this->hebing();
    }
    void add(List a,List b)
    {
        int i,l;
        l=0;
        LinkNode *currentc = new LinkNode();
        currentc = this->first;
        LinkNode *currenta = new LinkNode();
        currenta = a.first;
        LinkNode *currentb = new LinkNode();
        currentb = b.first;
        for (i=0; i<a.length; i++)
        {
            LinkNode *newnode =  new LinkNode();
            newnode->setA(currenta->getA());
            newnode->setB(currenta->getB());
            if (l==0)
            {
                first = newnode;
                currentc = newnode;
                l++;
            }
            else
            {
                currentc->next = newnode;
                currentc = newnode;
                l++;
            }
            currenta=currenta->next;
        }
        for (i=0; i<b.length; i++)
        {
            LinkNode *newnode =  new LinkNode();
            newnode->setA(currentb->getA());
            newnode->setB(currentb->getB());
            if (l==0)
            {
                first = newnode;
                currentc = newnode;
                l++;
            }
            else
            {
                currentc->next = newnode;
                currentc = newnode;
                l++;
            }
            currentb=currentb->next;
        }
        length =l;
        this->Sort();
        this->hebing();

    }
    void multiplication(List a,List b)
    {
        int i,l,j;
        l=0;
        LinkNode *currentc = new LinkNode();
        currentc = this->first;
        LinkNode *currenta = new LinkNode();
        currenta = a.first;
        LinkNode *currentb = new LinkNode();
        currentb = b.first;
        for (i=0; i<a.length; i++)
        {
            currentb = b.first;
            for(j=0; j<b.length; j++)
            {
                LinkNode *newnode = new LinkNode();
                newnode->setA(currenta->getA()*currentb->getA());
                newnode->setB(currenta->getB()+currentb->getB());
                if (l==0)
                {
                    first = newnode;
                    currentc = newnode;
                    l++;
                }
                else
                {
                    currentc->next = newnode;
                    currentc = newnode;
                    l++;
                }
                currentb=currentb->next;
            }
            currenta=currenta->next;
        }
        length=l;
        this->hebing();
        this->Sort();
    }
    void qiudao(List a)
    {
        int i;
        int l=0;
        LinkNode *current = new LinkNode();
        current = first;
        LinkNode *currenta = new LinkNode();
        currenta = a.first;
        for (i=0; i<a.length; i++)
        {
            LinkNode *newnode = new LinkNode();
            if(currenta->getB()==0)
            {
                newnode->setA(0);
                newnode->setB(0);
            }
            else
            {
                newnode->setA(currenta->getA()*currenta->getB());
                newnode->setB(currenta->getB()-1);
            }
            if (l==0)
            {
                first = newnode;
                current = newnode;
                l++;
            }
            else
            {
                current->next = newnode;
                current = newnode;
                l++;
            }
            currenta = currenta->next;
        }
        length = l;
        Sort();
    }
    void jisuan(float a)
    {
        int i;
        double sum = 0;
        LinkNode *current = new LinkNode();
        current = first;
        for (i=0; i<length; i++)
        {
            sum = sum + current->getA()*(pow(a,current->getB()));
            current = current->next;
        }
        printf("%.2f",sum);
        cout<<endl;

    }
};
int main()
{
    List a,b,*c;
    char x;

    cin>>x;
    getchar();
    while(x!='X')
    {
        if(x=='C')
        {
            a.Input();
            b.Input();
        }
        if (x=='P')
        {
          c=new List();
          c->add(a,b);
          cout<<"C(x)=";
          c->Output();
        }
        if(x=='S'){
            c=new List();
            c->reduce(a,b);
            cout<<"C(x)=";
            c->Output();
        }
        if(x=='M'){
            c=new List();
            c->multiplication(a,b);
            cout<<"C(x)=";
            c->Output();
        }
        if(x=='D'){
            c=new List();
            c->qiudao(a);
            cout<<"C(x)=";
            c->Output();
        }
        if(x=='V'){
            double num;
            cin>>num;
            a.jisuan(num);
        }
        cin>>x;
        getchar();
    }



    return 0;
}
