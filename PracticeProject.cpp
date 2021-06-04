//Tic-tac-toe game
#include <iostream>
#include <ctime>
#include <Windows.h>

void cleanConsole(); void printMainMenu(); void twoPlayers(); void printRules(); void exitFunction(bool &exit);
void printBoard(char *board); void victoryCheck(char *board, bool &Xwon, bool &ZeroWon, char &currentPlayer);
void coordinateCheck(int &coordinate, int &turn, char *board, int *occupiedField);
int chooseDifficulty(char &choice); void training(); void storyMode(); void loading();
void randomMove(int &coordinate, int &turn, char *board, int *occupiedFields);
void hardBot(int &coordinate, int &turn, char *board, int *occupiedFields);

int main()
{
	bool exit = false;
	while (exit == false)
	{
		std::cout << "Hello! Welcome to Tic-Tac-Toe game! Choose the mode from the list below:\n\n";
		printMainMenu();

		char choosenMode = '0';
		std::cin >> choosenMode;

		while (!(49 <= choosenMode && choosenMode <= 53))
		{
			cleanConsole();
			std::cout << "Error! Please choose the game from the list (1-5)!\n\n";
			printMainMenu();
			std::cin >> choosenMode;
		}

		cleanConsole();

		switch (choosenMode)
		{
		case '1': twoPlayers(); break;
		case '2': storyMode(); break;
		case '3': training(); break;
		case '4': printRules(); break;
		case '5': exitFunction(exit); break;
		}
	}
	
	return 0;
}

void twoPlayers()
{
	loading();
	cleanConsole();

	std::cout << "\nOk, Let the game begin!\n";
	char board[9] = { '-', '-', '-', '-', '-', '-', '-', '-', '-' };
	int occupiedFields[9];
	int coordinate;

	std::cout << "\nYou are playing for X so you start the game! Choose the coordinates:\n";

	printBoard(board);

	int turn = 0;
	bool Xwon = false, ZeroWon = false, Draw = false;

	while (Xwon == false || ZeroWon == false)
	{
		if (!(turn % 2))
		{
			std::cout << "X player's turn:\n";
		}
		else
		{
			std::cout << "0 player's turn:\n";
		}

		std::cin >> coordinate;
		coordinateCheck(coordinate, turn, board, occupiedFields);

		char currentPlayer;
		if (!(turn % 2))
		{
			board[coordinate - 1] = 'X';
			currentPlayer = 'X';
		}
		if (turn % 2)
		{
			board[coordinate - 1] = '0';
			currentPlayer = '0';
		}

		printBoard(board);

		victoryCheck(board, Xwon, ZeroWon, currentPlayer);

		char symbol;
		if (Xwon)
		{
			std::cout << "Congratulations! X player won! Enter any symbol to go back to main menu: ";
			std::cin >> symbol;
			break;
		}
		if (ZeroWon)
		{
			std::cout << "Congratulations! 0 player won! Enter any symbol to go back to main menu: ";
			std::cin >> symbol;
			break;
		}

		occupiedFields[turn] = coordinate;
		turn++;

		if (turn == 9)
		{
			std::cout << "Seems like it's a draw! Enter ant symbol to go back to main menu: ";
			std::cin >> symbol;
			break;
		}
	}
	loading();
	cleanConsole();
}

