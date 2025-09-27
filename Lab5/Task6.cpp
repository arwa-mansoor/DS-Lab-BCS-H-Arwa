#include <iostream>
using namespace std;

void displayMaze(int **grid, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int **arr, int x, int y, int n, int **visited)
{
    return (x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == 1 && visited[x][y] == 0);
}

bool ratInMaze(int **arr, int x, int y, int n, int **solArr, int **visited)
{
    if (x == n - 1 && y == n - 1)
    {
        solArr[x][y] = 1;
        return true;
    }

    if (isSafe(arr, x, y, n, visited))
    {
        solArr[x][y] = 1;
        visited[x][y] = 1;

        if (ratInMaze(arr, x + 1, y, n, solArr, visited))
            return true;

        if (ratInMaze(arr, x, y + 1, n, solArr, visited))
            return true;

        if (ratInMaze(arr, x - 1, y, n, solArr, visited))
            return true;

        if (ratInMaze(arr, x, y - 1, n, solArr, visited))
            return true;

        solArr[x][y] = 0;
        visited[x][y] = 0;
        return false;
    }

    return false;
}

int main()
{
    int n;
    cout << "Enter maze size (n x n): ";
    cin >> n;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    cout << "Enter the maze (0 = blocked, 1 = open):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Position [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
    cout << "Maze:\n";
    displayMaze(arr, n);

    int **solArr = new int *[n];
    int **visited = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solArr[i] = new int[n];
        visited[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            solArr[i][j] = 0;
            visited[i][j] = 0;
        }
    }

    if (ratInMaze(arr, 0, 0, n, solArr, visited))
    {
        cout << "Solution path:\n";
        displayMaze(solArr,  n);

    }
    else
    {
        cout << "No path exists.\n";
    }

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
        delete[] solArr[i];
        delete[] visited[i];
    }
    delete[] arr;
    delete[] solArr;
    delete[] visited;

    return 0;
}
