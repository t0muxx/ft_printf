
#include "libft.h"

int	main(int argc, char **argv)
{
	char *str;

	str = ft_strdup(argv[1]);
	printf("%s\n", ft_strrev(str));
}
