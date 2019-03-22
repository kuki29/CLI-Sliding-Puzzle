#pragma warning(disable : 4996)

#include <iostream>
#include <algorithm>
#include <conio.h>
#include <ctime>

#define HEIGHT		4

#define KEY_UP		72
#define KEY_DOWN	80
#define KEY_LEFT	75
#define KEY_RIGHT	77
#define KEY_Q		113

void printField(int field[HEIGHT][HEIGHT])
{
	system("cls");
	for (int i = 0; i < HEIGHT; i++)
	{

		for (int j = 0; j < HEIGHT; j++)
		{
			if (field[i][j] != 0)
			{
				std::cout << field[i][j] << "\t";
			}
			else
			{
				std::cout << " \t";
			}
		}

		std::cout << std::endl;
	}
}

int main()
{
	srand((unsigned int) time(NULL));
	int field[HEIGHT][HEIGHT];
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			field[i][j] = i * HEIGHT + j;
		}
		std::random_shuffle(field[i], field[i] + HEIGHT);
	}

	int indexV = 0;
	int indexH = 0;
	for (; indexV < HEIGHT; indexV++)
	{
		for (; indexH < HEIGHT; indexH++)
		{
			if (field[indexV][indexH] == 0)
			{
				break;
			}
		}
		if (field[indexV][indexH] == 0)
		{
			break;
		}
	}

	while (true)
	{
		printField(field);

		int c;
		c = _getch();
		//for glitchy workin' arrows, cuz sometimes it returns 2 or even 3 values
		if (c == 0 || c == 224 || c == -32)
		{
			switch (c = _getch())
			{
			case KEY_UP:
				if (indexV > 0 && indexV < HEIGHT)
				{
					field[indexV][indexH] = field[indexV - 1][indexH];
					indexV--;
					field[indexV][indexH] = 0;
				}
				break;

			case KEY_DOWN:
				if (indexV >= 0 && indexV < HEIGHT - 1)
				{
					field[indexV][indexH] = field[indexV + 1][indexH];
					indexV++;
					field[indexV][indexH] = 0;
				}
				break;

			case KEY_LEFT:
				if (indexH > 0 && indexH < HEIGHT)
				{
					field[indexV][indexH] = field[indexV][indexH - 1];
					indexH--;
					field[indexV][indexH] = 0;
				}
				break;

			case KEY_RIGHT:
				if (indexH >= 0 && indexH < HEIGHT - 1)
				{
					field[indexV][indexH] = field[indexV][indexH + 1];
					indexH++;
					field[indexV][indexH] = 0;
				}
				break;
			}
		}
		else
		{
			switch (c)
			{
			case KEY_Q:
				system("cls");
				std::cout << "\n\n\n\n\t\t\t\tBye!" << std::endl;
				std::cin.get();
				exit(EXIT_SUCCESS);
				break;
			}
		}
	}
}