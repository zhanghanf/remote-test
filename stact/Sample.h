#pragma once
#ifndef _SAMPLE_H
#define _SAMPLE_H
class StaticSample
{
private:
	static int obj_count;
	static int obj_living;
public:
	StaticSample();
	~StaticSample();
	static void display();
};
#endif // !1



