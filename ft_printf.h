/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiovann <egiovann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:04:17 by egiovann          #+#    #+#             */
/*   Updated: 2023/05/11 16:04:19 by egiovann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FORMATS "cspdiuxX%"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *input, ...);
int		pf_formats(va_list args, const char format);
int		nonformat(void);
int		format_s(char *str);
int		pf_print_c(int c);
int		pf_hexlen(unsigned	int num);
int		format_hex(unsigned int num, const char format);
int		pf_wnum_len(int wnum);
int		format_p(unsigned long long ptr);
int		format_d_i(int n);
int		format_u(unsigned int n);
int		pf_wunum_len(unsigned int wnum);
void	pf_putnbr(int nb);
void	pf_putptr(uintptr_t num);
void	ft_putchar_fd(char c, int fd);
void	pf_puthex(unsigned int num, const char format);
void	pf_putunbr(unsigned int nb);

#endif
