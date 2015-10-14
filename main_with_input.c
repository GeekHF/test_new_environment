#include <stdio.h>
int main(int argc, char const *argv[])
{
	for (int i = 1; i < argc; ++i)
	{
		printf("%s\n",argv[i]);
		int a = (int)(*argv[i] - '0');
		printf("%d\n", a);
	}
	const char *c;
	c = "hello world!";
	printf("%s\n",c);
	return 0;
}
