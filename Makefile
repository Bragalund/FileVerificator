#
# Generic makefile for compiling and linking more than one source file
#

TARGET = fileverificator
OBJS = main.o md5.o FileReader.o FileWriter.o Util.o ValidateInput.o # List object files here
DEPS = md5.h makefile FileReader.h FileWriter.h main.h Util.h ValidateInput.h

CFLAGS = -O0

%.o: %.c $(DEPS)
	gcc -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJS)
	gcc -o $@ $^ $(CFLAGS)

.phony:	clean
clean:
	rm -f *.o $(TARGET)
