#include "password_generator.h"

int main()
{
	srand(time(0));
	char* password = generate_password(16);
	printf("%s\n", password);
	free(password);
	return 0;
}

