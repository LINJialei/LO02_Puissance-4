#include "StdAfx.h"
#include"Game_ui.h"

using namespace std;

game_ui::game_ui(const unsigned int &_w_ui, const unsigned int &_h_ui, const unsigned int &_w_font, const unsigned int &_h_font)
{
	Game = new console;
	Game->set_title(L"New Game");
	Game->set_font(_w_font, _h_font);
	Game->set_dimensions(_w_ui, _h_ui);//50,30
	this->set_up();
}

game_ui::~game_ui()
{
	delete Game;
}

void game_ui::set_up()
{
	//22
    
	Game->set_cursor_color(blue);
	unsigned int i, j;
	for (i = 0; i < 19; i++)
	{
		if (i % 3 == 0)
		{
			Game->print_char(178, 22, 0, i);
		}
		else
		{
			for (j = 0; j < 22; j++)
				if (j % 3 == 0) 
					Game->print_char(178, 1, j, i);
				else
					Game->print_char(' ', 1, j, i);
		}
	}
	Game->set_cursor_color(green);
	Game->print_char(178, 22, 0, 19);
	Game->print_char(178, 22, 0, 28);
	/*Game->set_cursor_color(white);
	cout << "joueur ";
	Game->set_cursor_color(yellow);
	cout << "jaune"<<endl;
	Game->set_cursor_color(white);
	cout << "colonne :" << endl;
	cout << endl;
	cout << "votre choix (1 2 3 4 5 6 7)?" << endl;
	COORD pos;
	pos.X = 0;
	pos.Y = 25;
	Game->set_cursor_position(pos);*/

}
void game_ui::clean_text()
{
	unsigned int i;
	for (i = 20; i <= 27; i++)
		Game->print_string("                      ", 22, 0, i);
}
char game_ui::first()
{
	Game->set_cursor_color(white);
	Game->print_string("Welcome!", 8, 7, 20);
	Game->print_string("1.Two person", 12, 0, 21);
	Game->print_string("2.One person", 12, 0, 22);
	Game->print_string("3.DEMO", 6, 0, 23);
	Game->print_string("Choose 1, 2 or 3 to start the game", 34, 0, 24);
	char choose='0';
	COORD pos;
	pos.X = 0;
	pos.Y = 26;
	while (!(choose >= '1' && choose <= '3'))
	{
		Game->set_cursor_position(pos);
		choose=_getch();
		if (!(choose >= '1' && choose <= '3'))
		{
			unsigned int i;
			for (i = 0; i < 5; i++)
			{
				Game->print_string("                                  ", 34, 0, 24);
				Sleep(200);//滞留200毫秒
				Game->print_string("Choose 1, 2 or 3 to start the game", 34, 0, 24);
				Sleep(200);
			}
		}
	}
	return choose-48;
}

void game_ui::play_text(const char &stat, const char &last, const char(&which_can)[7])//1:ª∆£¨2£∫∫Ï£¨-1£∫ª∆win£¨-2£∫∫Ïwin, ˝◊È£¨ƒƒ“ª∏ˆø…∑≈£¨-1≤ªø…£¨0ø…
{
	COORD pos;
	unsigned int i;
	switch(stat)
	{
	case yellow:
		pos.X = 0;
		pos.Y = 20;
		Game->set_cursor_position(pos);
		Game->set_cursor_color(white);
		cout << "Player ";
		Game->set_cursor_color(yellow);
		cout << "Yellow" << endl;
		Game->set_cursor_color(white);
		cout << "Last Column : ";
		if (last == -1)
			cout << "No" << endl;
		else
			cout << last << endl;
		cout << "You choose ( ";
		for (i = 0; i < 7; i++)
			if (which_can[i] == 0) cout << i + 1 << ' ';
		cout << " )?";
		pos.X = 0;
		pos.Y = 26;
		Game->set_cursor_position(pos);
		break;
	case red:
		pos.X = 0;
		pos.Y = 20;
		Game->set_cursor_position(pos);
		Game->set_cursor_color(white);
		cout << "Player ";
		Game->set_cursor_color(red);
		cout << "Red" << endl;
		Game->set_cursor_color(white);
		cout << "Last Column : ";
		if (last == -1)
			cout << "No" << endl;
		else
			cout << last << endl;
		cout << "You choose ( ";
		for (i = 0; i < 7; i++)
			if (which_can[i] == 0) cout << i + 1 << ' ';
		cout << " )?";
		pos.X = 0;
		pos.Y = 26;
		Game->set_cursor_position(pos);
		break;
	case -1:
		pos.X = 0;
		pos.Y = 20;
		Game->set_cursor_position(pos);
		Game->set_cursor_color(yellow);
		cout << "Yellow Win! " << endl;
		Game->set_cursor_color(white);
		cout << "Again?(Y or N)" << endl;
		pos.X = 0;
		pos.Y = 26;
		Game->set_cursor_position(pos);
		break;
	case -2:
		pos.X = 0;
		pos.Y = 20;
		Game->set_cursor_position(pos);
		Game->set_cursor_color(red);
		cout << "Red Win! " << endl;
		Game->set_cursor_color(white);
		cout << "Again?(Y or N)" << endl;
		pos.X = 0;
		pos.Y = 26;
		Game->set_cursor_position(pos);
		break;
	case -3:
		pos.X = 0;
		pos.Y = 20;
		Game->set_cursor_position(pos);
		Game->set_cursor_color(red);
		cout << "Draw! " << endl;
		Game->set_cursor_color(white);
		cout << "Again?(Y or N)" << endl;
		pos.X = 0;
		pos.Y = 26;
		Game->set_cursor_position(pos);
		break;
	}
}

void game_ui::place_it(const char &stat, const char &column, const char &end)//stat£∫1 ª∆£¨2∫Ï£¨column£∫ƒƒ“ª¡–(0~6),end£∫¬‰µΩƒƒ¿Ô(0,1,2,3,4,5)
{
	COORD pos;
	pos.X = 0;
	pos.Y = 26;
	color temp;
	if (stat == 5) temp = yellow; else temp = red;
	unsigned int i;
	for (i = 0; i < (6 - end); i++)
	{
		Game->set_cursor_color(temp);
		Game->print_char(254, 2, 3 * column + 1, 3 * i + 1);
		Game->print_char(254, 2, 3 * column + 1, 3 * i + 2);
		Game->set_cursor_position(pos);
		if (i != 5 - end)
		{
			Sleep(100);
			Game->print_char(' ', 2, 3 * column + 1, 3 * i + 1);
			Game->print_char(' ', 2, 3 * column + 1, 3 * i + 2);
			Game->set_cursor_position(pos);
			Sleep(100);
		}
	}
}

void game_ui::error(const string &err)
{
	COORD pos;
	pos.X = 0;
	pos.Y = 26;
	Game->set_cursor_position(pos);
	cout << "ERROR:" << err << endl;
	Sleep(500);
	Game->print_string("                                  ", 34, 0, 26);
	Game->set_cursor_position(pos);
}

void game_ui::give_up(color what)
{
	COORD pos;
	pos.X = 0;
	pos.Y = 26;
	Game->set_cursor_position(pos);
	if (what == yellow) cout << "Yellow "; else cout << "Red ";
	cout << "Give Up!" << endl;
	Game->set_cursor_position(pos);
}