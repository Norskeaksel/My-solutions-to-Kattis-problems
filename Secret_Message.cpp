#include <iostream>
#include <string>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--){
		int m = 0;
		string str;
		cin >> str;
		int l = str.size();
		while (m*m < l)
			m++;
		for (int i = 0; i < l - m; i++)
			str += "*";
		string board[100][100];
		int a = 0;
		for (int y = 0; y < m; y++) {
			for (int x = 0; x < m; x++) {
				board[x][y] = str[a];
				a++;
				//cout << board[x][y] << " ";
			}
			//cout << endl;
		}
		for (int x = 0; x < m; x++) {
			for (int y = m - 1; y >= 0; y--) {
				if(board[x][y]=="*"){}				
				else
					cout << board[x][y];// << " ";
			}
			//cout << endl;
		}
		cout << endl;
	}
}