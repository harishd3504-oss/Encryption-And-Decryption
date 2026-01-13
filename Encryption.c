#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp1, *fp2;
    char fileName[100], ch;
    int key, choice;

    printf("1. Encrypt File\n");
    printf("2. Decrypt File\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter file name: ");
    scanf("%s", fileName);

    printf("Enter secret key (number): ");
    scanf("%d", &key);

    fp1 = fopen(fileName, "r");
    if (fp1 == NULL)
    {
        printf("File not found\n");
        return 0;
    }

    fp2 = fopen("output.txt", "w");

    while ((ch = fgetc(fp1)) != EOF)
    {
        fputc(ch ^ key, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    if (choice == 1)
        printf("File encrypted successfully\n");
    else if (choice == 2)
        printf("File decrypted successfully\n");
    else
        printf("Invalid choice\n");

    return 0;
}
