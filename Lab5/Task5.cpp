#include <iostream>
using namespace std;

const int rows = 9;
const int cols = 9;

void displayBoard(int **board)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool validation(int **board, int row, int col, int num)
{
    for (int j = 0; j < 9; j++)
    {
        if (board[row][j] == num)
        {
            return false;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num)
        {
            return false;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[startRow + i][startCol + j] == num)
            {
                return false;
            }
        }
    }

    return true;
}

bool findEmptyCell(int **board, int &row, int &col)
{
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (board[row][col] == 0)
            {
                return true;
            }
        }
    }
    return false;
}

bool solveSudoku(int **board)
{
    int row, col;

    if (!findEmptyCell(board, row, col))
    {
        return true;
    }

    for (int num = 1; num <= 9; num++)
    {
        if (validation(board, row, col, num))
        {
            board[row][col] = num;

            if (solveSudoku(board))
                return true;

            board[row][col] = 0;
        }
    }
    return false;
}

void initializeBoard(int **board)
{
    int puzzle[9][9] =
        {
            {0, 0, 0, 2, 6, 0, 7, 0, 1},
            {6, 8, 0, 0, 7, 0, 0, 9, 0},
            {1, 9, 0, 0, 0, 4, 5, 0, 0},
            {8, 2, 0, 1, 0, 0, 0, 4, 0},
            {0, 0, 4, 6, 0, 2, 9, 0, 0},
            {0, 5, 0, 0, 0, 3, 0, 2, 8},
            {0, 0, 9, 3, 0, 0, 0, 7, 4},
            {0, 4, 0, 0, 5, 0, 0, 3, 6},
            {7, 0, 3, 0, 1, 8, 0, 0, 0}
        };

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            board[i][j] = puzzle[i][j];
        }
    }
}

int main()
{

    int **board = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        board[i] = new int[cols]();
    }

    initializeBoard(board);

    cout << "Initial Sudoku Board:\n";
    displayBoard(board);

    cout << "\nSolving...\n\n";

    if (solveSudoku(board))
    {
        cout << "Solved Sudoku Board:\n";
        displayBoard(board);
    }
    else
    {
        cout << "No solution exists.\n";
    }

    for (int i = 0; i < 9; i++)
    {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}
