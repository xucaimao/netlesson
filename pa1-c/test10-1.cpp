/*
程序设计实习MOOC / 程序设计与算法（一）第十周测验(2017冬季)  
1:成绩排序
write by xucaimao,2018-01-10 12:40,AC 2018-01-10 12:53:51
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct Student{
	string name;
	int score;
	bool operator <(const Student &b)const{
		if(score==b.score)
			return name<b.name;
		else
			return score > b.score;
	}
};
Student stu[25];

int main(){
	freopen("in.txt","r",stdin);
	int n;
	cin>>n;
	string name;
	int score;
	for(int i=0;i<n;i++){

		cin>>name>>score;
		stu[i].name=name;
		stu[i].score=score;
	}
	sort(stu,stu+n);
	for(int i=0;i<n;i++){
		cout<<stu[i].name<<" "<<stu[i].score<<endl;
	}
	return 0;	
}