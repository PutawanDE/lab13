#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void inputMatrix(double A[][N]){
	for(int i = 0; i < N; i++){
		cout << "Row " << i+1 << ": ";
		for(int j = 0; j < N; j++){
			cin >> A[i][j];
		}
	}
}

void findLocalMax(const double matrix[][N], bool res[][N]){
	int j, k = 0;
	for(j = 0; j < N; j++){
		for(k = 0; k < N; k++){
			double current = matrix[j][k];
			res[j][k] =  0;

			if(j > 0 && j < N - 1 && k > 0 && k < N - 1){
				if(current >= matrix[j][k-1] && current >= matrix[j][k+1] && 
					current >= matrix[j+1][k] && current >= matrix[j-1][k]){
					res[j][k] =  1;
				}
			} else {
				res[j][k] = 0;
			}
		}
	}
}

void showMatrix(const bool res[][N]){
	for(int j = 0; j < N; j++){
		for (int k = 0; k < N; k++){
			cout << res[j][k] << " ";
		}
		cout << "\n";
	}
}
 