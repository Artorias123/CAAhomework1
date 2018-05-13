#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "math.h"
#include <ctime>
#include "readset.h"
#include "grid.h"
#include "calculator.h"
using namespace std;
double f(double t)
{
	double y;
	y = exp(-log(2)*pow((t-15) / 3, 2))/2;
	return (y);
}
int main()
{
	clock_t start_time = clock();
	read_doc A;
	cout<<"dx="<<A.dx<<'\t'<<"dt="<<A.dt<<endl;
	grid ex(A.b,A.e,A.g_n);
	for (unsigned i = 0; i < ex.g.size(); i++)
	{
		ex.g[i]=(f(ex.space()*i));
	}
	calculator c(ex,A.c,A.dt,A.t_s,A.ds);
	c.iteration();
	clock_t end_time = clock();
	cout << "time=" << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;
	return 0;
}