#include <stdio.h>
#include <string.h>
#define NO_OF_CHARS 256

void badCharHeuristic(char *str, int size, int badchar[NO_OF_CHARS]) {
    for (int i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;
    for (int i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}

void horspoolSearch(char *txt, char *pat) {
    int m = strlen(pat);
    int n = strlen(txt);
    int badchar[NO_OF_CHARS];
    int comparisons = 0;
    badCharHeuristic(pat, m, badchar);
    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;
        while(j >= 0 && pat[j] == txt[s + j]) {
            comparisons++;
            j--;
        }
        if(j < 0) {
            printf("Pattern found at index %d\n", s);
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        } else {
            comparisons++;
            s += (j - badchar[txt[s + j]] > 1) ? j - badchar[txt[s + j]] : 1;
        }
    }
    printf("Total key comparisons: %d\n", comparisons);
}

int main() {
    char txt[] = "ABAAABCD";
    char pat[] = "ABC";
    horspoolSearch(txt, pat);
    return 0;
}
