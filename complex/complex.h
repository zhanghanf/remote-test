#pragma once
#ifndef _COMPLEX_
#define _COMPLEX_
//同一个程序定义时不会重复定义 防卫式声明
#include""
//前置声明
#include<iostream>
#include<cmath>
class complex;
complex& _doapl(complex* ths, const complex& r);
//类声明
//参数的传递：尽量传递引用
//不想把实部虚部写死
/*
template<typename T>
class complex //class head
{//class bidy
public://考虑使用的人的需求
	//字符只一个字节？是否考虑值传递呢
	//值传递pass by value;整包传递，尽量引用传递
	complex(double r = 0, double i = 0) :re(r), im(i) {};//构造函数放在private不可以
	//不允许被外界调用时
	//传递使用指针：4个字节，传递速度更快 缺点：容易改变传递的值：不想改变值考虑加const：不希望传递后改变
	complex& operator+=(const complex&) ;//pass by reference引用传递：底层是指针传递，和指针传递一样快
	T real()const { return re; }//取得复数实部虚部
	T imag() const { return im; }//在函数后头加const，防止改变class内部的数据

	//同一个class中的各个object互为friends（友元）
	int fnuc(const complex& param) {
		return param.re + param.im;
	}


	
private:

	T re, im;//可能实部虚部有多种类型，使用模板template<typename T>
	void function();//函数声明
	friend complex& _doapl(complex*, const complex&);//友元函数可以访问复数的数据
};

*/
class complex //class head
{//class bidy
public://考虑使用的人的需求，被外界使用
	//字符只一个字节？是否考虑值传递呢
	//值传递pass by value;整包传递，尽量引用传递
	complex(double r = 0, double i = 0) :re(r), im(i) {};//构造函数放在private不可以，使用默认值，构造函数重载，没有返回值类型：创建对象时使用的
	//把收到的参数
	complex() :re(0), im(0) {};//默认构造函数
	//不允许被外界调用时
	//传递使用指针：4个字节，传递速度更快 缺点：容易改变传递的值：不想改变值考虑加const：不希望传递后改变
	complex& operator+=(const complex&) ;//pass by reference引用传递：底层是指针传递，和指针传递一样快
	inline double real()const { return re; }//取得复数实部虚部
	inline double imag() const { return im; }//在函数后头加const，防止改变class内部的数据
	
	//同一个class中的各个object互为friends（友元）
	int fnuc(const complex& param) {
		return param.re + param.im;
	}
	//客户可能对应的三种加法
	

	/*
	* 
	}
	*/
private://数据部分：不会被外界看到
	
	double re, im;//可能实部虚部有多种类型，使用模板template<typename T>
	void function();//函数声明
	friend complex& _doapl(complex*, const complex&);//友元函数可以访问复数的数据
	friend complex operator+(const complex& x, const complex& y);
};
/*
{
const complex c1(2,1);
cout<<c1.real;//编译器报错real没有加const，可能会改变class内real的值，与构建的对象冲突,private
}
*/
std::ostream& operator<< (std::ostream& os, complex& x) {//命名空间
	return os << '(' << x.imag() << ',' << x.real() << std::endl;

#endif // !_COMPLEX_