void training() //function for training mode
{
	char choice;

	chooseDifficulty(choice);
	
	std::cout << "\nOk, Let the game begin!\n";
	char board[9] = { '-', '-', '-', '-', '-', '-', '-', '-', '-' };
	int occupiedFields[9];
	int coordinate;

	std::cout << "\nYou are playing for X so you start the game! Choose the coordinates:\n";
	printBoard(board);

	int turn = 0;
	bool Xwon = false, ZeroWon = false, Draw = false;
	while (Xwon == false || ZeroWon == false)
	{

		if (!(turn % 2))
		{
			std::cout << "Your turn:\n";
			std::cin >> coordinate;
			coordinateCheck(coordinate, turn, board, occupiedFields);
			cleanConsole();
		}
		else
		{
			if (choice == '1')
			{

				cleanConsole();
			}
			else if (choice == '2')
			{
				randomMove(coordinate, turn, board, occupiedFields);
				cleanConsole();
			}
		}


		char currentPlayer;
		if (!(turn % 2))
		{
			board[coordinate - 1] = 'X';
			currentPlayer = 'X';
		}
		if (turn % 2)
		{
			board[coordinate - 1] = '0';
			currentPlayer = '0';
		}


		printBoard(board);

		if (turn % 2)
		{
			std::cout << "\nBot's turn was: " << coordinate << "\n";
		}

		victoryCheck(board, Xwon, ZeroWon, currentPlayer);

		char symbol;
		if (Xwon)
		{
			std::cout << "Congratulations! You have won! Enter any symbol to go back to main menu: ";
			std::cin >> symbol;
			break;
		}
		if (ZeroWon)
		{
			std::cout << "Unfortunately, you have lost! 0 player won! Enter any symbol to go back to main menu: ";
			std::cin >> symbol;
			break;
		}

		occupiedFields[turn] = coordinate;
		turn++;

		if (turn == 9)
		{
			std::cout << "Seems like it's a draw! Enter ant symbol to go back to main menu: ";
			std::cin >> symbol;
			break;
		}
	}
	
	loading();
	cleanConsole();
}

void hardBot(int &coordinate, int &turn, char *board, int *occupiedFields)
{

}

