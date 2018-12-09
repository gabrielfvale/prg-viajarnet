#!/bin/bash
echo -e "Que tipo de operacao deseja fazer?"
echo -e "1 - Compilar e executar programa"
echo -e "2 - Apagar binarios"
read action
if [ $action -eq 1 ] 
then
	mkdir bin
	echo -e "Compilando Usuario.o"
	gcc -c Usuario.c -o bin/Usuario.o
	echo -e "Compilando Registro.o"
	gcc -c Registro.c -o bin/Registro.o
	echo -e "Compilando ViajarNet.o"
	gcc -c ViajarNet.c -o bin/ViajarNet.o
	echo -e "Digite o nome da classe main"
	read main
	gcc -c $main.c -o bin/$main.o
	echo -e "Compilando $main.bin"
	gcc -o bin/$main.bin bin/Usuario.o bin/Registro.o bin/ViajarNet.o bin/$main.o
	echo -e "Executando $main.bin"
	./bin/$main.bin
else
	rm -rf bin/
fi
