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

    cout<<"歡迎使用學生成績管理系統!"<<endl<<endl;

    while(true)
    {
        cout<<"1. Add student"<<endl;
        cout<<"2. List all students"<<endl;
        cout<<"3. Sort by score"<<endl;
        cout<<"4. Search by id"<<endl;
        cout<<"5. Show statistics"<<endl;
        cout<<"0. Exit"<<endl<<endl;
        cout<<"請選擇功能 > ";
        cin>>choice;

        if(choice==0)
        {
            cout<<"離開學生成績管理系統!";
            break;
        }

        if(choice==1)
        {
            string addID;
            cout<<"輸入學號 > ";
            cin>>addID;

            bool duplicate=false;

            for(const auto& s : students)
            {
                if(s.id==addID)
                {
                    duplicate=true;
                    break;
                }
            }
            if(duplicate)
            {
                cout<<"該學生資料已存在!返回主選單!"<<endl<<endl;
            }
            else
            {
                Student s;
                s.id=addID;
                cout<<"輸入學生姓名 > ";
                cin>>s.name;
                cout<<"輸入學生成績 > ";
                cin>>s.score;
                students.push_back(s);
                cout<<endl<<"學生資料新增成功!!!"<<endl<<endl;
            }
        }

        else if(choice==2)
        {
            if(students.empty())
            {
                cout<<"目前無學生資料!!!"<<endl<<endl;
            }
            else
            {
                cout<<"學生資料:"<<endl;
                for(const auto& s : students)
                {
                    cout<<"學號: "<<s.id<<" | 姓名:"<<s.name<<" | 成績: "<<s.score<<endl;
                }
                cout<<endl;
            }
        }

        else if(choice==3)
        {
            if(students.empty())
            {
                cout<<"目前無學生資料!!!"<<endl;
            }
            else
            {
                int type;
                cout<<"請選擇排序方式!(1 成績由高到低 or 2 成績由低到高) > ";
                cin>>type;

                if(type==1)
                {
                    sort(students.begin(), students.end(), [](const Student& a, const Student& b)
                    {
                        return (a.score>b.score);
                    });
                    cout<<"排序完成!可使用功能2查看全部學生成績!"<<endl<<endl;
                }
                else if(type==2)
                {
                    sort(students.begin(), students.end(), [](const Student& a, const Student& b)
                    {
                        return (a.score<b.score);
                    });
                    cout<<"排序完成!可使用功能2查看全部學生成績!"<<endl<<endl;
                }
                else
                {
                    cout<<"輸入排序方式錯誤!返回返回主選單!";
                }
            }
        }

        else if(choice==4)
        {
            if(students.empty())
            {
                cout<<"目前無學生資料!!!"<<endl;

            }
            string searchID;
            cout<<"輸入查詢學號 > ";
            cin>>searchID;

            bool found=false;

            for(const auto& s : students)
            {
                if(s.id==searchID)
                {
                    cout<<"找到學生!"<<endl;
                    cout<<"姓名: "<<s.name<<"成績: "<<s.score<<endl;
                    found=true;
                    break;
                }
            }
            if(!found)
            {
                cout<<"查無此學生資料!!!"<<endl;
            }
        }


    }
}
