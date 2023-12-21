#include "s21_matrix_oop.h"

namespace s21matrix {

void S21Matrix::AllocMemory() {
  matrix_ = new double *[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}

void S21Matrix::ClearMemory() {
  if (matrix_ != nullptr && rows_ != 0 && cols_ != 0) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
      matrix_[i] = nullptr;
    }
    delete[] matrix_;
    matrix_ = nullptr;
    rows_ = 0;
    cols_ = 0;
  }
}

S21Matrix::S21Matrix() : rows_(0), cols_(0) { matrix_ = nullptr; }

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows_ <= 0 || cols_ <= 0) {
    throw std::invalid_argument("Incorrect rows or columns input");
  }
  AllocMemory();
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_) {
  if (other.matrix_ == nullptr || other.rows_ == 0 || other.cols_ == 0) {
    throw std::invalid_argument("Incorrect input matrix");
  }
  AllocMemory();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix &&other) : matrix_(nullptr) {
  ClearMemory();
  matrix_ = other.matrix_;
  rows_ = other.rows_;
  cols_ = other.cols_;

  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

S21Matrix::~S21Matrix() { ClearMemory(); }

// Accessors
int S21Matrix::GetRows() const { return rows_; }

int S21Matrix::GetColumns() const { return cols_; }

// Mutators
void S21Matrix::SetRows(int new_value) {
  if (new_value <= 0) {
    throw std::invalid_argument("Incorrect rows input");
  }
  S21Matrix tmp(new_value, cols_);
  if (rows_ > new_value) {
    for (int i = 0; i < tmp.rows_; i++) {
      for (int j = 0; j < tmp.cols_; j++) {
        tmp.matrix_[i][j] = matrix_[i][j];
      }
    }
  } else if (rows_ < new_value) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        tmp.matrix_[i][j] = matrix_[i][j];
      }
    }
  }
  *this = tmp;
}

void S21Matrix::SetColumns(int new_value) {
  if (new_value <= 0) {
    throw std::invalid_argument("Incorrect columns input");
  }
  S21Matrix tmp(rows_, new_value);
  if (cols_ > new_value) {
    for (int i = 0; i < tmp.rows_; i++) {
      for (int j = 0; j < tmp.cols_; j++) {
        tmp.matrix_[i][j] = matrix_[i][j];
      }
    }
  } else if (cols_ < new_value) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        tmp.matrix_[i][j] = matrix_[i][j];
      }
    }
  }
  *this = tmp;
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double number) {
  S21Matrix result(*this);
  result.MulNumber(number);
  return result;
}

S21Matrix operator*(const double number, const S21Matrix &matrix) {
  S21Matrix result(matrix);
  result.MulNumber(number);
  return result;
}

bool S21Matrix::operator==(const S21Matrix &other) { return EqMatrix(other); }

// Присваивание копирования
S21Matrix S21Matrix::operator=(const S21Matrix &other) {
  if (this != &other) {
    ClearMemory();

    rows_ = other.rows_;
    cols_ = other.cols_;
    AllocMemory();

    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = other.matrix_[i][j];
      }
    }
  }
  return *this;
}

// Присваивание перемещения
S21Matrix S21Matrix::operator=(S21Matrix &&other) {
  if (this != &other) {
    ClearMemory();

    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = other.matrix_;

    other.matrix_ = nullptr;
    other.rows_ = 0;
    other.cols_ = 0;
  }
  return *this;
}

S21Matrix S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

double &S21Matrix::operator()(int row, int col) {
  if (row >= rows_ || col >= cols_) {
    throw std::out_of_range("Index is outside the matrix");
  }
  return matrix_[row][col];
}

