#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define u_char unsigned char

bool g_found;

const	char alphaNum[] = {
	"abcdefghijklmnopqrstuvwxyz"
	"0123456789"
};

void	bruteForcing(u_char *currentPwd, int depth, int length, char *password)
{
	if (g_found) {
		return ;
	}
	for (const char *c = alphaNum; *c; ++c)
	{
		currentPwd[depth] = *c;
		if (depth < (length - 1))
			bruteForcing(currentPwd, (depth + 1), length, password);
		if (strcmp((char *)currentPwd, password) == 0) {
			g_found = true;
		}
	}
}

int		usage()
{
	printf("Usage :  findPasswordBruteForce by mbougrin\n");
	printf("\tExemple : findPasswordBruteForce password\n");
	return (1);
}
int		main(int ac, char **av)
{
	clock_t start_t;
	clock_t end_t;

	if (ac != 2)
		return (usage());
	g_found = false;
	start_t = clock();
	u_char *buffer = malloc((sizeof(u_char *) * strlen(av[1]) + 1));
	if (!buffer)
		return (1);;
	memset(buffer, 'a', strlen(av[1]));
	buffer[strlen(av[1])] = 0;
	bruteForcing(buffer, 0, strlen(av[1]), av[1]);
	end_t = clock();
	if (g_found) {
		printf("Password Brute Force Found (password:%s) Time:%fms\n",
			av[1],
			(double)(end_t - start_t) / CLOCKS_PER_SEC);

	}
	return (1);
}
