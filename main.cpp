#include <iostream>
#include <time.h>
#include "Boat.h"
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
using namespace std;
void ranking(Boat *boat);
int boats = 10;
int buoys = 10;
int last_rank = 0;
int main(int arg, char const *argv[]){
	srand(time(NULL));
	
	Boat *boat = new Boat[boats];
	Weather *weather = new Weather();
	Buoy *buoy = new Buoy[buoys];
	cout<<"Please click anything if you are ready to simulation ";
	getchar();
	for(int i  = 0; i<1000; ++i){
		system("clear");
		weather->refresh();
		for(int j = 0; j<boats; ++j){
			if(boat[j].id_buoy<buoys || boat[j].ruin)
			boat[j].refresh(weather, &buoy[boat[j].id_buoy]);
		}
		ranking(boat);
		int not_finish = 0;
		for(int j = 0; j<boats; ++j){
			if(boat[j].id_buoy==buoys){
				++boat[j].id_buoy;
				boat[j].distance=last_rank;
				++last_rank;
			}
			if(boat[j].id_buoy==buoys+1)
				cout<<j+1<<". Boat nr: "<<boat[j].id<<" finished."<<endl;
			else if(boat[j].ruin)
				cout<<"Boat nr: "<<boat[j].id<<" failed."<<endl;
			else{
			cout<<j+1<<". Boat nr: "<<boat[j].id<<".Distance to buoy nr "<<boat[j].id_buoy<<" : "<<boat[j].distance<<" miles with speed: "<<boat[j].speed<<endl;
			++not_finish;
			}
		}
		if(!not_finish)
			break;
			
		usleep(400000);
	}
}
void ranking(Boat *boat){
	for(int i=0;i<boats;i++)
    	for(int j=1;j<boats-i;j++) //pêtla wewnêtrzna
    	if(boat[j].id_buoy>boat[j-1].id_buoy){
      	  //zamiana miejscami
      	  Boat swap = *(boat+j);
      	  *(boat+j)=*(boat+(j-1));
      	  *(boat+(j-1))=swap;
		}
	for(int i=0;i<boats;i++)
  		for(int j=1;j<boats-i;j++) //pêtla wewnêtrzna
    	if(boat[j-1].distance>boat[j].distance&&boat[j].id_buoy==boat[j-1].id_buoy){
      	  //zamiana miejscami
      	  Boat swap = *(boat+j);
      	  *(boat+j)=*(boat+(j-1));
      	  *(boat+(j-1))=swap;
		}
}
