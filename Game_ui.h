#pragma once
#include"console.h"
#include<iostream>
#include<string>

//建议使用以下
//system("mode con cols=22 lines=30"); 在使用之前一定先写这行
//game_ui new_game(22, 30, 8, 8);//题目标准

class game_ui
{
private:
	console *Game;
public:
	game_ui(const unsigned int &_w_ui, const unsigned int &_h_ui, const unsigned int &_w_font, const unsigned int &_h_font);//界面宽，高，字体宽，高
	~game_ui();
	void set_up();//画游戏界面
	char first();//显示欢迎界面，并返回用户选择的值，1，2，3.
	void clean_text();//清除游戏文字显示区域
	void play_text(const char &stat, const char &last, const char(&which_can)[7]);//显示提示文字，1:黄，2：红，-1：黄win，-2：红win,数组，哪一列可放，-1不可，0可
	void place_it(const char &stat, const char &column, const char &end);//stat：1 黄，2红，column：哪一列(0~6),end：落到哪里(0,1,2,3,4,5)
	void error(const string &err);//在文字区域提示错误，传入字符串。
	void give_up(color what);//认输，what参数为哪一方，yellow或者red
};

