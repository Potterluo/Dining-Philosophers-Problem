// Philosopher's dining problem.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//不足：1.只有全部哲学家都吃一遍饭才能进入下次循环
#include"philosopher.h"
#include <iostream>
#include <windows.h>
#include <process.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
using namespace std;
CRITICAL_SECTION g;
DWORD WINAPI Threadphilos0(LPVOID lpParam);
DWORD WINAPI Threadphilos1(LPVOID lpParam);
DWORD WINAPI Threadphilos2(LPVOID lpParam);
DWORD WINAPI Threadphilos3(LPVOID lpParam);
DWORD WINAPI Threadphilos4(LPVOID lpParam);
int i, j;
bool b[5];
//初始化筷子及哲学家
Chopstick chopsticks[5] =
{ Chopstick(20,280,150,320,0),Chopstick(380,80,380,170,1),
Chopstick(700,300,600,350,2),Chopstick(500,570,600,670,3),Chopstick(260,570,160,670,4) };
Philosopher philos[5] =
{
Philosopher(190,190,0, chopsticks[0], chopsticks[1]),
Philosopher(580,198,1, chopsticks[1], chopsticks[2]),
Philosopher(630,450,2, chopsticks[2], chopsticks[3]),
Philosopher(380,640,3, chopsticks[3], chopsticks[4]),
Philosopher(130,450,4, chopsticks[4], chopsticks[0])
};
void draw();//创建背景
int main()
{
    draw();
	//在构造函数中勾画会发生内存冲突，所以把勾画放到外面了
	philos[0].draw(); philos[1].draw(); philos[2].draw();
	philos[3].draw(); philos[4].draw();
	chopsticks[0].draw();chopsticks[1].draw();chopsticks[2].draw();
	chopsticks[3].draw();chopsticks[4].draw();
	DWORD uID;
	HANDLE h[5];
	while (1) {
		::InitializeCriticalSection(&g);
		h[0] = ::CreateThread(NULL, 0, Threadphilos0, NULL, 0, &uID);
		h[1] = ::CreateThread(NULL, 0, Threadphilos1, NULL, 0, &uID);
		h[2] = ::CreateThread(NULL, 0, Threadphilos2, NULL, 0, &uID);
		h[3] = ::CreateThread(NULL, 0, Threadphilos3, NULL, 0, &uID);
		h[4] = ::CreateThread(NULL, 0, Threadphilos4, NULL, 0, &uID);
		::WaitForMultipleObjects(5, h, TRUE, INFINITE);
		CloseHandle(h[0]);
		CloseHandle(h[1]);
		CloseHandle(h[2]);
		CloseHandle(h[3]);
		CloseHandle(h[4]);
		::DeleteCriticalSection(&g);
	}
	system("pause");
    _getch();				// 按任意键继续
    closegraph();			// 关闭绘图窗口
    return 0;
}
void draw()
{
    initgraph(800, 800);	// 创建绘图窗口，大小为 800*800 像素
    setbkcolor(WHITE); // 设置背景色为白色
    cleardevice(); // 用背景色清空屏幕
    settextstyle(40, 40, DEFAULT_PITCH);//设置字体
    settextcolor(BLACK);
    TCHAR s[] = _T("哲学家就餐问题");
    outtextxy(120, 25, s);//标题
    setlinecolor(BROWN);
    circle(380, 380, 200);	// 画圆，圆心(380，380)，半径 200
}
DWORD WINAPI Threadphilos0(LPVOID)
{
	//::EnterCriticalSection(&g);
	philos[0].think();
	//::LeaveCriticalSection(&g);
	j = rand() *10;
	Sleep(j);
	do {
		::EnterCriticalSection(&g);//判断是否能吃饭是不能被中断
		b[0] = philos[0].eat();
		::LeaveCriticalSection(&g);
		Sleep(100);
	} while (!b[0]);
	::EnterCriticalSection(&g);
	philos[0].finish();            //放筷子时不能被中断
	::LeaveCriticalSection(&g);
	return 0;
}
DWORD WINAPI Threadphilos1(LPVOID)
{

	//::EnterCriticalSection(&g);
	philos[1].think();
	//::LeaveCriticalSection(&g);
	j = rand() % 10;
	Sleep(j);
	do
	{
		::EnterCriticalSection(&g);
		b[1] = philos[1].eat();
		::LeaveCriticalSection(&g);
		Sleep(100);
	} while (!b[1]);
	::EnterCriticalSection(&g);
	philos[1].finish();
	::LeaveCriticalSection(&g);
	return 0;
}
DWORD WINAPI Threadphilos2(LPVOID)
{

	//::EnterCriticalSection(&g);
	philos[2].think();
	//::LeaveCriticalSection(&g);
	j = rand() % 10;
	Sleep(j);
	do
	{
		::EnterCriticalSection(&g);
		b[2] = philos[2].eat();
		::LeaveCriticalSection(&g);
		Sleep(100);
	} while (!b[2]);
	::EnterCriticalSection(&g);
	philos[2].finish();
	::LeaveCriticalSection(&g);
	return 0;
}
DWORD WINAPI Threadphilos3(LPVOID)
{

	//::EnterCriticalSection(&g);
	philos[3].think();
	//::LeaveCriticalSection(&g);
	j = rand() % 10;
	Sleep(j);
	do
	{
		::EnterCriticalSection(&g);
		b[3] = philos[3].eat();
		::LeaveCriticalSection(&g);
		Sleep(100);
	} while (!b[3]);
	::EnterCriticalSection(&g);
	philos[3].finish();
	::LeaveCriticalSection(&g);
	return 0;
}
DWORD WINAPI Threadphilos4(LPVOID)
{

	//::EnterCriticalSection(&g);
	philos[4].think();
	//::LeaveCriticalSection(&g);
	j = rand() % 10;
	Sleep(j);
	do
	{
		::EnterCriticalSection(&g);
		b[4] = philos[4].eat();
		::LeaveCriticalSection(&g);
		Sleep(100);
	} while (!b[4]);
	::EnterCriticalSection(&g);
	philos[4].finish();
	::LeaveCriticalSection(&g);
	return 0;
}
