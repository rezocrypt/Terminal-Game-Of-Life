#include <iostream>
#include <unistd.h>

using namespace std;

// Function which will update screen
int matrix[1000][1000];
void update(bool default_mode, int height, int width, int mode_number,
	int color_number, int alive_symbol_number, 
	int die_symbol_number, int speed)
{
	system("clear");
	// Defining integer variables
	int rarity = 63;
	int symbol_number = 0;
	// Defining char list variables
	char* colors[6] = { "\033[1;34m", "\033[1;37m", "\033[1;31m", "\033[1;32m", "\033[1;33m", "\033[1;35m"};
	char* die_symbols[6] = { " ", "#", "O", "+", ".", "▅"};
	char* alive_symbols[6] = { "▅", "#", "O", "+", ".", " "};
	// Defining string variables
	string alive_symbol = alive_symbols[alive_symbol_number];
	string die_symbol = die_symbols[die_symbol_number];
	string color = colors[color_number];
	string mode = "";
	string shape = "";
	if (mode_number == 1)
	{
		mode = "B3/S23";
		shape = "random";
	}
	if (mode_number == 2)
	{
		mode = "B1/S012345678";
		shape = "alone";
	}
	if (mode_number == 3)
	{
		mode = "B4678/S35678";
		shape = "random";
	}
	// Generating matrix
	if (default_mode)
	{
		if (shape == "random")
		{
			for (int y = 0; y < height; y++)
			{
				for (int x = 0; x < width; x++)
				{
					if ((rand() % 100 + 1) > rarity)
					{
						symbol_number = 1;
					} else {
						symbol_number = 0;
					}
					matrix[y][x] = symbol_number;
				}
			}
		} else if (shape == "alone") {
			for (int y = 0; y < height; y++)
			{
				for (int x = 0; x < width; x++)
				{
					matrix[y][x] = 0;
				}
		}
		matrix[height / 2][width / 2] = 1;
		}
	}

	// Printing matrix
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (matrix[y][x] == 0)
			{
				cout << color <<  die_symbol;
			} else {
				cout << color << alive_symbol;
			}
		}
		cout << endl;
	}

	// Calculating
	int n = 0;
	int newmatrix[height][width];
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			newmatrix[y][x] = matrix[y][x];
		}
	}
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			try {
				if (newmatrix[y - 1][x - 1] == 1) {
					n++;
				}
			} catch (runtime_error err) {}
			try {
				if (newmatrix[y - 1][x] == 1) {
					n++;
				}
			} catch (runtime_error err) {}
			try {
				if (newmatrix[y - 1][x + 1] == 1) {
					n++;
				}
			} catch (runtime_error err) {}
			try {
				if (newmatrix[y][x - 1] == 1) {
					n++;
				}
			} catch (runtime_error err) {}
			try {
				if (newmatrix[y][x + 1] == 1) {
					n++;
				}
			} catch (runtime_error err) {}
			try {
				if (newmatrix[y + 1][x - 1] == 1) {
					n++;
				}
			} catch (runtime_error err) {
			}
			try {
				if (newmatrix[y + 1][x] == 1) {
					n++;
				}
			} catch (runtime_error err) {}
			try {
				if (newmatrix[y + 1][x + 1] == 1) {
					n++;
				}
			} catch (runtime_error err) {}
			if (mode == "B3/S23") {
				if (n < 2) {
					matrix[y][x] = 0;
				} else if (n == 3) {
					matrix[y][x] = 1;
				} else if (n > 3) {
					matrix[y][x] = 0;
				}
			}
			if (mode == "B1/S012345678") {
				if (n == 1) {
					matrix[y][x] = 1;
				}
			}
			if (mode == "B4678/S35678") {
				if (n == 4 || n == 6 || n == 7 || n == 8) {
					matrix[y][x] = 1;
				} else if (n == 3 || n == 5 || n == 6 ||
					n == 7 || n == 8) {} else {
					matrix[y][x] = 0;
				}
			}
			n = 0;
		}
		
	}
	usleep(speed);
}

