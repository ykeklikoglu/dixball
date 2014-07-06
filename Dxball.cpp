#include "Dxball.h"
#include <iostream>
#include<time.h>
using namespace std;
Dxball::Dxball(void)
{
	int t=0;
	ylnbas=22;
	score=0;
	for(int i=0;i<50;i++)
	{
		for(int m=0;m<50;m++){
			if(i>6&&i<10&&m>10&&m<40&&(i+m)%3)
				ekran[i][m]=1;
			else if(i==0)ekran[i][m]=5;
			else if(m==0)ekran[i][m]=4;
			else if(m==49)ekran[i][m]=6;
			else if(i==47&&(m>ylnbas-1&&m<ylnbas+15))ekran[i][m]=8;
			else	ekran[i][m]=0;}
	}
		iz.x=46;iz.y=26;
		yon=1;
		print();
}
int Dxball::getscore(void)const{
		return score;
	}
int Dxball::crash()const{
	if(ekran[iz.x][iz.y]==5){return 5;/*crsh_ustd();*/}
	else if(ekran[iz.x][iz.y]==4){return 4;/*crsh_sagd();*/}
	else if(ekran[iz.x][iz.y]==6){return 6;/*crsh_sold();*/}
	else if(ekran[iz.x][iz.y]==8){return 8;/*crsh_cbk();*/}
	else if(ekran[iz.x][iz.y]==1){return 1;/*crsh_tas(y);*/}
	else return 0;
}
int Dxball::way_yukarý_sag(void){
	iz.x--;iz.y++;
	if(ekran[iz.x][iz.y]!=0)
	return(1);
	print();
	return(0);
}
int Dxball::way_3yukarý_sag(){
	iz.x--;
	for(int i=1;i<4;i++)
	{
		iz.y++;
		if(ekran[iz.x][iz.y]!=0)
		{
			if(ekran[iz.x][iz.y-1]==8)
			{
				iz.x+1;iz.y++;
			}
			return 1;
		}
	}
	print();
	return 0;
}
int Dxball::way_yukarý_sol(void){
	iz.x--;iz.y--;
	if(ekran[iz.x][iz.y]!=0)
	return(1);
	print();
	return(0);
}
int Dxball::way_3yukarý_sol(void){
	iz.x--;
	for(int i=1;i<4;i++)
	{
		iz.y--;
		if(ekran[iz.x][iz.y]!=0)
			return 1;
	}
	print();
	return 0;
}
int Dxball::way_yukarý(void){
	iz.x--;
	if(ekran[iz.x][iz.y]!=0)
	return(1);
	print();
	return(0);
}
int Dxball::way_assagý_sol(void){
	iz.x++;iz.y--;
	if(ekran[iz.x][iz.y]!=0)
	return(1);
	print();
	return(0);
}
int Dxball::way_3assagý_sol(void)
{	
	iz.x++;
	for(int i=1;i<4;i++)
	{
		iz.y--;
		if(ekran[iz.x][iz.y]!=0)
		{
			if(ekran[iz.x][iz.y+1]==8)
			{
				iz.x+1;iz.y++;
			}
			return 1;	
		}
	}
	print();
	return 0;
}
int Dxball::way_assagý_sag(void){
	iz.x++;iz.y++;
	if(ekran[iz.x][iz.y]!=0)
	return(1);
	print();
	return(0);
}
int Dxball::way_3assagý_sag(){
	iz.x++;	
	for(int i=1;i<4;i++)
	{
		iz.y++;
		if(ekran[iz.x][iz.y]!=0)
			return 1;
	}
	print();
	return 0;
}
int Dxball::way_assagý(void){
	iz.x++;
	if(ekran[iz.x][iz.y]!=0)
	return(1);
	print();
	return(0);
}
void Dxball::crsh_sold(void){
	if(yon==1)
	{
		yon=2;
	}
	else if(yon==-1)
		yon=-2;
	else if(yon==7)
		yon=8;
	else { 

		yon=4;
	}
}
void Dxball::crsh_sagd(void){
	if(yon==4){
		yon=5;
	}
	else if(yon==8)
		yon=7;
	else if(yon==-2)
		yon=-1;
	else{
		yon=1;
	}
}
void Dxball::crsh_ustd(){
	if(yon==2||(iz.x==48&&iz.y==48))
		yon=4;
	else if(yon==1||(iz.x==1&&iz.y==1))
		yon=5;
	else if(yon==-2)
		yon=8;
	else if(yon==-1)
		yon=7;
	else
		yon=6;
	
}
void Dxball::crsh_cbk(){

	if(ylnbas+2>iz.y)
		yon=-2;
	else if(ylnbas+13<iz.y)
		yon=-1;
	else if(ylnbas+6>iz.y)
		yon=2;
	else if(ylnbas+8<iz.y)
		yon=1;
	else
		yon=3;
}
void Dxball::crsh_tas(){
	score++;
	ekran[iz.x][iz.y]=0;
	yon=rand()%6+1;
}
void Dxball::print(){
		ekran[iz.x][iz.y]=10;
	for(int c=1;c!=49;c++)
		if(c>=ylnbas&&c<ylnbas+16)			
			ekran[47][c]=8;
		else
			ekran[47][c]=0;
	for(int i=0;i<50;i++){
		for(int t=0;t<50;t++)
		{
			if(i==0)ekran[i][t]=5;
			if(t==0)ekran[i][t]=4;
			if(t==49)ekran[i][t]=6;
			if(ekran[i][t]==0)cout<<" ";
			if(ekran[i][t]==5||ekran[i][t]==4||ekran[i][t]==6)
				cout<<"#";
			if(ekran[i][t]==1)cout<<"*";
			if(ekran[i][t]==10)cout<<"O";
			if(ekran[i][t]==8){
				if(ylnbas+2>t)cout<<"/";else if(ylnbas+13<t)cout<<"\\";else cout<<"=";}
		}
		cout<<endl;
	}
	for(int s=0;s<2000000;s++){}
	system("CLS");
	ekran[iz.x][iz.y]=0;
	cout<<endl;
}
int Dxball::get_yon()const{
	return (yon);}
int Dxball::getfinish(){
	if(iz.x==49||score==39)
		return(0);
	else
		return(1);
}
void Dxball::set_yln(int m){
	if(ylnbas==1)
		{if (m==1)
		ylnbas+=m;}
	else if(ylnbas+16==49)
		{if(m==-1)
		ylnbas+=m;}
	else
		ylnbas+=m;
}