#include "ft_printf.h"
#include <stdlib.h>

int	format_d_i(int n)
{
	pf_putnbr(n);
	return (pf_wnum_len(n));
	// int		len;
	// char	*wnum;

	// len = 0;
	// wnum = ft_itoa(n);
	// len = format_s(wnum);
	// free(wnum);
	// return (len);
}

// char	*ft_uitoa(unsigned int n)
// {
// 	char	*wnum;
// 	int		len;

// 	len = pf_wnum_len(n);
// 	wnum = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!wnum)
// 		return (0);
// 	wnum[len] = '\0';
// 	while (n != 0)
// 	{
// 		wnum[len - 1] = n % 10 + 48;
// 		n = n / 10;
// 		len--;
// 	}
// 	return (wnum);
// }

int	format_u(unsigned int n)
{
	pf_putnbr((unsigned int)n);
	return (pf_wnum_len((unsigned int)n));
	// int		wn_len;
	// char	*wnum;

	// wn_len = 0;
	// if (n == 0)
	// 	wn_len += write(1, "0", 1);
	// else
	// {
	// 	wnum = ft_uitoa(n);
	// 	wn_len += format_s(wnum);
	// 	free(wnum);
	// }
	// return (wn_len);
}