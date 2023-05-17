#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char* username = argv[1];
    char* password = argv[2];

    buat_akun();

    // Cek apakah terdapat CLA yang sesuai
    if (argc != 3)
    {
        printf("Login gagal. Gunakan: %s [username] [password]\n", argv[0]);
        return 1;
    }

    // Lakukan proses login
    if (login(username, password)) {
        printf("Login berhasil!\n");

        // Tampilkan menu dan jalankan game quiz
        printf("Selamat datang di game quiz!\n");
    } else {
        printf("Login gagal. Gunakan: %s [username] [password]\n", argv[0]);
        return 1;
    }
    return 0;
}

void buat_akun() {
    Account akun_baru;
    FILE *fp = fopen("login.bin", "rb");

    if (fp == NULL){
        fp = fopen("login.bin", "wb");

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
    FILE *fp = fopen("login.bin", "rb");

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
    return 0; // Login gagal
}
