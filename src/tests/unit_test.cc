#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(Constructors, Basic_constructor) {
  s21matrix::S21Matrix m0;
  EXPECT_EQ(m0.GetRows(), 0);
  EXPECT_EQ(m0.GetColumns(), 0);
}

TEST(Constructors, Parametrized_constructor_1) {
  s21matrix::S21Matrix m1(1, 1);
  EXPECT_EQ(m1.GetRows(), 1);
  EXPECT_EQ(m1.GetColumns(), 1);
}

TEST(Constructors, Parametrized_constructor_2) {
  s21matrix::S21Matrix m4x3(11, 2);
  EXPECT_EQ(m4x3.GetRows(), 11);
  EXPECT_EQ(m4x3.GetColumns(), 2);
}

TEST(Constructors, Parameterized_constructor_3) {
  EXPECT_ANY_THROW(s21matrix::S21Matrix m(0, 0););
}

TEST(Constructors, Parameterized_constructor_4) {
  EXPECT_ANY_THROW(s21matrix::S21Matrix m(0, 1););
}

TEST(Constructors, Parameterized_constructor_5) {
  EXPECT_ANY_THROW(s21matrix::S21Matrix m(100, 0););
}

TEST(Constructors, Parameterized_constructor_6) {
  EXPECT_ANY_THROW(s21matrix::S21Matrix m(-1, 0););
}

TEST(Сonstructors, Copy_constructor_1) {
  s21matrix::S21Matrix A(5, 5);

  A(0, 0) = 0123;
  A(1, 1) = 1234;
  A(2, 2) = 2123;
  A(3, 3) = 34561;
  A(4, 4) = 4123;

  s21matrix::S21Matrix B = A;
  bool result = A.EqMatrix(B);
  EXPECT_TRUE(result);
}

TEST(Сonstructors, Copy_constructor_2) {
  s21matrix::S21Matrix A;

  EXPECT_ANY_THROW(s21matrix::S21Matrix B = A);
}

TEST(Сonstructors, Copy_constructor_4) {
  s21matrix::S21Matrix A(5, 5);
  s21matrix::S21Matrix B(2, 3);

  A(0, 0) = 17;
  A(4, 3) = 1234;
  A(2, 1) = 4123;

  B = A;
  bool result = A.EqMatrix(B);
  EXPECT_TRUE(result);
}

TEST(Сonstructors, Copy_constructor_5) {
  s21matrix::S21Matrix A(4, 4);
  s21matrix::S21Matrix B = A;
  bool result = A.EqMatrix(B);
  EXPECT_TRUE(result);
}

TEST(Сonstructors, Copy_constructor_6) {
  s21matrix::S21Matrix A(4, 4);
  s21matrix::S21Matrix B;
  A(0, 0) = 1;
  A(2, 3) = 3.14;

  B = A;
  bool result = A.EqMatrix(B);
  EXPECT_TRUE(result);
}

TEST(Сonstructors, Move_constructor_1) {
  s21matrix::S21Matrix A(3, 3);
  s21matrix::S21Matrix B(std::move(A));
  EXPECT_EQ(B.GetRows(), 3);
  EXPECT_EQ(B.GetColumns(), 3);
}

TEST(Сonstructors, Move_constructor_2) {
  s21matrix::S21Matrix A;
  s21matrix::S21Matrix B(std::move(A));
  EXPECT_EQ(B.GetRows(), 0);
  EXPECT_EQ(B.GetColumns(), 0);
}

TEST(Сonstructors, Move_constructor_3) {
  s21matrix::S21Matrix A(1, 2);

  A(0, 0) = 1;
  A(0, 1) = 15.134;

  s21matrix::S21Matrix expected = A;
  s21matrix::S21Matrix B(std::move(A));

  EXPECT_EQ(B.GetRows(), 1);
  EXPECT_EQ(B.GetColumns(), 2);
  EXPECT_EQ(A.GetRows(), 0);
  EXPECT_EQ(A.GetColumns(), 0);

  EXPECT_TRUE(B.EqMatrix(expected));
}

TEST(Сonstructors, Move_constructor_4) {
  s21matrix::S21Matrix A(3, 3);

  A(0, 0) = 11.345;
  A(0, 1) = 12.134;
  A(0, 2) = 13.134;
  A(1, 0) = 21.123;
  A(1, 1) = 22.134;
  A(1, 2) = 23.134;
  A(2, 0) = 31.123;
  A(2, 1) = 32.134;
  A(2, 2) = 33.134;

  s21matrix::S21Matrix expected = A;
  s21matrix::S21Matrix B(std::move(A));

  EXPECT_EQ(B.GetRows(), 3);
  EXPECT_EQ(B.GetColumns(), 3);
  EXPECT_EQ(A.GetRows(), 0);
  EXPECT_EQ(A.GetColumns(), 0);

  EXPECT_TRUE(B.EqMatrix(expected));
}

TEST(Сonstructors, Move_constructor_5) {
  s21matrix::S21Matrix A(3, 3);

  A(0, 0) = 11.345;
  A(0, 1) = 12.134;
  A(0, 2) = 13.134;
  A(1, 0) = 21.123;
  A(1, 1) = 22.134;
  A(1, 2) = 23.134;
  A(2, 0) = 31.123;
  A(2, 1) = 32.134;
  A(2, 2) = 33.134;

  s21matrix::S21Matrix expected = A;
  s21matrix::S21Matrix B = std::move(A);

  EXPECT_EQ(B.GetRows(), 3);
  EXPECT_EQ(B.GetColumns(), 3);
  EXPECT_EQ(A.GetRows(), 0);
  EXPECT_EQ(A.GetColumns(), 0);

  EXPECT_TRUE(B.EqMatrix(expected));
}

