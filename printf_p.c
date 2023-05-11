/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 01:55:42 by daddy_cool        #+#    #+#             */
/*   Updated: 2023/05/11 01:55:43 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putptr(uintptr_t num)
{
	if (num >= 16)
	{
		pf_putptr(num / 16);
		pf_putptr(num % 16); 
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	format_p(unsigned long long ptr)
{
	int	len;
	
	len = write(1, "0x", 2);
	if (ptr == 0)
		len += write(1, "0", 1);
	else
	{
		pf_putptr(ptr);
		while (ptr != 0)
		{
			len++;
			ptr = ptr / 16;
		}
	}
	return (len);
}
