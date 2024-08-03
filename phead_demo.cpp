/*
#include <iostream>   
#include <windows.h>   
using namespace std;
DWORD WINAPI Fun1(LPVOID lpParamter)
{
    for (int i = 0; i < 10; i++)
    {
        cout << "B Thread Fun Display!" << endl;
        Sleep(5000);
    }
    return 0L;
}
int Fun()
{
    for (int i = 0; i < 10; i++)
    {
        HANDLE hThread = CreateThread(NULL, 0, Fun1, NULL, 0, NULL);
        CloseHandle(hThread);
        cout << "A Thread Fun Display!" << endl;
        Sleep(5000);
    }
    return 0;
}
int main()
{
    Fun();
    return 0;
}*/