TEST(EqMatrix, EqMatrix_1) {
  s21matrix::S21Matrix A(3, 3);

  A(0, 0) = 11.345;
  A(0, 1) = 12.134;
  A(0, 2) = 13.134;
  A(1, 0) = 21.123;
  A(1, 1) = 22.134;
  A(1, 2) = 23.134;
  A(2, 0) = 31.123;
  A(2, 1) = 32.134;
  A(2, 2) = 33.134;

  s21matrix::S21Matrix B(3, 3);

  B(0, 0) = 11.345;
  B(0, 1) = 12.134;
  B(0, 2) = 13.134;
  B(1, 0) = 21.123;
  B(1, 1) = 22.134;
  B(1, 2) = 23.134;
  B(2, 0) = 31.123;
  B(2, 1) = 32.134;
  B(2, 2) = 33.134;

  bool result = A.EqMatrix(B);
  EXPECT_TRUE(result);
}

TEST(EqMatrix, EqMatrix_2) {
  s21matrix::S21Matrix A(3, 1);

  s21matrix::S21Matrix B(3, 3);

  bool result = A.EqMatrix(B);
  EXPECT_FALSE(result);
}

TEST(Operators, EqMatrix_3) {
  s21matrix::S21Matrix A(1, 1);
  s21matrix::S21Matrix B(1, 1);

  bool result = A.EqMatrix(B);
  EXPECT_TRUE(result);
}

TEST(SumMatrix, test_1) {
  s21matrix::S21Matrix A(2, 2);
  s21matrix::S21Matrix B(2, 2);
  s21matrix::S21Matrix expected(2, 2);

  A(0, 0) = 1;
  A(0, 1) = 10;
  A(1, 0) = 1.1;
  A(1, 1) = 10.1;

  B(0, 0) = 5;
  B(0, 1) = 50;
  B(1, 0) = 5.1;
  B(1, 1) = 50.1;

  expected(0, 0) = 6;
  expected(0, 1) = 60;
  expected(1, 0) = 6.2;
  expected(1, 1) = 60.2;

  A.SumMatrix(B);
  EXPECT_TRUE(A.EqMatrix(expected));
}

TEST(SumMatrix, test_2) {
  s21matrix::S21Matrix A(1, 2);
  s21matrix::S21Matrix B(1, 2);
  s21matrix::S21Matrix expected(1, 2);

  A(0, 0) = 1;
  A(0, 1) = 10;

  B(0, 0) = 5;
  B(0, 1) = 50;

  expected(0, 0) = 6;
  expected(0, 1) = 60;

  A.SumMatrix(B);
  EXPECT_TRUE(A.EqMatrix(expected));
}

TEST(SumMatrix, test_3) {
  s21matrix::S21Matrix A(1, 2);
  s21matrix::S21Matrix B(2, 1);

  A(0, 0) = 1;
  A(0, 1) = 10;

  B(0, 0) = 5;
  B(1, 0) = 5.1;

  EXPECT_ANY_THROW(A.SumMatrix(B));
}

TEST(SumMatrix, test_4) {
  s21matrix::S21Matrix A(3, 5);
  s21matrix::S21Matrix B(3, 5);
  s21matrix::S21Matrix expected(3, 5);

  A(0, 0) = 10;
  A(2, 4) = 1;

  B(0, 1) = 5;
  B(1, 2) = 5.1;

  expected(0, 0) = 10;
  expected(2, 4) = 1;
  expected(0, 1) = 5;
  expected(1, 2) = 5.1;

  A.SumMatrix(B);
  EXPECT_TRUE(A.EqMatrix(expected));
}

TEST(SubMatrix, test_1) {
  s21matrix::S21Matrix A(2, 2);
  s21matrix::S21Matrix B(2, 2);
  s21matrix::S21Matrix expected(2, 2);

  A(0, 0) = 10;
  A(0, 1) = 10;
  A(1, 0) = 10;
  A(1, 1) = 10;

  B(0, 0) = 5;
  B(0, 1) = 50;
  B(1, 0) = 5.5;
  B(1, 1) = 55.5;

  expected(0, 0) = 5;
  expected(0, 1) = -40;
  expected(1, 0) = 4.5;
  expected(1, 1) = -45.5;

  A.SubMatrix(B);
  EXPECT_TRUE(A.EqMatrix(expected));
}

TEST(SubMatrix, test_2) {
  s21matrix::S21Matrix A(1, 2);
  s21matrix::S21Matrix B(1, 2);
  s21matrix::S21Matrix expected(1, 2);

  A(0, 0) = 1;
  A(0, 1) = 10;

  B(0, 0) = 5;
  B(0, 1) = 50;

  expected(0, 0) = -4;
  expected(0, 1) = -40;

  A.SubMatrix(B);
  EXPECT_TRUE(A.EqMatrix(expected));
}

TEST(SubMatrix, test_3) {
  s21matrix::S21Matrix A(1, 2);
  s21matrix::S21Matrix B(2, 1);

  A(0, 0) = 1;
  A(0, 1) = 10;

  B(0, 0) = 5;
  B(1, 0) = 5.1;

  EXPECT_ANY_THROW(A.SubMatrix(B));
}

