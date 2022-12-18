#include "Matrix.h"

//访问矩阵中的元素
T& Matrix<T>::operator()(int i, int j)
{
	return datas[(i - 1) * col + j - 1];
}
//矩阵赋值
Matrix<T>& Matrix<T>::operator =(const Matrix<T>& a)
{
	delete datas;
	row = a.row;
	col = a.col;
	datas = new int[row * col];
	for (int i = 0; i < row * col; i++)
	{
		datas[i] = a.datas[i];
	}
	return *this;
}
//矩阵相加
Matrix<T> Matrix<T>::operator +(const Matrix<T>& a) const
{
	if (row != a.row || col != a.col)
	{
		Matrix<T> tmp;
		return tmp;
	}
	Matrix<T> tmp(*this);
	for (int i = 0; i < row * col; i++)
	{
		tmp.datas[i] += a.datas[i];
		return tmp;
	}
}
//矩阵相乘
Matrix<T> Matrix<T>::operator *(const Matrix<T>& a) const
{
	if (col != a.row)
	{
		Matrix<T> tmp;
		return tmp;
	}
	Matrix<T> tmp(row, a.col);
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= a.col; j++)
		{
			for (int k = 1; k <= col; k++)
			{
				tmp.datas[(i - 1) * tmp.col + j - 1] +=
					this->datas[(i - 1) * col + k - 1] * a.datas[(k - 1) * a.col + j - 1];
			}
		}
	}
	return tmp;
}
//打印矩阵
void Matrix<T>::show()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << datas[i * col + j] << "   \t";
		}
		cout << endl;
	}
}
//初始化矩阵
void Matrix<T>::init()
{
	for (int i = 0; i < row * col; i++)
	{
		datas[i] = 0;
	}
}
