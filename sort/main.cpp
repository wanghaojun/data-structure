#include "assert.h"
#include <iostream>
using namespace std;
void change(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void Sort(int a[],int n)
{
    int i,j,k;
    i=0;
    j=0;
    k=n-1;
    while(j<=k)
    {
        if(a[j]==1)
        {
            change(&a[i],&a[j]);
            if (i!=j)
            {
                cout<<i<<"<--->"<<j<<endl;
            }
            j++;
            i++;
        }
        else if (a[j]==2)
        {
            j++;
        }
        else if(a[j]==3)
        {
            change(&a[j],&a[k]);
            if(j!=k){
                cout<<j<<"<--->"<<k<<endl;
            }

            k=k-1;
        }
    }
    for (i=0;i<n;i++){
        cout<<a[i];
    }
    cout<<endl;
}

int main()
{
    int n;
    cin >> n;
    int * a= new int[n];
    for (int i=0; i<n; i++)
        cin>>a[i];
    Sort(a,n);
}
