#pragma once
//设计模式Singleton
class A
{
public:
	static A& getInstance();//外界唯一的接口
	void setup() { return ; }
private:
	A();
	A(const A& rhs);
	//static A a;
};
A& A::getInstance() {//没有人调用是a不存在，有人调用是才会存在
	//自己给自己准备了一份：放在对外窗口
	static A a;
	return a;
}
class Account {
public:
	static double m_rate;
	static void set_rate(const double& x) { m_rate = x; }

};
double Account::m_rate = 8.0;
//或者产生对象了通过set_rate()调用