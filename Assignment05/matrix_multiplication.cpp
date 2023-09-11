#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <omp.h>

using namespace std;

void initializeMatrix(int size, vector<vector<int>>& matrix) {
    matrix.resize(size, vector<int>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            matrix[i][j] = rand() % 100 + 1; // Initialize with random values (1-100)
        }
    }
}

void printMatrix(const vector<vector<int> >& matrix, const string& title) {
//    cout << title << ":\n";
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << value << " ";
        }
//        cout << "\n";
    }
//    cout << "\n";
}

int main() {
    int numThreads, matrixSize;

    cout << "Enter the number of threads: ";
    cin >> numThreads;

    cout << "Enter the size of the square matrix: ";
    cin >> matrixSize;

    srand(time(nullptr)); // Initialize random number generator

    vector<vector<int>> matrixA, matrixB, result;

    // Initialize matrices with random values
    initializeMatrix(matrixSize, matrixA);
    initializeMatrix(matrixSize, matrixB);

    // Set the number of threads
    omp_set_num_threads(numThreads);

    // Parallel section for matrix summation
    double stime = omp_get_wtime();
    #pragma omp parallel shared(matrixA, matrixB, result)
    {
        #pragma omp for schedule(static)
        for (int i = 0; i < matrixSize; i++) {
            vector<int> row;
            for (int j = 0; j <= i; j++) {
                row.push_back(matrixA[i][j] + matrixB[i][j]);
            }
            result.push_back(row);
        }
    }
    double etime = omp_get_wtime();
    double time = etime - stime;


    cout<<"Time Taken is "<<time<<endl;
    return 0;
}
