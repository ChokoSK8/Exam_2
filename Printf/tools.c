/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:16:06 by abrun             #+#    #+#             */
/*   Updated: 2021/11/08 15:32:30 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_n_digit(int n)
{
	int	res;
	int	minus;

	minus = 0;
	if (n < 0)
	{
		n *= -1;
		minus = 1;
	}
	res = 1;
	while (n > 10)
	{
		n / 10;
		res++;
	}
	if (minus)
		res++;
	return (res);
}

char	*ft_itoa(int n)
{
	char	*itoa;

	
