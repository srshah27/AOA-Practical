#include <stdio.h>
#include <conio.h>
#include <string.h>
void prefixSuffixArray(char *pat, int M, int *psa)
{
   int length = 0;
   int i = 1;
   psa[0] = 0;
   while (i < M)
   {
      if (pat[i] == pat[length])
      {
         length++;
         psa[i] = length;
         i++;
      }
      else
      {
         if (length != 0)
            length = psa[length - 1];
         else
         {
            psa[i] = 0;
            i++;
         }
      }
   }
}
void KMPSearch(char *txt, char *pat)
{
   int M = strlen(pat);
   int N = strlen(txt);
   int psa[50];
   int i = 0, j = 0;
   prefixSuffixArray(pat, M, psa);
   while (i < N)
   {
      if (pat[j] == txt[i])
      {
         j++;
         i++;
      }
      if (j == M)
      {
         printf("Found %s pattern at index %d \n", pat, i - j);
         j = psa[j - 1];
      }
      else if (i < N && pat[j] != txt[i])
      {
         if (j != 0)
            j = psa[j - 1];
         else
            i = i + 1;
      }
   }
}
void main()
{
   char txt[20];
   char pat[20];
   clrscr();
   printf("Enter the text: ");
   scanf("%s", txt);
   printf("Enter the pattern: ");
   scanf("%s", pat);
   KMPSearch(txt, pat);
   getch();
}