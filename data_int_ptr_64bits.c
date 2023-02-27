#include <stdio.h>
#include <assert.h>

void put_data(unsigned long long *p, unsigned long long data)
{
	assert(data < 8);
	*p |= data;
}

unsigned long long get_data(unsigned long long p)
{
	return (p & 7);
}

void cleanse_pointer(unsigned long long *p)
{
	*p &= ~7;
}
//Given that the bitness of the operating system is 64 bits, rewrite it to a 64-bit version.
int main(void)
{
	unsigned long long x = 701;
	unsigned long long p = (unsigned long long) &x;

	printf("Original ptr: %llu\n", p);

	put_data(&p, 6);

	printf("ptr with data: %llu\n", p);
	printf("data stored in ptr: %llu\n", get_data(p));

	cleanse_pointer(&p);

	printf("Cleansed ptr: %llu\n", p);
	printf("Dereferencing cleansed ptr: %lli\n", *(unsigned long long *)p);

	return 0;
}
