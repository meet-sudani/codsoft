#include <iostream>
using namespace std;

char board[3][3];

// Initialize board
void initializeBoard()
{
    char ch = '1';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ch++;
        }
    }
}

// Display board
void displayBoard()
{
    cout << "\n";
    cout << "-------------\n";

    for (int i = 0; i < 3; i++)
    {
        cout << "| ";

        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " | ";
        }

        cout << "\n-------------\n";
    }
}

// Check winner
bool checkWin(char player)
{
    // Rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;
    }

    // Columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

    // Diagonals
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

// Check draw
bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

int main()
{
    char playAgain;

    do
    {
        initializeBoard();

        char currentPlayer = 'X';

        while (true)
        {
            displayBoard();

            int choice;

            cout << "\nPlayer " << currentPlayer << ", Enter Position (1-9): ";
            cin >> choice;

            if (choice < 1 || choice > 9)
            {
                cout << "\nInvalid Position!\n";
                continue;
            }

            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;

            if (board[row][col] == 'X' || board[row][col] == 'O')
            {
                cout << "\nPosition Already Taken!\n";
                continue;
            }

            board[row][col] = currentPlayer;

            if (checkWin(currentPlayer))
            {
                displayBoard();
                cout << "\n🎉 Player " << currentPlayer << " Wins!\n";
                break;
            }

            if (checkDraw())
            {
                displayBoard();
                cout << "\nGame Draw!\n";
                break;
            }

            if (currentPlayer == 'X')
                currentPlayer = 'O';
            else
                currentPlayer = 'X';
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThank You For Playing!\n";

    return 0;
}