void storyMode() //function for story mode
{
	cleanConsole();
	bool lose = false;

	while (lose == false)
	{
		char choice;
		char next[20];
		chooseDifficulty(choice);

		std::cout << "Welcome to the story mode of Tic-Tac-Toe, champion!\n";
		std::cout << "Please tell me how can i call you?\n";
		std::string name;
		std::cin >> name;
		std::cout << "\nOk, " << name << ", my name is John, I will conduct you during your whole way!\nYou are going to take part in the tournament where you will meet the best players of Tic-Tac-Toe game on our planet!";
		std::cout << "\n\nEnter any symbol to continue: ";
		std::cin >> next;

		loading();
		cleanConsole();

		std::cout << "Level 1. Il programista\n";
		std::cout << "Ok, it's round 1 and you will face Mario il Programista. He is a C# programmer that prefers to use # instead of 0.";
		std::cout << "\nGood luck, champion!\n";
		std::cout << "\nEnter any symbol to continue: ";
		std::cin >> next;

		loading();
		cleanConsole();

		std::cout << "\nOk, Let the game begin!\n";

		char board[9] = { '-', '-', '-', '-', '-', '-', '-', '-', '-' };
		int occupiedFields[9] = {};
		int coordinate;
		int turn = 0;

		std::cout << "\nYou are playing for X so you start the game! Choose the coordinates:\n";
		printBoard(board);

		bool Xwon = false, ZeroWon = false, Draw = false;
		while (Xwon == false || ZeroWon == false)
		{

			if (!(turn % 2))
			{
				std::cout << "Your turn:\n";
				std::cin >> coordinate;
				coordinateCheck(coordinate, turn, board, occupiedFields);
				cleanConsole();
			}
			else
			{
				if (choice == '1')
				{

					cleanConsole();
				}
				else if (choice == '2')
				{
					randomMove(coordinate, turn, board, occupiedFields);
					cleanConsole();
				}
			}


			char currentPlayer;
			if (!(turn % 2))
			{
				board[coordinate - 1] = 'X';
				currentPlayer = 'X';
			}
			if (turn % 2)
			{
				board[coordinate - 1] = '#';
				currentPlayer = '#';
			}

			printBoard(board);

			if (turn % 2)
			{
				std::cout << "\nMario's turn was: " << coordinate << "\n";
			}

			victoryCheck(board, Xwon, ZeroWon, currentPlayer);
			
			if (Xwon)
			{
				std::cout << "Congratulations! You have won!";
				std::cout << "\nEnter any symbol to continue: ";
				std::cin >> next;
				cleanConsole();
				break;
			}
			if (ZeroWon)
			{
				std::cout << "Unfortunately, you have lost! Mario il Programista player won!\nEnter any symbol to go back to main menu: ";
				std::cin >> next;
				lose = true;
				loading();
				cleanConsole();
				return;
			}

			occupiedFields[turn] = coordinate;
			turn++;

			if (turn == 9)
			{
				std::cout << "Seems like it's a draw!\nEnter ant symbol to go back to main menu: ";
				std::cin >> next;
				lose = true;
				loading();
				cleanConsole();
				return;
			}
		}

		std::cout << "\nMario: It's not the end. It's not over yet, amico! Viva la Italia!\n";
		std::cout << "John: Don't listen to him, " << name << ". " << "You have been on fire tonight!\n";
		std::cout << "\nEnter any symbol to continue: ";
		std::cin >> next;

		loading();
		cleanConsole();

		std::cout << "Level 2. Scratch McDuck\n";
		std::cout << "You gonna face Scratch McDuck that prefers to use $ instead of 0.\n";
		std::cout << "Good Luck, champion!\n";
		std::cout << "\nEnter any symbol to continue: ";
		std::cin >> next;

		loading();
		cleanConsole();

		std::cout << "\nOk, Let the game begin!\n";

		char board2[9] = { '-', '-', '-', '-', '-', '-', '-', '-', '-' };
		int occupiedFields2[9] = {};

		std::cout << "\nYou are playing for X so you start the game! Choose the coordinates:\n";
		printBoard(board2);

		turn = 0;
		Xwon = false, ZeroWon = false, Draw = false;

		while (Xwon == false || ZeroWon == false)
		{

			if (!(turn % 2))
			{
				std::cout << "Your turn:\n";
				std::cin >> coordinate;
				coordinateCheck(coordinate, turn, board2, occupiedFields2);
				cleanConsole();
			}
			else
			{
				if (choice == '1')
				{

					cleanConsole();
				}
				else if (choice == '2')
				{
					randomMove(coordinate, turn, board2, occupiedFields2);
					cleanConsole();
				}
			}


			char currentPlayer;
			if (!(turn % 2))
			{
				board2[coordinate - 1] = 'X';
				currentPlayer = 'X';
			}
			if (turn % 2)
			{
				board2[coordinate - 1] = '$';
				currentPlayer = '$';
			}

			printBoard(board2);

			if (turn % 2)
			{
				std::cout << "\nMcDuck's turn was: " << coordinate << "\n";
			}

			victoryCheck(board2, Xwon, ZeroWon, currentPlayer);

			if (Xwon)
			{
				std::cout << "Congratulations! You have won!";
				std::cout << "\nEnter any symbol to continue: ";
				std::cin >> next;
				break;
			}
			if (ZeroWon)
			{
				std::cout << "Unfortunately, you have lost! Scratch McDuck won!\nEnter any symbol to go back to main menu: ";
				std::cin >> next;
				lose = true;
				loading();
				cleanConsole();
				return;
			}

			occupiedFields2[turn] = coordinate;
			turn++;

			if (turn == 9)
			{
				std::cout << "Seems like it's a draw! Enter ant symbol to go back to main menu: ";
				std::cin >> next;
				lose = true;
				loading();
				cleanConsole();
				return;
			}
		}

		std::cout << "\nScratch McDuck: Oh no, i can't believe! Quack-quack!\n";
		std::cout << "John: Good job, " << name << ". " << "You have shown that money can't win games!\n";
		std::cout << "\nEnter any symbol to continue: ";
		std::cin >> next;

		loading();
		cleanConsole();

		std::cout << "Level 3. K means Kolya\n";
		std::cout << "This is the final round, " << name << ". You've been preparing for this your whole life!\n";
		std::cout << "Your opponent is Dyadya Kolya! He is the best player of Tic-Tac-Toe in the world but i believe in you!\n";
		std::cout << "Good Luck, champion!\n";
		std::cout << "\nEnter any symbol to continue: ";
		std::cin >> next;

		loading();
		cleanConsole();

		std::cout << "\nOk, Let the game begin!\n";

		char board3[9] = { '-', '-', '-', '-', '-', '-', '-', '-', '-' };
		int occupiedFields3[9] = {};

		std::cout << "\nYou are playing for X so you start the game! Choose the coordinates:\n";
		printBoard(board3);

		turn = 0;
		Xwon = false, ZeroWon = false, Draw = false;

		while (Xwon == false || ZeroWon == false)
		{

			if (!(turn % 2))
			{
				std::cout << "Your turn:\n";
				std::cin >> coordinate;
				coordinateCheck(coordinate, turn, board3, occupiedFields3);
				cleanConsole();
			}
			else
			{
				if (choice == '1')
				{

					cleanConsole();
				}
				else if (choice == '2')
				{
					randomMove(coordinate, turn, board3, occupiedFields3);
					cleanConsole();
				}
			}


			char currentPlayer;
			if (!(turn % 2))
			{
				board3[coordinate - 1] = 'X';
				currentPlayer = 'X';
			}
			if (turn % 2)
			{
				board3[coordinate - 1] = 'K';
				currentPlayer = 'K';
			}

			printBoard(board3);

			if (turn % 2)
			{
				std::cout << "\nDyadya Kolya's turn was: " << coordinate << "\n";
			}

			victoryCheck(board3, Xwon, ZeroWon, currentPlayer);

			if (Xwon)
			{
				std::cout << "Congratulations! You have won the tournament!";
				std::cout << "\nEnter any symbol to continue: ";
				std::cin >> next;
				break;
			}
			if (ZeroWon)
			{
				std::cout << "Unfortunately, you have lost! Dyadya Kolya won!\nEnter any symbol to go back to main menu: ";
				std::cin >> next;
				lose = true;
				loading();
				cleanConsole();
				return;
			}

			occupiedFields3[turn] = coordinate;
			turn++;

			if (turn == 9)
			{
				std::cout << "Seems like it's a draw! Enter ant symbol to go back to main menu: ";
				std::cin >> next;
				lose = true;
				loading();
				cleanConsole();
				return;
			}
		}
		std::cout << "\n\n\n";
		std::cout << "\t        ___________     \n";
		std::cout << "\t   .---'           '---.\n";
		std::cout << "\t  (                     )\n";
		std::cout << "\t  |`-----._______.-----'|\n";
		std::cout << "\t  |                     |\n";
		std::cout << "\t.-|                     |-.\n";
		std::cout << "\t \\|                     |/\n";
		std::cout << "\t  |                     |\n";
		std::cout << "\t  |  Special Award For  |\n";
		std::cout << "\t  |    Winner of the    |\n";
		std::cout << "\t  |     Tournament      |\n";
		std::cout << "\t  |                     |\n";
		std::cout << "\t  |                     |\n";
		std::cout << "\t   \\                   /\n";
		std::cout << "\t    '.               .'\n";
		std::cout << "\t      '-._       _.-'\n";
		std::cout << "\t\t  |     |\n";
		std::cout << "\t\t  |     |\n";
		std::cout << "\t\t  |     |\n";
		std::cout << "\t\t  |     |\n";
		std::cout << "\t\t /       \\\n";
		std::cout << "\t    __.-'         `-.__\n";
		std::cout << "\t   (_                 _)\n";
		std::cout << "\t     '\"\"\"---------\"\"\"'\n\n";

		std::cout << "Enter any symbol to go back to main menu: ";
		std::cin >> next;

		break;
	}

	loading();
	cleanConsole();
}

