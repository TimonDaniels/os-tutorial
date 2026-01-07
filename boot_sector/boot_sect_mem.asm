mov ah, 0x0e

mov al, "1"
int 0x10
mov al, secret_key
int 0x10

mov al, "2"
int 0x10
mov al, [secret_key]
int 0x10

mov al, "3"
int 0x10
mov al, secret_key + 0x7C00
int 0x10

mov al, "4"
int 0x10
mov al, [0x26 + 0x7C00]
int 0x10

jmp $

secret_key:
    db "X"

times 510 - ($-$$) db 0
dw 0xaa55
