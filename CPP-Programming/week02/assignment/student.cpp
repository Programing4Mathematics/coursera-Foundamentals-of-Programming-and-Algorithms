#include<iostream>
#include <cstdlib>
using namespace std;

class student
{
private:
    char * name;
    int age;
    char * id;
    int score;
    
public:
    void Init(char * str);
    void setscore(int * score_, int count);
    int getscore(void);
    char * getname(void);
    int getage(void);
    char * getid(void);
};

int main(void)
{
    char * str = new char[255];
    
    cin >> str;
    
    student Tom;
    
    Tom.Init(str);
    
    cout << Tom.getname() << "," << Tom.getage() << "," << Tom.getid() << "," << Tom.getscore() << endl;
    
    return 0;
}

void student::Init(char * str)
{
    int i = 0;                                              // 计数器
    int si = 0;                                             // score计数器
    int * score_ = new int[4];                              // 用来保存每学年成绩
    
    int j = i;                                              // 获取学生姓名
    while ( str[i] != ',' )
        i++;
    char *newname = new char[i - j];
    for ( int ic = 0; ic < i; ic++ )
        newname[ic] = str[ic];
    newname[i] = '\0';
    name = newname;
    //delete[] newname;
    
    j = i;                                              // 获取学生年龄
    i++;
    while ( str[i] != ',' )
        i++;
    char *newage = new char[i - j];
    for ( int ic = 0; ic < (i - j - 1); ic++ )
        newage[ic] = str[ic + j + 1];
    newage[i - j - 1] = '\0';
    age = atoi(newage);
    delete[] newage;
    
    j = i;                                              // 获取学生学号
    i++;
    while ( str[i] != ',' )
        i++;
    char *newid = new char[i - j];
    for ( int ic = 0; ic < (i - j - 1); ic++ )
        newid[ic] = str[ic + j + 1];
    newid[i - j - 1] = '\0';
    id = newid;
    
    j = i;
    i++;
    while ( str[i] != ',' )
        i++;
    char *newscore = new char[i - j];
    for ( int ic = 0; ic < (i - j - 1); ic++ )
        newscore[ic] = str[ic + j + 1];
    newscore[i - j - 1] = '\0';
    score_[si++] = atoi(newscore);
    delete[] newscore;
    
    j = i;
    i++;
    while ( str[i] != ',' )
        i++;
    newscore = new char[i - j];
    for ( int ic = 0; ic < (i - j - 1); ic++ )
        newscore[ic] = str[ic + j + 1];
    newscore[i - j - 1] = '\0';
    score_[si++] = atoi(newscore);
    delete[] newscore;
    
    j = i;
    i++;
    while ( str[i] != ',' )
        i++;
    newscore = new char[i - j];
    for ( int ic = 0; ic < (i - j - 1); ic++ )
        newscore[ic] = str[ic + j + 1];
    newscore[i - j - 1] = '\0';
    score_[si++] = atoi(newscore);
    delete[] newscore;
    
    j = i;
    i++;
    while ( str[i] != '\0' )
        i++;
    newscore = new char[i - j];
    for ( int ic = 0; ic < (i - j - 1); ic++ )
        newscore[ic] = str[ic + j + 1];
    newscore[i - j - 1] = '\0';
    score_[si++] = atoi(newscore);
    delete[] newscore;
    
    setscore(score_, 4);
}

void student::setscore(int *score_, int count_)
{
    int sum = 0;
    for ( int count = 0; count < count_; count++ )
        sum += score_[count];
    
    score = sum / count_;
}

int student::getscore(void)
{
    return score;
}

char * student::getname(void)
{
    return name;
}

int student::getage(void)
{
    return age;
}

char * student::getid(void)
{
    return id;
}