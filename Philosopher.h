#pragma once
#include "graphics.h"
#include"chopstick.h"
#include <conio.h>
#include <iostream>
#include <wincrypt.h>
#include <windows.h>
using namespace std;
class Philosopher {// ��ѧ����
public:
  
    int x, y;//��ѧ��λ�ö�Ӧ������
    int id;//��ѧ�ҵı��
    Chopstick& left, & right;//��ѧ�ҵ����ҿ���
    Philosopher(int a, int b,int num, Chopstick& c1, Chopstick
        & c2) :left(c1), right(c2), x(a), y(b), id(num)
    {
        //setfillcolor(GREEN);       //��ɫ˼��״̬
        //solidcircle(a, b, 50);	   // ��Բ��Բ��(200, 200)���뾶 100
    }
    void draw()
    {
        setfillcolor(GREEN);       //��ɫ˼��״̬
        solidcircle(x, y, 50);	   // ��Բ��Բ��(200, 200)���뾶 100
    }
    bool eat()                     //��ʳ
    {
        setfillcolor(RED);         //��ɫ����״̬
        solidcircle(x, y, 50);
        Sleep(500);                //������ʾ������һ��ʱ���ٽ�ʳ  
            bool br, bl;              //���ҿ��ӵ�״̬
            bl = left.takeup();       //���������
            if (!bl)
            {
                Sleep(500);         //���ò������ȴ�1s,�˳�
                return 0;               
            }
            br = right.takeup();
            if (!br)
            {
                left.putdown();      // �������ҿ���ʱ��Ҫ������ӷ���
                Sleep(500);         //���ò������ȴ�0.5s,�˳�
                return 0;            
            }
            if (br && bl)
            {
                setfillcolor(YELLOW);    //��ɫ��ʳ״̬
                solidcircle(x, y, 50);
                Sleep(500);
                return true;
            }
        
    }
    void think()
    {
        left.putdown();
        right.putdown();
        setfillcolor(GREEN);//��ɫ˼��״̬
        solidcircle(x, y, 50);
        Sleep(1000);
    }
    void finish()
    {
        Sleep(1000);
        left.putdown();//���������
        right.putdown();//�����ҿ���
        setfillcolor(GREEN);//��ɫ˼��״̬
        solidcircle(x, y, 50);
    }
    
};


/* void think()//˼��ģʽ
    {
        setfillcolor(GREEN);
        solidcircle(x, y, 50);
    }
    void hungry()//�е�����
    {
        setfillcolor(RED);
        solidcircle(x, y, 50);
        Sleep(5 * 1000);//��ʱ5��
    }
    void eat()//�Է�
    {
        setfillcolor(YELLOW);
        solidcircle(x, y, 50);
        Sleep(5 * 1000);//��ʱ5��
    }
    void full()//�Ա���
    {
        setfillcolor(GREEN);
        solidcircle(x, y, 50);
    }
    void Lchopstick()//������ߵĿ���
    {

    }

    void Rchopstick()//�����ұߵĿ���
    {

    }
    */