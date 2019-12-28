/*************************************************************************
    > File Name: main.cpp
    > Author: wangjw
    > Mail: 
    > Created Time: 四 10/17 22:01:39 2019
 ************************************************************************/
#ifndef __MAT_H__
#define __MAT_H__
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vec.h>

using std::istringstream;
using std::vector;
using std::ifstream;
using std::cin;
using std::cout;
using std::istream;
using std::ostream;
using std::endl;

char getch() {
    char a;
    system("stty -icanon");
    a = getchar();
    // printf("%c",a);
    return a;
}

//空间申请异常类
class Wrongmem{};
//下标越界异常类
class Outofrange{};
//定义错误异常类
class Differ{};

/*********************************矩阵类开始**************************************/
extern const int MAT_MAX_SIZE;
template<class T> 
class Mat
{
private:
    // vector<vector<T>> _mem;
    vector<Vec<T>>  _mem;
public:
    Mat() {
        resize(0);
    }
    Mat(int r,int c) {
        resize(r, c);
    }
    Mat(const vector<vector<T>>& array)
    {
        resize(0);
        for (const auto & t :array){
            append(t);
        }
    }
    void append(const vector<T>& line) {
        _mem.push_back(line);
    }
    void append(const Vec<T>& line) {
        _mem.push_back(line);
    }
    void resize(int r) {
        if(r > MAT_MAX_SIZE || r < 0 )  {
            printf("Invald resize arguments.\n");
            return;
        }
        _mem.resize(r);
    }
    void resize(int r, int c) {
        if(r > MAT_MAX_SIZE || r < 0 || c > MAT_MAX_SIZE || c < 0)  {
            printf("Invald resize arguments.\n");
            return;
        }
        _mem.resize(r);
        for (auto& row : _mem)
            row.resize(c);
    }
    //析构函数
    ~Mat() {
        resize(0, 0);
    }
    int row()const {
        return _mem.size();
    }
    int col(int r = 0) const {
        if (r >= row()) {
            printf("Invalid row nubmer.\n");
            return 0;
        }
        else
            return _mem[r].size();
    }
    bool isMatrix() const {
        for (auto i = 0; i < row(); ++i) {
            if (col(i) != col(0))
                return false;
        }
        return true;
    }
    //拷贝构造函数
    Mat(const Mat<T> &rhs) {
        _mem = rhs._mem;
    }
    //重载函数调用运算符()
    // T &operator()(int i, int j) {
        // return _mem[i][j];
    // }
    // const T &operator()(int i, int j) const {
        // return _mem[i][j];
    // }
    Vec<T>& operator[](int i) {
        return _mem[i];
    }
    const Vec<T>& operator[](int i) const {
        return _mem[i];
    }
    //重载赋值运算符=
    Mat<T>& operator=(const Mat<T> &x) {
        _mem = x._mem;
        return *this;
    }
    Vec<T> mean() const {
        if (row() == 0) {
            return Vec<T>();
        }
        Vec<T> ret = (*this)[0];
        for (int i = 1; i < row(); ++i) {
            ret = ret + (*this)[i]; 
        }
        ret = ret * (1.0 / row());
        return ret;
    }

    Vec<T> nth(int n) const {
        Vec<T> ret; 
        for (int i = 0; i < row(); ++i) {
            ret.append((*this)[i][n]);
        }
        return ret;
    }

    //重载转置!
    Mat<T> operator!() const {
        Mat<T> tmp;
        for (int i = 0; i < col(); ++i) {
            tmp.append(nth(i)); 
        }
        return tmp;
    }
    //重载+
    Mat<T> operator+(const Mat<T> &x) const {
        Mat<T> temp(0, 0);
        if(row() != x.row() || col()!=x.col()) {
            printf("Mat shape is not equal.\n");
            return temp;
        }
        temp = *this;
        for (int i = 0; i < row(); ++i) 
        {
            temp[i] = temp[i] + x[i];
        }
        return temp;
    }
    //重载-
    Mat<T> operator-(const Mat<T> &x) const {
        Mat<T> temp(0, 0);
        if(row() != x.row() || col()!=x.col()) {
            printf("Mat shape is not equal.");
            return temp;
        }
        temp = *this;
        for (int i = 0; i < row(); ++i) 
        {
            temp[i] = temp[i] - x[i];
        }
        return temp;
    }
    //重载*
    Mat<T> operator*(const Mat<T> &x) const {
        // if(cols!=x.rows) throw Differ();
        // Mat<T> temp(rows,x.cols);
        // for(int i=0;i<rows;i++)
        // for(int j=0;j<x.cols;j++)
        // {
        // temp(i,j)=0;
        // for(int k=0;k<x.rows;k++)
        // temp(i,j)+=mem[i*cols+k]*x.mem[k*x.cols+j];
        // }
        printf("Multiply is not supported at present.\n");
        Mat<T> tmp(0, 0);
        return tmp;
    }
    //重载求负-
    Mat<T> operator-() const
    {
        Mat<T> temp(*this);
        for(int i=0; i<row(); i++)
        {
            temp[i] = -temp[i];
        }
        return temp;
    }
};

//重载输入运算符
template<class T>
istream &operator >> (istream &in, Mat<T> &x)
{
    x.resize(0, 0); 
    std::string tmp;
    while(getline(in, tmp)) {
        Vec<T> line(tmp);
        if (line.size() > 0)
            x.append(line); 
    }
    return in;
}

//重载输出<<
template <class T>
ostream &operator << (ostream &out, const Mat<T> &x)
{
    for(int i = 0; i < x.row(); ++i) {
        out << x[i];
    }
    out<<endl;
    return out;
}
#endif
