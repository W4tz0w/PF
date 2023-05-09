#include <stdio.h>
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
		//printf("wtf is this : %d\n", len);
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
	printf("LEN %d\n", len);
	return (len);
}


int		main(void)
{
	char	*name = "Enzo le plus beau";
	
	ft_printf("int test = %i\n", -1);
	printf("original printf = %i\n",-1);
	/*
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
