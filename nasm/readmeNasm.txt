## Comando utilizado para gerar binario ##
nasm -felf64 intro.asm && ld intro.o && ./a.out
ld -m elf_x86_64 intro.o -o intro 

