#include <iostream>

using namespace std;
class Edge
{
    friend class Vertex;
    friend class Map;
private:
    int dest;
    int cost;
    bool real;
    Edge *link;
public:
    Edge(int d,int c,bool r)
    {
        dest=d;
        cost=c;
        real=r;
        link=NULL;
    }
    Edge(){}

};
class Vertex
{
    friend class Map;
private:
    char data;
    int neighbor;
    Edge *adj;
public:
    Vertex() {}
    Vertex(char x){data=x;}
};
class Map
{
private:
    Vertex *vertex;
    int edgeNumber,vertexNumber;
public:
    Map() {}
    void setEdge(int edgeNumber)
    {
        this->edgeNumber=edgeNumber;
    }
    void setVertex(int vertexNumber)
    {
        this->vertexNumber=vertexNumber;
    }
    void createMap(){
        int a,i,e,c;
        char x;
        cin>>a;
        setVertex(a);
        vertex=new Vertex[vertexNumber];
        for(i=0;i<vertexNumber;i++){
                cin>>x;
            vertex[i].data=x;
            vertex[i].neighbor=0;
        }
        cin>>a;
        setEdge(a);
        for (i=0;i<edgeNumber;i++){
            cin>>a>>e>>c;
            insertEdge(a,e,c,true);
            insertEdge(e,a,c,false);
        }

    }
    void insertEdge(int a,int b,int x,bool r){

        Edge *edge = new Edge(b,x,r);
        Edge *current=new Edge();

         if(vertex[a].neighbor==0){
            vertex[a].adj=edge;
            vertex[a].neighbor++;
         }
         else{
                current=vertex[a].adj;
            while(current->link!=NULL){
                current=current->link;
            }
            current->link=edge;
         }
    }
    void Output(){
        cout<<"edges are:"<<endl;
    int i;
    Edge *current=NULL;
    for(i=0;i<vertexNumber;i++){
            current=vertex[i].adj;
        while(current!=NULL){
            if(current->real==true){
                cout<<vertex[i].data<<'-'<<vertex[current->dest].data<<":"<<current->cost<<endl;
            }
            current=current->link;
        }
    }
    }
    int getFirstNeighbor(int v){
      Edge *p=vertex[v].adj;
      if(p!=NULL)
      {
          return p->dest;
      }
      else
        return -1;
    }
    int getNextNeighbor(int v,int w){
        Edge *p=vertex[v].adj;
        if(v!=-1){
            while(p!=NULL&&p->dest!=w)
                p=p->link;
            if(p->link!=NULL && p!=NULL)
                return p->link->dest;
        }
        return -1;
    }
    void DFS(){
    int i,n;
    n=vertexNumber;
    bool *visit=new bool[n];
    for (i=0;i<n;i++){
        visit[i]=false;
    }
    DFS(0,visit);
    }
    void DFS(int v,bool visit[]){
    cout<<vertex[v].data<<" ";
    visit[v]=true;
    int w=getFirstNeighbor(v);
    while(w!=-1){
        if(visit[w]==false)
        {
            DFS(w,visit);
        }
        w=getNextNeighbor(v,w);
    }
    }
    void BFS(){
    int i,n;
    n=vertexNumber;
    Edge *p=new Edge();
    bool *visit=new bool[n];
    for (i=0;i<n;i++){
        visit[i]=false;
    }
    for (i=0;i<n;i++){
        if(visit[i]==false){
            cout<<vertex[i].data<<" ";
            visit[i]=true;
        }
        p=vertex[i].adj;
        while(p!=NULL){
            if(visit[p->dest]==false){
                cout<<vertex[p->dest].data<<" ";
                visit[p->dest]=true;
            }
            p=p->link;
        }
    }
    }
};

int main()
{
    Map m;
    m.createMap();
    cout<<"DFS:";
    m.DFS();
    cout<<endl;
    cout<<"BFS:";
    m.BFS();
    cout<<endl;
    m.Output();
}
