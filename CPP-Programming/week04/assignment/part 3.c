// #include <iostream>
// #include <cstring>
// using namespace std;
class Array2
{
 private:
	int width;										
	int height;										
	int *ptr;										
 public:
	 Array2() {}									
	 Array2(int width_, int height_)				
	 {
		 width = width_;
		 height = height_;

		 if (width == 0 || height == 0)
			 ptr = NULL;
		 else
			 ptr = new int[width * height];
	 }

	 int * operator[](int i)
	 {
		 int * pTmp = ptr;
		 for (int count = 0; count < i * height; count++)
			 pTmp++;

		 return pTmp;
	 }

	 int & operator()(int width_, int height_)
	 {
		/* if (width_ < width && width >= 0 && height_ < height && height_ >= 0)
		 {*/
			 return ptr[width_ * height + height_];
		 //}
	 }

	 Array2 & operator =(const Array2 & arr)
	 {
		 if (ptr == arr.ptr)							
			return *this;

		 if (arr.ptr == NULL)
		 {
			 if (ptr) delete[] ptr;
			 ptr = NULL;
			 width = 0;
			 height = 0;
			 return *this;
		 }
		 
		 if (width * height < arr.width * arr.height)	
		 {
			 if (ptr != NULL)
				 delete[] ptr;

			 ptr = new int[arr.width * arr.height];
		 }
		
		 memcpy(ptr, arr.ptr, sizeof(int) * arr.width * arr.height);
		 width = arr.width;
		 height = arr.height;
		 /*for (int i = 0; i < width; i++)
		 {
			 for (int j = 0; j < height; j++)
				 ptr[i * height + j] = arr.ptr[i * height + j];
		 }*/

		 return *this;
	 }
};
// int main() {
//     Array2 a(3,4);
//     int i,j;
//     for(  i = 0;i < 3; ++i )
//         for(  j = 0; j < 4; j ++ )
//             a[i][j] = i * 4 + j;
//     for(  i = 0;i < 3; ++i ) {
//         for(  j = 0; j < 4; j ++ ) {
//             cout << a(i,j) << ",";
//         }
//         cout << endl;
//     }
//     cout << "next" << endl;
//     Array2 b;     b = a;
//     for(  i = 0;i < 3; ++i ) {
//         for(  j = 0; j < 4; j ++ ) {
//             cout << b[i][j] << ",";
//         }
//         cout << endl;
//     }
//     return 0;
// }