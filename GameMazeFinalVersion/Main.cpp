#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
using namespace std;

void menu(int* ptrchoisemenu)
{
	cout << "\tMENU" << endl;
	cout << endl;
	cout << "1. START" << endl;
	cout << "2. EXIT" << endl;
	cout << endl;
	cout << "Enter action (1/2): ";
	cin >> *ptrchoisemenu;
}

void showMatrix(string matrix[][20])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
void winner()
{
	for (int i = 0; i < 5; i++)
	{
		Sleep(1000);
		system("CLS");
		Sleep(1000);
		cout << "#       #\t\t# # # # #\t\t#       #\t\t\t\t#       #\t\t# # # # #\t\t#       #" << endl;
		cout << "#       #\t\t#       #\t\t#       #\t\t\t\t#       #\t\t#       #\t\t#       #" << endl;
		cout << "#       #\t\t#       #\t\t#       #\t\t\t\t#       #\t\t#       #\t\t#       #" << endl;
		cout << "  # # #  \t\t#       #\t\t#       #\t\t\t\t#   #   #\t\t#       #\t\t# #     #" << endl;
		cout << "    #    \t\t#       #\t\t#       #\t\t\t\t#   #   #\t\t#       #\t\t#   #   #" << endl;
		cout << "    #    \t\t#       #\t\t#       #\t\t\t\t#   #   #\t\t#       #\t\t#     # #" << endl;
		cout << "    #    \t\t# # # # #\t\t# # # # #\t\t\t\t# #   # #\t\t# # # # #\t\t#       #" << endl;
	}
}
void loser()
{
	for (int i = 0; i < 5; i++)
	{
		Sleep(500);
		system("CLS");
		Sleep(500);
		cout << "# # # # #\t\t# # # # #\t\t#        #\t\t# # # # #" << endl;
		cout << "#       #\t\t#       #\t\t# #    # #\t\t#        " << endl;
		cout << "#        \t\t#       #\t\t#  #  #  #\t\t#        " << endl;
		cout << "# # # # #\t\t# # # # #\t\t#    #   #\t\t# # # # #" << endl;
		cout << "#       #\t\t#       #\t\t#        #\t\t#        " << endl;
		cout << "#       #\t\t#       #\t\t#        #\t\t#        " << endl;
		cout << "# # # # #\t\t#       #\t\t#        #\t\t# # # # #" << endl;
		cout << endl;
		cout << endl;
		cout << "# # # # #\t\t#       #\t\t# # # # #\t\t# # # # #" << endl;
		cout << "#       #\t\t#       #\t\t#        \t\t#       #" << endl;
		cout << "#       #\t\t#       #\t\t#        \t\t#       #" << endl;
		cout << "#       #\t\t#       #\t\t# # # # #\t\t# # # # #" << endl;
		cout << "#       #\t\t#       #\t\t#        \t\t#   #    " << endl;
		cout << "#       #\t\t  #   #  \t\t#        \t\t#     #  " << endl;
		cout << "# # # # #\t\t    #    \t\t# # # # #\t\t#       #" << endl;

	}
}
string moveLeft(string matrix[][20], int* ptrx, int* ptry)
{

	if (matrix[*ptrx][*ptry - 1] == "*")
	{

	}
	else if (matrix[*ptrx][*ptry - 1] == "#")
	{
		loser();
		matrix[*ptrx][*ptry] = " ";
		
	}
	else if (matrix[*ptrx][*ptry - 1] == "F")
	{
		winner();
		matrix[*ptrx][*ptry] = " ";

	}
	else
	{
		(*ptry)--;
		matrix[*ptrx][*ptry] = "$";
		matrix[*ptrx][*ptry + 1] = " ";

	}


	return matrix[*ptrx][*ptry];
}
string moveRight(string matrix[][20], int* ptrx, int* ptry)
{
	if (matrix[*ptrx][*ptry + 1] == "*")
	{

	}
	else if (matrix[*ptrx][*ptry + 1] == "#")
	{
		loser();
		matrix[*ptrx][*ptry] = " ";
		
	}
	else if (matrix[*ptrx][*ptry + 1] == "F")
	{
		winner();
		matrix[*ptrx][*ptry] = " ";

		
	}
	else
	{
		(*ptry)++;
		matrix[*ptrx][*ptry] = "$";
		matrix[*ptrx][*ptry - 1] = " ";

	}


	return matrix[*ptrx][*ptry];

}
string moveUp(string matrix[][20], int* ptrx, int* ptry) 
{
	if (matrix[*ptrx - 1][*ptry] == "*")
	{

	}
	else if (matrix[*ptrx - 1][*ptry] == "#")
	{
		loser();
		matrix[*ptrx][*ptry] = " ";

		
	}
	else if (matrix[*ptrx - 1][*ptry] == "F")
	{
		winner();
		matrix[*ptrx][*ptry] = " ";
		
	}
	else
	{
		(*ptrx)--;
		matrix[*ptrx][*ptry] = "$";
		matrix[*ptrx + 1][*ptry] = " ";
	}
	return matrix[*ptrx][*ptry];

}
string moveDown(string matrix[][20], int* ptrx, int* ptry)
{
	if (matrix[*ptrx + 1][*ptry] == "*")
	{

	}
	else if (matrix[*ptrx + 1][*ptry] == "#")
	{
		loser();
		matrix[*ptrx][*ptry] = " ";
		
	}
	else if (matrix[*ptrx + 1][*ptry] == "F")
	{

		winner();
		matrix[*ptrx][*ptry] = " ";
		
	}
	else
	{
		(*ptrx)++;
		matrix[*ptrx][*ptry] = "$";
		matrix[*ptrx - 1][*ptry] = " ";
	}
	return matrix[*ptrx][*ptry];

}
int main()
{
	int i_input;
	i_input = _getch();
	int choiseMenu = 0;
	int* ptrchoisemenu = &choiseMenu;
	string myMatrix[20][20] = {
		"*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*",
		"*", " ", " ", "*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*",
		"*", " ", " ", "*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*", "*", "*", "*",
		"*", " ", " ", "*", "*", "*", "*", "*", "*", " ", " ", " ", "*", "*", "*", " ", " ", " ", "*", "*",
		"*", " ", " ", " ", " ", " ", " ", " ", "*", " ", " ", " ", "*", " ", " ", " ", " ", " ", "*", "*",
		"*", " ", " ", " ", "*", " ", " ", " ", "*", "*", "*", "*", "*", "*", "*", "*", "*", " ", "*", "*",
		"*", " ", " ", " ", "*", "*", "*", "*", "#", " ", " ", " ", "*", " ", " ", " ", " ", " ", "*", "*",
		"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*", "*", " ", " ", "#", "*", "*", "*",
		"*", "*", "#", " ", " ", " ", " ", " ", "#", " ", " ", " ", " ", "*", " ", " ", "*", " ", " ", "*",
		"*", " ", "*", " ", " ", "*", "*", "*", "*", "*", "*", " ", " ", "*", " ", " ", "*", "*", " ", "*",
		"*", " ", "*", "*", "*", "*", " ", " ", "#", " ", " ", " ", " ", "*", " ", " ", " ", " ", " ", "*",
		"*", " ", " ", " ", " ", "*", " ", " ", " ", " ", " ", " ", "#", "*", " ", " ", " ", " ", " ", "*",
		"*", " ", " ", "#", " ", " ", " ", "#", "*", "*", "*", "#", "*", " ", " ", "#", "*", "*", " ", "*",
		"*", " ", " ", "*", " ", " ", " ", "*", " ", "*", " ", " ", " ", " ", " ", " ", " ", "*", " ", "*",
		"*", " ", " ", "*", " ", "*", "*", "*", " ", "*", " ", " ", "#", "*", "*", "*", " ", "*", " ", "*",
		"*", " ", " ", "*", "#", "*", " ", " ", " ", "#", " ", " ", "*", " ", " ", "*", " ", "*", " ", "*",
		"*", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "*", " ", " ", "*", "*", "*", " ", "*",
		"*", " ", " ", " ", " ", "#", "*", "*", "*", "*", "*", "*", "*", " ", " ", " ", " ", " ", " ", "*",
		"*", " ", " ", " ", " ", "#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "F", "*",
		"*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"
	};
	int x;
	int y;
	
	cout << "#       #\t# # # #\t\t# # # #\t\t# # # #" << endl;
	cout << "# #   # #\t#     #\t\t      #\t\t#      " << endl;
	cout << "#   #   #\t# # # #\t\t    #  \t\t# # # #" << endl;
	cout << "#       #\t#     #\t\t  #    \t\t#      " << endl;
	cout << "#       #\t#     #\t\t# # # #\t\t# # # #" << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	do
	{
		x = 1;
		y = 1;
		int* ptrx = &x;
		int* ptry = &y;
		myMatrix[x][y] = "$";
		system("CLS");
		menu(&choiseMenu);
		switch (*ptrchoisemenu)
		{
		case 1:
			do
			{
				system("CLS");
				showMatrix(myMatrix);
				cout << "Use ^/v/</> to move $" << endl;
				switch (_getch())
				{
				case 75:
					myMatrix[x][y] = moveLeft(myMatrix, &x, &y);
					break;
				case 77:
					myMatrix[x][y] = moveRight(myMatrix, &x, &y);
					break;
				case 72:
					myMatrix[x][y] = moveUp(myMatrix, &x, &y);
					break;
				case 80:
					myMatrix[x][y] = moveDown(myMatrix, &x, &y);
					break;
				}

			} while (myMatrix[x][y] !=" ");

			break;
		case 2:
			cout << "GOOGBYE!" << endl;
			break;
		default:
			break;
		}

	} while (*ptrchoisemenu != 2);



	system("pause");
	return 0;
}