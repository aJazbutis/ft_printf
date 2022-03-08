/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:08:22 by ajazbuti          #+#    #+#             */
/*   Updated: 2021/11/05 20:40:10 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_pt_two(t_printf *p, char *s)
{
	if (p->mnus || p->zero)
	{
		s = ft_solve_field(p, s, 2);
		if (s)
			s = ft_add_prfx("0x", s);
	}
	else
	{
		s = ft_add_prfx("0x", s);
		if (s)
			s = ft_solve_field(p, s, 0);
	}
	return (s);
}

char	*ft_solve_p(t_printf *p)
{
	unsigned long	n;
	char			*s;

	n = va_arg(p->args, unsigned long);
	if (n == 0 && p->prec && p->prec_v == 0)
		s = (char *)ft_calloc(1, 1);
	else
		s = ft_ultobase(n, "0123456789abcdef");
	if (!s)
		return (s);
	if (p->prec)
	{
		s = ft_prec_nbr(p, s);
		if (s)
			s = ft_add_prfx("0x", s);
		if (p->wdth > (int)ft_strlen(s) && s)
			s = ft_put_field(p, s);
	}
	else if (p->wdth - (int)ft_strlen(s) > 2)
		s = ft_pt_two(p, s);
	else
		s = ft_add_prfx("0x", s);
	return (s);
}
