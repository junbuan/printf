/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juho <juho@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 14:49:46 by juho              #+#    #+#             */
/*   Updated: 2026/09/01 13:27:39 by juho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define HEX_UP "0123456789ABCDEF"
# define HEX_LOW "0123456789abcdef"
# define DECIMAL "0123456789"

int	ft_putunbr_pf(unsigned long n);
int	ft_putptr_pf(void *ptr);
int	ft_puthex_pf(unsigned long n, char *base);

#endif