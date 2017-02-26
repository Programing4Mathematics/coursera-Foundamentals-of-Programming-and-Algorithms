// #include <iostream>
// using namespace std;

class CType{
private:
	int number_;
public:
	CType(){number_ = 0;}
	void setvalue(int number){
		number_ = number;
	}
	int operator++(int){
		return number_;
	}
	friend ostream & operator<< ( ostream & o, const CType &obj) { o << obj.number_ * obj.number_; return o; }
};

// int main(int argc, char* argv[]) {
//         CType obj;
//         int n;
//         cin>>n;
//         while ( n ) {
//                 obj.setvalue(n);
//                 cout<<obj++<<" "<<obj<<endl;
//                 cin>>n;
//         }
//         return 0;
// }