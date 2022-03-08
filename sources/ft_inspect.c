/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:26:40 by ajazbuti          #+#    #+#             */
/*   Updated: 2021/11/06 00:30:17 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static void	ft_set_reset(t_printf *p)
{
	p->format++;
	p->wdth = 0;
	p->mnus = 0;
	p->zero = 0;
	p->prec = 0;
	p->plus = 0;
	p->hash = 0;
	p->spce = 0;
	p->prec_v = 0;
}

static void	ft_solve_flgs(t_printf *p)
{
	while (*p->format && ft_strchr("-0 +#", *p->format))
	{
		if (*p->format == '-')
			p->mnus = 1;
		if (*p->format == '0')
			p->zero = 1;
		if (*p->format == ' ')
			p->spce = 1;
		if (*p->format == '+')
			p->plus = 1;
		if (*p->format == '#')
			p->hash = 1;
		p->format++;
	}
	if (p->mnus && p->zero)
		p->zero = 0;
	if (p->plus && p->spce)
		p->spce = 0;
}

static void	ft_solve_wdth(t_printf *p)
{
	if (ft_isdigit(*p->format))
	{
		p->wdth = ft_atoi(p->format);
		while (ft_isdigit(*p->format))
			p->format++;
	}
	if (*p->format == '*')
	{
		p->format++;
		p->wdth = va_arg(p->args, int);
	}
	if (p->wdth < 0)
	{	
		p->wdth = (-1 * p->wdth);
		p->mnus = 1;
		p->zero = 0;
	}
}

static void	ft_solve_prec(t_printf *p)
{
	if (*p->format == '.')
	{
		p->prec = 1;
		p->format++;
		if (ft_isdigit(*p->format))
		{
			p->prec_v = ft_atoi(p->format);
			while (ft_isdigit(*p->format))
				p->format++;
		}
		if (*p->format == '*')
		{
			p->format++;
			p->prec_v = va_arg(p->args, int);
		}
	}
	if (p->prec_v < 0)
		p->prec = 0;
}

void	ft_inspect(t_printf *p)
{
	ft_set_reset(p);
	ft_solve_flgs(p);
	ft_solve_wdth(p);
	ft_solve_prec(p);
	ft_convert(p);
}
