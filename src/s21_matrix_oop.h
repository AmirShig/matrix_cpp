#ifndef CPP1_S21_MATRIXPLUS_1_SRC_S21_MATRIX_OOP_H
#define CPP1_S21_MATRIXPLUS_1_SRC_S21_MATRIX_OOP_H

#include <cmath>
#include <iostream>

namespace s21matrix {

class S21Matrix {
 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other);

  S21Matrix operator=(const S21Matrix &other);
  S21Matrix operator=(S21Matrix &&other);

  ~S21Matrix();

  // Operators
  bool operator==(const S21Matrix &other);
  S21Matrix operator+(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other);
  S21Matrix operator*(const S21Matrix &other);

  S21Matrix operator+=(const S21Matrix &other);
  S21Matrix operator-=(const S21Matrix &other);

  S21Matrix operator*(const double number);
  friend S21Matrix operator*(const double number, const S21Matrix &matrix);

  S21Matrix operator*=(const S21Matrix &other);
  S21Matrix operator*=(const double num);
  double &operator()(int row, int col);
  double operator()(int row, int col) const;

  bool EqMatrix(const S21Matrix &other);
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);

  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix inverseMatrix();

  // Accessors
  int GetRows() const;
  int GetColumns() const;

  // Mutators
  void SetRows(int new_value);
  void SetColumns(int new_value);

 private:
  int rows_, cols_;
  double **matrix_;

  void ClearMemory();
  void AllocMemory();
  void MinorMatrix(const S21Matrix &other, int row, int col);
};

}  // namespace s21matrix

#endif  // CPP1_S21_MATRIXPLUS_1_SRC_S21_MATRIX_OOP_H
