FILE_EXT = cpp
SRC = $(wildcard src/*.$(FILE_EXT))

NAME = Tictactoe_Minimax

CC = g++

CPPFLAGS = -Wall -Wextra -Wpedantic -g -Og -O2
LDFLAGS = #-fsanitize=address 

OBJ_DIR = obj
SRC_DIR = src
DOC_DIR = doc
BIN_DIR = bin
INC_DIR = inc

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:$(SRC_DIR)/%.$(FILE_EXT)=%.o))

# -j multifil (multi threads) / ameliore la vitesse de compliation
# --no-print-directory / n'affiche pas: make[N]: Leaving directory '...'
all:
	@$(MAKE) -j $(BIN_DIR)/$(NAME) --no-print-directory

# permet de pouvoir comparer la derniere modification de la dep par rapport a la regle
$(BIN_DIR)/$(NAME): $(OBJ) .gitignore
	@mkdir -p $(BIN_DIR)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)
	@echo $(NAME) : created !

# si le .c est plus recent que le .o on rentre dans la regle
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(FILE_EXT)
	@mkdir -p $(OBJ_DIR)	
	$(CC) $(CPPFLAGS) -I $(INC_DIR) -c $< -o $@

clean: 
	@rm -rf $(OBJ_DIR)
	@rm -fr $(DOC_DIR)
	@rm -rf $(BIN_DIR)
	@rm -fr *.log
	@echo "obj, bin, doc, log deleted"

init:	
	@mkdir -p src inc
	@echo $(SRC_DIR) $(INC_DIR) : created !

doc:
	@mkdir -p doc
	@echo creation of the DoxyFile...
	echo DOXYFILE_ENCODING      = UTF-8 > $(DOC_DIR)/DoxyFile
	echo PROJECT_NAME           = "$(NAME)" >> $(DOC_DIR)/DoxyFile
	echo OUTPUT_LANGUAGE        = French >> $(DOC_DIR)/DoxyFile
	echo INPUT                  = ../src ../inc ../README.md >> $(DOC_DIR)/DoxyFile
	echo OPTIMIZE_OUTPUT_FOR_C  = YES >> $(DOC_DIR)/DoxyFile
	echo QUIET                  = YES >> $(DOC_DIR)/DoxyFile
	@echo $(DOC_DIR)/DoxyFile : created !

docHtml:
	@(cd doc; doxygen DoxyFile)
	firefox ./doc/html/index.html &

re: clean all

.gitignore:
	@echo $(OBJ_DIR) > .gitignore
	@echo $(BIN_DIR) >> .gitignore
	@echo $(DOC_DIR) >> .gitignore
	@echo *.log >> .gitignore
	@echo ".gitignore created !"

.PHONY: all, clean, init, save, doc, docHtml, re
