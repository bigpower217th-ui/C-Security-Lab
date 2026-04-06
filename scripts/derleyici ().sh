#!/bin/bash

echo "--- C Projeleri Derleme İşlemi Başladı ---"

# 1. Akıllı Şifre Üretici
gcc akilli-sifre.c -o akilli-sifre
echo "[+] akilli-sifre derlendi."

# 2. Virüs Simülasyonu
gcc virus-ornek.c -o virus-ornek
echo "[+] virus-ornek derlendi."

# 3. Bellek Yönetimi (Linked List)
gcc bellek.c -o bellek
echo "[+] bellek derlendi."

# 4. Anti-Malware
gcc anti-malware.c -o anti-malware
echo "[+] anti-malware derlendi."

# 5. Hesaplama Araçları (C ve C++)
gcc hesap.c -o hesap

echo "[+] hesaplama araçları derlendi."

# 6. Matris İşlemleri
gcc matris.c -o matris
echo "[+] matris derlendi."

# 7. ağ kesifçisi 
gcc ag_kesifcisi.c -o kesifci

# 8.dinamik bellek
gcc bellek-v1.c -o v1

# 9.farkli hesap makinesi 
gcc kali.c -o kali

# 10.pdf anti-virusu
gcc anti-pdf.c -o pdf



echo "------------------------------------------"
echo "Tüm dosyalar hazır! Çalıştırmak için: ./dosya_adi"
