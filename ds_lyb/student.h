//
// Created by xcm on 2020/5/7.
//

#ifndef DS_LYB_STUDENT_H
#define DS_LYB_STUDENT_H

#include <iostream>
#include <string>
using namespace std;

struct Student{
    string name;
    int score;

    bool operator <(const Student &otherStudent){
        if(score==otherStudent.score)
            return name < otherStudent.name;
        else return score < otherStudent.score;
    }

    friend ostream& operator<<(ostream &os, const Student &s){
        os<<"Student: "<<s.name<<" "<<s.score<<endl;
        return os;
    }
};

#endif //DS_LYB_STUDENT_H
