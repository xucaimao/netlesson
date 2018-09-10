/*中国大学MOOC-陈越、何钦铭-数据结构-2018秋
// 02-线性结构2 一元多项式的乘法与加法运算（20 分）
// write by xucaimao,2018-09-10，提交部分通过，提示段错误
 * */

#include <stdio.h>
#include <stdlib.h>

typedef struct Nod * List;
struct Nod{
    int coef,exp;//系数和指数
    List next;
};

List ReadList(){
    int n,coef,exp;
    List head=(List)malloc(sizeof(struct Nod));//生成头结点
    head->next=NULL;
    List tail=head;//定义尾指针便于数据插入
    scanf("%d",&n);
    while(n--){
        List temp=(List)malloc(sizeof(struct Nod));
        scanf("%d%d",&coef,&exp);
        temp->next=NULL;
        temp->coef=coef;
        temp->exp=exp;
        tail->next=temp;//插入
        tail=tail->next;
    }
    return head;
}

void PrintList(List l){
    List p=l->next;
    if(p==NULL){
        printf("0 0\n");
        return;
    }
    int n=0;
    while(p){
        if(n>0)printf(" ");
        printf("%d %d",p->coef,p->exp);
        n++;
        p=p->next;
    }
    printf("\n");
}
//释放链表空间
void FreeList(List l){
    List p=l,pnext;
    while(p){
        pnext=p->next;
        free(p);
        p=pnext;
    }
    l=NULL;
}
//链表形式的多项式加法
//不破坏la和lb的原始结构，重新生成节点
List AddList(List la,List lb){
    List ans=(List)malloc(sizeof(struct Nod));//生成头结点
    ans->next=NULL;
    List tail=ans;//tail指向尾节点
    List pa=la->next,pb=lb->next;//分别指向两个链表的第一个数据节点
    while(pa && pb){
        List temp=(List)malloc(sizeof(struct Nod));
        temp->next=NULL;
        if(pa->exp < pb->exp){
            temp->exp=pb->exp;
            temp->coef=pb->coef;
            pb=pb->next;
        }
        else if(pa->exp > pb->exp){
            temp->exp=pa->exp;
            temp->coef=pa->coef;
            pa=pa->next;
        }
        else{//二者指数相等
            temp->exp=pa->exp;
            temp->coef=pa->coef + pb->coef;
            pa=pa->next;
            pb=pb->next;
        }
//        printf("%d X ^ %d \n",temp->coef,temp->exp);
        if(temp->coef){//非零项才记录
            tail->next=temp;
            tail=temp;
        }
        else{//零项，节点应删除，否则当前temp节点就没有被使用，产生内存垃圾
            free(temp);
        }
    }

    //采用重新复制结点的方式，将没有参加计算的la或lb链表的剩余节点插入答案链表尾部
    List last;
    if(pa) last=pa;
    if(pb) last=pb;
    while(last){
        //生成新节点，并复制剩余节点的信息
        List temp=(List)malloc(sizeof(struct Nod));
        temp->next=NULL;
        temp->coef=last->coef;
        temp->exp=last->exp;
        //插入新链表尾部
        tail->next=temp;
        tail=temp;
        last=last->next;
    }
    return ans;
}
//链表形式的多项式乘法
List MultiList(List la,List lb){
    List ans=(List)malloc(sizeof(struct Nod));//生成头结点
    ans->next=NULL;
    List pa=la->next;//指向pa的第一个数据节点
    while(pa){
        //把la中的每一项分别与lb相乘,中间结果放在ansOne链表
        List ansOne=(List)malloc(sizeof(struct Nod));
        ansOne->next=NULL;
        List tailOne=ansOne;
        List pb=lb->next;   //指向pb的第一个数据节点
        //把pa所指向的节点，与pb中的每一项相乘
        while(pb){
            //生成新节点，并把相除的结果存入数据域
            List tempnode=(List)malloc(sizeof(struct Nod));
            tempnode->next=NULL;
            tempnode->coef=pa->coef * pb->coef;//系数相乘
            tempnode->exp=pa->exp + pb->exp;//指数相加
            //新节点插入链表尾部
            tailOne->next=tempnode;
            //移动尾指针
            tailOne=tempnode;
            pb=pb->next;
        }
//        PrintList(ansOne);
        //ans=ans+listtemp
        List tans=ans;
        ans=AddList(tans,ansOne);
        FreeList(tans);
        FreeList(ansOne);//释放中间结果ansOne链表的空间
//        PrintList(ans);
        pa=pa->next;
    }
    return ans;
}

int main() {
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    List la=ReadList();
    List lb=ReadList();
//    PrintList(la);
//    PrintList(lb);
    List lMulti=MultiList(la,lb);
    PrintList(lMulti);

    List lAdd=AddList(la,lb);
    PrintList(lAdd);
//    FreeList(lAdd);

//    FreeList(lMulti);
//    FreeList(la);
//    FreeList(lb);

    return 0;
}