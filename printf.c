/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 01:56:01 by daddy_cool        #+#    #+#             */
/*   Updated: 2023/05/11 01:56:02 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_print_c(int c)
{
	write(1, &c, 1);
	return (1);
}

int	format_s(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	nonformat(void)
{
	write(1, "%", 1);
	return (1);
}

int	pf_formats(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += pf_print_c(va_arg(args, int));
	else if (format == 's')
		len += format_s(va_arg(args, char *));
	else if (format == 'p')
		len += format_p(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += format_d_i(va_arg(args, int));
	else if (format == 'u')
		len += format_u(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += format_x_X(va_arg(args, unsigned int), format);
	else if (format == '%')
		len += nonformat();
	else
		len--;
	return (len);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			len += pf_formats(args, input[i + 1]);
			i++;
		}
		else
			len += pf_print_c(input[i]);
		i++;
	}
	va_end(args);
	return (len);
}


int		main(void)
{
	// ft_printf("%i", -1);
	// printf("\n");
	// printf("%i\n",-1);
	ft_printf("(Y9Lk%i`h1X.(U%d*,"%c%u6"%xr.i!No*8z%pJ!h\v%sNzxXX%uC_Ok\v\rD", 1826227172, 457743330, -1280881534, -1306065819, 
37642916, (void *)849345852295461385, "'fc^`.r", -1112964109);
	printf("\n=========================\n");
	printf("(Y9Lk%i`h1X.(U%d*,"%c%u6"%xr.i!No*8z%pJ!h\v%sNzxXX%uC_Ok\v\rD", 1826227172, 457743330, -1280881534, -1306065819, 
37642916, (void *)849345852295461385, "'fc^`.r", -1112964109);
	/*
	char	*name = "Enzo le plus beau";

	ft_printf("salut %s, ca roule comme tu veux?\n", name);
	ft_printf("hexa test %x\n", 42);
	ft_printf("ptr test = %p\n", name);
	printf("%p\n", name);
	ft_printf("HEXA test = %X\n", 367);
	ft_printf("char test = %c\n", 'G');
	ft_printf("unsigned int test = %u\n", -365222);
	printf("%u\n", -365222);
	ft_printf("");*/
	return (0);
}
