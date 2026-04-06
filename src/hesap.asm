; --- C Kütüphanesini Kullanan Stabil ASM Hesap Makinesi ---
extern printf, scanf

section .data
    istek_mesaj  db "Iki sayi girin (Ornek: 5 3): ", 0
        format_al    db "%d %d", 0
            format_yaz   db "Toplam Sonuc: %d", 10, 0

            section .bss
                sayi1 resd 1
                    sayi2 resd 1

                    section .text
                        global main

                        main:
                            ; --- STACK ALIGNMENT (SegFault Onleyici) ---
                                sub rsp, 8          ; Yığını 16-byte hizasına getir

                                    ; --- Mesajı Yazdır ---
                                        mov rdi, istek_mesaj
                                            xor rax, rax
                                                call printf

                                                    ; --- Sayıları Kullanıcıdan Al ---
                                                        mov rdi, format_al
                                                            mov rsi, sayi1
                                                                mov rdx, sayi2
                                                                    xor rax, rax
                                                                        call scanf

                                                                            ; --- Toplama İşlemi (Register Düellosu) ---
                                                                                mov eax, [sayi1]    ; Birinci sayıyı EAX'e al
                                                                                    add eax, [sayi2]    ; İkinci sayıyı üzerine ekle

                                                                                        ; --- Sonucu Ekrana Bas ---
                                                                                            mov rdi, format_yaz
                                                                                                mov rsi, rax        ; Sonuç EAX (RAX'in alt yarısı) içindeydi
                                                                                                    xor rax, rax
                                                                                                        call printf

                                                                                                            ; --- GÜVENLİ ÇIKIŞ ---
                                                                                                                add rsp, 8          ; Yığını eski haline getir
                                                                                                                    mov rax, 0          ; Return 0
                                                                                                                        ret