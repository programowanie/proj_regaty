#include "Boat.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
int Boat::counter = 0;
Boat::Boat(){
	id = counter++;
	length = rand()%250+450; 
	weight = length * (float)((float)(rand()%70+30)/100);
	s_size = length * (float)((float)(rand()%40+40)/(float)1000);
	c_skill = rand()%4+1;
	X_position = 5000;
	Y_position = 5000;
	id_buoy = 0;
	ruin = false;
	cout<<"New boat number: "<<id<<endl
	<<"length: "<<length<<"cm"<<endl
	<<"weight: "<<weight<<"kg"<<endl
	<<"sail size: "<<s_size<<"m2"<<endl
	<<"crew skill mark: "<<c_skill<<endl;
}
void Boat::refresh(Weather* weather, Buoy* buoy){
	int X_length = buoy->X_position-X_position;
	int Y_length = Y_position-buoy->Y_position;
	float course = atan((float)Y_length/(float)X_length)*(float)180/(float)M_PI;
	if(X_length<0)
		course+=180;
	if(Y_length<0&&X_length>0)
		course+=360;	
	//Obliczony optymalny kurs na boj� - teraz sprawdzam czy mog� p�yn��, poniewa� idealnie pod wiatr nie da si� p�yn��
	if(abs(course-weather->alfa_now)<30||abs(course-weather->alfa_now)>330){
		course = course>330?course-360:course;		
		float wind = weather->alfa_now>330?weather->alfa_now-360:weather->alfa_now;
		if(course>wind)
			course = wind+30;
		else
			course = wind-30;
		if(course>360)
			course-=360;
		if(course<0)
			course+=360;
	}
		speed = abs(course-weather->alfa_now)>180?(360-abs(course-weather->alfa_now))/(float)180:(abs(course-weather->alfa_now))/(float)180;
		speed*=weather->Wind_now;
		speed=((float)((float)s_size*3/(float)weight)*0.2*(float)speed)+speed*0.8; //wp�yw stosunku wielko�ci �agla do ci�aru ��dki
		speed=(0.9*speed)+(0.1*speed*c_skill/5); //wp�yw umiej�tno�ci za�ogi
		if(weather->Sea_now+c_skill-5>7){	//wywr�cenie si� ��dki
			ruin = true;
			id_buoy = 0;
			distance = 0;
			return;}
		speed=(0.9*speed)+(speed*0.5/(abs((weight/10)-weather->alfa_now)+1)); //wp�yw stosunku si�y wiatru do masy ��dki 
		/*jak �atwo zauwa�y� pr�dko�� ��dki w ekstremalnym przypadku mo�e by� wi�ksza od pr�dko�ci wiatru, jednak zdarzaj� si� 
		takie sytuacje na regatach) */
		int last_X = X_position;
		int last_Y = Y_position;
		Y_position-=sin(course*M_PI/180)*speed*50;
		X_position+=cos(course*M_PI/180)*speed*50;
		if((last_Y<buoy->Y_position&&Y_position>=buoy->Y_position ||
			last_Y>buoy->Y_position&&Y_position<=buoy->Y_position) &&
			(last_X<buoy->X_position&&X_position>=buoy->X_position ||
			last_X>buoy->X_position&&X_position<=buoy->X_position))
				id_buoy++;
		X_length = buoy->X_position-X_position;
		Y_length = Y_position-buoy->Y_position;
		distance=sqrt(X_length*X_length+Y_length*Y_length);
		distance/=50;
}
