// #include <iostream>
// using namespace std;
template <class T>
class CArray3D{
public:
    template<class T1>
    class CArray2D{
        public:
            template<class T2>
            class CArray1D{
            public:
                CArray1D(int p){  
                    a = new T[p];
                }
                CArray1D(){ 
                    a = NULL;
                }
                ~CArray1D(){
                    if (a) delete []a;
                }
                T2 &operator[](int i){
                    return a[i];
                }
                void set(int n){
                    if(a) delete a;
                    a = new T[n];
                }
            private:
                T2 *a;
            };
            CArray2D(int n, int p){
                array1d = new CArray1D<T> [n];
                for (int i = 0; i < n; ++i)
                {
                    array1d[i] = new CArray1D<T> [p];
                }
            }
            CArray2D(){
                array1d = NULL;
            }
            ~CArray2D(){
                if (array1d)
                    delete [] array1d;
            }
            CArray1D<T1> &operator[](int i){
                return array1d[i];
            }
            void set(int n, int p){
                array1d = new CArray1D<T> [n];
                for (int i = 0; i < n; ++i){
                    array1d[i].set(p);
                }
            }
        private:
            CArray1D<T1> *array1d;
    };
    CArray3D(int m, int n, int p){
        array2d = new CArray2D<T> [m];
        for (int i = 0; i < m; ++i)
        {
            array2d[i].set(n, p);
        }
    }
    ~CArray3D(){
        if(array2d)
            delete [] array2d;
    }
    CArray2D<T> &operator[](int i){
        return array2d[i];
    }
private:
    CArray2D<T> *array2d;
};
    // int main()
// {
//     CArray3D<int> a(3,4,5);
//     int No = 0;
//     for( int i = 0; i < 3; ++ i )
//         for( int j = 0; j < 4; ++j )
//             for( int k = 0; k < 5; ++k )
//                 a[i][j][k] = No ++;
//     for( int i = 0; i < 3; ++ i )
//         for( int j = 0; j < 4; ++j )
//             for( int k = 0; k < 5; ++k )
//                 cout << a[i][j][k] << ",";
//     return 0;
// }