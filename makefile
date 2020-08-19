PREFIX=
CC=gcc
CP=g++

PROJECT_NAME=hex2signed
DEFAULT=c

ifeq ($(OS),Windows_NT)
	OBJ=main.exe
	EXECPREFIX=
else
    OBJ=main.o
	EXECPREFIX=./
endif

# add -D HACKED for using casting method
CFLAG=

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
	$(CC) $@/main.$@ $@/$(PROJECT_NAME).$@ $(CFLAG) -o $(OBJ)
	$(EXECPREFIX)$(OBJ)

cpp:
	$(CP) $@/main.$@ $@/$(PROJECT_NAME).$@ $(CFLAG) -o $(OBJ)
	$(EXECPREFIX)$(OBJ)

clean:
	rm -rf $(OBJ)

.PHONY: all c cpp clean
