#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char kalimat[20] = "ini adalah kalimat";
    char *kata[10];
    int i = 0;

    kata[0] = strtok(kalimat, " ");

    while (kata[i++] != NULL)
    {
        // printf("%s \n", kata);
        kata[i] = strtok(NULL, " ");
    }

    int y = 0;
    printf("%s", kata[y]);
    return 0;
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
