#include <iostream>
#include <Windows.h>
#include <ctime>
#include<conio.h>
#include<cstring>
using namespace std;

void play1(int matran[][100], int x, int y);
void taomang( int matran[][100], int d, int c, int k);
void saochep( int bmx[0][100], int bm[0][100], int d, int c);
void vebando1(int bmx[][100], int bm[][100], int d, int c);
void vebando2(int bmx[][100], int bm[][100], int d, int c);
void textcolor(int x);
void gioithieu();
int kt(int bmx[][100], int d, int c );
int main ()

{
	SetConsoleTitle("Tran Xuan Tuyen");
	gioithieu();
	int bm[100][100] = {0};
	int bmx[100][100];
	int d, c, k, i, j, x, y;
	cout << "Nhap vao so dong x = ";
	cin >> d;
	cout << "Nhap vao so cot y = ";
	cin >> c;
	cout << "Nhap vao so min: ";
	cin >> k;
 	taomang(bm, d, c, k);
 	saochep(bmx, bm, d, c);
	system("cls");
	for ( i = 0; i <= d ; ++i )
	{
		cout << " \n\n\n\t\t\t";
		for ( j = 0; j<= c; ++j)
		{
			if (i == 0)
			{
				cout << "y" << j << "	";
			}
			else {
				if (j == 0)
				cout << "x" << i << "	";
				else cout << "?" << "	";
			}
		}
	}
	while(kt(bmx, d, c) < d*c - k)
	{
		cout << "\n\n\n" << "		Nhap vao dong thu x (1 <= x <= " << d << ") = ";
		cin >> x;
		cout << "		Nhap vao dong thu y (1 <= y <= " << c << ") = ";
		cin >> y;
		system("cls");
		if (bmx[x][y] != 0 && bmx[x][y] != -1)
		{
			bmx[x][y] = 10;
			vebando2(bmx, bm, d, c);
		}
		else
		{
			if (bmx[x][y] == 0)
			{
				play1(bmx, x , y);
				vebando2(bmx, bm, d, c);
			}
		}
		if (bmx[x][y] == -1)
		{
			cout << "			YOU ARE DEAD";
			vebando1(bmx, bm, d, c);
			return 0;
		}
	}
	
	system("cls");
	cout << "			BAN DA THANG";
	vebando1(bmx, bm, d, c);
}

void play1(int matran[][100], int x, int y)
{
	if (matran[x][y] == 0 )
	{
		matran[x][y] = 10;
		play1(matran, x + 1, y);
		play1(matran, x , y + 1);
		play1(matran, x , y - 1);
		play1(matran, x - 1, y);
		play1(matran, x - 1, y -1);
		play1(matran, x + 1, y +1);
		play1(matran, x - 1, y +1);
		play1(matran, x + 1, y -1);
	}
	else 
	{
		matran[x][y] = 10;		
	}
}

void taomang( int matran[][100], int d, int c, int k) 
{
	 int i, j;
	 srand(time(NULL));
	 for (int l = 0; l < k; l++)
	{
		do 
		{
			i = rand() % (d+1);
			j = rand() % (c+1);
		} 
		while (matran[i][j] == -1 || i == 0 || j == 0 || i == d + 1 || j == c +1);
	matran[i][j] = -1;
	}
	
	for (i = 1; i <= d; i++)
	{
		for (j = 1; j <= c; j++)
		{
			if ( matran[i][j] != -1)
			{
				if ( matran[i+1][j] == -1)
				matran[i][j]++;
				if ( matran[i-1][j] == -1 )
				matran[i][j]++;
				if ( matran[i][j+1] == -1 )
				matran[i][j]++;
				if ( matran[i][j-1] == -1 )
				matran[i][j]++;
				if ( matran[i+1][j+1] == -1 )
				matran[i][j]++;
				if ( matran[i+1][j-1] == -1 )
				matran[i][j]++;
				if ( matran[i-1][j+1] == -1 )
				matran[i][j]++;
				if ( matran[i-1][j-1] == -1 )
				matran[i][j]++;
			
			}
		}
	}
	for (i = 0; i <= c +1; ++i)
	{
		matran[0][i] = 11;
		matran[d+1][i] = 11;
	}
	
	for (i = 0; i <= d +1; ++i)
	{
		matran[i][c+1] = 11;
		matran[i][0] = 11;
	}
}

void saochep( int bmx[0][100], int bm[0][100], int d, int c)
{
	for ( int i = 0; i <= d + 1; ++i )
	{
		for ( int j = 0; j <= c + 1; ++j)
		{
			bmx[i][j] = bm[i][j];
		}
	}
}

void vebando1(int bmx[][100], int bm[][100], int d, int c)
{
	for ( int i = 0; i <= d; ++i )
	{
		cout << " \n\n\n\t\t\t";
		for ( int j = 0; j <= c ; ++j)
		{
			if (i == 0)
			{
				cout << "y" << j << "	";
			}
			else 
			{
				if (j == 0)
				cout << "x" << i << "	";
				else 
				{
					if (bm[i][j] == -1)
					{
						cout << "*" << "	";
					}
					else 
					{
						textcolor(bm[i][j] + 9);
						cout << bm[i][j] << "	";
						textcolor(7);
					}
				}
			}
		}
	}
}

void vebando2(int bmx[][100], int bm[][100], int d, int c)
{
	for ( int i = 0; i <= d; ++i )
	{
		cout << " \n\n\n\t\t\t";
		for ( int j = 0; j <= c ; ++j)
		{
			if (i == 0)
			{
				cout << "y" << j << "	";
				
			}
			else 
			{
				if (j == 0)
				cout << "x" << i << "	";
				else
				{
					if (bmx[i][j] == 10)
					{
						textcolor(bm[i][j] + 9);
						cout << bm[i][j] << "	";
						textcolor(7);
					}
					if (bmx[i][j] == -1)
					{
						cout << "?" << "	";
					}
					if (bmx[i][j] >= 0 && bmx[i][j] != 10)
					{
						cout << "?" << "	";
					}
				
				}
			}
		}
	}
}

void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

int kt(int bmx[][100], int d, int c )
{
	int dem = 0;
	for ( int i = 1; i <= d; ++i )
	{
		for ( int j = 1; j <= c; ++j)
		{
			if (bmx[i][j] == 10)
			dem ++;
		}
	}
	return dem;
}

void gioithieu()
{
	char a[100] = "Sinh vien: Tran Xuan Tuyen";
	char b[100] = "Lop      : K60-DA";
	int a1 = strlen(a);
	int b1 = strlen(b);
	textcolor(14);
	for ( int i = 0; i < a1; ++i)
	{
		cout << a[i];
		Sleep(100);
	}
	cout << "\n";
	for ( int i = 0; i < b1; ++i)
	{
		cout << b[i];
		Sleep(80);
	}
	
	cout << "\n";
	textcolor(12);
	Sleep(1000);
	cout << "Bai thuc hanh BT05: GAME DO MIN ";
	Sleep(1000);
	system("cls");
	
	textcolor(7);
}

