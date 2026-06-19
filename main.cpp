#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student
{
    string id;
    string name;
    int score;
};

template <class T>
    T getMax(T a, T b)
    {
        return(a>b) ? a : b;
    }

template <class T>
    T getMin(T a, T b)
    {
        return(a<b) ? a : b;
    }

int main()
{
    vector<Student> students;
    int choice;

    while(true)
    {
        cout<<"1. Add student"<<endl;
        cout<<"2. List all students"<<endl;
        cout<<"3. Sort by score"<<endl;
        cout<<"4. Search by id"<<endl;
        cout<<"5. Show statistics"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"請選擇功能 > ";
        cin>>choice;

        if(choice==0)
        {
            cout<<"離開學生成績管理系統!";
            break;
        }

        
    }
}
