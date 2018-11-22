/*中国大学MOOC-陈越、何钦铭-数据结构-2018秋
 * 05-树9 Huffman Codes （30 分）
 * wirte by xucaimao,2018-10-14
 * 2018-11-20把程序中的无用部分做了删减
 * 初次尝试泛型，感觉很爽
 * */
#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>
using namespace std;
const int maxN=64;
char C[maxN];
int F[maxN];
vector<string> Code;

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

    int myLog2(int i)const{
        int ret=0;
        int x=i;
        while ( x > 1 ) {
            x /= 2;
            ret ++;
        }
        return ret;
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

    ElementType getMin(){
        assert(Size>0);
        return data[1];
    }

    void print()const{
        int dw=2;//数字显示宽度
        int ds=2;//数字间距
        int treeHeight=myLog2(Size);
        int dp=1;//指向当前打印的元素在数组中的下标
        int width=pow(2,treeHeight)*dw+ (pow(2,treeHeight)-1)*ds;//计算最底层的最大宽度
        for(int h=0;h<=treeHeight && dp<=Size;h++){//按层打印
            int numOfLevel=pow(2,h);    //每层的最大元素数量
            if(h>0){
                int ddp=dp;
                for(int i=0;i<(width-dw)/2;i++)
                    cout<<" ";//打印行前空格
                for(int n=1;n<=numOfLevel && ddp<=Size;){//每层最多有n个节点
                    if(n%2 ==1) cout<<" /"; //打印连接符号
                    else cout<<" \\";
                    ddp++;
                    n++;
                    if(n>1 && n<=numOfLevel){
                        for(int i=0;i<width;i++)
                            cout<<" ";//
                    }
                }
                cout<<endl;   //每层末尾打印回车
            }
            for(int i=0;i<(width-dw)/2;i++)
                cout<<" ";//打印行前空格
            for(int n=1;n<=numOfLevel && dp<=Size;){//每层最多有n个节点
                cout.width(2);
                cout<<data[dp++];
                n++;
                if(n>1 && n<=numOfLevel){
                    for(int i=0;i<width;i++)
                        cout<<" ";//
                }
            }
            width=(width-dw)/2;
            cout<<endl;   //每层末尾打印回车
        }
    }

    int size(){
        return Size;
    }
};

struct huffNode{
    char ch;
    int weight;
    huffNode* left;
    huffNode* right;
    huffNode(){}
    huffNode(char c,int w):ch(c),weight(w){
        left=right=NULL;
    }
};

struct pHuff{
    //堆中存储的是节点的指针，为了对指针所指向的节点进行排序，定义了此结构体
    huffNode* point;
    bool operator<(pHuff pb){
        return point->weight < pb.point->weight;
    }
    friend ostream &operator<<(ostream & os, pHuff & p){
        os<<p.point->ch<<p.point->weight;
        return os;
    }
};

int WPL(huffNode* r,int treeHeight){
    if(r->right==NULL && r->left==NULL){
        //是叶子节点，返回该节点的wpl值
        return r->weight * treeHeight;
    }
    //否则，对于huffman树，不是叶子节点，一定有两个孩子
    return ( WPL(r->left,treeHeight+1) + WPL(r->right,treeHeight+1) );
}

int huffmanCode(MinHeap<pHuff> & h){
    //从最小堆，建立huffman树，树的根就是堆顶元素
    //建完树后的堆中，只有一个元素，指向树的根
    while(h.size()>1){
        pHuff l,r;
        l=h.deleteMin();
        r=h.deleteMin();
        pHuff tt;
        tt.point=new huffNode(); //生成新的非叶子节点
        tt.point->left=l.point;
        tt.point->right=r.point;
        tt.point->weight=l.point->weight + r.point->weight;
        h.insert(tt);
    }
    //下面开始计算WPL
    pHuff root;
    root=h.getMin();
    return WPL(root.point,0);
}

bool judgeCode(vector<string> & code){
    // huffman每个编码的最终点必须在叶子节点上
    // 编码串不能经过其它编码已经确定的叶子节点
    struct nod{
        int isLeaf; //用于标注该节点是叶子节点
        nod* left;
        nod* right;
        nod(){
            isLeaf=0;
            left=right=NULL;
        }
    };

    bool ans=true;
    int num=code.size();
    nod* root=new nod;
    for(int i=0;i<num;i++){
        string s=code[i];
        nod* p=root;
        for(int j=0;j<s.length();j++){
            if(s[j]=='0'){//往左
                if(p->left==NULL){//左子树为空
                    p->left=new nod;
                    p=p->left;
                }
                else{   //左子树非空
                    p=p->left;
                    if(p->isLeaf){  //经过叶子节点
                        ans=false;
                        break;
                    }
                }
            }
            else{   //s[i]==1，往右
                if(p->right==NULL){//右子树为空
                    p->right=new nod;
                    p=p->right;
                }
                else{   //右子树非空
                    p=p->right;
                    if(p->isLeaf){  //经过叶子节点
                        ans=false;
                        break;
                    }
                }
            }
        }
        // 对叶子节点进行标注
        if(p->left==NULL && p->right==NULL)
            p->isLeaf=1;
        // 不是叶子节点则说明本序列是某个编码的前缀码
        if(p->left || p->right){
            ans=false;
            break;
        }
    }
    return ans;
}


int main(){
    freopen("in.txt","r",stdin);
    int N;
    scanf("%d",&N);
    MinHeap<pHuff> ha(N);
    pHuff t;
    for(int i=0;i<N;i++){//输入字符及相应权重数据
        cin>>C[i]>>F[i];
        t.point=new huffNode(C[i],F[i]); //生成新节点
        ha.insert(t);
    }

//    printf("After insert init , the tree is: \n");
//    ha.print();

    //根据最小堆，建立huffman树，并计算WPL
    int wplHa=huffmanCode(ha);

//    printf("After huffmanCode , the tree is: \n");
//    ha.print();
//    printf("The WPL is: %d\n",wplHa);

    int Case;
    cin>>Case;
    while(Case--){
        Code.clear();   //少了这一句会导致case1正确，后面的都错误
        string s;
        char ch;
        int wplCase=0;
        bool ans=true;
        for(int i=0;i<N;i++){
            cin>>ch;    //读字符
            cin>>s;     //读字符的编码
            wplCase+= F[i]*s.length();
            Code.push_back(s);
        }
        if( wplHa==wplCase && judgeCode(Code) )
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

    return 0;
}