#------------------------------------------------------------------------------#
# This makefile was generated by 'cbp2make' tool rev.147                       #
#------------------------------------------------------------------------------#


WORKDIR = `pwd`

CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = windres

INC = 
CFLAGS = -Wall
RESINC = 
LIBDIR = 
LIB = 
LDFLAGS = 

INC_DEBUG = $(INC)
CFLAGS_DEBUG = $(CFLAGS) -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj/Debug
DEP_DEBUG = 
OUT_DEBUG = ./U03E_Templates_Exceptions_STL_Structures_exe

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS) -O2
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS) -s
OBJDIR_RELEASE = obj/Release
DEP_RELEASE = 
OUT_RELEASE = ./U03E_Templates_Exceptions_STL_Structures_exe

OBJ_DEBUG = $(OBJDIR_DEBUG)/StoreProgram/Program.o $(OBJDIR_DEBUG)/StoreProgram/ShoppingCart.o $(OBJDIR_DEBUG)/StoreProgram/Store.o $(OBJDIR_DEBUG)/Utilities/Helper.o $(OBJDIR_DEBUG)/main.o

OBJ_RELEASE = $(OBJDIR_RELEASE)/StoreProgram/Program.o $(OBJDIR_RELEASE)/StoreProgram/ShoppingCart.o $(OBJDIR_RELEASE)/StoreProgram/Store.o $(OBJDIR_RELEASE)/Utilities/Helper.o $(OBJDIR_RELEASE)/main.o

all: debug release

clean: clean_debug clean_release

before_debug: 
	test -d bin/Debug || mkdir -p bin/Debug
	test -d $(OBJDIR_DEBUG)/StoreProgram || mkdir -p $(OBJDIR_DEBUG)/StoreProgram
	test -d $(OBJDIR_DEBUG)/Utilities || mkdir -p $(OBJDIR_DEBUG)/Utilities
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)/StoreProgram/Program.o: StoreProgram/Program.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c StoreProgram/Program.cpp -o $(OBJDIR_DEBUG)/StoreProgram/Program.o

$(OBJDIR_DEBUG)/StoreProgram/ShoppingCart.o: StoreProgram/ShoppingCart.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c StoreProgram/ShoppingCart.cpp -o $(OBJDIR_DEBUG)/StoreProgram/ShoppingCart.o

$(OBJDIR_DEBUG)/StoreProgram/Store.o: StoreProgram/Store.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c StoreProgram/Store.cpp -o $(OBJDIR_DEBUG)/StoreProgram/Store.o

$(OBJDIR_DEBUG)/Utilities/Helper.o: Utilities/Helper.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Utilities/Helper.cpp -o $(OBJDIR_DEBUG)/Utilities/Helper.o

$(OBJDIR_DEBUG)/main.o: main.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c main.cpp -o $(OBJDIR_DEBUG)/main.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf bin/Debug
	rm -rf $(OBJDIR_DEBUG)/StoreProgram
	rm -rf $(OBJDIR_DEBUG)/Utilities
	rm -rf $(OBJDIR_DEBUG)

before_release: 
	test -d bin/Release || mkdir -p bin/Release
	test -d $(OBJDIR_RELEASE)/StoreProgram || mkdir -p $(OBJDIR_RELEASE)/StoreProgram
	test -d $(OBJDIR_RELEASE)/Utilities || mkdir -p $(OBJDIR_RELEASE)/Utilities
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)/StoreProgram/Program.o: StoreProgram/Program.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c StoreProgram/Program.cpp -o $(OBJDIR_RELEASE)/StoreProgram/Program.o

$(OBJDIR_RELEASE)/StoreProgram/ShoppingCart.o: StoreProgram/ShoppingCart.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c StoreProgram/ShoppingCart.cpp -o $(OBJDIR_RELEASE)/StoreProgram/ShoppingCart.o

$(OBJDIR_RELEASE)/StoreProgram/Store.o: StoreProgram/Store.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c StoreProgram/Store.cpp -o $(OBJDIR_RELEASE)/StoreProgram/Store.o

$(OBJDIR_RELEASE)/Utilities/Helper.o: Utilities/Helper.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Utilities/Helper.cpp -o $(OBJDIR_RELEASE)/Utilities/Helper.o

$(OBJDIR_RELEASE)/main.o: main.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c main.cpp -o $(OBJDIR_RELEASE)/main.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf bin/Release
	rm -rf $(OBJDIR_RELEASE)/StoreProgram
	rm -rf $(OBJDIR_RELEASE)/Utilities
	rm -rf $(OBJDIR_RELEASE)

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release

