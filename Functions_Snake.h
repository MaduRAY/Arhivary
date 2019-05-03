#pragma once
//Версия от 12.04.19
#include "pch.h"				 //Прорамма запускатеся, но есть ошибки кода
#include <iostream>		//1Возможно, неверно описан процесс движения хвоста змейки, 2Выдается правая стенка при увеличении хвоста, 3Завершается программа после увеличения хвоста(fixed)
#include <conio.h>		    //2: отъезжает стенка. Возможно, связано с тем, что символ хвоста вставляется в строку, поэтому она увеличивается
#include "cstdlib" 
#include "ctime" 
#include <windows.h> 

using namespace std;

/*bool End;
const int wid = 50;
const int hei = 25;
int x, y, Fx, Fy, score, nT;
int tX[125], tY[125];
/*enum vec {
    Stop = 0, Up, Down, Right, Left
    };
vec way;*/

void Start (bool End, enum , int x, int y, int Fx, int fY, int score)

void Map (int: tX[], tY[], score,  wid, bool T )

void Input (enum vec )

void Mechanics (enum vec, int pX = tX[0], pY = tY[0], p2X, p2Y, wid, hei, Fx, Fy)
