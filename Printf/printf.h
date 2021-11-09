/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 07:55:51 by abrun             #+#    #+#             */
/*   Updated: 2021/11/09 09:23:14 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
#define PRINTF_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *s, ...);

int	print_arg(char c, va_list lst);

int	print_d(int arg);

int	print_s(char *arg);

int	print_x(unsigned int arg);

int		ft_n_digit(int n);

char	*ft_itoa(int n);

void	ft_getnbr(char *itoa, int n_bis, int counter);

size_t	ft_strlen(char *s);

char	*convert_hexa(unsigned int n);

int	get_n_hexa(unsigned int n);

char	*get_hexa_base(void);
#endif
