#include<iostream>
using namespace std;
template<typename T>
class Matrix{
private:
	int row;
	int col;
	T* datas;
	void init();
public:
	//无参构造
	Matrix()
	{
		row = 0;
		col = 0;
		datas = NULL;
		init();
	}
	//r行c列构造
	Matrix(int r, int c)
	{
		row = r;
		col = c;
		datas = new int[r * c];
		init();
	}
	//拷贝构造
	Matrix(const Matrix& a)
	{
		row = a.row;
		col = a.col;
		datas = new T[row * col];
		for (int i = 0; i < row * col; i++)
		{
			datas[i] = a.datas[i];
		}

	}
	//析构
	~Matrix() { delete datas; }

	int& operator ()(int i, int j);
	Matrix& operator =(const Matrix& a);
	Matrix operator +(const Matrix& a) const;
	Matrix operator -(const Matrix& a) const;
	Matrix operator *(const Matrix& a) const;
	void show();
};
