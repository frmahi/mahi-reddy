#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char states[][3]={
        "AP", "KA", "TS", "TN", "MH",
        "KL", "DL", "UP", "GJ", "RJ",
        "WB", "BR", "MP", "OD", "PB",
        "HR", "HP", "JK", "CG", "GA",
        "AS", "AR", "JH", "SK", "TR",
        "MN", "ML", "MZ", "NL", "UK",
        "AN", "CH", "DD", "LA", "LD", "PY"
    };

    char v[20];
    int i,found =0, len;

    printf("Enter vehicle number:");
    scanf("%19s",v);
    

    for (i =0; v[i]!='\0';i++)
    {
        v[i]=toupper((unsigned char)v[i]);
    }

    len = strlen(v);

    if (len < 9 || len > 10)
    {
        printf("Invalid length");
        return 0;
    }

    for (i = 0; i < 36; i++)
    {
        if (v[0] == states[i][0] &&
            v[1] == states[i][1])
        {
            found = 1;
            break;
        } 

    }
    if (!found)
    {
        printf("Inavlid state code");
        return 0;
    }

    if (!isdigit((unsigned char)v[2]) &&
        !isdigit((unsigned char)v[3]))
    {
        printf("Invalid RTO code");
        return 0;
    }

    for ( i = 4; i < len -4;i++)
    {
        if (!isalpha((unsigned char)v[i]))
        {
            printf("Inavlid series code");
            return 0;
        }
    }

    for (i = len -4; i < len ; i++)
    {
        if(!isdigit((unsigned char)v[i]))
        {
            printf("Inavlid registration number");
            return 0;
        }
    }
    printf("Valid  Vehicle number");
    return 0;
}
