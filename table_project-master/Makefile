CC				= g++
DEBUG			= gdb
CFLAGS			= -g -Wall
SRC_DIR			= src
BIN_DIR 		= bin
OBJ_DIR			= obj

FINAL_EXEC		= prog
SRCS 			= main.cpp etudiant.cpp table.cpp element.cpp 
									#rajouter ici les fichiers dépendances


all : $(BIN_DIR)/$(FINAL_EXEC) 

$(BIN_DIR)/$(FINAL_EXEC): $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
	$(CC) $(CFLAGS) $+ -o $@ 


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp 
	$(CC) $(CFLAGS) -c  $< -o $@


clean: 
	rm $(OBJ_DIR)/*.o

veryclean: clean
	rm $(BIN_DIR)/*

re: veryclean all

