## Comando para compilar o objeto ##
gcc -c -I. program.c -o program.o

## Comando para gerar a biblioteca .a ##
ar rsc libprogram.a program.o