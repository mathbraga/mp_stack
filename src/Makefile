IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -ftest-coverage -fprofile-arcs

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = pilha.hpp TipoPilha.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = testa_pilha.o pilhaVetor.o # pilhaVetor.o ou pilhaDinamica.o, depende da implementação escolhida
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -Wall -c -o $@ $< $(CFLAGS)

testar: $(OBJ)
	$(CC) -Wall -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(ODIR)/*.gcda $(ODIR)/*.gcno *~ core $(INCDIR)/*~ 

cleanTest:
	rm testar