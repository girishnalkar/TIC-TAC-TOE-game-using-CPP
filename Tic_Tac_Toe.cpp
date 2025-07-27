#include <iostream>
using namespace std;
int choice;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, col;
char turn = 'X';
bool draw = false;

void display_board()
{
    system("cls");
    cout << "\n     TIC TAC TOE GAME" << endl;
    cout << "\tPlayer 1[X]" << endl;
    cout << "\tPlayer 2[O]" << endl;

    cout << "\t     |     |     " << endl;
    cout << "\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  " << endl;
    cout << "\t_____|_____|_____" << endl;
    cout << "\t     |     |     " << endl;
    cout << "\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  " << endl;
    cout << "\t_____|_____|_____" << endl;
    cout << "\t     |     |     " << endl;
    cout << "\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  " << endl;
    cout << "\t     |     |     " << endl;
}

void player_turn()
{
    if (turn == 'X')
    {
        cout << "Player 1[X] turn:";
    }
    else if (turn == 'O')
    {
        cout << "Player 2[O] turn:";
    }
    cin >> choice;
    switch (choice)
    {
    case 1:
        row = 0, col = 0;
        break;
    case 2:
        row = 0, col = 1;
        break;
    case 3:
        row = 0, col = 2;
        break;
    case 4:
        row = 1, col = 0;
        break;
    case 5:
        row = 1, col = 1;
        break;
    case 6:
        row = 1, col = 2;
        break;
    case 7:
        row = 2, col = 0;
        break;
    case 8:
        row = 2, col = 1;
        break;
    case 9:
        row = 2, col = 2;
        break;
    default:
        cout << "invalid input" << endl;
        break;
    }
    if (turn == 'X' && board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = 'O';
        turn = 'X';
    }
    else
    {
        cout << "box already filled by another's input" << endl;
        cout << "please try again." << endl;
        player_turn();
    }
}

bool gameover()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return false;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return false;
        }
    }

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return false;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return true;
            }
        }
    }

    draw = true;
    return false;
}

void reset_game()
{
    char start = '1';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = start++;
        }
    }
    turn = 'X';
    draw = false;
}

int main()
{
    int input;
    while (true)
    {
        cout << "enter 1 to play game and 0 to quit: ";
        cin >> input;
        if (input == 0)
        {
            cout << "Thanks for playing!!" << endl;
            break;
        }
        if (input == 1)
        {
            reset_game();
            while (gameover())
            {
                display_board();
                player_turn();
                gameover();
                display_board();
            }

            if (turn == 'O' && draw == false)
            {
                cout << "congratulations!!...Player1[X] won the game." << endl;
            }
            else if (turn == 'X' && draw == false)
            {
                cout << "congratulations!!...Player2[O] won the game." << endl;
            }
            else
            {
                cout << "GAME DRAW!" << endl;
            }
        }
        else {
            cout << "Invalid input. Please enter 1 or 0.\n";
        }
    }
    return 0;
}