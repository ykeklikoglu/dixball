#include "Dxball.h"
#include <iostream>
#include<conio.h>
#include<time.h>
using namespace std;
int main(void){
	srand(time(NULL));
	system("color 4F");
	Dxball game;
	int a,y,s(0);
	char c;
	do{
		if(kbhit())
			{
				c=getch();
				if(c=='a')
					game.set_yln(-1);
				else if(c=='d')
					game.set_yln(1);
			}
		if(s==0)
		{
			switch(game.get_yon())
			{
				case-2:s=game.way_3yukarý_sol();break;
				case-1:s=game.way_3yukarý_sag();break;
				case 1:s=game.way_yukarý_sag();break;
				case 2:s=game.way_yukarý_sol();break;
				case 3:s=game.way_yukarý();break;
				case 4:s=game.way_assagý_sol();break;
				case 5:s=game.way_assagý_sag();break;
				case 6:s=game.way_assagý();break;
				case 7:s=game.way_3assagý_sag();break;
				case 8:s=game.way_3assagý_sol();break;
			}
		}
		else{
			a=game.crash();
			switch(a){
			case 5:game.crsh_ustd();break;
			case 4:game.crsh_sagd();break;
			case 6:game.crsh_sold();break;
			case 8:game.crsh_cbk();break;
			case 1:game.crsh_tas();break;
			}s=0;
		}
	}while(game.getfinish());
	do{
		if(game.getscore()==39)cout<<"Tebrikler"<<endl<<"Score:39"<<endl<<"cikis icin c ye basin"<<endl;
		else
		cout<<"oyun bitti."<<endl<<"score="<<game.getscore()<<endl<<"cikis icin c ye basin"<<endl<<endl<<endl<<endl;
	cin>>c;
	}while(c!='c');
}
