#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

/*
*	Given a 2D board and a word, find if the word exists in the grid.

	The word can be constructed from letters of sequentially adjacent cell 
	where "adjacent" cells are those horizontally or vertically neighboring. 
	The same letter cell may not be used more than once.
	https://leetcode-cn.com/problems/word-search
*/

const int maxn = 250;
char board[maxn][maxn];
bool visited[maxn][maxn];
string word;
int n, m;

bool dfs(int x, int y, int m, int n, string to, int step) {
	if (x >= n || x < 0 || y >= m || y < 0) return false;
	if (visited[x][y]) return false;
	if (board[x][y] != to[step]) return false;
	else {
		visited[x][y] = 1;
		if (step == word.size()-1) return true;
		bool flag=dfs(x + 1, y, m, n, to, step + 1) || dfs(x - 1, y, m, n, to, step + 1) || dfs(x, y + 1, m, n, to, step + 1) || dfs(x, y - 1, m, n, to, step + 1);
		visited[x][y] = 0;
		return flag;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> board[i];
	cin >> word;
	bool flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(visited, 0, sizeof(visited));
			if (dfs(i, j, m, n, word, 0)) {
				flag = 1;
				break;
			}
		}
		if (flag) break;
	}
	if (flag) cout << "Success" << endl;
	else cout << "Failed" << endl;
	system("pause");
	return 0;
}
