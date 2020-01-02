#include "monty.h"

/**
 * main -
 * @argc:
 * @argv:
 * Return:
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	montyFile(argv);
	return (0);
}

/**
 * montyFile -
 * @argc:
 * @argv:
 * Return:
 */
void montyFile(char **argv)
{
	const char *filename = argv[1];
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", filename);
		exit(EXIT_FAILURE);
	}
}
