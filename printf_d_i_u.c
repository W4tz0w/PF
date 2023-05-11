/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d_i_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiovann <egiovann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:04:50 by egiovann          #+#    #+#             */
/*   Updated: 2023/05/11 16:04:51 by egiovann         ###   ########.fr       */
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
