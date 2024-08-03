#pragma once
#include "share.h"
class Chopstick
{
public:
	int id;
	bool available;
	int x1, y1,x2,y2;
	void draw()//筷子初始化
	{
		setlinecolor(WHITE);
		line(x1, y1, x2, y2);
	}
	bool takeup()
	{
		if(!available)//拿不到就退出，返回Flase
		{
			return false;
		}
		available = false;
		setlinecolor(WHITE);
		line(x1, y1, x2, y2);
		return true;
	}
	void putdown()//放下筷子
	{
		available = true;
		setlinecolor(BLACK);
		line(x1, y1, x2, y2);
	}
	Chopstick(int a, int b, int c, int d,int e);
};
Chopstick::Chopstick(int a, int b, int c, int d,int e)
{
	this->x1 = a;
	this->y1 = b;
	this->x2 = c;
	this->y2 = d;
	this->id = e;
	available = true;
}

