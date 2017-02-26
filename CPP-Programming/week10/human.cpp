// #include <iostream>
// #include <set>
// #include <iterator>
// #include <algorithm>
// using namespace std;

class A{
private:
        int age_;
        char type_;
public:
        A(int age):age_(age){ type_ = 'A';}
        A(int age, char type):age_(age), type_(type){}
        int age(){
                return age_;
        }
        char type(){
                return type_;
        }
};

class B:public A{
public:
        B(int age):A(age,'B'){}
};

class Comp{
public:
        bool operator()(A* a1, A* a2){
                return a1->age() < a2->age();
        }
};

void Print(A* a)
{
    cout << a->type() << " " << a->age() << endl;
}


// int main()
// {

//         int t;
//         cin >> t;
//         set<A*,Comp> ct;
//         while( t -- ) {
//                 int n;
//                 cin >> n;
//                 ct.clear();
//                 for( int i = 0;i < n; ++i)	{
//                         char c; int k;
//                         cin >> c >> k;

//                         if( c == 'A')
//                                 ct.insert(new A(k));
//                         else
//                                 ct.insert(new B(k));
//                 }
//                 for_each(ct.begin(),ct.end(),Print);
//                 cout << "****" << endl;
//         }
// }