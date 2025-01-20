#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

bool stringMatch(char* str, char* pat)
{
	int i,j;
	bool flag = false;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == pat[0])
		{
			flag = true;
			for (j = 1; pat[j] != '\0'; j++)
			{
				if (str[i+j] == '\0' || str[i+j] != pat[j])
				{
					flag = false;
					break;
				}
			}

			if (flag)
			{
				printf("String found at pos %d",i);
				return true;
			}
		}
	}

	printf("String not found.");
	return false;
}

int main()
{
	char str[50];
	char pat[50];

	printf("Enter the string : ");
	fgets(str,50,stdin);
	str[strcspn(str,"\n")] = '\0';

	printf("Enter the pattern : ");
	fgets(pat,50,stdin);
	pat[strcspn(pat,"\n")] = '\0';

	stringMatch(str,pat);

	return 0;

}