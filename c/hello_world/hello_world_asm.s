.section .rdata,"dr"
.LC0:
    .ascii "Hello, World!!\0"

.text
.global main

main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $32, %rsp
    call    __main
    leaq    .LC0(%rip), %rax
    movq    %rax, %rcx
    call    printf
    movl    $0, %eax
    addq    $32, %rsp
    popq    %rbp
    ret
