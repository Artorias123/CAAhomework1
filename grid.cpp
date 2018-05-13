#include "grid.h"
using namespace std;
grid::grid(double b, double e, unsigned m){
	unsigned n = m + 1;
    begin=b;end=e;
	g.resize(n);
	for (int i = 0; i < n; i++)
	{
		g[i]=begin + i*(end - begin) / m;
	}
}
grid::grid(grid &x){
	g = x.g;
	begin = x.begin;
    end=x.end;
}
double grid::space(){
	return (end-begin)/(g.size()-1);
}
int grid::initial(grid &x){
	g = x.g;
	begin = x.begin;
    end =x.end;
	return 0;
}
int grid::initial(double* a,unsigned m){
	for (unsigned i = 0; i < m; i++)
	{
		g[i] = a[i];
	}
	return 0;
}
void grid::result(ofstream &fout,int m){
	for (unsigned i = 0; i < g.size(); i=i+m)
	{
		fout << g[i] << '\t';
	}
	fout << endl;
}
void grid::save(ofstream &fout){
    fout<<begin<<'t'<<end<<endl;
    for (unsigned i = 0; i < g.size(); i=i)
	{
		fout << g[i] << '\t';
	}
	fout << endl;
}
void grid::load(ifstream &fin){
    fin>>begin>>end;
    for (unsigned i = 0; i < g.size(); i=i)
	{
		fin >> g[i];
	}
}
