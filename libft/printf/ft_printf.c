/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:01:07 by isouaidi          #+#    #+#             */
/*   Updated: 2023/06/01 19:28:15 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_search_arg(const char c)
{
	return (ft_strchr2("scpdiuxX%", c) != 0);
}

int	ft_arg(const char s, va_list ap, int len)
{
	if (s == '%')
		len += ft_putchar(s);
	else if (s == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (s == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (s == 'p')
	{
		len += ft_putstr("0x");
		len += ft_putptr(va_arg(ap, unsigned long ));
	}
	else if (s == 'd')
		len += ft_putnbr(va_arg(ap, int));
	else if (s == 'i')
		len += ft_putnbr(va_arg(ap, int));
	else if (s == 'u')
		len += ft_putinnbr(va_arg(ap, unsigned int));
	else if (s == 'x')
		len += ft_printhexa_min(va_arg(ap, unsigned int));
	else if (s == 'X')
		len += ft_printhexa_max(va_arg(ap, unsigned int));
	return (len);
}

int	ft_final_arg(const char *s, va_list ap)
{
	int	len;

	len = 0;
	while (*s)
	{
		if (*s == '%' && ft_search_arg(*(s + 1)))
		{
			s++;
			len = ft_arg(*s, ap, len);
		}
		else
		{
			ft_putchar(*s);
			len ++;
		}
		s++;
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		len;
	va_list	ap;

	va_start (ap, s);
	len = ft_final_arg(s, ap);
	va_end (ap);
	return (len);
}
