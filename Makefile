IDIR =./
CC=g++
CFLAGS=-I$(IDIR) -std=c++11

ODIR=obj

LIBS= -lm -lgtest -lgtest_main -lpthread

_DEPS = romano.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = romano.o testa_romano.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test.out: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

verify: test.out
	valgrind --leak-check=full ./test.out
	@echo "*** CPP CHECK ***"
	cppcheck --enable=warning romano.cpp

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *.gch *.out 