void randomMove(int &coordinate, int &turn, char *board, int *occupiedFields) //function of random choice for bot
{
	bool occupied = false;
	
	do {
		srand(time(NULL));
		coordinate = rand() % 9 + 1;
		for (int i = 0; i < 9; i++)
		{
			if (coordinate == occupiedFields[i])
			{
				occupied = true;
				coordinate = rand() % 9;
				break;
			}
			else
			{
				occupied = false;
			}
		}
	} while (occupied == true);
}

int chooseDifficulty(char &choice) { //function that prints choice for the difficulty
	std::cout << "Choose difficulty:\n";
	std::cout << "1. Hard (trained AI)\n";
	std::cout << "2. Easy (random moving Bot)\n\n";
	
	std::cin >> choice;
	while (choice != '1' && choice != '2') //loop to check if user's input is correct 
	{
		cleanConsole();
		
		std::cout << "1. Hard (trained AI)\n";
		std::cout << "2. Easy (random moving Bot)\n\n";
		std::cout << "Error! Please choose from the list (1-2):\n";
		std::cin >> choice;
	}

	loading();
	cleanConsole();

	return choice;
}

void cleanConsole() //function that cleans console's screen by using loop with new lines
{
	for (int i = 0; i < 30; i++)
	{
		std::cout << "\n";
	}
}

void loading() //function that imitates loading icon
{
	int i = 0;
	
	while (i < 7)
	{
		std::cout << "\\\r";
  		Sleep(70);
		std::cout << "|\r";
		Sleep(70);
		std::cout << "/\r";
		Sleep(70);
		std::cout << "-\r";
		Sleep(70);
		i++;
	}
}

