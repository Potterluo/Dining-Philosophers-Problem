#pragma once
#include "graphics.h"
#include"chopstick.h"
#include <conio.h>
#include <iostream>
#include <wincrypt.h>
#include <windows.h>
using namespace std;
class Philosopher {// 哲学家类
public:
  
    int x, y;//哲学家位置对应的坐标
    int id;//哲学家的编号
    Chopstick& left, & right;//哲学家的左右筷子
    Philosopher(int a, int b,int num, Chopstick& c1, Chopstick
        & c2) :left(c1), right(c2), x(a), y(b), id(num)
    {
        //setfillcolor(GREEN);       //绿色思考状态
        //solidcircle(a, b, 50);	   // 画圆，圆心(200, 200)，半径 100
    }
    void draw()
    {
        setfillcolor(GREEN);       //绿色思考状态
        solidcircle(x, y, 50);	   // 画圆，圆心(200, 200)，半径 100
    }
    bool eat()                     //进食
    {
        setfillcolor(RED);         //红色饥饿状态
        solidcircle(x, y, 50);
        Sleep(500);                //清晰显示，饥饿一段时间再进食  
            bool br, bl;              //左右筷子的状态
            bl = left.takeup();       //拿起左筷子
            if (!bl)
            {
                Sleep(500);         //若拿不到，等待1s,退出
                return 0;               
            }
            br = right.takeup();
            if (!br)
            {
                left.putdown();      // 不能拿右筷子时，要把左筷子放下
                Sleep(500);         //若拿不到，等待0.5s,退出
                return 0;            
            }
            if (br && bl)
            {
                setfillcolor(YELLOW);    //黄色进食状态
                solidcircle(x, y, 50);
                Sleep(500);
                return true;
            }
        
    }
    void think()
    {
        left.putdown();
        right.putdown();
        setfillcolor(GREEN);//绿色思考状态
        solidcircle(x, y, 50);
        Sleep(1000);
    }
    void finish()
    {
        Sleep(1000);
        left.putdown();//放下左筷子
        right.putdown();//放下右筷子
        setfillcolor(GREEN);//绿色思考状态
        solidcircle(x, y, 50);
    }
    
};


/* void think()//思考模式
    {
        setfillcolor(GREEN);
        solidcircle(x, y, 50);
    }
    void hungry()//感到饥饿
    {
        setfillcolor(RED);
        solidcircle(x, y, 50);
        Sleep(5 * 1000);//延时5秒
    }
    void eat()//吃饭
    {
        setfillcolor(YELLOW);
        solidcircle(x, y, 50);
        Sleep(5 * 1000);//延时5秒
    }
    void full()//吃饱了
    {
        setfillcolor(GREEN);
        solidcircle(x, y, 50);
    }
    void Lchopstick()//拿起左边的筷子
    {

    }

    void Rchopstick()//拿起右边的筷子
    {

    }
    */