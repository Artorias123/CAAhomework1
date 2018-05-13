#include "calculator.h"
#include "grid.h"
#include "math.h"
using namespace std;
#define v 0.0001
const extern double l[5] = { 0.87563358536375269299268627610429, -0.29038555010154020074786753253633, 0.093221900544420204523311219557013, -0.022046226961042944931471466630933, 0.0027313442100477749318001993642138 },
d[6] = { 0.50246367223754133548206491132391, -0.26772502992033224087730250684487,
0.00028841804131356446932391561658651, 0.014279610565243077248401912076978
- 0.0015202541600842322103563712785399, 0.0034454193550891636289005947678938 },
b[4] = { 0.159177852630552, 0.333333333333333, 0.348310961405563, 0.159177852630552 },
a[4] = { 0, 0.5, 0.5, 1 };


int mod(int a, int b)
{
 return (a + b) % b;
}
calculator::calculator(grid &x,double ic, double dt, unsigned m,unsigned autosave,double it)
{
	p=&x;
	c=ic;
	d_t=dt;
	t=it;
	total_step=m;
	ds=autosave;
}
void calculator::save()
{
	ofstream sfout("save.dat",ios::out|ios::trunc);
	sfout<<t<<endl;
	p->save(sfout);
}
void calculator::load(double ic, double dt, unsigned m,unsigned autosave=0)
{
	ifstream lfin("save.dat",ios::in);
	lfin>>t;
	p->load(lfin);
	c=ic;
	d_t=dt;
	total_step=m;
	ds=autosave;
}
vector<double> calculator::cal_k(vector<double> &x,const vector<double> &k,unsigned ki)
{
	unsigned n=p->g.size();
	double dx=p->space();
	vector<double> y(n);
	double temp[2];
	for(unsigned i = 0; i < 5; i++)
	{
		temp[0] = 0; temp[1] = d[0] * (x[i] + d_t*a[ki] * k[i]);
		double tem[2] = { 0,d[0] * (x[n - i - 1] + d_t*a[ki] * k[n - i - 1]) };
		for(int j = 1; j < 6; j++)
		{
			temp[0]+=l[j-1]*(x[i+j]+d_t*a[ki]*k[i+j]-x[mod(i-j,n)]-d_t*a[ki]*k[mod(i-j,n)]);
			temp[1]+=d[j]*(x[mod(i-j,n)]+d_t*a[ki]*k[mod(i-j,n)]+x[i+j]+d_t*a[ki]*k[i+j]);
			tem[0]+=l[j-1]*(x[mod(n-i+j-1,n)]+d_t*a[ki]*k[mod(n-i+j-1,n)]-x[n-i-j-1]-d_t*a[ki]*k[n-i-j-1]);
			tem[1]+=d[j]*(x[mod(n-i+j-1,n)]+d_t*a[ki]*k[mod(n-i+j-1,n)]+x[n-i-j-1]+d_t*a[ki]*k[n-i-j-1]);
		}
		y[i]=-temp[0]/dx-v*temp[1]/(dx*dx);
		y[n-i-1]=-tem[0]/dx-v*tem[1]/(dx*dx);
	}
	for(unsigned i = 5; i < n-5; i++)
	{
		temp[0] = 0; temp[1] = d[0] * (x[i] + d_t*a[ki] * k[i]);
		for(int j = 1; j < 6; j++)
		{
			temp[0]+=l[j-1]*(x[i+j]+d_t*a[ki]*k[i+j]-x[i-j]-d_t*a[ki]*k[i-j]);
			temp[1]+=d[j]*(x[i-j]+d_t*a[ki]*k[i-j]+x[i+j]+d_t*a[ki]*k[i+j]);
		}
		y[i]=-temp[0]/dx-v*temp[1]/(dx*dx);
	}
	return y;
}
void calculator::advance()
{
	unsigned n=p->g.size();
	vector<vector<double>> k(4,vector<double>(n));
	k[0]=cal_k(p->g,p->g,0);
	for(unsigned i = 1; i < 4; i++)
	{
		k[i]=cal_k(p->g,k[i-1],i);
	}
	for(unsigned i = 0; i < n; i++)
	{
		p->g[i]+=d_t*(b[0]*k[0][i]+b[1]*k[1][i]+b[2]*k[2][i]+b[3]*k[3][i]);
	}
}
void calculator::iteration(unsigned s)
{
	ofstream fout("result.dat",ios::out|ios::trunc);
	int h = 1 / d_t, c = 0.1 / p->space(), k = 0;
	if (c <= 1)
	{
		c = 1;
	}
	for (; step < total_step;)
	{
		advance();
		//x.result(c);
		if (step % h == h - 1)  p->result(fout,c);
		//if (step == total_step - 1)  x.result(1);
		step++;
		t = t + d_t;
	}
	fout.close();
}