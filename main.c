#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tampilkanPertanyaan(const char *pertanyaan, const char *opsiA, const char *opsiB, const char *opsiC, const char *opsiD)
{
    printf("==========================================\n");
    printf("%s\n", pertanyaan);
    printf("A. %s\n", opsiA);
    printf("B. %s\n", opsiB);
    printf("C. %s\n", opsiC);
    printf("D. %s\n", opsiD);
    printf("==========================================\n");
}

void menu()
{
    char jawaban[10];
    int skor = 0;

    // Pertanyaan 1
    tampilkanPertanyaan("Siapakah presiden Indonesia yang pertama?", "Soekarno", "Soeharto", "Joko Widodo", "Abdurrahman Wahid");
    printf("Jawaban Anda (A/B/C/D): ");
    scanf("%s", jawaban);
    if (strcmp(jawaban, "A") == 0 || strcmp(jawaban, "a") == 0)
    {
        skor += 100;
        printf("Jawaban Anda benar!\n");
    }
    else
    {
        printf("Jawaban Anda salah!\n");
    }
    printf("==========================================\n");

    // Pertanyaan 2
    tampilkanPertanyaan("Berapa jumlah provinsi di Indonesia saat ini?", "30", "32", "34", "36");
    printf("Jawaban Anda (A/B/C/D): ");
    scanf("%s", jawaban);
    if (strcmp(jawaban, "C") == 0 || strcmp(jawaban, "c") == 0)
    {
        skor += 100;
        printf("Jawaban Anda benar!\n");
    }
    else
    {
        printf("Jawaban Anda salah!\n");
    }
    printf("==========================================\n");

    // Pertanyaan 3
    tampilkanPertanyaan("Apa ibu kota Indonesia?", "Jakarta", "Bandung", "Surabaya", "Yogyakarta");
    printf("Jawaban Anda (A/B/C/D): ");
    scanf("%s", jawaban);
    if (strcmp(jawaban, "A") == 0 || strcmp(jawaban, "a") == 0)
    {
        skor += 100;
        printf("Jawaban Anda benar!\n");
    }
    else
    {
        printf("Jawaban Anda salah!\n");
    }
    printf("==========================================\n");

    // Pertanyaan 4
    tampilkanPertanyaan("Apa nama mata uang resmi Indonesia?", "Rupiah", "Dinar", "Euro", "Yen");
    printf("Jawaban Anda (A/B/C/D): ");
    scanf("%s", jawaban);
    if (strcmp(jawaban, "A") == 0 || strcmp(jawaban, "a") == 0)
    {
        skor += 100;
        printf("Jawaban Anda benar!\n");
    }
    else
    {
        printf("Jawaban Anda salah!\n");
    }
    printf("==========================================\n");

    // Pertanyaan 5
    tampilkanPertanyaan("Nama siapa yang terkenal dalam dunia musik Indonesia dengan lagu 'Pergi Pagi Pulang Pagi'?", "Raisa", "Tulus", "Judika", "Armada");
    printf("Jawaban Anda (A/B/C/D): ");
    scanf("%s", jawaban);
    if (strcmp(jawaban, "D") == 0 || strcmp(jawaban, "d") == 0)
    {
        skor += 100;
        printf("Jawaban Anda benar!\n");
    }
    else
    {
        printf("Jawaban Anda salah!\n");
    }
    printf("==========================================\n");
    printf("Skor Anda: %d\n", skor);
}

int main(int BanyakArgumen, char *argumen[]) // ./main username passwword
{
    if (BanyakArgumen != 3)
    {

        printf("\n Cara penggunaan : ./(namafile) username password\n");

        return EXIT_FAILURE;
    }

    char usernameinput[10], passwordinput[10];
    // argumen[1] = "qwertyuiopasdfH";
    // argumen[2] = "WIKWOKasdjnhb";
    strcpy(usernameinput, argumen[1]);
    strcpy(passwordinput, argumen[2]);

    FILE *fpr = fopen("database/login.bin", "rb");
    char akun[20];

    if (fpr == NULL)
    {
        printf("Gagal membuka file.\n");
        return 1;
    }

    // Cek apakah file kosong
    fseek(fpr, 0, SEEK_END);
    if (ftell(fpr) == 0)
    {
        printf("================================================================\n");
        printf("\tGagal login, Silahkan registrasi terlebih dahulu!\n");
        printf("================================================================\n");

        FILE *fpw = fopen("database/login.bin", "wb");
        char id[20];
        char pw[20];
        printf("Registrasi\n");
        printf("Masukan id: ");
        scanf("%s", id);

        printf("Masukan pw: ");
        scanf("%s", pw);
        fprintf(fpw, "%s", id);

        fprintf(fpw, " ");
        fprintf(fpw, "%s", pw);

        fprintf(fpw, "\0"); // Menambahkan karakter nul di akhir data

        fclose(fpw);

        return EXIT_FAILURE;
    }

    if ((fpr = fopen("database/login.bin", "rb")) == NULL)
    {
        printf("Gagal membuka file!");

        return EXIT_FAILURE;
    }

    fread(akun, sizeof(char), sizeof(akun) / sizeof(char), fpr);

    fclose(fpr);

    char *string[3];
    char username[20], password[20];
    int ctrl = 0;

    string[0] = strtok(akun, " ");

    while (string[ctrl++] != NULL)
    {
        string[ctrl] = strtok(NULL, " ");
    }

    strcpy(username, string[0]);
    strcpy(password, string[1]);

    if (strcmp(usernameinput, username) == 0 && strcmp(usernameinput, username) == 0)
    {
        printf("Login Berhasil!\n");
        menu();
    }
    else
    {
        printf("PW SALAH!\n");

    }

    return 0;
}
