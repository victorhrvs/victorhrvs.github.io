CC=g++
CFLAGS=-I.
LIBS=-lgtest -lgtest_main -lpthread
COBERTURA = -ftest-coverage -fprofile-arcs
DEPS = pilha.h

#%.o: %.c $(DEPS)
	#$(CC) -c -o $@ $< $(CFLAGS)


obj/test_pilha: src/pilha.c src/testa_pilha.c
	$(CC) -o $@ $^ $(LIBS)

clean:
	rm  obj/*
