CC 	 = gcc	#compiler name
CFLAGS   = -Wall # compress all warning, choose your own compile flags (if any)
BIN      = bin
TARGET   = ./bin/test
OBJFILES = ./bin/test.o ./bin/list.o
 
$(TARGET): $(OBJFILES) $(BIN) 
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) 

./bin/test.o: test.c list.c $(BIN) # Meaning: target test.o depends on test.c list.c
	gcc -c test.c list.c 
	mv test.o ./bin/test.o

./bin/list.o: list.c $(BIN) list.h #target list.o on list.c and indirectly on list.h	
	gcc -c list.c
	mv list.o ./bin/list.o

$(BIN):				#make bin directory
	mkdir -p $(BIN)

clean: 
	rm -f $(OBJFILES) $(TARGET)

