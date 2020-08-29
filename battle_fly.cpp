#include<iostream>
#include <string>
#include <Windows.h>
#include <ctime>

using namespace std;

void resizeConsole(int width, int height);
void textcolor(int x);
void gotoxy(int x,int y);
void XoaManHinh();
void veXenguoichoi(int x, int y);
void xoaXenguoichoi(int &x, int &y);
void veXemay(int &x, int &y);
void taoBando1();
void taoBando2();
void inBando();
void dieuKhienxe(int &x, int &y);
char map[50][50];



int main()
{
	SetConsoleTitle("Game dua xe");
	resizeConsole(800, 600);
	int x = 25, y= 15;
	int x1 = 2;
	int y1, x2, y2, x3, y3;
	x2 = 5;
	y2 = 	2 + rand() % 26;
	x3 = 2;
	y3 = 8 + rand() % 25;
	while (true)
	{	
		dieuKhienxe(x, y);
		if(x1 % 2 == 0)
		taoBando1();
		else taoBando2();
		veXenguoichoi(x, y);
		veXemay(x1, y1);
		veXemay(x2, y2);
		if(0 == 0){
			veXemay(x3, y3);
		}
		inBando();
		XoaManHinh();
		x1++;
		x2++;
		x3++;
		if(x1 > 30)
		x1 = 2;
		
		if(x2 > 50)
		{
			x2 = 2;
			y2 = y1 - 5;
		}
		if( x3 > 100)
		{
			x3 = 2;
			if(y3 > 20)
			y3 = 20;
			else y3 = y3 + 3;
			
		}
		
		srand(time(0));
		y1 =  2 + rand() % 26;
		
		if ( map[x][y] == '8' || map[x-1][y] == '8' || map[x][y-1] == '8' || map[x][y+1] == '8' || map[x+1][y+1] == '8'
		   || map[x+1][y-1] == '8')
		   {
				return 0;
		   }
	}
}




void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}


void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}


void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}


void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void veXenguoichoi(int x, int y){
	map[x][y] = 'x';
	map[x-1][y] = 'x';
	map[x][y-1] = 'x';
	map[x][y+1] = 'x';
	map[x+1][y+1] = 'x';
	map[x+1][y-1] = 'x';
}

void xoaXenguoichoi(int &x, int &y){
	map[x][y] = ' ';
	map[x-1][y] = ' ';
	map[x][y-1] = ' ';
	map[x][y+1] = ' ';
	map[x+1][y+1] = ' ';
	map[x+1][y-1] = ' ';
}

void veXemay(int &x, int &y){

	map[x][y] = '8';
	map[x-1][y] = '8';
	map[x][y-1] = '8';
	map[x][y+1] = '8';
	map[x+1][y+1] = '8';
	map[x+1][y-1] = '8';
}

void taoBando1(){
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (j == 0 || j == 29){
				map[i][j] = '|';
			}
			else if (j == 14 && i % 2 == 0 )
			{
				map[i][j] = '7';
			}
			
			else map[i][j] = ' ';
		}
	}
}

void taoBando2(){
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (j == 0 || j == 29){
				map[i][j] = '|';
			}
			else if (j == 14 && i % 2 == 1 )
			{
				map[i][j] = '7';
			}
			
			else map[i][j] = ' ';
		}
	}
}

void inBando(){
	for (int i = 0; i < 30; i++)
	{
		cout << endl;
		cout << "\t\t\t";
		for (int j = 0; j < 30; j ++)
		{
			if(map[i][j] == 'x' && map[i-1][j] == 'x' && map[i][j+1] == 'x')
			{
				textcolor(158);
				cout << "X";
				textcolor(7);
			}
			else if (map[i][j] == 'x' &&  map[i+1][j] == 'x' && (map[i][j+1] == 'x' || map[i][j-1] == 'x'))
			{
				textcolor(158);
				cout << "T";
				textcolor(7);
			}
			else if (map[i][j] == 'x')
			{
				textcolor(158);
				cout << " ";
				textcolor(7);
			}
			else if (map[i][j] == '8')
			{
				textcolor(204);
				cout << " ";
				textcolor(7);
			}
			else if (map[i][j] == '|')
			{
				textcolor(128);
				cout << " ";
				textcolor(7);
			}
			else if (map[i][j] == '7')
			{
				textcolor(240);
				cout << " ";
				textcolor(7);
			}
			
			
			else cout << map[i][j];
			
		}
		
	}
}

void dieuKhienxe(int &x, int &y){
	if(GetAsyncKeyState(VK_LEFT) && y > 2)
	{
		xoaXenguoichoi(x, y);
		y = y - 1;
		veXenguoichoi(x,y);
	}
	if(GetAsyncKeyState(VK_RIGHT) && y < 27)
	{
		xoaXenguoichoi(x, y);
		y = y + 1;
		veXenguoichoi(x,y);
	}
	if(GetAsyncKeyState(VK_UP) && x > 1)
	{
		xoaXenguoichoi(x, y);
		x = x - 1;
		veXenguoichoi(x,y);
	}
	if(GetAsyncKeyState(VK_DOWN) && x < 28)
	{
		xoaXenguoichoi(x, y);
		x = x + 1;
		veXenguoichoi(x,y);
	}	
}

