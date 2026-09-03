/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juho <juho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 14:08:54 by juho              #+#    #+#             */
/*   Updated: 2026/09/03 12:17:40 by juho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1), 1);
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr((long)va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunbr_pf((unsigned long)va_arg(args, unsigned int)));
	else if (c == 'p')
		return (ft_putptr_pf(va_arg(args, void *)));
	else if (c == 'x')
		return (ft_puthex_pf(va_arg(args, unsigned int), HEX_LOW));
	else if (c == 'X')
		return (ft_puthex_pf(va_arg(args, unsigned int), HEX_UP));
	else if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count += ft_format(*format, ap);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
