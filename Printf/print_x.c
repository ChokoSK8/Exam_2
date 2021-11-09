/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 08:55:55 by abrun             #+#    #+#             */
/*   Updated: 2021/11/09 09:31:00 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_x(unsigned int arg)
{
	int	len;
	char	*hexa;

	hexa = convert_hexa(arg);
	if (!hexa)
		return (-1);
	len = ft_strlen(hexa);
	write(1, hexa, len);
	return (len);
}
