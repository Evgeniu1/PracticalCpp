#ifndef TERM_PAPER_MENU_H
#define TERM_PAPER_MENU_H
#include "Container.h"
#include <fstream>

class Menu
{
private:
	List container;
public:
	Menu();
	virtual ~Menu();
	static Menu& menu();
	void  run();
	void create_turbojet();
	void create_piston();
	void show_all();
	void remove_all();
	void read_file();
	void write_file();
	void search_obj();
	void total_power();
};

#endif
