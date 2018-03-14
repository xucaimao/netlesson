/*中国大学MOOC-陈越、何钦铭-数据结构-2018春
 * 编程作业程序
 * 把后面的程序粘贴进来，就可以修改编译
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
//释放链表空间，只保留表头结点
void FreeList(List l){
    List p=l->next,pnext;
    while(p){
        pnext=p->next;
        free(p);
        p=pnext;
    }
    l->next=NULL;
}
//链表形式的多项式加法
List AddList(List la,List lb){
    List head=(List)malloc(sizeof(struct Nod));//生成头结点
    head->next=NULL;
    List tail=head;
    List pa=la->next,pb=lb->next;
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
        if(temp->coef){//非零项才记录
            tail->next=temp;
            tail=temp;
        }
    }
    if(pa)tail->next=pa;
    if(pb)tail->next=pb;
    return head;
}
//链表形式的多项式乘法
List MultiList(List la,List lb){
    List ans=(List)malloc(sizeof(struct Nod));//生成头结点
    ans->next=NULL;
    List pa=la->next;
    while(pa){
        //把la中的每一项分别与lb相乘,结果放在listtemp链表
        List listtemp=(List)malloc(sizeof(struct Nod));
        listtemp->next=NULL;
        List tail=listtemp;
        List pb=lb->next;
        while(pb){
            //每一次相乘所得的listtemp链表的长度其实是一定的，也就是表lb的长度
            //所以才可以使用下面的方法节省空间
            List tempnode=tail->next;
            if(tempnode==NULL){
                //防止每次循环生成新结点，浪费空间
                tempnode=(List)malloc(sizeof(struct Nod));
                tempnode->next=NULL;
            }
            tempnode->coef=pa->coef * pb->coef;//系数相乘
            tempnode->exp=pa->exp + pb->exp;//指数相加
            tail->next=tempnode;
            tail=tempnode;
            pb=pb->next;
        }
        //ans=ans+listtemp
        ans=AddList(ans,listtemp);
        pa=pa->next;
    }
    return ans;
}

int main() {
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    List la=ReadList();
    List lb=ReadList();
    //PrintList(la);
    //PrintList(lb);
    List ld=MultiList(la,lb);
    PrintList(ld);
    List lc=AddList(la,lb);
    PrintList(lc);
    return 0;
}