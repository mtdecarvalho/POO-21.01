#!/bin/bash

g++ -c src/util.cpp -Iinc -o obj/util.o
g++ -c src/classes.cpp -Iinc -o obj/classes.o
g++ -c src/main.cpp -Iinc -o obj/main.o

g++ -o historico-academico obj/main.o obj/classes.o obj/util.o
teste