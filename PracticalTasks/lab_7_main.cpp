#include <stdio.h>

void binary_mask(unsigned x)
{
	for (unsigned mask = 1 << (sizeof(int) * 8 - 1); mask; mask >>= 1)
		(x & mask ? printf("1") : printf("0"));
	printf("\n");
}

int bit(unsigned int n)
{
	int p = 0;
	for (unsigned i = 8 * sizeof(n) - 1; i > 0; --i)
	{
		if ((n & 3) == 3)
			p++;
		n >>= 1;
	}
	return p;
}

int main()
{
	unsigned x = 0;
	printf("Enter an integer: ");
	scanf("%d", &x);
	binary_mask(x);
	int p = bit(x);
	printf("\nThe number of pairs of bits: %d\n", p);
	return 0;
}