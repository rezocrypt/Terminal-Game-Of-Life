#include <iostream>

using namespace std;

// Defining global variables
int height = 23;
int width = 80;
int speed = 20000;
int mode_number = 1;
int alive_symbol = 1;
int die_symbol = 1;
int color_number = 5;

// Function which will clear screen
void clear()
{
	system("clear");
}

// This unction returns if player wants to continue with default settings or no 
int config_choose_output()
{
	clear();
	int config_choice = 0;
	cout << "\033[0;33mEnter choice:\n" << endl;
	cout << "\033[0;32mDefaut settings 24x80 (1)" << endl;
	cout << "\033[0;32mConfig settings (2)" << endl;
	cin >> config_choice;
	clear();	
	return config_choice;
}

// Function for getting row count from user
int get_row_count()
{
	int height;
	clear();
	cout << "\n\033[0;33mCount of rows:\t\033[0;32m";
	cin >> height;
	return height;
}

// Function for getting column count from user
int get_column_count()
{
	int width;
	clear();
	cout << "\n\033[0;33mCount of columns:\t\033[0;32m";
	cin  >> width;
	return width;
}

// Function for getting speed from user
int get_speed()
{
	int speed;
	clear();
	cout << "\n\033[0;33mSpeed (0-100):\t\033[0;32m";
	cin >> speed;
	speed = (100 - speed) * 10000;
	return speed;
}

// Function for getting algorithm number
int get_algorithm()
{
	int mode_number;
	clear();
	cout << "\033[0;33mAlgorithm:\n\033[0;32m";
	cout << "\n1.B3/S23\n2.B1/S012345678\n3.B4678/S35678\n";
	cin >> mode_number;
	return mode_number;
}

// Function for getting alive symbol
int get_alive_symbol()
{
	int alive_symbol_number;
	clear();
	cout << "\033[0;33mChoose alive symbol:\n\033[0;32m";
	cout << "1. ▅" << endl;
	cout << "2. #" << endl;
	cout << "3. O" << endl;
	cout << "4. +" << endl;
	cout << "5. ." << endl;
	cout << "6.   (space)" << endl;
	cin >> alive_symbol_number;
	return alive_symbol_number;
}

// Function for getting die symbol
int get_die_symbol()
{
	int die_symbol_number;
	clear();
	cout << "\033[0;33mChoose die symbol:\n\033[0;32m";
	cout << "1.   (space) << endl";
	cout << "2. #" << endl;
	cout << "3. O" << endl;
	cout << "4. +" << endl;
	cout << "5. ." << endl;
	cout << "6. ▅" << endl;
	cin >> die_symbol_number;
	return die_symbol_number;
}

// Function for getting color
int get_color_choice()
{
	int color_choice;
	clear();
	cout << "\033[0;33mChoose color:\n\033[0;32m";
	cout << "\033[34m1. Blue" << endl;
	cout << "\033[37m2. White" << endl;
	cout << "\033[31m3. Red" << endl;
	cout << "\033[32m4. Green" << endl;
	cout << "\033[33m5. Yellow" << endl;
	cout << "\033[35m6. Pink" << endl;
	cout << "\033[32m";
	cin >> color_choice;
	return color_choice;
}

// Function which will combine results
int * combine_results(int height, int width, int speed,
int mode_number, int alive_symbol, int die_symbol, int color_number)
{
	// For giving space to combined array
	int array[20];
	int *combined = array;
	// Feeling array and returning it
	combined[0] = height;
	combined[1] = width;
	combined[2] = speed;
	combined[3] = mode_number;
	combined[4] = alive_symbol; 
	combined[5] = die_symbol; 
	combined[6] = color_number; 
	return combined;
}

// Function for configurating settings if user wants it
int * config_settings(bool default_choice)
{
	if (default_choice)
	{
		int a[100];
		int *array = a;
		array = combine_results(height, width,speed,
		mode_number, alive_symbol, die_symbol, color_number);
		return array;	
	}
	else
	{
		int config_choice = config_choose_output();
		// Selecting default values
		if (config_choice == 2)
		{
			height = get_row_count();
			width = get_column_count();	
			speed = get_speed();
			mode_number = get_algorithm();
			alive_symbol = get_alive_symbol();
			die_symbol = get_die_symbol();
			color_number = get_color_choice();
		}
		int a[100];
		int *array = a;
		array = combine_results(height, width,speed, 
			mode_number, alive_symbol, die_symbol, color_number);
		return array;
	}
}
