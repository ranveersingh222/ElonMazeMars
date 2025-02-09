#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 10; // Maze size
char maze[N][N];
pair<int, int> elon = {1, 1}; // Start position
pair<int, int> mars = {N - 2, N - 2}; // Mars position

void generateMaze() {
    srand(time(0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || j == 0 || i == N - 1 || j == N - 1) {
                maze[i][j] = '#'; // Walls
            } else {
                maze[i][j] = (rand() % 3) ? ' ' : '#'; // Random walls
            }
        }
    }
    maze[elon.first][elon.second] = 'E';
    maze[mars.first][mars.second] = 'M';
}

void printMaze() {
    system("clear");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

bool moveElon(char move) {
    int dx = 0, dy = 0;
    if (move == 'w') dx = -1;
    else if (move == 's') dx = 1;
    else if (move == 'a') dy = -1;
    else if (move == 'd') dy = 1;

    int nx = elon.first + dx, ny = elon.second + dy;
    if (maze[nx][ny] == ' ' || maze[nx][ny] == 'M') {
        maze[elon.first][elon.second] = ' ';
        elon = {nx, ny};
        maze[nx][ny] = 'E';
        return (nx == mars.first && ny == mars.second);
    }
    return false;
}

int main() {
    generateMaze();
    printMaze();

    char move;
    while (true) {
        cin >> move;
        if (moveElon(move)) {
            cout << "Elon reached Mars! 🚀\n";
            break;
        }
        printMaze();
    }
    return 0;
}
