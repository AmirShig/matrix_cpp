.PHONY: s21_matrix_oop.a test

CXX := g++ -Wall -Wextra -Werror
CXXFLAGS := --std=c++17 -lstdc++ -lm

#FUNC_SRC := $(wildcard ./s21_functions/s21_*.cc)
FUNC_SRC := s21_matrix_oop.cc
TEST_SRC := $(wildcard ./tests/*.cc)
OBJ = ./*.o

GTEST_FLAGS := -lgtest -lgcov -pthread
GCOV_FLAGS := --coverage
HTML = lcov -t test -o rep.info -c -d ./
STYLE = n

MSG=Minor bug fixes
BRANCH=$(shell git branch --show-current)
OS := $(shell uname -s)

ifeq ($(OS),Linux)
	OPEN_CMD = xdg-open
endif
ifeq ($(OS),Darwin)
	OPEN_CMD = open
endif

all: clean test gcov_report

s21_matrix_oop.a: clean
	$(CXX) $(GCOV_FLAGS) -c $(FUNC_SRC)
	ar rcs $@ $(OBJ)
	ranlib $@
	rm -rf $(OBJ)

test: s21_matrix_oop.a
	$(CXX) -g $(TEST_SRC) s21_matrix_oop.a $(CXXFLAGS) $(GTEST_FLAGS) -o test
	./test

gcov_report: test
	$(HTML)
	genhtml -o report rep.info
	$(OPEN_CMD) report/index.html
	rm -rf *.o *.gcda *.gcno *.info

clean:
	clear
	rm -rf *.o *.a *.so *.gcda *.gcno *.gch rep.info *.html *.css test report *.txt *.dSYM *.info my_start.sh

style:
	clear
	@cp ../materials/linters/.clang-format .
	clang-format -$(STYLE) $(FUNC_SRC) $(TEST_SRC) *.h
	@rm -rf .clang-format

run_docker:
ifeq ($(OS), Darwin)
	cp ~/Downloads/my_start.sh ./
endif
ifeq ($(OS),Linux)
	sh my_start.sh
endif

valgrind:
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test

push:
	git add .
	git commit -m "$(BRANCH): $(MSG)"
	git push origin $(BRANCH)

pull:
	git pull origin $(BRANCH)

gitback:
	git stash save --keep-index

