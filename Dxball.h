#ifndef DXBALL
#define DXBALL
#include <iostream>
#include<string>
struct dxbll{
	int x;
	int y;
};

class Dxball
{
private:
	struct dxbll iz;
	int ekran[50][50];
	int score;
	int yon;
	int ylnbas;
public:
	Dxball(void);
	void set_yln(int);
	int getscore(void)const;
	void print(void);
	int way_yukar�_sag (void);
	int way_3yukar�_sag(void);
	int way_yukar�_sol (void);
	int way_3yukar�_sol(void);
	int way_assag�_sol (void);
	int way_3assag�_sol(void);
	int way_assag�_sag (void);
	int way_3assag�_sag(void);
	int way_assag�(void);
	int way_yukar�(void);
	int crash()const;
	void crsh_sold ();
	void crsh_sagd ();
	void crsh_ustd ();
	void crsh_cbk ();
	void crsh_tas ();
	int getfinish();
	int get_yon(void)const;
};
#endif