#include <iostream>

#include <stdlib.h>

using namespace std;

int main()
{
  std::system("clear");
  // Defining important variables
  int height = 40;
  int width = 120;
  int s = 0;
  int multiply = 0;
  int just = 12;
  int rarity = 63;
  int speed = 100000;

  string die = " ";
  string alive = "▅";
  string mode = "B3/S23";
  string shape = "random";

  int a = 0;
  cout << "\nStart (1) or change settings (2):\t";
    cin >> a;
  
  if (a == 2)
  {
    cout << "\nCount of rows (30):\t";
    cin >> a;
    height = a;
    cout << "\nCount of columns (50):\t";
    cin >> a;
    width = a;
    cout << "\nSpeed (0-100):\t";
    cin >> a;
    speed = a * 100000;
    cout << "\nAlgorithm:\n1.B3/S23\n2.B1/S012345678\n3.B4678/S35678\n";
    cin >> a;
    if (a == 1)
    {
      mode = "B3/S23";
      shape = "random";
    }
    if (a == 2)
    {
      mode = "B1/S012345678";
      shape = "alone";
    }
    if (a == 3)
    {
      mode = "B4678/S35678";
      shape = "random";
    }
  }

  // Generateing matrix
  int matrix[height][width];
  if (shape == "random")
  {
    for (int y = 0; y < height; y++)
    {
      for (int x = 0; x < width; x++)
      {
        if ((rand() % 100 + 1) > rarity)
        {
          s = 1;
        }
        else
        {
          s = 0;
        }
        matrix[y][x] = s;
      }
    }
  }
  else if (shape == "alone")
  {
    for (int y = 0; y < height; y++)
    {
      for (int x = 0; x < width; x++)
      {
        matrix[y][x] = 0;
      }
    }
    matrix[height / 2][width / 2] = 1;
  }

  while (true)
  {

    if (multiply < speed)
    {
      multiply++;
      for (int k = 0; k < 100; k++)
      {
        just *= 12;
        just /= 12;
      }
      continue;
    }
    else
    {
      multiply = 0;
      std::system("clear");
    }
    // Printing matrix
    for (int y = 0; y < height; y++)
    {

      for (int x = 0; x < width; x++)
      {
        if (matrix[y][x] == 0)
        {
          cout << die;
          //cout << die << die;
        }
        else
        {
          cout << alive;
          //cout << alive << alive;
        }
      }
      cout << endl;
    }

    // Calculateing
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
        try
        {
          if (newmatrix[y - 1][x - 1] == 1)
          {
            n++;
          }
        }
        catch (runtime_error err)
        {
        }
        try
        {
          if (newmatrix[y - 1][x] == 1)
          {
            n++;
          }
        }
        catch (runtime_error err)
        {
        }
        try
        {
          if (newmatrix[y - 1][x + 1] == 1)
          {
            n++;
          }
        }
        catch (runtime_error err)
        {
        }
        try
        {
          if (newmatrix[y][x - 1] == 1)
          {
            n++;
          }
        }
        catch (runtime_error err)
        {
        }
        try
        {
          if (newmatrix[y][x + 1] == 1)
          {
            n++;
          }
        }
        catch (runtime_error err)
        {
        }
        try
        {
          if (newmatrix[y + 1][x - 1] == 1)
          {
            n++;
          }
        }
        catch (runtime_error err)
        {
        }
        try
        {
          if (newmatrix[y + 1][x] == 1)
          {
            n++;
          }
        }
        catch (runtime_error err)
        {
        }
        try
        {
          if (newmatrix[y + 1][x + 1] == 1)
          {
            n++;
          }
        }
        catch (runtime_error err)
        {
        }
        if (mode == "B3/S23")
        {
          if (n < 2)
          {
            matrix[y][x] = 0;
          }
          else if (n == 3)
          {
            matrix[y][x] = 1;
          }
          else if (n > 3)
          {
            matrix[y][x] = 0;
          }
        }
        if (mode == "B1/S012345678")
        {
          if (n == 1)
          {
            matrix[y][x] = 1;
          }
        }
        if (mode == "B4678/S35678")
        {
          if (n == 4 || n == 6 || n == 7 || n == 8)
          {
            matrix[y][x] = 1;
          }
          else if (n == 3 || n == 5 || n == 6 || n == 7 || n == 8)
          {
          }
          else
          {
            matrix[y][x] = 0;
          }
        }
        n = 0;
      }
    }
  }
}
