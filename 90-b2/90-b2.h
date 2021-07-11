/*1953609 软件 王灏廷*/
#pragma once
int find_max(int moto[][10], int row, int column);//找到数组最大值
int random(int max);//随机值函数
void find_res(int moto[][10], int row, int column, int findmoto[][10], int x, int y, int res);//所有找到相邻的相等数字
void find_res_rec(int moto[][10], int row, int column, int findmoto[][10], int x, int y, int res);
int merge_res(int moto[][10], int row, int column, int findmoto[][10], int x, int y);
int judge_merge(int moto[][10], int row, int column);
int judge_adjoin(int moto[][10], int row, int column, int x, int y);
int score(int res, int merge_sum);
void down_arr(int moto[][10], int row, int column);
void end(int column);
void print_removeZero(int moto[][10], int row, int column, int findmoto[][10]);
void print_res(int moto[][10], int row, int column, int findmoto[][10], int tag);
void print_moto(int moto[][10], int row, int column);//打印数组
void set_arr(int moto[][10], int row, int column);
void set_zero(int moto[][10], int row, int column);
int cmd_opr(int moto[][10], int row, int column, int findmoto[][10], int x, int y, int res, int target, int score_sum);
void initial(char sign);

//Graph
void drawborder(int row, int column, bool haveBorder);
void drawCard(int card_y, int card_x, int value, bool haveBorder, int bgcolor = -1, int fgcolor = -1);
void setbottonCur(bool set = false, int value = 0);
void getGraphSizeInfo(int row, int column, bool haveBorder, int& width, int& heigh);
void initial_graph(char sign);
void dropCardSmooth(int card_x, int card_y, int value);//默认有框的,原色的,仅下降一次
void downAnime(int moto[][10], int findmoto[][10], int row, int column);//默认有框的