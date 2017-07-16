#pragma once
#include "Windows.h"
#include <string>
#include <iostream>

using namespace std;

enum color { default_color, blue, red, green, white, yellow };

class console
{
	private:
		HANDLE hScreenBuffer;
		CONSOLE_SCREEN_BUFFER_INFO screenInfo;
		void error_exit(const string& s) const;
	public:
		console(void);
		~console(void);
		void set_title(const wstring& s); //设置标题
		void set_dimensions(unsigned int width, unsigned int height); //变换窗口大小
		void set_cursor_position(const COORD& p);
		void set_cursor_color(color c); //设置颜色
		void clear(); //CLS
		void set_font(unsigned int width, unsigned int height);//变换字体大小
		void print_string(const char *ch, UINT count, UINT x, UINT y);//在坐标(x,y)处输出字符串ch,ch里有count个字符
		void print_char(const char ch, UINT count, UINT x, UINT y);//在坐标(x,y)处输出count个字符
};
