CC=clang++
CFLAGS=-I./src

ODIR=obj

DEPS = src/BinarySearchTree.h

_OBJ = Assignment6.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: src/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
bin/Assignment6: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) 
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core /*~ 
