OS := $(shell uname -s)

SOURCES= s21_array.cpp\
		s21_list.cpp\
		s21_queue.cpp\
		s21_stack.cpp\
		s21_vector.cpp\
		s21_map.cpp\
		s21_set.cpp\
		s21_multiset.cpp
		
OBJECTS=$(SOURCES:.cpp=.o)
CC=g++
GFLAGS= -fprofile-arcs -ftest-coverage

ifeq ($(OS), Linux)
  LIBS= -lgtest -lpthread -lrt -lm
  LEAKER= valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes -s
else
  LIBS= -lgtest
  LEAKER= CK_FORK=no leaks --atExit --
endif


all: test

s21_containers.a:
	$(CC) -c $(SOURCES)  -std=c++17
	ar rcs s21_containers.a $(OBJECTS)
	ranlib s21_containers.a

test: s21_containers.a
	$(CC) -std=c++20 -c s21_test.cpp
	$(CC) s21_test.o s21_containers.a $(LIBS) -o Test
	./Test

gcov_report:
	@rm -rf coverage test *.info *.gcda *.gcno
	@$(CC) -std=c++20 s21_test.cpp  $(SOURCES) $(LIBS) $(GFLAGS) -o test
	@./test
	@lcov -c -d ./ -o coverage.info
	@genhtml -o coverage coverage.info
	@rm -f *.gcno *gcda *.info *.o
	

clean:
	@rm -f *.o Test *.out *.gcov *.gcda *.gcno *.info *.a CPPLINT.cfg
	@rm -rf ./coverage

rebuild: clean all

check:
	cppcheck --enable=all --suppress=missingIncludeSystem *.cpp

leaks: test
	$(LEAKER) ./Test

.PHONY: all clean check rebuild test gcov_report
