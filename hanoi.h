/*1953609 软件 王灏廷*/
#pragma once

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */
char menu(void);
void hanoi(int n, char src, char tmp, char dst, char sign);
void initial(char num);
void move(char src, char dst);
void print();
void print_move(int n, char src, char dst, char sign);
void print_move_one(int n, char src, char dst, char sign);
void print_tower(char sign);
void transverse(int n, char src, char tmp, char dst,char sign);
void wait();
void print_disk();
void print_disk_ini(char src, int sum);
void disk_move(int n, char src, char dst, char sign);
