; ----------------------------------------------------------------------------------------
;     nasm -felf64 intro.asm && ld intro.o && ./a.out
; ----------------------------------------------------------------------------------------

          global    _start

          section   .text
_start:   mov       rax, 1                  ; system call for write
          mov       rdi, 1                  ; file handle 1 is stdout
          mov       rsi, message            ; address of string to output
	  mov       rdx, 250                ; number of bytes
          syscall
	  mov       rsi, message2           ;
          mov       rdx, 250                ; number of bytes
          syscall                           ; invoke operating system to do the write
          mov       rax, 60                 ; system call for exit
          xor       rdi, rdi                ; exit code 0
          syscall                           ; invoke operating system to exit

          section   .data
message:  db        10, "################################################################", 10, "                     JOGO DA ADIVINHACAO", 10, "################################################################", 10 ;

message2:  db        10, "Created by: Marcelo Lourenco dos Santos - RA: 103523", 10, 10     ; note the newline at the end