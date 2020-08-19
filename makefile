PREFIX=
CC=gcc
CP=g++

PROJECT_NAME=Hex2Signed32
DEFAULT=c

ifeq ($(OS),Windows_NT)
	OBJ=main.exe
	EXECPREFIX=
else
    OBJ=main.o
	EXECPREFIX=./
endif

all: 
	@echo -e "all\tPrint this help information."
	@echo -e "run\tRun default method."
	@echo -e "c\tRun for C language."
	@echo -e "cpp\tRun fpr C++ language."
	@echo -e "clean\tClean object file."

run: $(OBJ)
	$(EXECPREFIX)$(OBJ)

$(OBJ): $(DEFAULT)


c:
	$(CC) c/main.c c/$(PROJECT_NAME).c -o $(OBJ)
	$(EXECPREFIX)$(OBJ)

cpp:
	$(CP) cpp/main.cpp cpp/$(PROJECT_NAME).cpp -o $(OBJ)
	$(EXECPREFIX)$(OBJ)

clean:
	rm -rf $(OBJ)

.PHONY: all c cpp clean
