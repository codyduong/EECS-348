#include <iostream>
#include <fstream>
using namespace std;

#define MAX_SIZE 100

void readMatrix(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int &size, const char *filename)
{
  ifstream fin(filename);
  if (!fin.is_open())
  {
    cerr << "Error: Could not open file " << filename << endl;
    return;
  }

  // read first line into size reference
  fin >> size;

  // read first matrix
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      fin >> matrix1[i][j];
    }
  }

  // read second matrix
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      fin >> matrix2[i][j];
    }
  }

  fin.close();
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

void addMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
}

void multiplyMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      for (int k = 0; k < size; k++)
      {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
}

void subtractMatrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      result[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }
}

int main()
{
  // declare and initialize the empty matrices
  int matrixA[MAX_SIZE][MAX_SIZE];
  int matrixB[MAX_SIZE][MAX_SIZE];
  int matrixSum[MAX_SIZE][MAX_SIZE];
  int matrixProduct[MAX_SIZE][MAX_SIZE];
  int matrixDifference[MAX_SIZE][MAX_SIZE];
  int size = MAX_SIZE;
  readMatrix(matrixA, matrixB, size, "matrix_input.txt");

  std::cout << "Cody Duong\nLab #6: Matrix Multiplication" << endl;

  cout << "\nMatrix A:\n";
  printMatrix(matrixA, size);

  cout << "\nMatrix B:\n";
  printMatrix(matrixB, size);

  cout << "\nMatrix Sum (A + B):\n";
  addMatrices(matrixA, matrixB, matrixSum, size);
  printMatrix(matrixSum, size);

  cout << "\nMatrix Product (A * B):\n";
  multiplyMatrices(matrixA, matrixB, matrixProduct, size);
  printMatrix(matrixProduct, size);

  cout << "\nMatrix Difference (A - B):\n";
  subtractMatrices(matrixA, matrixB, matrixDifference, size);
  printMatrix(matrixDifference, size);

  return 0;
}