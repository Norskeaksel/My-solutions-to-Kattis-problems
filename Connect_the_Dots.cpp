#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#else
#include<bits/stdc++.h>
using namespace std;
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 


#define dx first
#define dy second
#define forx(n) for (int x=1;x<=n;x++)
#define fory(n) for (int y=1;y<=n;y++)
#define rall(v) (v).rbegin(),(v).rend()
#define all(v) (v).begin(),(v).end()
#define fork(n) for (int k=0;k<n;k++)
#define forj(n) for (int j=0;j<n;j++)
#define fori(n) for (int i=0;i<n;i++)
#define in() int t; cin >> t; while(t--)
#define trav(v) for(auto &i:v)
#define pb(x) push_back(x)

vector<char> order;
pair<int,int> findZero(vector<string> matrix){
	for(int i=0;i<matrix.size();i++){
		forj(matrix[i].size()){
			if (matrix[i][j] == '0')
				return { i,j };
		}
	}
	return { -1,-1 };
}

string findWay(vector<string> matrix ,int &startRow, int &startCol,int &next){
	for(int col= startCol;col>=0;col--){
		if (matrix[startRow][col]==order[next]){
			next++;
			startCol = col;
			return "left";
		}
	}
	for (int col = startCol; col < matrix[startRow].size(); col++) {
		if (matrix[startRow][col] == order[next]) {
			next++;
			startCol = col;
			return "right";
		}
	}
	for (int row = startRow; row >= 0; row--) {
		if (matrix[row][startCol] == order[next]) {
			next++;
			startRow = row;
			return "up";
		}
	}
	for (int row = startRow; row < matrix.size(); row++) {
		if (matrix[row][startCol] == order[next]) {
			next++;
			startRow = row;
			return "down";
		}
	}
	return "done";
}
void print(vector<string> matrix){
	trav(matrix) {
		cout << i << endl;
	}
	cout << endl;
}
void draw(vector<string> matrix, set<char> exists){
	pair<int, int> rowcol = findZero(matrix);
	int next = 1;
	string way;
	while (rowcol != make_pair(-1, -1)) {
		int startRow = rowcol.first;
		int startCol = rowcol.second;
		way = findWay(matrix, rowcol.first, rowcol.second, next);
		if(way=="done")
			break;
		if(way=="down"){
			for(int row= startRow+1;row<rowcol.first;row++){
				if (matrix[row][startCol] == '.' || matrix[row][startCol]== '|')
					matrix[row][startCol] = '|';
				else if (!exists.count(matrix[row][startCol]))
						matrix[row][startCol] = '+';
			}
		}
		if (way == "up") {
			for (int row = startRow - 1; row > rowcol.first; row--) {
				if (matrix[row][startCol] == '.' || matrix[row][startCol] == '|')
					matrix[row][startCol] = '|';
				else if (!exists.count(matrix[row][startCol]))
					matrix[row][startCol] = '+';
			}
		}
		if (way == "left") {
			for (int col = startCol - 1; col > rowcol.second; col--) {
				if (matrix[startRow][col] == '.' || matrix[startRow][col] == '-')
					matrix[startRow][col] = '-';
				else if (!exists.count(matrix[startRow][col]))
					matrix[startRow][col] = '+';
			}
		}
		if (way == "right") {
			for (int col = startCol + 1; col < rowcol.second; col++) {
				if (matrix[startRow][col] == '.' || matrix[startRow][col] == '-')
					matrix[startRow][col] = '-';
				else if (!exists.count(matrix[startRow][col]))
					matrix[startRow][col] = '+';
			}
		}
		//print(matrix);
	}
	print(matrix);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	for(int number= 48; number<= 57;number++){
		order.push_back(number);
	}
	for(int smallLetter= 97;smallLetter<= 122;smallLetter++){
		order.push_back(smallLetter);
	}
	for(int bigLetters= 65;bigLetters<= 90;bigLetters++){
		order.push_back(bigLetters);
	}
	string row;
	set<char> exists(all(order));
	while (getline(cin, row)){
		vector<string> matrix;
		while(row!=""){
			matrix.push_back(row);
			getline(cin, row);
			if(!cin)
				break;
		}
		draw(matrix, exists);
	}
}