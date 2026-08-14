#include <stdio.h>
#include <stdbool.h>
bool recherche(char t[], char e)
{
    int i = 1;
    while (i < t[0])
    {
        if (t[i] == e)
        {
            return true;
        }
        else if (e < t[i])
        {
            i = i * 2;
        }
        else
        {
            i = i * 2 + 1;
        }
    }
    return false;
}
int main()
{
    char tab[16] = {15,
                    'A',
                    'B',
                    'C',
                    'D',
                    'E',
                    'F',
                    'G',
                    'H',
                    'I',
                    'J',
                    'K',
                    'L',
                    'M',
                    'N',
                    'O'};
    printf("%d", recherche(tab, 'J'));
}