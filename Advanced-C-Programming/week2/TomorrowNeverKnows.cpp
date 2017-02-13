#include "iostream"
#include <iomanip>
using namespace std;
int isendofyear(int year, int month, int day){
    if(month == 12 && day ==31)
        return 1;
    else
        return 0;

}

int isendofmonth(int year, int month, int day){
    int leap = 0;
    if((year%4==0&&year%100!=0)||year%400==0)
        leap = 1;
    switch (month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: return day == 31;
        case 4:
        case 6:
        case 9:
        case 11: return day == 30;
        case 2: return ((day==28) && (leap == 0)) || ((day == 29) && (leap ==1));

    }
}
int main(int argc, char const *argv[])
{
    int year, month, day;
    char temp;
    cin >> year >> temp >> month >> temp >> day;
    cout<<setfill('0');
    if (isendofyear(year, month, day))
        cout << year+1 << "-" << "01" << "-" << "01";
    else if (isendofmonth(year, month, day))
        cout << year << "-" << setw(2) << month + 1 << "-" << "01";
    else
        cout << year << "-" << setw(2) << month<< "-" << setw(2) << day + 1;
    return 0;
}