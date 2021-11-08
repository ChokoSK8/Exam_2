/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:46:28 by abrun             #+#    #+#             */
/*   Updated: 2021/11/08 15:28:11 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	print_arg(char c, va_list lst)
{
	if (c == 'd')
		return (print_d(va_arg(lst, int));
	else if (c == 's')
		return (print_s(va_arg(lst, char *));
	else
		return (print_x(lst, long long int));
}	

int	ft_printf(const char *s, ...)
{
	va_list	lst;
	char	*num;
	int		ret;
	int		n_ktr;
	
	va_start(lst, s);
	n_ktr = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			ret = print_arg(*s, lst);
			if (ret >= 0)
				n_ktr += ret;
			else
				return (1);
		}
		else
		{
			write(1, s, 1);
			n_ktr++;
		}
		if (*s)
			s++;
	}
	return (ret);
}
