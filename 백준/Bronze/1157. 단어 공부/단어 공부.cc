#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 이진호 코드 아님
int main(void)
{
    int i,Midx = 0,count = 0;
    char Most;
    int alpha[26] = { 0 };
    char* Cha = (char*)malloc(sizeof(char) * 1000000);

    
    scanf("%s", Cha);
    if (strlen(Cha) > 1000000)
        return 0;
    for (i = 0; i < strlen(Cha); ++i)
    {
        switch (*(Cha + i))
        {
        case 'A':
            alpha[0] += 1;
            break;
        case 'B':
            alpha[1] += 1;
            break;
        case 'C':
            alpha[2] += 1;
            break;
        case 'D':
            alpha[3] += 1;
            break;
        case 'E':
            alpha[4] += 1;
            break;
        case 'F':
            alpha[5] += 1;
            break;
        case 'G':
            alpha[6] += 1;
            break;
        case 'H':
            alpha[7] += 1;
            break;
        case 'I':
            alpha[8] += 1;
            break;
        case 'J':
            alpha[9] += 1;
            break;
        case 'K':
            alpha[10] += 1;
            break;
        case 'L':
            alpha[11] += 1;
            break;
        case 'M':
            alpha[12] += 1;
            break;
        case 'N':
            alpha[13] += 1;
            break; 
        case 'O':
            alpha[14] += 1;
            break;
        case 'P':
            alpha[15] += 1;
            break;
        case 'Q':
            alpha[16] += 1;
            break;
        case 'R':
            alpha[17] += 1;
            break;
        case 'S':
            alpha[18] += 1;
            break;
        case 'T':
            alpha[19] += 1;
            break;
        case 'U':
            alpha[20] += 1;
            break;
        case 'V':
            alpha[21] += 1;
            break;
        case 'W':
            alpha[22] += 1;
            break;
        case 'X':
            alpha[23] += 1;
            break;
        case 'Y':
            alpha[24] += 1;
            break;
        case 'Z':
            alpha[25] += 1;
            break;
        case 'a':
            alpha[0] += 1;
            break;
        case 'b':
            alpha[1] += 1;
            break;
        case 'c':
            alpha[2] += 1;
            break;
        case 'd':
            alpha[3] += 1;
            break;
        case 'e':
            alpha[4] += 1;
            break;
        case 'f':
            alpha[5] += 1;
            break;
        case 'g':
            alpha[6] += 1;
            break;
        case 'h':
            alpha[7] += 1;
            break;
        case 'i':
            alpha[8] += 1;
            break;
        case 'j':
            alpha[9] += 1;
            break;
        case 'k':
            alpha[10] += 1;
            break;
        case 'l':
            alpha[11] += 1;
            break;
        case 'm':
            alpha[12] += 1;
            break;
        case 'n':
            alpha[13] += 1;
            break;
        case 'o':
            alpha[14] += 1;
            break;
        case 'p':
            alpha[15] += 1;
            break;
        case 'q':
            alpha[16] += 1;
            break;
        case 'r':
            alpha[17] += 1;
            break;
        case 's':
            alpha[18] += 1;
            break;
        case 't':
            alpha[19] += 1;
            break;
        case 'u':
            alpha[20] += 1;
            break;
        case 'v':
            alpha[21] += 1;
            break;
        case 'w':
            alpha[22] += 1;
            break;
        case 'x':
            alpha[23] += 1;
            break;
        case 'y':
            alpha[24] += 1;
            break;
        case 'z':
            alpha[25] += 1;
            break;
        default:
            break;
        }
    }

    for (i = 0; i < 26; ++i)
    {
        if (alpha[Midx] < alpha[i])
            Midx = i;
    }

    for (i = 0; i < 26; ++i)
    {
        if (alpha[Midx] == alpha[i])
            count++;
        if (count > 1)
        {
            Midx = 26;
            break;
        }
    }

    switch (Midx)
    {
    case 0:
        Most = 'A';
        break;
    case 1:
        Most = 'B';
        break;
    case 2:
        Most = 'C';
        break;
    case 3:
        Most = 'D';
        break;
    case 4:
        Most = 'E';
        break;
    case 5:
        Most = 'F';
        break;
    case 6:
        Most = 'G';
        break;
    case 7:
        Most = 'H';
        break;
    case 8:
        Most = 'I';
        break;
    case 9:
        Most = 'J';
        break;
    case 10:
        Most = 'K';
        break;
    case 11:
        Most = 'L';
        break;
    case 12:
        Most = 'M';
        break;
    case 13:
        Most = 'N';
        break;
    case 14:
        Most = 'O';
        break;
    case 15:
        Most = 'P';
        break;
    case 16:
        Most = 'Q';
        break;
    case 17:
        Most = 'R';
        break;
    case 18:
        Most = 'S';
        break;
    case 19:
        Most = 'T';
        break;
    case 20:
        Most = 'U';
        break;
    case 21:
        Most = 'V';
        break;
    case 22:
        Most = 'W';
        break;
    case 23:
        Most = 'X';
        break;
    case 24:
        Most = 'Y';
        break;
    case 25:
        Most = 'Z';
        break;
    case 26:
        Most = '?';
        break;
    default:
        break;
    }

    printf("%c", Most);

    free(Cha);
    return 0;
}