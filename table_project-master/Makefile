CC				= g++
DEBUG			= gdb
CFLAGS			= -g -Wall -std=c++11
SRC_DIR			= src
BIN_DIR 		= bin
OBJ_DIR			= obj

FINAL_EXEC		= prog
SRCS 			= main.cpp element.cpp etudiant.cpp table.cpp   
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

 