void printMainMenu() { //function that prints main menu on the screen
	std::cout << "1. 2 players mode\n";
	std::cout << "2. Story mode\n";
	std::cout << "3. Training against computer\n";
	std::cout << "4. Read rules.\n";
	std::cout << "5. Exit\n\n";
}

void printRules() { //function that prints rules of tic-tac-toe
	std::cout << "\nThe goal of tic-tac-toe is to be the first player to get three in a row on a 3-by-3 grid.\n";
	std::cout << "In a 3-by-3 grid game, the player who is playing X always goes first.\n";
	std::cout << "Players placing Xs and 0s on the board until either player has 3 in a row, horizontally, vertically or diagonally.\n";
	std::cout << "If a player is able to draw three Xs or three Os in a row, then that player wins.\n";
	std::cout << "If all squares are filled and neither player has made a complete row of Xs or Os, then the game is a draw.\n";
	std::cout << "\nEnter any symbol to go back: ";
	char symbol[20];
	std::cin >> symbol;

	cleanConsole();
}

void exitFunction(bool &exit) //function for exit
{
	std::cout << "\nAre you sure?\n";
	char sure = '0';
	std::cout << "1. Yes\n";
	std::cout << "2. No\n\n";
	std::cin >> sure;
	
	while (sure != '1' && sure != '2')
	{
		cleanConsole();

		std::cout << "Error! Please choose from the list:\n";
		std::cout << "1. Yes\n";
		std::cout << "2. No\n\n";
		std::cin >> sure;
	}

	if (sure == '1')
	{
		exit = true;
		cleanConsole();
	}
	else
	{
		exit = false;
		cleanConsole();
	}
}

void coordinateCheck(int &coordinate, int &turn, char *board, int *occupiedFields) //function that check if entered coordinates are true
{
	bool occupied = false;
	
	do  {
		for (int i = 0; i < 9; i++)
		{
			if (coordinate == occupiedFields[i])
			{
				occupied = true;
				cleanConsole();
				printBoard(board);
				std::cout << "This field is already occupied! Please choose the free one: ";
				std::cin >> coordinate;
				break;
			}
			else
			{
				occupied = false;
			}
		}
	} while (occupied == true);
	
	cleanConsole();

	while (!(1 <= coordinate && coordinate <= 9))
	{
		printBoard(board);

		std::cout << "\nWrong coordinate! Enter coordinate from the board (1-9)!\n";
		if (!(turn % 2))
		{
			std::cout << "X player's turn:\n";
		}
		else
		{
			std::cout << "0 player's turn:\n";
		}
		std::cin >> coordinate;
		cleanConsole();
	}
}

void victoryCheck(char *board, bool &Xwon, bool &ZeroWon, char &currentPlayer) //function that defines the winner
{ 
	int win_combos[8][3] = {{0,1,2}, {3,4,5}, {6,7,8},
							{0,3,6}, {1,4,7}, {2,5,8},
							{0,4,8}, {2,4,6} }; //array with all victory combinations

	for (int i = 0; i < 8; i++) //this loop check the board
	{
		int counter = 0;
		for (int j = 0; j < 3; j++) {
			if (board[win_combos[i][j]] == currentPlayer) //we count symbols accroding to combos from array
			{
				counter++;
			}
			if (counter == 3) //when counter becomes 3 we determine the winner
			{
				switch (currentPlayer)
				{
				case 'X': Xwon = true; break;
				case '0': ZeroWon = true; break;
				case '#': ZeroWon = true; break;
				case '$': ZeroWon = true; break;
				}
			}
		}
	}
}

void printBoard(char *board) //function that prints game board on the screen
{
	std::cout << "\n-7-|-8-|-9-\t";
	std::cout << "\t-" << board[6] << "-|" << "-" << board[7] << "-|" << "-" << board[8] << "-\n";
	std::cout << "-4-|-5-|-6- \t";
	std::cout << "\t-" << board[3] << "-|" << "-" << board[4] << "-|" << "-" << board[5] << "-\n";
	std::cout << "-1-|-2-|-3- \t";
	std::cout << "\t-" << board[0] << "-|" << "-" << board[1] << "-|" << "-" << board[2] << "-\n\n";
}