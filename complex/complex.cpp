#include "complex.h"
inline complex& _doapl(complex* ths, const complex& r) {//第一个参数会改变，第二个不会改变
	//设计一个类：数据尽可能放在private 参数尽可能reference 返回值尽量以reference
	//在类的body（本体）能加const尽量加const
	ths->re += r.re;//这个动作在r+rhs后直接放在ths中，如果使用+运算符，需要创建一个临时的变量，这时候不能用引用
	ths->im += r.im;
	return *ths;//返回地址
}
//成员函数操作符重载
complex& complex::operator+=(const complex& r) {
	//什么时候不可以返回引用：传递一个临时变量时不可行
	return _doapl(this, r);
}
void complex::function() {//函数定义

}
//函数可以设计成成员函数和非成员函数
inline double real(const complex& x) { return x.real(); }//非成员函数
inline double imag(const complex& x) { return x.imag(); }//非成员函数
inline complex operator+(const complex& x, const complex& y) {
	return complex(real(x) + real(y), imag(x) + imag(y));
}
inline complex operator+(double x, const complex& y) {
	return complex(x + real(y), imag(x) + imag(y));
}
inline complex operator+(const complex& x, double y) {
	return complex(real(x) + real(y), imag(x) + y);
}
inline complex operator+(const complex& x) {
	return x;
}
inline complex operator-(const complex& x) {
	return complex(-real(x), -imag(x));
}
//复数相等
inline bool operator==(const complex& x, const complex& y) {
	return (x.imag() == y.imag() || x.real() == real(y));
}
//不相等
inline bool operator==(const complex& x, const complex& y) {

}