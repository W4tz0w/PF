/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 01:55:50 by daddy_cool        #+#    #+#             */
/*   Updated: 2023/05/11 01:55:51 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_wnum_len(int wnum)
{
	int	len;

	len = 0;
	if (wnum == 0)
		len++;
	if (wnum < 0)
		len++;
	while (wnum != 0)
	{
		if (wnum == '-')
			len++;
		else if (wnum == 0)
			len++;
		len++;
		wnum = wnum / 10;
	}
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

int	pf_wunum_len(unsigned int wnum)
{
	int	len;

	len = 0;
	if (wnum == 0)
		len++;
	if (wnum < 0)
		len++;
	while (wnum != 0)
	{
		if (wnum == '-')
			len++;
		else if (wnum == 0)
			len++;
		len++;
		wnum = wnum / 10;
	}
	return (len);
}

void	pf_putunbr(unsigned int nb)
{
	if (nb >= 10)
	{
		pf_putunbr(nb / 10);
		pf_putunbr(nb % 10);
	}
	else
	{
		ft_putchar_fd(nb + '0', 1);
	}
}
