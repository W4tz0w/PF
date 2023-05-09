#include "printf.h"
#include "../libft/libft.h"
#include <stdlib.h>

int	pf_wnum_len(unsigned int wnum)
{
	int	len;

	len = 0;
	while (wnum != 0)
	{
		len++;
		wnum = wnum / 10;
	}
	return (len);
}
void	pf_putnbr(long int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(nb * -1);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}
