#include "readset.h"
#include <string>
read_doc::read_doc()
{
	std::ifstream fin("set.txt",std::ios::in);
	std::string tem;
	bool n=0,nt=0;
	while(std::getline(fin,tem))
	{
		if(!tem.empty())
		{
			std::string judg,cont;
            unsigned judg_p,r=tem.find(" ");
            while(r!=-1)
            {
                tem.replace(r,1,"");
                r=tem.find(" ");
            }
            judg_p=tem.find(":")+1;
            judg=tem.substr(0,judg_p-1);
			cont=tem.substr(judg_p);
			const char *p=cont.data();
            if(judg=="c") c=atof(p);
			else if(judg=="dt") dt=atof(p);
			else if(judg=="t") t=atof(p);
			else if(judg=="total_step") {t_s=atoi(p);nt=1;}
			else if(judg=="auto_save") ds=atoi(p);
			else if(judg=="dx") dx=atof(p);
			else if(judg=="begin") b=atof(p);
			else if(judg=="end") e=atof(p);
			else if(judg=="grid_number") {g_n=atoi(p);n=1;}
		}
	}
	if(!n)
	{
		g_n=(e-b)/dx;
	}
	else{dx=(e-b)/g_n;}
	if(!nt)
	{
		t_s=t/dt;
	}
	else{t=t_s*dt;}
}