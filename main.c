#include <stdio.h>

int main()
{
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

    fclose(fpw);

        return 0;
}
