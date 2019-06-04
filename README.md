# 一维对流方程
完整题目要求在pdf中  
空间离散格式：11点4阶DRP格式  
时间推进格式：4步3阶LDDRK格式  
  
直接make即可编译生成可执行文件  
  
set文件中控制参数为：  
c(对流方程系数\对流速度):value  
begin(计算域起始坐标):value  
end(计算域终止坐标):value  
dx(空间步长):value  
dt(时间步长):value  
total_step(计算步数):value  
t(终止时间):value  
grid_number(网格数量):value  
total_step和t具体怎么判断结束我忘了。。。。。。  
grid_number和dx、begin、end怎么分配网格我也忘了。。。。  
尽量都手动匹配吧  
  
边界条件为周期边界条件，出场按照题目要求给出，在main.cpp可以修改  
