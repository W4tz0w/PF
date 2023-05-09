#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

int	pf_wnum_len(int wnum)
{
	int	len;

	len = 0;
	while (wnum != 0)
	{
		len++;
		wnum = wnum / 10;
	}
	//printf("%d", len);
	return (len);
}

void	pf_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		pf_putnbr(147483648);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		pf_putnbr(nb * -1);
	}
	else if (nb >= 10)
	{
		pf_putnbr(nb / 10);
		pf_putnbr(nb % 10);
	}
	else
	{
		ft_putchar_fd(nb + '0', 1);
	}
}
