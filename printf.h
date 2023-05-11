#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FORMATS "cspdiuxX%"
# include <stdarg.h>
# include <stdlib.h>
# include "../Libft/libft.h"

int	ft_printf(const char *input, ...);
int	pf_formats(va_list args, const char format);
int	nonformat(void);
int	format_s(char *str);
int	pf_print_c(int c);
int	pf_hexlen(unsigned	int num);
void	pf_puthex(unsigned int num, const char format);
int	format_x_X(unsigned int num, const char format);
void	pf_putnbr(long int nb);
int	pf_wnum_len(unsigned int wnum);
void	pf_putptr(uintptr_t num);
int	format_p(unsigned long long ptr);
int	format_d_i(long int n);
int	format_u(unsigned int n);
int	pf_wunum_len(unsigned int wnum);
void	pf_putunbr(unsigned int nb);

#endif