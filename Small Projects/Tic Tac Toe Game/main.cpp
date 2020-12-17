/*************************************************
				Header Files
**************************************************/
#include <iostream>
using namespace std;

/*************************************************
				Global Variables
**************************************************/
char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

/*************************************************
			Function declaration
**************************************************/
int checkwin();
void board();

/*************************************************
				Main Function
**************************************************/
int main() {
	cout << "\n\n\tTic Tac Toe Game\n\n";
}

/*************************************************
	FUNCTION TO RETURN GAME STATUS
		1 FOR GAME IS OVER WITH RESULT
		-1 FOR GAME IS IN PROGRESS
		O GAME IS OVER AND NO RESULT
**************************************************/
int checkwin() {
	return 0;
}

/*************************************************
	FUNCTION TO DRAW BOARD OF 
	TIC TAC TOE WITH PLAYERS MARK
**************************************************/
void board() {
//	system('cls');
	cout << "\n\n\tTic Tac Toe Game\n\n";
	
	cout << "Player 1 (X) - Player 2 (O)" << endl << endl;
	cout << endl;
	
	cout << "    |    |    " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
	cout << "____|____|____" << endl;
	cout << "    |    |    " << endl;
	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
	cout << "____|____|____" << endl;
	cout << "    |    |    " << endl;
	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
}

/*************************************************
				End Of Project
**************************************************/