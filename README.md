# Tugas Kecil 1 IF2211 Strategi Algoritma - Word Search Puzzle Solver
## Deskripsi Program
Word Search Puzzle Solver adalah program untuk mendapatkan penyelesaian dari teka-teki Word Search. Program ini menggunakan algoritma brute force untuk mencari jawaban pada grid kata. Prinsip dasarnya, solver ini akan mencari huruf pertama jawaban pada grid kata. Jika ditemukan, huruf yang bersebelahan (di kanan, kanan bawah, bawah, kiri bawah, dst) akan dicek kecocokannya dengan huruf kedua pada jawaban. Hal ini dilakukan terus menerus pada untuk semua jawaban yang tertera hingga semua jawaban selesai dicari.

## Persyaratan Penggunaan
Bahasa yang digunakan untuk tugas kecil 1 Strategi Algoritma ini adalah bahasa pemrograman C++. Untuk melakukan kompilasi pada program, diperlukan GNU Compiler Collection / GCC. Tidak ada library tambahan yang perlu diunduh. Jika sistem operasi yang digunakan dapat menjalankan file executable, artinya program ini sudah dapat digunakan.

GCC yang sudah tersedia dapat digunakan untuk kompilasi program dengan membuka command-line interface (CLI) yang mengarah ke directory ini dan mengeksekusi command di bawah ini pada CLI:

    g++ src/main.cpp src/lib/file_loader/file_loader.cpp src/lib/puzzle_matcher/puzzle_matcher.cpp -o bin/main

Jika ingin menggunakan makefile untuk melakukan kompilasi, lakukan eksekusi pada instruksi di bawah ini:

    make

Eksekusi perintah yang berhasil akan menghasilkan file binary `main` atau `main.exe` pada folder bernama `bin`.

## Cara Penggunaan Program
Untuk menggunakan program, file executable harus sudah dibuat atau di-compile. Hal ini dapat dilakukan dengan melakukan pengecekan pada folder `bin`. File executable seharusnya sudah ada dan siap dijalankan. Jika belum ada, mohon mengacu pada [Persyaratan Penggunaan](#persyaratan-penggunaan).

Jalankan file executable yang ada pada folder `bin`. Jika sistem operasi yang digunakan adalah Windows, `main.exe` digunakan. Jika sistem operasi yang digunakan berbasis Linux, jalankan file bernama `main`. Pengguna dapat menggunakan perintah pada CLI sebagai berikut:

    ./bin/main

Eksekusi file `main` atau `main.exe` yang sukses akan membawa pengguna ke menu Word-Search Puzzle Solver. Setelah itu, nama file yang ingin diketahui solusinya dapat diketik setelah muncul perintah untuk memasukkan nama file. 

    Word-Search Puzzle Solver
    Masukkan nama file:

Sebagai contoh:

    Word-Search Puzzle Solver
    Masukkan nama file: test/file1.txt

Jika file yang dimaksud dapat dibuka dan formatnya sesuai, program akan melakukan pencarian solusi.

## Format File Konfigurasi
Program ini memerlukan file konfigurasi tertentu untuk mendapatkan solusi. Format puzzle yang akan diselesaikan diberikan di bawah ini.

    P U Z Z L E
    B E R I S I
    G R I D K A
    T A K A T A
    <kosong>
    KATA
    KUNCI
    JAWABAN

Contoh isi file:

    J S O L U T I S
    S U N A R U U A
    N E P T U N E T
    S O N I E I S U
    R C E V T R E R
    A H T R A E S N
    M M E R C U R Y

    EARTH
    JUPITER
    MARS
    MERCURY
    NEPTUNE
    SATURN
    URANUS
    VENUS

## Struktur Folder

    .
    ├───bin                       # berisi file executable
    ├───doc                       # berisi laporan
    ├───src                       # terdiri atas kode sumber program
    │   └───lib
    │       ├───file_loader
    │       └───puzzle_matcher
    └───test                      # berisi file konfigurasi

## Identitas Pembuat
13520153 - Vito Ghifari