#include "password_generator.h"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <length>\n", argv[0]);
		exit(1);
	}

	srand(time(0));
	char* password = (char*) malloc(sizeof(char) * (atoi(argv[1]) + 1));
	generate_password(password, atoi(argv[1]));
	printf("%s\n", password);
	free(password);
	return 0;
}

