#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
	int i;
	printf("i    addr = %p\n", &i);
	printf("argc addr = %p\n", &argc);
	printf("argv addr = %p\n", &argv);
	for(i = 0; i < argc; i++)
		printf("\targv[%2d] addr = %p\n", i, argv+i);

	printf("envp addr = %p\n", &envp);
	for(i = 0; envp[i]; i++)
		printf("\tenvp[%2d] addr = %p\n", i, envp+i);

	return 0;
}
