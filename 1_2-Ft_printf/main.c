#include "ft_printf.h"

int	main()
{
	char	*s;
	int	i;
	int	j;
	s = "je suis ton pere";
	i = printf("%c %d %s %x %p\n", 'c', 1233333333, "", 2300, s);
	j = ft_printf("%c %d %s %x %p\n", 'c', 1233333333, "", 2300, s);
	printf("vrai %d - copy %d", i, j);
}