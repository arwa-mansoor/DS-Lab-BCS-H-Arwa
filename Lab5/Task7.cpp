#include <iostream>
using namespace std;

const int MAX = 20;
int board[MAX];
int solutionCount = 0;

bool isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i] == col || (board[i] - col == i - row) || (board[i] - col == row - i))
        {
            return false;
        }
    }
    return true;
}

void solveNQueens(int row, int n)
{
    if (row == n)
    {
        solutionCount++;
        cout << "Solution " << solutionCount << ":\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i] == j)
                {
                    cout << "Q ";
                }
                else
                {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            board[row] = col;
            solveNQueens(row + 1, n);
            board[row] = -1;
        }
    }
}

int main()
{
    int n;
    cout << "Enter value of N for N-Queens: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        board[i] = -1;
    }

    solveNQueens(0, n);

    cout << "Total solutions: " << solutionCount << endl;

    return 0;
}
