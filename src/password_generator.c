#include "password_generator.h"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <length>\n", argv[0]);
		exit(0);
	}

	srand(time(0));
	char* password = generate_password(atoi(argv[1]));
	// char* password = generate_password(16);
	printf("%s\n", password);
	free(password);
	return 0;
}

