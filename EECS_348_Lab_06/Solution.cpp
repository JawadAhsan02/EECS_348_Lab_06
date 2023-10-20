#include <iostream>
#include <fstream>

const int MAX_Size = 100;

void readMat(int matrix[MAX_Size][MAX_Size], int& size, const std::string& fileName) {
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        exit(1);
    }

    inputFile >> size;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            inputFile >> matrix[i][j];
        }
    }

    inputFile.close();
}

void printMat(int matrix[MAX_Size][MAX_Size], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void addMat(int matrixA[MAX_Size][MAX_Size], int matrixB[MAX_Size][MAX_Size], int result[MAX_Size][MAX_Size], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void subtractMat(int matrixA[MAX_Size][MAX_Size], int matrixB[MAX_Size][MAX_Size], int result[MAX_Size][MAX_Size], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

void multiplyMat(int matrixA[MAX_Size][MAX_Size], int matrixB[MAX_Size][MAX_Size], int result[MAX_Size][MAX_Size], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    int matrixA[MAX_Size][MAX_Size];
    int matrixB[MAX_Size][MAX_Size];
    int size;

    std::string fileNameA, fileNameB; // Corrected data type

    std::cout << "Enter the name of the input file for matrix A: ";
    std::cin >> fileNameA;
    readMat(matrixA, size, fileNameA);

    std::cout << "Enter the name of the input file for matrix B: ";
    std::cin >> fileNameB;
    readMat(matrixB, size, fileNameB);

    std::cout << "Matrix A:" << std::endl;
    printMat(matrixA, size);

    std::cout << "Matrix B:" << std::endl;
    printMat(matrixB, size);

    int result[MAX_Size][MAX_Size]; // Corrected data type

    addMat(matrixA, matrixB, result, size);
    std::cout << "Matrix Sum (A + B):" << std::endl;
    printMat(result, size);

    multiplyMat(matrixA, matrixB, result, size);
    std::cout << "Matrix Product (A * B):" << std::endl;
    printMat(result, size);

    subtractMat(matrixA, matrixB, result, size);
    std::cout << "Matrix Difference (A - B):" << std::endl;
    printMat(result, size);

    return 0;
}