double S21Matrix::operator()(int row, int col) const {
  if (row >= rows_ || col >= cols_) {
    throw std::out_of_range("Index is outside the matrix");
  }
  return matrix_[row][col];
}

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  bool result = true;

  if (cols_ == other.cols_ && rows_ == other.rows_) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        result = (fabs(matrix_[i][j] - other.matrix_[i][j]) < 1e-6);
      }
    }
  } else {
    result = false;
  }

  return result;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (matrix_ == nullptr || other.matrix_ == nullptr) {
    throw std::invalid_argument("Matrices is empty");
  } else if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Different size of matrices A and B");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (matrix_ == nullptr || other.matrix_ == nullptr) {
    throw std::invalid_argument("Matrices is empty");
  } else if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Different size of matrices A and B");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  if (matrix_ == nullptr || rows_ == 0 || cols_ == 0) {
    throw std::invalid_argument("Matrix is empty");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (matrix_ == nullptr || other.matrix_ == nullptr) {
    throw std::invalid_argument("Matrices is empty");
  } else if (cols_ != other.rows_) {
    throw std::invalid_argument(
        "Incorrect size of matrices for multiplication");
  }
  S21Matrix result(rows_, other.cols_);
  for (int x = 0; x < rows_; x++) {
    for (int j = 0; j < other.cols_; j++) {
      for (int i = 0; i < cols_; i++) {
        result.matrix_[x][j] += matrix_[x][i] * other.matrix_[i][j];
      }
    }
  }
  *this = result;
}

S21Matrix S21Matrix::Transpose() {
  if (matrix_ == nullptr || rows_ == 0 || cols_ == 0) {
    throw std::invalid_argument("Matrix is empty");
  }
  S21Matrix result(cols_, rows_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[i][j] = matrix_[j][i];
    }
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (matrix_ == nullptr || rows_ == 0 || cols_ == 0) {
    throw std::invalid_argument("Matrix is empty");
  } else if (rows_ != cols_) {
    throw std::out_of_range("The matrix is not square");
  }

  S21Matrix result(rows_, cols_);
  S21Matrix minor_tmp(rows_, cols_);

  if (rows_ == 1) {
    minor_tmp.matrix_[0][0] = 1;
  } else if (rows_ > 1) {
    minor_tmp.SetRows(rows_ - 1);
    minor_tmp.SetColumns(cols_ - 1);
  }

  double det_tmp = 0;

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      det_tmp = 0;
      if (rows_ > 1) minor_tmp.MinorMatrix(*this, i, j);
      det_tmp = minor_tmp.Determinant();
      result.matrix_[i][j] = det_tmp * pow(-1, i + j);
    }
  }

  return result;
}

void S21Matrix::MinorMatrix(const S21Matrix &other, int row, int col) {
  for (int i = 0, m_row = 0; i < other.rows_; i++) {
    for (int j = 0, m_col = 0; j < other.cols_; j++) {
      if (i != row && j != col) {
        matrix_[m_row][m_col] = other.matrix_[i][j];
        m_col++;
      }
    }
    if (i != row) m_row++;
  }
}

double S21Matrix::Determinant() {
  if (matrix_ == nullptr || rows_ == 0 || cols_ == 0) {
    throw std::invalid_argument("Matrix is empty");
  } else if (rows_ != cols_) {
    throw std::out_of_range("The matrix is not square");
  }

  double result = 0;
  int row = rows_, col = cols_;

  if (col == 1) {
    result = matrix_[0][0];
  } else if (col == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else if (col > 2) {
    // Начинаю идти по первой строке матрицы
    for (int i = 0; i < col; i++) {
      // Создаю буфферную матрицу для вычисления минора для А[i][j]
      S21Matrix matrix_tmp(row - 1, col - 1);
      // Находим минор матрицы для текущего элемента
      matrix_tmp.MinorMatrix(*this, 0, i);
      // Вычисляем детерминант матрицы с помощью рекурсии
      result += (pow(-1, i) * matrix_[0][i] * matrix_tmp.Determinant());
    }
  }

  return result;
}

S21Matrix S21Matrix::inverseMatrix() {
  double det_tmp = Determinant();
  if (det_tmp == 0) {
    throw std::out_of_range("Error. Matrix Determinant is 0");
  }

  int row = cols_, col = rows_;
  S21Matrix result(row, col);
  if (row == 1) {
    result.matrix_[0][0] = 1 / det_tmp;
  } else {
    result = CalcComplements().Transpose();
    result.MulNumber(1 / det_tmp);
  }
  return result;
}

}  // namespace s21matrix