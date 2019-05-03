#pragma once
//Версия от 12.04.19
#include "pch.h"				 //Прорамма запускатеся, но есть ошибки кода
#include <iostream>		//1Возможно, неверно описан процесс движения хвоста змейки, 2Выдается правая стенка при увеличении хвоста, 3Завершается программа после увеличения хвоста(fixed)
#include <conio.h>		    //2: отъезжает стенка. Возможно, связано с тем, что символ хвоста вставляется в строку, поэтому она увеличивается
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

void Start () {	    //Функция определяет координаты поля, фруков и задает контроьную переменную End
    End = false;
    way = Stop;
    x = wid / 2 + 1;
    y = hei / 2 + 1;
    Fx = 1 + rand () % wid;
    Fy = 1 + rand () % hei;
    score = 0;
    }

void Map () {		    //Функция отвечает за заполнение поля (фрукты, змейку, хвост, количество очков)

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

void Input () {	    //Обработка ввода/направения движения
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

void Mechanics () {		   //Функция описывает процесс изменений на поле
    int pX = tX[0], pY = tY[0], p2X, p2Y;
    tX[0] = x;
    tY[0] = y;
    for ( int i = 1; i < nT; i++ ) {	//Механика движения хвоста змейки (ошибочна)
	   p2X = tX[i];
	   p2Y = tY[i];
	   tX[i] = pX;
	   tY[i] = pY;
	   pY = p2Y;
	   pX = p2X;
	   }
    switch ( way ) {    //Обработка ввода

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

    if ( x >= wid - 1 ) {   //Механика прохода змейкой чере стенки
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

		  if ( x == Fx || y == Fy ) {	 //Сбор фруктов и увеличение очков
			 score += 10;
			 Fx = 1 + rand () % wid;
			 Fy = 1 + rand () % hei;
			 nT++;
			 }
		  int main{

			 }
    }