#include <iostream>

using namespace std;
class SparseMatrix;
class Triple
{
    friend class SparseMatrix;
private:
    int row,col;
    int value;
public:
    Triple() {}
    int getvalue()
    {
        return value;
    }
    int getrow()
    {
        return row;
    }
    int getcol()
    {
        return col;
    }
    Triple(int r,int c,int v)
    {
        row=r;
        col=c;
        value=v;
    }
    void Set(int r,int c,int v)
    {
        row=r;
        col=c;
        value=v;
    }
};
class SparseMatrix
{
private:
    int rows,cols,terms;
    Triple smArray[100];
public:
    void addterms()
    {
        terms=terms+1;
    }
    void rterms()
    {
        terms=terms-1;
    }
    void setValue(int r,int c,int t)
    {
        rows=r;
        cols=c;
        terms=t;
    }
    int getrows()
    {
        return rows;
    }
    int getcols()
    {
        return cols;
    }
    Triple gettriple(int i)
    {
        return smArray[i];
    }
    void settriple(int i,Triple t)
    {
        smArray[i]=t;
    }
    int getterms()
    {
        return terms;
    }
    SparseMatrix() {}
    SparseMatrix(int r,int c,int t)
    {
        rows=r;
        cols=c;
        terms=t;
    }
    void input()
    {
        int r,c,v;
        cin>>rows;
        cin>>cols;
        cin>>terms;
        int i;
        for (i=0; i<terms; i++)
        {
            cin>>r;
            cin>>c;
            cin>>v;
            smArray[i].Set(r,c,v);

        }
    }
    void output()
    {
        int i=0;
        for(i=0; i<terms; i++)
        {
            cout<<smArray[i].getrow()<<' '<<smArray[i].getcol()<<' '<<smArray[i].getvalue();
            cout<<endl;
        }
    }
    void transpose()
    {
        int i,j;
        int *rowSize = new int[cols];
        int *rowStart = new int[cols];
        SparseMatrix b;
        b.setValue(cols,rows,terms);
        for (i=0; i<cols; i++)
        {
            rowSize[i]=0;
        }
        rowStart[0]=0;
        for (i=0; i<terms; i++)
        {
            rowSize[smArray[i].col]++;
        }
        for (i=1; i<cols; i++)
        {
            rowStart[i]=rowStart[i-1]+rowSize[i-1];
        }
        for (i=0; i<terms; i++)
        {
            j=rowStart[smArray[i].col];
            b.smArray[j].col=smArray[i].row;
            b.smArray[j].row=smArray[i].col;
            b.smArray[j].value=smArray[i].value;
            rowStart[smArray[i].col]++;
        }
        cout<<"The transformed matrix  is:"<<endl;
        b.output();
    }
    void add(SparseMatrix &b)
    {
        SparseMatrix result;
        result.setValue(rows,cols,0);
        int i=0,j=0;
        Triple x,y;
        int indexa,indexb;
        while(i<terms&&j<b.getterms())
        {
            x=b.gettriple(j);
            indexa=cols*smArray[i].row+smArray[i].col;
            indexb=b.getcols()*x.getrow()+x.getcol();
            if(indexa>indexb)
            {
                result.settriple(result.getterms(),x);
                j++;
            }
            else if(indexa<indexb)
            {
                result.settriple(result.getterms(),smArray[i]);
                i++;
            }
            else
            {
                y.Set(smArray[i].getrow(),smArray[i].getcol(),smArray[i].getvalue()+x.getvalue());
                i++;
                j++;
                if (y.getvalue()==0)
                {
                    continue;
                }
                result.settriple(result.getterms(),y);
            }
            result.addterms();

        }
        for(; i<terms; i++)
        {
            result.settriple(result.getterms(),smArray[i]);
            result.addterms();
        }
        for(; j<terms; j++)
        {
            result.settriple(result.getterms(),b.gettriple(j));
            result.addterms();
        }
        result.rterms();
        cout<<"The added matrix is:"<<endl;

        result.output();
    }

};

int main()
{
    SparseMatrix a,b;
    a.input();
    b.input();
    a.transpose();
    a.add(b);
    return 0;
}
