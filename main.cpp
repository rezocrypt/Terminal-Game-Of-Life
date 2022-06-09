#include <iostream>
#include "config.hpp"
#include "engine.hpp"

using namespace std;

int main() {
	// Clearing screen
	system("clear");
	config_settings(false);
	// Defining important variables
	int s = 0;
	int just = 12;
	int multiply = 0;
	string mode = "";	
	string shape = "";
	int width = config_settings(true)[1];
	int speed = config_settings(true)[2];
	int height = config_settings(true)[0];
	int mode_number = config_settings(true)[3];
	int color_number = config_settings(true)[6]-1;
	int alive_symbol_number = config_settings(true)[4]-1;
	int die_symbol_number =  config_settings(true)[5]-1;
	update(true, height, width, mode_number, color_number,
	alive_symbol_number, die_symbol_number, speed);
	// Defining characters of players
	while (true)
	{
		update(false,height, width, mode_number, color_number,
		alive_symbol_number,die_symbol_number,speed);
	}
}
