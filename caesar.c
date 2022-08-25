#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void print_cipher(char str, int key)
{
    int index = str;

    if ((index + key) > 122)
    {
        key = (index + key) - 122;
        str = '`';
        printf("%c", str + key);
    }
    else
    {
        printf("%c", str + key);
    }
}

void print_cipher2(char str, int key)
{
    int index = str;

    if ((index + key) > 90)
    {
        key = (index + key) - 90;
        str = '@';
        printf("%c", str + key);
    }
    else
    {
        printf("%c", str + key);
    }
}

int only_digits(string str)
{
    for(int i = 0; i < strlen(str); i++)
    {
        if (isdigit(str[i]))
        {
            //nothing to do here
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

int main(int argc, string argv[])
{
    string plaintext;

    if (argc > 2 || argc < 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        if (only_digits(argv[1]))
        {
        printf("Usage: ./caesar key\n");
        return 1;
        }
    else
    {
        int key = atoi(argv[1]) % 26;
        plaintext = get_string("plaintext:  ");
        printf("Ciphertext: ");

        for (int i = 0; i < strlen(plaintext); i++)
        {
            int uppercase = 65, lowercase = 97, flag = 0;

        for (int j = 0; j < 26; j++)
        {
            if(plaintext[i]==lowercase)
            {
                print_cipher(plaintext[i],key);
                flag=1;
                break;
            }
            else if(plaintext[i] == uppercase)
            {
                print_cipher2(plaintext[i],key);
                flag=1;
                break;
            }
            else
            {
                ++lowercase;
                ++uppercase;
            }
        }

        if(flag==0)
        {
            printf("%c",plaintext[i]);
        }
    }
    printf("\n");
    }
    }
}