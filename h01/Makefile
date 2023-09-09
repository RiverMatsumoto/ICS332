# practicing scalable makefiles, not really practical here
SRC_DIR := src
BIN_DIR := bin
OBJ_DIR := obj

EXE := $(BIN_DIR)/request_times
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

.PHONY: all clean

all: $(EXE)

# link into executable
$(EXE): $(OBJ) text_files | $(BIN_DIR)
	$(CC) $< -o $@

# compile into object files (needs object directory)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $< -o $@

# create all the text files with the bash script(s)
text_files: $(SRC_DIR)/generate_data.bash
	bash $< $(SRC_DIR) $(BIN_DIR)

# create the binary directory if it doesnt exist
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean: $(BIN_DIR)
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR) # The @ disables the echoing of the command

# automatic dependency generation for makefile to use :)
-include $(OBJ:.o=.d) # The dash silences errors when files don't exist (yet)