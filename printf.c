#include "printf.h"

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
		len += format_d_i(va_arg(args, long int));
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
	char	*name = "Enzo le plus beau";
	
	ft_printf("salut %s, ca roule comme tu veux?", name);
	return (0);
}
