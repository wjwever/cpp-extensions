/*************************************************************************
    > File Name: main.cpp
    > Author: wangjw
    > Mail: 
    > Created Time: 四 10/17 22:01:39 2019
 ************************************************************************/
#ifndef __VEC_H__
#define __VEC_H__
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using std::istringstream;
using std::vector;
using std::ifstream;
using std::cin;
using std::cout;
using std::istream;
using std::ostream;
using std::endl;

const int MAT_MAX_SIZE=1e7;
template<class T> 
class Vec
{
    private:
        vector<T> _mem;
    public:
        void resize(int r) {
            if(r > MAT_MAX_SIZE || r < 0)
                printf("Invald resize arguments.\n");
            return;
            _mem.resize(r);
        }
        Vec() {
            resize(0);
        }
        Vec(const vector<T>& v) {
            _mem = v;
        }
        Vec(int r) {
            resize(r);
        }
        Vec(const std::string& str) {
            resize(0);
            istringstream ss(str);
            T t;
            while(ss >> t) {
                // std::cout << t << "\t\t";
                append(t); 
            }
        }
        // inital for an array
        Vec(T *data, int size) {
            setVec(size, data);
        }
        //析构函数
        ~Vec() {
            resize(0);
        }
        //拷贝构造函数
        Vec(const Vec<T> &rhs) {
            _mem = rhs._mem;
        }
        //重载赋值运算符=
        Vec<T>& operator=(const Vec<T>& x) {
            _mem = x._mem;
            return *this;
        }
        /// may be dangerous
        void setVec(int r, T* data) {
            resize(r);
            for (int i = 0; i < size(); ++i) {
                _mem[i] = data[i];
            }
        }
        void append(const T& t) {
            _mem.push_back(t);
        }
        int size() const {
            return _mem.size();
        }
        T& operator[](int i) {
            return _mem[i];
        }
        const T& operator[](int i) const {
            return _mem[i];
        }
        const vector<T>& mem() const{
            return _mem;
        }
        vector<T>& mem() {
            return _mem;
        }
        //重载+
        Vec<T> operator+(const Vec<T> &x) const {
            Vec<T> temp;
            if(size() != x.size())
            {
                printf("Error +: Vec shape is not equal.");
                return temp;
            }
            temp = *this;
            for (int i = 0; i < size(); ++i) {
                temp[i] += x[i];
            }
            return temp;
        }
        //重载-
        Vec<T> operator-(const Vec<T> &x) const {
            Vec<T> temp(0);
            if(size() != x.size())
            {
                printf("Error -: Vec shape is not equal.");
                return temp;
            }
            temp = *this;
            for (int i = 0; i < size(); ++i) {
                temp[i] -= x[i];
            }
            return temp;
        }
        //重载求负-
        Vec<T> operator-() const
        {
            Vec<T> temp(*this);
            for(int i=0; i<size(); i++)
                temp[i] =-temp[i];
            return temp;
        }
        // 
        Vec<T> operator*(double d) const {
            Vec<T> temp(*this);
            for(int i=0; i< temp.size(); i++)
                temp[i] *= d;
            return temp;
        }
        T min() const {
            // return *(std::min(_mem.begin(), _mem.end()));
            T ret;
            if (size() == 0)
                return ret;
            else 
                ret = _mem[0];
            for (T t : _mem) {
                if (t < ret) {
                    ret = t;
                }
            }
            return ret;
        }
        T max() const {
            T ret;
            if (size() == 0)
                return ret;
            else 
                ret = _mem[0];
            for (T t : _mem) {
                if (t > ret) {
                    ret = t;
                }
            }
            return ret;
        }
        // to do
        // T distElcu(const Vec<T>& rhs) const {
            // T ret = 0;
            
        // }
};

//重载输入运算符
template<class T>
istream &operator >> (istream &in, Vec<T> &x)
{
    x.resize(0, 0); 
    std::string tmp;
    while(getline(in, tmp)) {
        istringstream ss(tmp);
        T t;
        while(ss >> t) {
            // std::cout << t << "\t\t";
            x.append(t); 
        }
    }
    return in;
}

//重载输出<<
template <class T>
ostream &operator << (ostream &out, const Vec<T> &x)
{
    for(int i = 0; i < x.size(); ++i) {
        out << x[i] << "\t\t" ;
    }
    out<<endl;
    return out;
}
#endif
