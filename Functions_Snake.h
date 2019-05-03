#pragma once
//������ �� 12.04.19
#include "pch.h"				 //�������� �����������, �� ���� ������ ����
#include <iostream>		//1��������, ������� ������ ������� �������� ������ ������, 2�������� ������ ������ ��� ���������� ������, 3����������� ��������� ����� ���������� ������(fixed)
#include <conio.h>		    //2: ��������� ������. ��������, ������� � ���, ��� ������ ������ ����������� � ������, ������� ��� �������������
#include "cstdlib" 
#include "ctime" 
#include <windows.h> 

using namespace std;

bool End;
const int wid = 50;
const int hei = 25;
int x, y, Fx, Fy, score, nT;
int tX[125], tY[125];
enum vec {
    Stop = 0, Up, Down, Right, Left
    };
vec way;

void Start () {	    //������� ���������� ���������� ����, ������ � ������ ���������� ���������� End
    End = false;
    way = Stop;
    x = wid / 2 + 1;
    y = hei / 2 + 1;
    Fx = 1 + rand () % wid;
    Fy = 1 + rand () % hei;
    score = 0;
    }

void Map () {		    //������� �������� �� ���������� ���� (������, ������, �����, ���������� �����)

    system ( "cls" );

    cout << "|";

    for ( int i = 1; i < wid; i++ ) {
	   cout << "~";
	   }
    cout << "|" << endl;

    for ( int i = 0; i < hei; i++ ) {
	   for ( int j = 0; j < wid; j++ ) {
		  if ( j == 0 || j == wid - 1 )
			 cout << "|";
		  if ( i == y && j == x )
			 cout << "O";
		  else if ( i == Fy && j == Fy )
			 cout << "F";
		  else {
			 bool T = false;
			 for ( int k = 0; k < nT; k++ ) {
				if ( tX[k] == j && tY[k] == i ) {
				    T = true;
				    cout << "o";
				    }
				}
			 if ( T = false );
			 cout << " ";
			 }
		  }
	   cout << endl;
	   }

    for ( int i = 0; i < wid + 1; i++ ) {
	   cout << "~";
	   }
    cout << endl;
    cout << "Score: " << score << endl;
    }

void Input () {	    //��������� �����/���������� ��������
    if ( _kbhit () ) {
	   switch ( _getch () ) {
			 case 'w':
			 way = Up;
			 break;

			 case 's':
			 way = Down;
			 break;

			 case 'a':
			 way = Left;
			 break;

			 case 'd':
			 way = Right;
			 break;

			 case 'x':
			 End = true;
			 break;

		  }
	   }
    }

void Mechanics () {		   //������� ��������� ������� ��������� �� ����
    int pX = tX[0], pY = tY[0], p2X, p2Y;
    tX[0] = x;
    tY[0] = y;
    for ( int i = 1; i < nT; i++ ) {	//�������� �������� ������ ������ (��������)
	   p2X = tX[i];
	   p2Y = tY[i];
	   tX[i] = pX;
	   tY[i] = pY;
	   pY = p2Y;
	   pX = p2X;
	   }
    switch ( way ) {    //��������� �����

		  case Up:
		  y--;
		  break;

		  case Down:
		  y++;
		  break;

		  case Right:
		  x++;
		  break;

		  case Left:
		  x--;
		  break;
	   }

	   /*if ( x > wid || x < 0 || y > hei || y < 0 ) {
	   End = true;
	   }*/

    if ( x >= wid - 1 ) {   //�������� ������� ������� ���� ������
	   x = 0;
	   } else if ( x < 0 ) {
		  x = wid - 2;
		  }

	   if ( y >= hei - 1 ) {
		  y = 0;
		  } else if ( y < 0 ) {
			 y = hei - 2;
			 }

		  for ( int i = 0; i < nT; i++ ) {
			 if ( y == tY[i] && x == tX[i] ) {
				End = true;
				}
			 }

		  if ( x == Fx || y == Fy ) {	 //���� ������� � ���������� �����
			 score += 10;
			 Fx = 1 + rand () % wid;
			 Fy = 1 + rand () % hei;
			 nT++;
			 }
		  int main{

			 }
    }