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
