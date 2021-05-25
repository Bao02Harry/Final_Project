#include<iostream>
#include<conio.h>
#include<string>
#include"Windows.h"
using namespace std;

//ham thay doi kich co cmd

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console,r.left, r.top, width, height, TRUE);
}

// mau

void TextColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
//toa do
void gotoxy(int x,int y)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD tinh = {x,y} ;
	SetConsoleCursorPosition(mau,tinh ) ;
}
// to mau 
void tomau(int x, int y, string a, int color)
{
	gotoxy(x,y);
	TextColor(color);
	cout<<a;
	TextColor(7);
}
