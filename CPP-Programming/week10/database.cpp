// #include <iostream>
// #include <string>
// #include <map>
// #include <iterator>
// #include <algorithm>
// using namespace std;

template <class T1, class T2, class G = greater<T1> >
class MyMultimap : public multimap<T1, T2, G> {
public:
        typedef typename multimap<T1, T2, G>::iterator iterator;
        void Set(const T1 &x, const T2 &y) {
                pair<iterator, iterator> ret = this -> equal_range(x);
                for (iterator i = ret.first; i != ret.second; ++i) {
                        i -> second = y;
                }
        }
};

template <class Key,class Value>
ostream & operator <<( ostream & o, const pair<Key,Value> & p)
{
        o << "(" << p.first << "," << p.second << ")";
        return o;
}

// struct Student
// {
//         string name;
//         int score;
// };
// template <class T>
// void Print(T first,T last) {
//         for(;first!= last; ++ first)
//                 cout << * first << ",";
//         cout << endl;
// }
// int main()
// {

//         Student s[] = { {"Tom",80},{"Jack",70},
//                                         {"Jone",90},{"Tom",70},{"Alice",100} };
//         MyMultimap<string,int> mp;
//         for(int i = 0; i<5; ++ i)
//                 mp.insert(make_pair(s[i].name,s[i].score));
//         Print(mp.begin(),mp.end()); 

//         mp.Set("Tom",78); 
//         Print(mp.begin(),mp.end());


//         MyMultimap<int,string,less<int> > mp2;
//         for(int i = 0; i<5; ++ i)
//                 mp2.insert(make_pair(s[i].score,s[i].name));

//         Print(mp2.begin(),mp2.end()); 
//         mp2.Set(70,"Error");          
//         Print(mp2.begin(),mp2.end());
//         cout << "******" << endl;

//         mp.clear();
        
//         string name;
//         string cmd;
//         int score;
//         while(cin >> cmd ) {
//                 if( cmd == "A") {
//                         cin >> name >> score;
//                         if(mp.find(name) != mp.end() ) {
//                                 cout << "erroe" << endl;
//                         }
//                         mp.insert(make_pair(name,score));
//                 }
//                 else if(cmd == "Q") {
//                         cin >> name;
//                         MyMultimap<string,int>::iterator p = mp.find(name);
//                         if( p!= mp.end()) {
//                                 cout << p->second << endl;
//                         }
//                         else {
//                                 cout << "Not Found" << endl;
//                         }
//                 }
//         }
//         return 0;
// }