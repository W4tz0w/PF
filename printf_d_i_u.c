/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d_i_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 01:55:48 by daddy_cool        #+#    #+#             */
/*   Updated: 2023/05/11 01:55:49 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_d_i(int n)
{
	pf_putnbr(n);
	return (pf_wnum_len(n));
}

int	format_u(unsigned int n)
{
	pf_putunbr(n);
	return (pf_wunum_len(n));
}