TEST(SubMatrix, test_4) {
  s21matrix::S21Matrix A(3, 5);
  s21matrix::S21Matrix B(3, 5);
  s21matrix::S21Matrix expected(3, 5);

  A(0, 0) = 10;
  A(2, 4) = 1;

  B(0, 1) = 5;
  B(1, 2) = 5.1;

  expected(0, 0) = 10;
  expected(0, 1) = -5;
  expected(1, 2) = -5.1;
  expected(2, 4) = 1;

  A.SubMatrix(B);
  EXPECT_TRUE(A.EqMatrix(expected));
}

TEST(MulNumber, test_1) {
  s21matrix::S21Matrix A(2, 2), expected(2, 2);
  double number = 0.5;

  A(0, 0) = 1.0;
  A(0, 1) = 1.0;
  A(1, 0) = 1.0;
  A(1, 1) = 1.0;

  expected(0, 0) = 0.5;
  expected(0, 1) = 0.5;
  expected(1, 0) = 0.5;
  expected(1, 1) = 0.5;

  A.MulNumber(number);
  EXPECT_TRUE(A.EqMatrix(expected));
}

TEST(MulNumber, test_2) {
  s21matrix::S21Matrix A(2, 2), expected(2, 2);
  double number = 1000000.0;

  A(0, 0) = 1000000.0;
  A(0, 1) = 1000000.0;
  A(1, 0) = 1000000.0;
  A(1, 1) = 1000000.0;

  expected(0, 0) = 1000000000000.0;
  expected(0, 1) = 1000000000000.0;
  expected(1, 0) = 1000000000000.0;
  expected(1, 1) = 1000000000000.0;

  A.MulNumber(number);
  EXPECT_TRUE(A.EqMatrix(expected));
}

TEST(MulNumber, test_3) {
  s21matrix::S21Matrix A(2, 2), expected(2, 2);
  double number = 2.0;

  A(0, 0) = 3.2;
  A(0, 1) = 4.5;
  A(1, 0) = 6.7;
  A(1, 1) = 8.9;

  expected(0, 0) = 6.4;
  expected(0, 1) = 9.0;
  expected(1, 0) = 13.4;
  expected(1, 1) = 17.8;

  A.MulNumber(number);
  EXPECT_TRUE(A.EqMatrix(expected));
}

TEST(MulNumber, test_4) {
  s21matrix::S21Matrix A(2, 2), expected(2, 2);
  double number = 2.0;

  A(0, 0) = 0.0;
  A(0, 1) = 0.0;
  A(1, 0) = 0.0;
  A(1, 1) = 0.0;

  expected(0, 0) = 0.0;
  expected(0, 1) = 0.0;
  expected(1, 0) = 0.0;
  expected(1, 1) = 0.0;
  A.MulNumber(number);
  EXPECT_TRUE(A.EqMatrix(expected));
}

TEST(MulMatrix, test_1) {
  s21matrix::S21Matrix A(3, 2);
  s21matrix::S21Matrix B(2, 3);
  s21matrix::S21Matrix expected(3, 3);

  A(0, 0) = 0;
  A(0, 1) = 1;
  A(1, 0) = 3;
  A(1, 1) = 4;
  A(2, 0) = 6;
  A(2, 1) = 7;

  B(0, 0) = 9;
  B(0, 1) = 8;
  B(0, 2) = 7;
  B(1, 0) = 6;
  B(1, 1) = 5;
  B(1, 2) = 4;

  expected(0, 0) = 6;
  expected(0, 1) = 5;
  expected(0, 2) = 4;
  expected(1, 0) = 51;
  expected(1, 1) = 44;
  expected(1, 2) = 37;
  expected(2, 0) = 96;
  expected(2, 1) = 83;
  expected(2, 2) = 70;

  A.MulMatrix(B);
  EXPECT_TRUE(A.EqMatrix(expected));
}

TEST(MulMatrix, test_2) {
  s21matrix::S21Matrix A(1, 1);
  s21matrix::S21Matrix B(1, 1);
  s21matrix::S21Matrix expected(1, 1);

  A(0, 0) = -1;
  B(0, 0) = 5;
  expected(0, 0) = -5;

  A.MulMatrix(B);
  EXPECT_TRUE(A.EqMatrix(expected));
}

TEST(MulMatrix, test_3) {
  s21matrix::S21Matrix A(3, 1);
  s21matrix::S21Matrix B(2, 2);

  EXPECT_ANY_THROW(A.MulMatrix(B));
}

TEST(MulMatrix, test_4) {
  s21matrix::S21Matrix A(1, 1);
  s21matrix::S21Matrix B(2, 2);

  EXPECT_ANY_THROW(A.MulMatrix(B));
}

TEST(MulMatrix, test_5) {
  s21matrix::S21Matrix A(2, 2);
  s21matrix::S21Matrix B(1, 1);

  EXPECT_ANY_THROW(A.MulMatrix(B));
}

