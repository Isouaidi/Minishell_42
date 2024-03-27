/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:17:35 by isouaidi          #+#    #+#             */
/*   Updated: 2023/06/02 12:19:46 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

char	ft_putchar(char c);
char	*ft_strchr2(const char *s, int c);
int		ft_printf(const char *s, ...);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_printhexa_min(unsigned int n);
int		ft_putinnbr(unsigned int n);
int		ft_putptr(unsigned long n);
int		ft_printhexa_max(unsigned int n);

#endif
