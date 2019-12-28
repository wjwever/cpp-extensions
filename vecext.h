/*************************************************************************
    > File Name: vecext.h
    > Author: wangjw
    > Mail: 
    > Created Time: 日 10/20 21:24:43 2019
 ************************************************************************/

#ifndef  __VEC_EXT__
#define  __VEC_EXT__
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <iostream>
using std::vector;
using std::min;

template<class T, class M>
vector<T> vecAdd(const vector<T>& v1, const vector<M>& v2)
{
    vector<T> ret = v1;
    for (int i = 0; i < min(v1.size(), v2.size()); ++i)
    {
        ret[i] += v2[i];
    }
    return ret;
}

template<class T, class M>
vector<T> vecMul(const vector<T>& v1, const M mul)
{
    vector<T>ret = v1;
    for (T &t : ret)
        t  = t * mul;
    return ret;
}

template<class T, class M>
vector<T> vecMul(const vector<T>& v1, const vector< M >& mul)
{
    vector<T>ret = v1;
    for (int i = 0; i < min(ret.size(), mul.size()); ++i)
    {
        ret[i] *= mul[i];
    }
    return ret;
}

template<class T>
vector<T> vecLog(vector<T>& v1)
{
    vector<T> ret = v1;
    for (T& t : ret)
    {
        t = log(t);
    }
    return ret;
}

template<class T>
T vecSum(vector<T>& v1)
{
    T ret = 0;
    for (int i = 0; i < v1.size(); ++i)
    {
        ret = ret + v1[i];
    }
    return ret;
}


template<class T, class M>
vector<T> vecDot(const vector<T>& v1, const vector< M >& mul)
{
    vector<T>ret = vecMul(v1, mul);
    return vecSum(ret);
}

//重载>>
template<class T>
std::istream &operator >> (std::istream &in, vector<T> &x)
{
    x.clear();
    std::string tmp;
    while(std::getline(in, tmp)) {
        std::istringstream ss(tmp);
        T t;
        while(ss >> t) {
            x.append(t); 
        }
    }
    return in;
}

//重载输出<<
template <class T>
std::ostream &operator << (std::ostream &out, const vector<T> &x)
{
    for(int i = 0; i < x.size(); ++i) {
        out << x[i] << "\t";
    }
    return out;
}

template <class T>
void vecStr(const std::string& str, std::vector<T>& v)
{
    v.clear();
    std::istringstream ss(str);
    T t;
    while(ss >> t) {
        v.push_back(t); 
    }
}

//重载>>
template<class T>
std::istream &operator >> (std::istream &in, vector<vector<T>>& x)
{
    x.resize(0); 
    std::string tmp;
    while(getline(in, tmp)) {
        vector<T> line ;
        vecStr(tmp, line);
        if (line.size() > 0)
            x.push_back(line); 
    }
    return in;
}

//重载输出<<
template <class T>
std::ostream &operator << (std::ostream &out, const vector<vector<T>> &x)
{
    for(int i = 0; i < x.size(); ++i) {
        out << x[i];
        out<<std::endl;
    }
    return out;
}


template <class T>
bool isMat(const vector<vector<T>>& v)
{
    if (v.size() == 0)
        return true;
    for (size_t i = 1; i < v.size(); ++i) {
        if (v[i].size() != v[0].size())
            return false;
    }
    return true;
}

template <class T>
vector<T> vecTrans(const vector<vector<T>>& v)
{
    std::cout << "No supported yet!\n";
    vector<T> ret;
    return ret;
}

#endif
