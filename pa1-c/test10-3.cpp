/*
程序设计实习MOOC / 程序设计与算法（一）第十周测验(2017冬季)  
3:病人排队
write by xucaimao,2018-01-10 13:20,AC 2018-01-10 13:45:39
注意id不是排队的序号
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct Patient{
	string id;
	int age;
	int ord;//增加排队序号
	bool operator <(const Patient &b)const{
		if(age>=60 && b.age>=60){//都是老年人
			if(age==b.age)
				return ord<b.ord;//年龄相同按序号
			else
				return age>b.age;//年龄不同按年龄
		}
		else if(age<60 && b.age<60)
			return ord<b.ord;//非老年人按序号
		else if(age>=60)return true;
		else if(b.age>=60)return false;
	}
};

Patient p[110];

int main(){
	freopen("in.txt","r",stdin);
	int n;
	cin>>n;
	string id;
	int age;
	for(int i=0;i<n;i++){
		cin>>id>>age;
		p[i].id=id;
		p[i].age=age;
		p[i].ord=i;//排队的序号
	}
	sort(p,p+n);
	for(int i=0;i<n;i++){
		cout<<p[i].id<<endl;
	}
	return 0;	
}