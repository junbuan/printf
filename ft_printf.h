/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juho <juho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 14:49:46 by juho              #+#    #+#             */
/*   Updated: 2026/09/05 18:36:26 by juho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define HEX_UP "0123456789ABCDEF"
# define HEX_LOW "0123456789abcdef"
# define DECIMAL "0123456789"

int		ft_putnbr_pf(long n);
int		ft_putstr_pf(char *s);
int		ft_putptr_pf(void *ptr);
int		ft_putunbr_pf(unsigned long n);
int		ft_format(char c, va_list args);
int		ft_printf(const char *format, ...);
int		ft_puthex_pf(unsigned long long n, char *base);

#endif