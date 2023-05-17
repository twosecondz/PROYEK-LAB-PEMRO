#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) 
{
    char *username = argv[1];
    char *password = argv[2];
    char *soal;
    int jumlah_soal;

    buat_akun();

    // Cek apakah terdapat CLA yang sesuai
    if (argc != 3)
    {
        printf("Login gagal. Gunakan: %s [username] [password]\n", argv[0]);
        return 1;
    }

    // Lakukan proses login
    if (login(username, password))
    {
        printf("Login berhasil!\n");

        // Tampilkan menu dan jalankan game quiz
        printf("Selamat datang di quiz!\n");
    } else {
        printf("Login tidak berhasil. Gunakan: %s [username] [password]\n", argv[0]);
        return 1;
    }
    
    jalankan_permainan(&pertanyaan, jumlah);
    
    return 0;
}

void buat_akun() {
    Account akun_baru;
    FILE *fpw = fopen("login.bin", "rb");

    if (fp == NULL){
        fp = fopen("database/login.bin", "wb");

        // Meminta input username dan password baru dari pengguna
        printf("Masukkan username: ");
        scanf("%s", akun_baru.username);
        printf("Masukkan password: ");
        scanf("%s", akun_baru.password);

        // Menulis data akun baru ke dalam file binary
        fwrite(&akun_baru, sizeof(Account), 1, fp);

        printf("Akun berhasil dibuat!\n");
    }
    fclose(fp);
}

int login(char* username, char* password) {
    Account akun;
    FILE *fp = fopen("database/login.bin", "rb");

    // Membaca data akun dari file binary dan membandingkan dengan input username dan password
    while (fread(&akun, sizeof(Account), 1, fp)) {
        if (strcmp(akun.username, username) == 0 && strcmp(akun.password, password) == 0) {
            fclose(fp);
            return 1; // Login berhasil
        } else {
            printf("Username dan Sandi yang anda inputkan salah!!\n");
        }
    }

    fclose(fp);
    return 0; // Login anda gagal
}

void jalankan_permainan(Pertanyaan* pertanyaan, int jumlah) {
    int poin = 0;
    int i;
    char jawaban[50];

    printf("Selamat datang di game quiz!\n");

    for (i = 0; i < jumlah; i++) {
        printf("Pertanyaan %d: %s\n", i+1, pertanyaan[i].pertanyaan);
        printf("Jawaban: ");
        scanf("%s", jawaban);

        for(int j = 0; (tolower(jawaban[j])) != '\0'; j++);
        
        if (strcmp(jawaban, pertanyaan[i].jawaban) == 0) {
            printf("Jawaban benar!\n");
            poin += 10;
        } else {
            printf("Jawaban salah!\n");
        }

        printf("\n");
    }
