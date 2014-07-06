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
	int way_yukarý_sag (void);
	int way_3yukarý_sag(void);
	int way_yukarý_sol (void);
	int way_3yukarý_sol(void);
	int way_assagý_sol (void);
	int way_3assagý_sol(void);
	int way_assagý_sag (void);
	int way_3assagý_sag(void);
	int way_assagý(void);
	int way_yukarý(void);
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