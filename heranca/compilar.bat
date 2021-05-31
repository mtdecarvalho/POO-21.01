gcc -c .\src\Disciplina.cpp -Iinclude -o .\obj\Disciplina.o
gcc -c .\src\DisciplinaTipo1.cpp -Iinclude -o .\obj\DisciplinaTipo1.o
gcc -c .\src\DisciplinaTipo2.cpp -Iinclude -o .\obj\DisciplinaTipo2.o
gcc -c .\src\DisciplinaTipo3.cpp -Iinclude -o .\obj\DisciplinaTipo3.o
gcc -c .\src\Historico.cpp -Iinclude -o .\obj\Historico.o
gcc -c .\src\menu.cpp -Iinclude -o .\obj\menu.o
gcc -c .\src\main.cpp -Iinclude -o .\obj\main.o

g++ -o Historico.exe .\obj\Disciplina.o .\obj\DisciplinaTipo1.o .\obj\DisciplinaTipo2.o .\obj\DisciplinaTipo3.o .\obj\Historico.o .\obj\menu.o .\obj\main.o