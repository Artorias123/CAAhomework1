#ifndef grid_H
#define grid_H
#include<vector>
#include<string>
#include<fstream>
using namespace std;
class grid
{
public:
	vector<double> g;
	double begin,end;
	grid(double begin, double end, unsigned m);
	grid(grid &x);
	grid(){};
	~grid(){};
	double space();
	int initial(grid &x);
	int initial(double* a,unsigned m);
	void prt_all(ofstream fout);
    void show();
	void result(ofstream &fout,int m = 1);
	void save(ofstream &fout);
	void load(ifstream &fin);
};
#endif 