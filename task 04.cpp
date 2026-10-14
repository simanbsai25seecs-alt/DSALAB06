#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int cx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int cy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool isValid(int x, int y, int n, const vector<vector<int>>& board) {
	return (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == -1);
}

bool solveKnightTourUtil(int x, int y, int moveCount, vector<vector<int>>& board, int n) {
	if (moveCount == n * n) {
		return true;
	}

	for (int i = 0; i < 8; i++) {
		int nextX = x + cx[i];
		int nextY = y + cy[i];

		if (isValid(nextX, nextY, n, board)) {
			board[nextX][nextY] = moveCount;
			if (solveKnightTourUtil(nextX, nextY, moveCount + 1, board, n)) {
				return true;
			}
			board[nextX][nextY] = -1;
		}
	}

	return false;
}

void printBoard(const vector<vector<int>>& board, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(4) << board[i][j];
		}
		cout << "\n";
	}
}

int main() {
	int n;
	cout << "Enter board size N: ";
	cin >> n;

	if (n < 1) {
		cout << "Invalid board size!\n";
		return 1;
	}

	int startX, startY;
	cout << "Enter starting position (row and col, 0-indexed): ";
	cin >> startX >> startY;

	if (startX < 0 || startX >= n || startY < 0 || startY >= n) {
		cout << "Error: Starting position is outside the board bounds!\n";
		return 1;
	}

	vector<vector<int>> board(n, vector<int>(n, -1));

	board[startX][startY] = 0;

	if (solveKnightTourUtil(startX, startY, 1, board, n)) {
		cout << "\nKnight's Tour successfully found:\n";
		printBoard(board, n);
	}
	else {
		cout << "\nNo valid Knight's Tour found for the specified starting position.\n";
	}

	return 0;
}