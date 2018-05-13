#ifndef calculator_H
#define calculator_H
#include<vector>
#include<string>
#include<fstream>
#include"grid.h"
using namespace std;
class calculator
{
public:
	unsigned step = 0, total_step,ds;
	double c, d_t, t;
    grid *p;
	calculator(grid &x,double ic, double dt, unsigned m,unsigned autosave,double it=0);
	~calculator(){};
	void save();
	void load(double ic, double dt, unsigned m,unsigned autosave);
	vector<double> cal_k(vector<double> &x,const vector<double> &k,unsigned ki);
	void advance();
	void iteration(unsigned s = 0);
};
#endif 