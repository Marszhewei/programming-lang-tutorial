#makefile

vpath %.cc type point macro stl stream function reference namespace

CC := g++
RM := rm -f

TARGET := out

.PHONY : all
all : ${TARGET}

${TARGET} : ${SRC}
	$(CC) -std=c++20 $^ -o $@
	@echo "build finished"


.PHONY : clean
clean:
	$(RM) ${TARGET}