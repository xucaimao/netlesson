/*中国大学MOOC-陈越、何钦铭-数据结构-2017秋
 * 08-图7 公路村村通
 * wirte by xucaimao,2018-10-21
 * 考察知识点--最小生成树
 * 编程比较复杂，综合运用了 类、模板、迭代器、运算符重载、最小堆等知识点
 * */

#include <cstdio>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

//定义边的类型
class Edge{
private:
    int v,w;    //如果对于有向边，默认边为v->w
    int weight;
public:
    Edge(int v_,int w_,int weight_):v(v_),w(w_),weight(weight_){}
    Edge(){}
    friend ostream&operator<<(ostream& os,Edge &e){
        os<<"("<<e.v<<"-"<<e.w<<":"<<e.weight<<")";
        return os;
    }
    bool operator<(Edge &b){
        return weight<b.weight;
    }
    int startV(){   //返回起点
        return v;
    }
    int endV(){   //返回终点
        return w;
    }
    int otherVertex(int i){   //返回另外一点
        if(i==v || i==w)
            return i==v ? w : v;
        else
            return -1;
    }
    int wt(){
        return weight;
    }

};

//定义一个邻接表(adjacency list)形式的无向图
class adjGraph{
private: //为了简化后面的编程
    int V,E;        //图中的顶点数与边数
    int minVexNum;  //图中最小顶点的编号，针对顶点编号从0或1开始的情况
    vector< vector< Edge > > GVec; //邻接表
public:
    adjGraph(int vertexNum){
        V=vertexNum;
        E=0;
        minVexNum=9999;
        for(int i=0;i<=V;i++)  // <= 综合考虑了顶点编号从0或1开始的情况
            GVec.push_back( vector<Edge>() );//插入空的vector
    }
    void addEdge(int v_,int w_,int weight_){
        if(v_<minVexNum) minVexNum=v_;
        if(w_<minVexNum) minVexNum=w_;
        GVec[v_].push_back(Edge(v_,w_,weight_));
        GVec[w_].push_back(Edge(w_,v_,weight_));
        E++;
    }

    bool hasEdge(int v_,int w_){
        for(int i=0;i<GVec[v_].size();i++)
            if(GVec[v_][i].otherVertex(v_)==w_)
                return true;
        return false;
    }
    void print(){
        for(int i=minVexNum;i< minVexNum+V;i++){
            cout<<"Vertex "<<i<<":\t";
            for(int j=0;j<GVec[i].size();j++)
                cout<<GVec[i][j]<<"\t";
            cout<<endl;
        }
    }
    int vertexNum(){ //顶点的数量
        return V;
    }
    int edgeNum(){ //边的数量
        return E;
    }
    int minV(){
        return minVexNum;
    }
    //迭代器
    class adjIterator{
    private:
        adjGraph &G;
        int v;
        int index;
    public:
        adjIterator(adjGraph & g,int v_):G{g}{
            v=v_;
            index=0;
        }
        Edge* begin(){
            index=0;
            if(G.GVec[v].size())
                return &G.GVec[v][index];
            else return NULL;
        }
        Edge* next(){
            index++;
            if(index < G.GVec[v].size())
                return &G.GVec[v][index];
            else return NULL;
        }

        bool end(){
            return index>=G.GVec[v].size();
        }
    };
};

//自己以前实现的最小堆，做了简化
template <typename ElementType>
class MinHeap{
    //实现最小堆，为了泛型的考虑，内部大小比较只使用<符号，使用cout进行输出
private:
    ElementType *data;
    int Capacity;
    int Size;

    void percolateDown(int hole){
        int child;
        ElementType tmp=data[hole];
        while(hole*2 <= Size){//左孩子存在
            child=hole*2;
            if(child+1<=Size && data[child+1]<data[child])//右孩子存在且比左孩子小
                child+=1;
            //此时child指向左右孩子中较小的
            if(data[child]<tmp){
                data[hole]=data[child];//小的元素上移
                hole=child;
            }
            else break;
        }
        data[hole]=tmp;
    }

public:
    MinHeap(int capacity_){
        Capacity=capacity_;
        Size=0;
        data=new ElementType[Capacity+1];//0号元素不使用
    }

    ~MinHeap(){
        delete[] data;
    }

    void insert(ElementType x){
        assert(Size<Capacity);
        data[0]=x;  //设置哨兵位,下面的循环就不用对data[1]做单独处理
        int hole=++Size;
        for(;x<data[hole/2];hole/=2)
            data[hole]=data[hole/2];    //大的往下移动
        data[hole]=x;
    }

    ElementType deleteMin(){
        assert(Size>0);
        ElementType ret=data[1];
        data[1]=data[Size--];
        percolateDown(1);
        return ret;
    }

    int size(){
        return Size;
    }
};

class PrimeMST{
private:
    adjGraph &G;
    MinHeap<Edge> pq;
    bool * marked;
    vector<Edge> mst;
    int visitedNum;     //访问过的节点数量，通过这个判断图是否联通
    int mstWeight;
    bool isConnected;   //判断图是否联通

    void visit(int v){
        assert( !marked[v]);
        visitedNum++;   //访问的节点数++
        marked[v]=true;
        //遍历以节点v为出发点的所有边（也就是遍历v的所有邻接点）
        //建立迭代器
        typename adjGraph::adjIterator iter(G,v);
        //遍历
        for(Edge* e=iter.begin();!iter.end();e=iter.next()){
            //边e的另一个点没有被访问
            if(!marked[e->otherVertex(v)])
                pq.insert(*e);
        }
    }

public:
    //以边数为参数创建一个最小堆（必须放在初始化列表中）
    PrimeMST(adjGraph &g):G(g),pq( MinHeap<Edge>( g.edgeNum() ) ){
        marked=new bool[g.vertexNum()+1];   // +1 综合考虑了顶点编号从0或1开始的情况
        for(int i=0;i<=g.vertexNum();i++)
            marked[i]= false;
        visitedNum=0;
        mst.clear();

        //Prime
        visit(G.minV());
        while(pq.size()>0){
            //取出最小权重的边
            Edge e=pq.deleteMin();
            //判断两个顶点是否在同一切分内，如果是则丢弃该边（不记录）
            if(marked[e.startV()] == marked[e.endV()])
                continue;
            mst.push_back(e);   //找到最小连通图上的一条边，记录
            if(marked[e.startV()])  //接着访问该边上的另一点
                visit(e.endV());
            else
                visit(e.startV());
        }

        if(visitedNum==G.vertexNum()){   //访问过的节点数等于图的节点数
            isConnected=true;
            mstWeight=mst[0].wt();
            for(int i=1;i<mst.size();i++)
                mstWeight+=mst[i].wt();
        }
        else{   //图不是联通的
            mstWeight=-1;
            isConnected=false;
        }
    }

    ~PrimeMST(){
        delete [] marked;
    }

    vector<Edge> mstEdges(){
        return mst;
    }

    int mstWeightResult(){
        return mstWeight;
    }
};


int main(){
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    int N,M;
    int u,v,w;
    cin>>N>>M;
    adjGraph G(N);
    while(M--){
        cin>>u>>v>>w;
        G.addEdge(u,v,w);
    }
    PrimeMST mst(G);
    cout<<mst.mstWeightResult()<<endl;

    vector<Edge> e=mst.mstEdges();
    for(int i=0;i<e.size();i++)
        cout<<e[i]<<"\t";
    cout<<endl;

    return 0;
}