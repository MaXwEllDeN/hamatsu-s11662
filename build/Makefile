EXE 		:= example_save_frame.out

SRC_DIR 	:= ../src
OBJ_DIR 	:= obj

SRC 		:= $(wildcard $(SRC_DIR)/*.cpp)
OBJ 		:= $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CPPFLAGS 	:= -I../include
CFLAGS 		:= -ansi -pedantic-errors -Wall -Werror -Wextra
LDFLAGS 	:= -L/usr/lib
LDLIBS 		:= -lm -lstdc++

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir $@
clean:
	$(RM) -r $(OBJ_DIR)

