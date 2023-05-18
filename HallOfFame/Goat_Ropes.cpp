#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#else
#include<bits/stdc++.h>
using namespace std;
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen() 


#define fori(n) for (int i=0;i<n;i++)
#define pb(x) push_back(x)
#define all(v) (v).begin(),(v).end()
using ld = long double;
using vld = vector<ld>;

template<typename T>
void printVector(const T& t) {
	copy(t.cbegin(), t.cend(), ostream_iterator<typename T::value_type>(cout, "\t"));
	cout << "\n";
}

template<typename T>
void print2DVector(const T& t) {
	for_each(t.cbegin(), t.cend(), printVector<typename T::value_type>);
}

class Simplex {
	vector<vld> T;
	int pivotCol = -1;
	int pivotRow = -1;

public:
	vector<vld> getT() {
		return T;
	}
	Simplex(vector<vld>tablau) {
		T = tablau;
	}
	void pCol() {
		pivotCol = -1;
		ld value = 0;
		int colNr = -1;
		for (auto colVal : T[0]) {
			colNr++;
			if (colVal < value) {
				pivotCol = colNr;
				value = colVal;
			}
		}
	}

	void pRow() {
		if (pivotCol == -1) {
			pivotRow = -1;
			return;
		}

		int w = T[0].size() - 1;
		pivotRow = -1;
		ld FT = 123456789;
		int rowNr = -1;
		for (auto row : T) {
			rowNr++;
			if (row[pivotCol] == 0)
				continue;

			if (row[w] / row[pivotCol] < FT && row[w] / row[pivotCol]>0) {
				FT = row[w] / row[pivotCol];
				pivotRow = rowNr;
			}
		}
	}

	void rowDivide(ld factor, int changeRowNr) {
		int colNr = -1;
		for (auto col : T[changeRowNr]) {
			colNr++;
			T[changeRowNr][colNr] /= factor;
		}
	}

	void rowSubtrackt(int changeRowNr, ld factor, int orgRowNr) {
		int colNr = -1;
		for (auto col : T[changeRowNr]) {
			colNr++;
			T[changeRowNr][colNr] -= T[orgRowNr][colNr] * factor;
		}
	}

	int iterate() {
		pCol();
		pRow();
		if (pivotRow == -1)
			return -1;

		ld factor = T[pivotRow][pivotCol];
		rowDivide(factor, pivotRow);
		int rowNr = -1;
		for (auto row : T) {
			rowNr++;
			if (rowNr != pivotRow) {
				factor = T[rowNr][pivotCol];
				rowSubtrackt(rowNr, factor, pivotRow);
			}
		}
		return 0;
	}

};

ld distanceBetweenPoints(pair<ld, ld> xy1, pair<ld, ld>xy2) {
	return sqrt((pow(xy2.first - xy1.first, 2) + pow(xy2.second - xy1.second, 2)));
}

//finner alle kombinasjoner av tall i en vektor
auto findPermutations(vld a) {
	sort(all(a));
	//vector<vld>permutations;
	set<vld> permutations;
	do {
		//permutations.push_back(a);
		permutations.insert(a);
	} while (::next_permutation(all(a)));
	return permutations;
}


vector<vld> createTablou(int n, vector<pair<ld, ld>> points) {
	//max Z=cx
	//s.t.
	//Ax=b
	int nrOfEq = n * (n - 1) / 2;
	int h = nrOfEq + 1;
	int w = n + nrOfEq + 1;
	vector<vld> T(h, vld(w, 0));

	// build c
	fori(n) {
		T[0][i] = -1;
	}

	// build A
	vld poles(n, 0);
	poles[0] = 1;
	poles[1] = 1;
	set<vld> permutationSet = findPermutations(poles);
	vector<vld> permutation;
	permutation.assign(all(permutationSet));
	//print2DVector(permutation);
	int i = -2;
	int s = 0;
	for (auto &row : T) {
		i++;
		if (i == -1)
			continue;
		row = permutation[i];
		fori(nrOfEq + 1) {
			if (i == s)
				row.pb(1);
			else
				row.pb(0);
		}
		s++;
	}
	//print2DVector(T);
	// build b
	int rowNr = 0;
	for (int rowNr = 1; rowNr < h; rowNr++) {
		pair<ld, ld> xy1 = { -1,-1 }, xy2 = { -1,-1 };
		fori(n) {
			if (T[rowNr][i] == 1) {
				if (xy1 == xy2)
					xy1 = points[i];
				else
					xy2 = points[i];
			}
		}
		T[rowNr][w - 1] = distanceBetweenPoints(xy1, xy2);
		//print2DVector(T);
	}
	//print2DVector(T);
	return T;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER 
	freopen("Text.txt", "r", stdin);//read all input form this local file 
#endif
	int n, a, b;
	cin >> n;
	vector<pair<ld, ld>> points;
	fori(n) {
		cin >> a >> b;
		points.pb(make_pair(a, b));
	}

	vector<vld>tablau = createTablou(n, points);
	//print2DVector(tablau);
	Simplex solve(tablau);
	int d = 0;
	do {
		//print2DVector(solve.getT());
		//cout << endl;
		d = solve.iterate();
	} while (d == 0);

	vector<vld>finalTablau = solve.getT();
	//print2DVector(finalTablau);
	int w = finalTablau[0].size() - 1;
	cout << fixed << setprecision(2) << finalTablau[0][w] << endl;
}