TEST(Transpose, test_1) {
  s21matrix::S21Matrix A(1, 1);
  s21matrix::S21Matrix expected(1, 1);

  A(0, 0) = 1.25;
  expected(0, 0) = 1.25;

  s21matrix::S21Matrix result = A.Transpose();

  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(Transpose, test_2) {
  s21matrix::S21Matrix A(3, 3);
  s21matrix::S21Matrix expected(3, 3);

  A(0, 0) = 0.25;
  A(0, 1) = 1.25;
  A(0, 2) = 2.25;
  A(1, 0) = 3.25;
  A(1, 1) = 4.25;
  A(1, 2) = 5.25;
  A(2, 0) = 6.25;
  A(2, 1) = 7.25;
  A(2, 2) = 8.25;

  expected(0, 0) = 0.25;
  expected(1, 0) = 1.25;
  expected(2, 0) = 2.25;
  expected(0, 1) = 3.25;
  expected(1, 1) = 4.25;
  expected(2, 1) = 5.25;
  expected(0, 2) = 6.25;
  expected(1, 2) = 7.25;
  expected(2, 2) = 8.25;

  s21matrix::S21Matrix result = A.Transpose();

  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(Transpose, test_3) {
  s21matrix::S21Matrix A;
  EXPECT_ANY_THROW(A.Transpose());
}

TEST(CalcComplements, test_1) {
  s21matrix::S21Matrix A(3, 3);
  s21matrix::S21Matrix expected(3, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 0;
  A(1, 1) = 4;
  A(1, 2) = 2;
  A(2, 0) = 5;
  A(2, 1) = 2;
  A(2, 2) = 1;

  expected(0, 0) = 0;
  expected(0, 1) = 10;
  expected(0, 2) = -20;
  expected(1, 0) = 4;
  expected(1, 1) = -14;
  expected(1, 2) = 8;
  expected(2, 0) = -8;
  expected(2, 1) = -2;
  expected(2, 2) = 4;

  s21matrix::S21Matrix result = A.CalcComplements();

  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(CalcComplements, test_2) {
  s21matrix::S21Matrix A(3, 3);
  s21matrix::S21Matrix expected(3, 3);

  A(0, 0) = 5;
  A(0, 1) = -1;
  A(0, 2) = 1;
  A(1, 0) = 2;
  A(1, 1) = 3;
  A(1, 2) = 4;
  A(2, 0) = 1;
  A(2, 1) = 0;
  A(2, 2) = 3;

  expected(0, 0) = 9;
  expected(0, 1) = -2;
  expected(0, 2) = -3;
  expected(1, 0) = 3;
  expected(1, 1) = 14;
  expected(1, 2) = -1;
  expected(2, 0) = -7;
  expected(2, 1) = -18;
  expected(2, 2) = 17;

  s21matrix::S21Matrix result = A.CalcComplements();

  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(CalcComplements, test_3) {
  s21matrix::S21Matrix A(1, 1);
  s21matrix::S21Matrix expected(1, 1);

  A(0, 0) = 5;

  expected(0, 0) = 1;

  s21matrix::S21Matrix result = A.CalcComplements();

  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(CalcComplements, test_4) {
  s21matrix::S21Matrix A(3, 2);

  EXPECT_ANY_THROW(A.CalcComplements());
}

TEST(CalcComplements, test_5) {
  s21matrix::S21Matrix A;

  EXPECT_ANY_THROW(A.CalcComplements());
}

TEST(Determinant, test_1) {
  s21matrix::S21Matrix A(1, 1);
  A(0, 0) = 1.25;
  double expected = 1.25;

  double result = A.Determinant();

  EXPECT_TRUE(fabs(expected - result) < 1e-7);
}

TEST(Determinant, test_2) {
  s21matrix::S21Matrix A(3, 3);
  double result = 0, expected = -69;

  A(0, 0) = 0.25;
  A(0, 1) = 1.25;
  A(0, 2) = 2.25;
  A(1, 0) = 3.25;
  A(1, 1) = 10;
  A(1, 2) = 5.25;
  A(2, 0) = 6.25;
  A(2, 1) = 7.25;
  A(2, 2) = 8.25;

  result = A.Determinant();

  EXPECT_TRUE(fabs(expected - result) < 1e-7);
}

TEST(Determinant, test_3) {
  s21matrix::S21Matrix A(2, 2);
  double result = 0, expected = 6;

  A(0, 0) = 2;
  A(0, 1) = 4;
  A(1, 0) = -5;
  A(1, 1) = -7;

  result = A.Determinant();

  EXPECT_TRUE(fabs(expected - result) < 1e-7);
}

TEST(Determinant, test_4) {
  s21matrix::S21Matrix A(3, 3);
  double result = 0, expected = -2;

  A(0, 0) = 2;
  A(0, 1) = 4;
  A(0, 2) = -6;
  A(1, 0) = -5;
  A(1, 1) = -7;
  A(1, 2) = 5;
  A(2, 0) = 3;
  A(2, 1) = 5;
  A(2, 2) = -6;

  result = A.Determinant();

  EXPECT_TRUE(fabs(expected - result) < 1e-7);
}

TEST(Determinant, test_5) {
  s21matrix::S21Matrix A;
  EXPECT_ANY_THROW(A.Determinant());
}

TEST(InverseMatrix, test_1) {
  s21matrix::S21Matrix A(3, 3);
  s21matrix::S21Matrix expected(3, 3);

  A(0, 0) = 2.8;
  A(0, 1) = 1.3;
  A(0, 2) = 7.01;
  A(1, 0) = -1.03;
  A(1, 1) = -2.3;
  A(1, 2) = 3.01;
  A(2, 0) = 0;
  A(2, 1) = -3;
  A(2, 2) = 2;

  expected(0, 0) = 44300.0 / 367429.0;
  expected(0, 1) = -236300.0 / 367429.0;
  expected(0, 2) = 200360.0 / 367429.0;
  expected(1, 0) = 20600.0 / 367429.0;
  expected(1, 1) = 56000.0 / 367429.0;
  expected(1, 2) = -156483.0 / 367429.0;
  expected(2, 0) = 30900.0 / 367429.0;
  expected(2, 1) = 84000.0 / 367429.0;
  expected(2, 2) = -51010.0 / 367429.0;

  s21matrix::S21Matrix result = A.inverseMatrix();

  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(InverseMatrix, test_2) {
  s21matrix::S21Matrix A(3, 3);
  s21matrix::S21Matrix expected(3, 3);

  A(0, 0) = 2.0;
  A(0, 1) = 5.0;
  A(0, 2) = 7.0;
  A(1, 0) = 6.0;
  A(1, 1) = 3.0;
  A(1, 2) = 4.0;
  A(2, 0) = 5.0;
  A(2, 1) = -2.0;
  A(2, 2) = -3.0;

  expected(0, 0) = 1.0;
  expected(0, 1) = -1.0;
  expected(0, 2) = 1.0;
  expected(1, 0) = -38.0;
  expected(1, 1) = 41.0;
  expected(1, 2) = -34.0;
  expected(2, 0) = 27.0;
  expected(2, 1) = -29.0;
  expected(2, 2) = 24.0;

  s21matrix::S21Matrix result = A.inverseMatrix();

  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(InverseMatrix, test_3) {
  s21matrix::S21Matrix A(3, 3);
  s21matrix::S21Matrix expected(3, 3);

  A(0, 0) = 2;
  A(0, 1) = 5;
  A(0, 2) = 7;
  A(1, 0) = 6;
  A(1, 1) = 3;
  A(1, 2) = 4;
  A(2, 0) = 5;
  A(2, 1) = -2;
  A(2, 2) = -3;

  expected(0, 0) = 1;
  expected(0, 1) = -1;
  expected(0, 2) = 1;
  expected(1, 0) = -38;
  expected(1, 1) = 41;
  expected(1, 2) = -34;
  expected(2, 0) = 27;
  expected(2, 1) = -29;
  expected(2, 2) = 24;

  s21matrix::S21Matrix result = A.inverseMatrix();

  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(InverseMatrix, test_4) {
  s21matrix::S21Matrix A(3, 2);

  EXPECT_ANY_THROW(A.inverseMatrix());
}

TEST(InverseMatrix, test_5) {
  s21matrix::S21Matrix A;

  EXPECT_ANY_THROW(A.inverseMatrix());
}

TEST(InverseMatrix, test_6) {
  s21matrix::S21Matrix A(1, 1);
  s21matrix::S21Matrix expected(1, 1);

  A(0, 0) = 2;

  expected(0, 0) = 0.5;

  s21matrix::S21Matrix result = A.inverseMatrix();

  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(InverseMatrix, test_7) {
  s21matrix::S21Matrix A(3, 3);

  EXPECT_ANY_THROW(A.inverseMatrix());
}

TEST(OperatorEqMatrix, EqMatrix_1) {
  s21matrix::S21Matrix A(3, 3);

  A(0, 0) = 11.345;
  A(0, 1) = 12.134;
  A(0, 2) = 13.134;
  A(1, 0) = 21.123;
  A(1, 1) = 22.134;
  A(1, 2) = 23.134;
  A(2, 0) = 31.123;
  A(2, 1) = 32.134;
  A(2, 2) = 33.134;

  s21matrix::S21Matrix B(3, 3);

  B(0, 0) = 11.345;
  B(0, 1) = 12.134;
  B(0, 2) = 13.134;
  B(1, 0) = 21.123;
  B(1, 1) = 22.134;
  B(1, 2) = 23.134;
  B(2, 0) = 31.123;
  B(2, 1) = 32.134;
  B(2, 2) = 33.134;

  EXPECT_TRUE(A == B);
}

TEST(OperatorEqMatrix, EqMatrix_2) {
  s21matrix::S21Matrix A(3, 1);

  s21matrix::S21Matrix B(3, 3);

  EXPECT_FALSE(A == B);
}

TEST(OperatorPlus, test_1) {
  s21matrix::S21Matrix A(2, 2);
  s21matrix::S21Matrix B(2, 2);
  s21matrix::S21Matrix expected(2, 2);

  A(0, 0) = 1;
  A(0, 1) = 10;
  A(1, 0) = 1.1;
  A(1, 1) = 10.1;

  B(0, 0) = 5;
  B(0, 1) = 50;
  B(1, 0) = 5.1;
  B(1, 1) = 50.1;

  expected(0, 0) = 6;
  expected(0, 1) = 60;
  expected(1, 0) = 6.2;
  expected(1, 1) = 60.2;

  s21matrix::S21Matrix result = A + B;

  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(OperatorPlus, test_2) {
  s21matrix::S21Matrix A(1, 2);
  s21matrix::S21Matrix B(1, 2);
  s21matrix::S21Matrix expected(1, 2);

  A(0, 0) = 1;
  A(0, 1) = 10;

  B(0, 0) = 5;
  B(0, 1) = 50;

  expected(0, 0) = 6;
  expected(0, 1) = 60;

  s21matrix::S21Matrix result = A + B;

  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(OperatorPlus, test_3) {
  s21matrix::S21Matrix A(1, 2);
  s21matrix::S21Matrix B(2, 1);

  A(0, 0) = 1;
  A(0, 1) = 10;

  B(0, 0) = 5;
  B(1, 0) = 5.1;

  EXPECT_ANY_THROW(A + B);
}

TEST(OperatorPlus, test_4) {
  s21matrix::S21Matrix A(3, 5);
  s21matrix::S21Matrix B(3, 5);
  s21matrix::S21Matrix expected(3, 5);

  A(0, 0) = 10;
  A(2, 4) = 1;

  B(0, 1) = 5;
  B(1, 2) = 5.1;

  expected(0, 0) = 10;
  expected(2, 4) = 1;
  expected(0, 1) = 5;
  expected(1, 2) = 5.1;

  s21matrix::S21Matrix result = A + B;

  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(OperatorPlus, test_5) {
  s21matrix::S21Matrix A(1, 2);
  s21matrix::S21Matrix B(2, 1);

  A(0, 0) = 1;
  A(0, 1) = 10;

  B(0, 0) = 5;
  B(1, 0) = 5.1;

  EXPECT_ANY_THROW(A += B);
}

TEST(OperatorPlus, test_6) {
  s21matrix::S21Matrix A(3, 5);
  s21matrix::S21Matrix B(3, 5);
  s21matrix::S21Matrix expected(3, 5);

  A(0, 0) = 10;
  A(2, 4) = 1;

  B(0, 1) = 5;
  B(1, 2) = 5.1;

  expected(0, 0) = 10;
  expected(2, 4) = 1;
  expected(0, 1) = 5;
  expected(1, 2) = 5.1;

  A += B;

  EXPECT_TRUE(A.EqMatrix(expected));
}

TEST(OperatorSub, test_1) {
  s21matrix::S21Matrix A(2, 2);
  s21matrix::S21Matrix B(2, 2);
  s21matrix::S21Matrix expected(2, 2);

  A(0, 0) = 10;
  A(0, 1) = 10;
  A(1, 0) = 10;
  A(1, 1) = 10;

  B(0, 0) = 5;
  B(0, 1) = 50;
  B(1, 0) = 5.5;
  B(1, 1) = 55.5;

  expected(0, 0) = 5;
  expected(0, 1) = -40;
  expected(1, 0) = 4.5;
  expected(1, 1) = -45.5;

  s21matrix::S21Matrix result = A - B;

  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(OperatorSub, test_2) {
  s21matrix::S21Matrix A(1, 2);
  s21matrix::S21Matrix B(1, 2);
  s21matrix::S21Matrix expected(1, 2);

  A(0, 0) = 1;
  A(0, 1) = 10;

  B(0, 0) = 5;
  B(0, 1) = 50;

  expected(0, 0) = -4;
  expected(0, 1) = -40;

  s21matrix::S21Matrix result = A - B;

  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(OperatorSub, test_3) {
  s21matrix::S21Matrix A(1, 2);
  s21matrix::S21Matrix B(2, 1);

  A(0, 0) = 1;
  A(0, 1) = 10;

  B(0, 0) = 5;
  B(1, 0) = 5.1;

  EXPECT_ANY_THROW(A - B);
}

TEST(OperatorSub, test_4) {
  s21matrix::S21Matrix A(3, 5);
  s21matrix::S21Matrix B(3, 5);
  s21matrix::S21Matrix expected(3, 5);

  A(0, 0) = 10;
  A(2, 4) = 1;

  B(0, 1) = 5;
  B(1, 2) = 5.1;

  expected(0, 0) = 10;
  expected(0, 1) = -5;
  expected(1, 2) = -5.1;
  expected(2, 4) = 1;

  s21matrix::S21Matrix result = A - B;

  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(OperatorSub, test_5) {
  s21matrix::S21Matrix A(1, 2);
  s21matrix::S21Matrix B(2, 1);

  A(0, 0) = 1;
  A(0, 1) = 10;

  B(0, 0) = 5;
  B(1, 0) = 5.1;

  EXPECT_ANY_THROW(A -= B);
}

TEST(OperatorSub, test_6) {
  s21matrix::S21Matrix A(3, 5);
  s21matrix::S21Matrix B(3, 5);
  s21matrix::S21Matrix expected(3, 5);

  A(0, 0) = 10;
  A(2, 4) = 1;

  B(0, 1) = 5;
  B(1, 2) = 5.1;

  expected(0, 0) = 10;
  expected(0, 1) = -5;
  expected(1, 2) = -5.1;
  expected(2, 4) = 1;

  A -= B;

  EXPECT_TRUE(A.EqMatrix(expected));
}

TEST(OperatorMulNumber, test_1) {
  s21matrix::S21Matrix A(2, 2), expected(2, 2);
  double number = 0.5;

  A(0, 0) = 1.0;
  A(0, 1) = 1.0;
  A(1, 0) = 1.0;
  A(1, 1) = 1.0;

  expected(0, 0) = 0.5;
  expected(0, 1) = 0.5;
  expected(1, 0) = 0.5;
  expected(1, 1) = 0.5;

  s21matrix::S21Matrix result = A * number;

  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(OperatorMulNumber, test_2) {
  s21matrix::S21Matrix A(2, 2), expected(2, 2);
  double number = 1000000.0;

  A(0, 0) = 1000000.0;
  A(0, 1) = 1000000.0;
  A(1, 0) = 1000000.0;
  A(1, 1) = 1000000.0;

  expected(0, 0) = 1000000000000.0;
  expected(0, 1) = 1000000000000.0;
  expected(1, 0) = 1000000000000.0;
  expected(1, 1) = 1000000000000.0;

  s21matrix::S21Matrix result = A * number;

  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(OperatorMulNumber, test_3) {
  s21matrix::S21Matrix A(2, 2), expected(2, 2);
  double number = 2.0;

  A(0, 0) = 3.2;
  A(0, 1) = 4.5;
  A(1, 0) = 6.7;
  A(1, 1) = 8.9;

  expected(0, 0) = 6.4;
  expected(0, 1) = 9.0;
  expected(1, 0) = 13.4;
  expected(1, 1) = 17.8;

  s21matrix::S21Matrix result = A * number;

  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(OperatorMulNumber, test_4) {
  s21matrix::S21Matrix A(2, 2), expected(2, 2);
  double number = 2.0;

  A(0, 0) = 0.0;
  A(0, 1) = 0.0;
  A(1, 0) = 0.0;
  A(1, 1) = 0.0;

  expected(0, 0) = 0.0;
  expected(0, 1) = 0.0;
  expected(1, 0) = 0.0;
  expected(1, 1) = 0.0;

  s21matrix::S21Matrix result = A * number;

  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(OperatorMulNumber, test_5) {
  s21matrix::S21Matrix A(2, 2), expected(2, 2);
  double number = 2.0;

  A(0, 0) = 3.2;
  A(0, 1) = 4.5;
  A(1, 0) = 6.7;
  A(1, 1) = 8.9;

  expected(0, 0) = 6.4;
  expected(0, 1) = 9.0;
  expected(1, 0) = 13.4;
  expected(1, 1) = 17.8;

  A *= number;

  EXPECT_TRUE(A.EqMatrix(expected));
}

TEST(OperatorMulNumber, test_6) {
  s21matrix::S21Matrix A(2, 2), expected(2, 2);
  double number = 2.0;

  A(0, 0) = 0.0;
  A(0, 1) = 0.0;
  A(1, 0) = 0.0;
  A(1, 1) = 0.0;

  expected(0, 0) = 0.0;
  expected(0, 1) = 0.0;
  expected(1, 0) = 0.0;
  expected(1, 1) = 0.0;

  A *= number;

  EXPECT_TRUE(A.EqMatrix(expected));
}

TEST(OperatorMulNumber, test_7) {
  s21matrix::S21Matrix A(2, 2), expected(2, 2);
  double number = 2.0;

  A(0, 0) = 3.2;
  A(0, 1) = 4.5;
  A(1, 0) = 6.7;
  A(1, 1) = 8.9;

  expected(0, 0) = 6.4;
  expected(0, 1) = 9.0;
  expected(1, 0) = 13.4;
  expected(1, 1) = 17.8;

  s21matrix::S21Matrix result = number * A;

  EXPECT_TRUE(result == expected);
}

TEST(OperatorMulMatrix, test_1) {
  s21matrix::S21Matrix A(3, 2);
  s21matrix::S21Matrix B(2, 3);
  s21matrix::S21Matrix expected(3, 3);

  A(0, 0) = 0;
  A(0, 1) = 1;
  A(1, 0) = 3;
  A(1, 1) = 4;
  A(2, 0) = 6;
  A(2, 1) = 7;

  B(0, 0) = 9;
  B(0, 1) = 8;
  B(0, 2) = 7;
  B(1, 0) = 6;
  B(1, 1) = 5;
  B(1, 2) = 4;

  expected(0, 0) = 6;
  expected(0, 1) = 5;
  expected(0, 2) = 4;
  expected(1, 0) = 51;
  expected(1, 1) = 44;
  expected(1, 2) = 37;
  expected(2, 0) = 96;
  expected(2, 1) = 83;
  expected(2, 2) = 70;

  s21matrix::S21Matrix result = A * B;

  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(OperatorMulMatrix, test_2) {
  s21matrix::S21Matrix A(1, 1);
  s21matrix::S21Matrix B(1, 1);
  s21matrix::S21Matrix expected(1, 1);

  A(0, 0) = -1;
  B(0, 0) = 5;
  expected(0, 0) = -5;

  s21matrix::S21Matrix result = A * B;

  EXPECT_TRUE(result.EqMatrix(expected));
}

TEST(OperatorMulMatrix, test_3) {
  s21matrix::S21Matrix A(3, 1);
  s21matrix::S21Matrix B(2, 2);

  EXPECT_ANY_THROW(A * B);
}

TEST(OperatorMulMatrix, test_4) {
  s21matrix::S21Matrix A(1, 1);
  s21matrix::S21Matrix B(2, 2);

  EXPECT_ANY_THROW(A * B);
}

TEST(OperatorMulMatrix, test_5) {
  s21matrix::S21Matrix A(2, 2);
  s21matrix::S21Matrix B(1, 1);

  EXPECT_ANY_THROW(A * B);
}

TEST(OperatorMulMatrix, test_6) {
  s21matrix::S21Matrix A(3, 2);
  s21matrix::S21Matrix B(2, 3);
  s21matrix::S21Matrix expected(3, 3);

  A(0, 0) = 0;
  A(0, 1) = 1;
  A(1, 0) = 3;
  A(1, 1) = 4;
  A(2, 0) = 6;
  A(2, 1) = 7;

  B(0, 0) = 9;
  B(0, 1) = 8;
  B(0, 2) = 7;
  B(1, 0) = 6;
  B(1, 1) = 5;
  B(1, 2) = 4;

  expected(0, 0) = 6;
  expected(0, 1) = 5;
  expected(0, 2) = 4;
  expected(1, 0) = 51;
  expected(1, 1) = 44;
  expected(1, 2) = 37;
  expected(2, 0) = 96;
  expected(2, 1) = 83;
  expected(2, 2) = 70;

  A *= B;

  EXPECT_TRUE(A.EqMatrix(expected));
}

TEST(OperatorMulMatrix, test_7) {
  s21matrix::S21Matrix A(1, 1);
  s21matrix::S21Matrix B(1, 1);
  s21matrix::S21Matrix expected(1, 1);

  A(0, 0) = -1;
  B(0, 0) = 5;
  expected(0, 0) = -5;

  A *= B;

  EXPECT_TRUE(A.EqMatrix(expected));
}

TEST(Accessors, test_1) {
  int rows = 2, cols = 6;
  s21matrix::S21Matrix A(rows, cols);
  int rows_res = A.GetRows();
  int cols_res = A.GetColumns();

  EXPECT_EQ(rows_res, rows);
  EXPECT_EQ(cols_res, cols);
}

TEST(Accessors, test_2) {
  int rows = 7, cols = 15;
  s21matrix::S21Matrix A(rows, cols);
  int rows_res = A.GetRows();
  int cols_res = A.GetColumns();

  EXPECT_EQ(rows_res, rows);
  EXPECT_EQ(cols_res, cols);
}

TEST(Mutators, test_1) {
  int rows = 2, cols = 2;
  s21matrix::S21Matrix A(3, 3);
  s21matrix::S21Matrix expected(rows, cols);

  A(0, 0) = 11.345;
  A(0, 1) = 12.134;
  A(0, 2) = 13.134;
  A(1, 0) = 21.123;
  A(1, 1) = 22.134;
  A(1, 2) = 23.134;
  A(2, 0) = 31.123;
  A(2, 1) = 32.134;
  A(2, 2) = 33.134;

  expected(0, 0) = 11.345;
  expected(0, 1) = 12.134;
  expected(1, 0) = 21.123;
  expected(1, 1) = 22.134;

  A.SetRows(rows);
  A.SetColumns(cols);

  int rows_res = A.GetRows();
  int cols_res = A.GetColumns();

  EXPECT_EQ(rows_res, rows);
  EXPECT_EQ(cols_res, cols);

  EXPECT_TRUE(A == expected);
}

TEST(Mutators, test_2) {
  int rows = 3, cols = 3;
  s21matrix::S21Matrix A(2, 2);
  s21matrix::S21Matrix expected(rows, cols);

  A(0, 0) = 11.345;
  A(0, 1) = 12.134;
  A(1, 0) = 21.123;
  A(1, 1) = 22.134;

  expected(0, 0) = 11.345;
  expected(0, 1) = 12.134;
  expected(0, 2) = 0;
  expected(1, 0) = 21.123;
  expected(1, 1) = 22.134;
  expected(1, 2) = 0;
  expected(2, 0) = 0;
  expected(2, 1) = 0;
  expected(2, 2) = 0;

  A.SetRows(rows);
  A.SetColumns(cols);

  int rows_res = A.GetRows();
  int cols_res = A.GetColumns();

  EXPECT_EQ(rows_res, rows);
  EXPECT_EQ(cols_res, cols);

  EXPECT_TRUE(A == expected);
}

TEST(Mutators, test_3) {
  s21matrix::S21Matrix A(3, 3);

  EXPECT_ANY_THROW(A.SetColumns(0));
}

TEST(Mutators, test_4) {
  s21matrix::S21Matrix A(3, 3);

  EXPECT_ANY_THROW(A.SetColumns(-1));
}

TEST(Mutators, test_5) {
  s21matrix::S21Matrix A(3, 3);

  EXPECT_ANY_THROW(A.SetRows(0));
}

TEST(Mutators, test_6) {
  s21matrix::S21Matrix A(3, 3);

  EXPECT_ANY_THROW(A.SetRows(-1));
}

TEST(Sum, throw_1) {
  s21matrix::S21Matrix A;
  EXPECT_ANY_THROW(A += A);
}

TEST(Sub, throw_1) {
  s21matrix::S21Matrix A;
  EXPECT_ANY_THROW(A -= A);
}

TEST(MulM, throw_1) {
  s21matrix::S21Matrix A;
  EXPECT_ANY_THROW(A *= A);
}

TEST(MulN, throw_1) {
  s21matrix::S21Matrix A;
  EXPECT_ANY_THROW(A *= 10);
}

TEST(Overloads, test_1) {
  s21matrix::S21Matrix A(2, 2);
  double value = 123.123456;
  A(1, 1) = value;

  const s21matrix::S21Matrix B(A);
  double res = B(1, 1);

  EXPECT_TRUE(fabs(res - value) < 1e-6);
}

TEST(Overloads, test_2) {
  s21matrix::S21Matrix A(2, 2);
  double value = 123.123456;
  A(1, 1) = value;

  const s21matrix::S21Matrix B(A);

  EXPECT_ANY_THROW(B(1, 5));
}

TEST(Overloads, test_3) {
  s21matrix::S21Matrix A(2, 2);
  double value = 123.123456;
  EXPECT_ANY_THROW(A(1, 5) = value);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
