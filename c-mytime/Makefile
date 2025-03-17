APPS = ./apps
BIN = ./bin
INCLUDES = ./includes
OBJ = ./obj
SRC = ./src

DKID = 

FLAGSGCC = -o3 -Wall

all:libed myapps 
 
libed:
	gcc -c $(FLAGSGCC) $(SRC)/float_vector.c -I $(INCLUDES) -o $(OBJ)/float_vector.o
	gcc -c $(FLAGSGCC) $(SRC)/my_time.c -I $(INCLUDES) -o $(OBJ)/my_time.o

myapps:
	gcc  $(APPS)/app.c $(OBJ)/* -I $(INCLUDES)  -o $(BIN)/app
	# gcc  $(APPS)/app_com_my_time.c $(OBJ)/*.o -I $(INCLUDES)  -o $(BIN)/app_com_my_time


run:
	./bin/app 

clean:
	rm ./bin/* ./obj/*

dkid:
	docker ps
	
dkstop:
	docker stop 