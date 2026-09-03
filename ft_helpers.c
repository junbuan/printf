/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juho <juho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 15:36:07 by juho              #+#    #+#             */
/*   Updated: 2026/09/03 14:49:57 by juho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putstr_pf(char * s)
{
	write(1, s, ft_strlen(s));
}

	
int	ft_putunbr_pf(unsigned long n)
{
	int	i;

	i = 0;
	if (n >= 10)
		i += ft_putunbr_pf(n / 10);
	i += write(1, &DECIMAL[n % 10], 1);
	return (i);
}

int	ft_putptr_pf(void *ptr)
{
	if (!ptr)
		return (ft_putstr_pf("(nil)"));
	return (ft_putstr_pf("0x") + ft_puthex_pf((unsigned long) ptr, HEX_LOW));
}

int	ft_puthex_pf(unsigned long n, char *base)
{
	char	buffer[32];
	int		i;
	int		j;

	if (n == 0)
		return (write(1, "0", 1));
	i = 0;
	j = 0;
	while (n)
	{
		buffer[j++] = base[n % 16];
		n /= 16;
	}
	while (j--)
		i += write(1, &buffer[j], 1);
	return (i);
}
