/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:31:49 by ajazbuti          #+#    #+#             */
/*   Updated: 2021/11/05 20:47:35 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_neg_pt_two(t_printf *p, char *s)
{
	char	*di;

	di = s;
	if (p->mnus || p->zero)
	{
		di = ft_solve_field(p, s, 1);
		if (di)
			di = ft_add_prfx("-", di);
	}
	else
	{
		di = ft_add_prfx("-", s);
		if (di)
			di = ft_solve_field(p, di, 0);
	}
	return (di);
}

static char	*ft_neg_di(t_printf *p, char *s)
{
	char	*di;

	di = NULL;
	if (p->prec)
	{
		di = ft_prec_nbr(p, s);
		if (di)
			di = ft_add_prfx("-", di);
		if (p->wdth > (int)ft_strlen(di) && di)
			di = ft_put_field(p, di);
	}
	else if (p->wdth - (int)ft_strlen(s) > 1)
		di = ft_neg_pt_two(p, s);
	else
		di = ft_add_prfx("-", s);
	return (di);
}

static char	*ft_pos_pt_two(t_printf *p, char *s)
{
	char	*di;

	di = s;
	if (p->wdth - (int)ft_strlen(s) > 1)
		di = ft_solve_field(p, s, 1);
	if (di)
	{
		if (p->plus)
			di = ft_add_prfx("+", di);
		else
			di = ft_add_prfx(" ", di);
	}
	return (di);
}

static char	*ft_pos_di(t_printf *p, char *s)
{
	char	*di;

	di = s;
	if (p->prec)
	{
		di = ft_prec_nbr(p, s);
		if (di && p->plus)
			di = ft_add_prfx("+", di);
		else if (di && p->spce)
			di = ft_add_prfx(" ", di);
		if (p->wdth > (int)ft_strlen(di) && di)
			di = ft_put_field(p, di);
	}
	else if (p->plus || p->spce)
		di = ft_pos_pt_two(p, s);
	else if (p->wdth > (int)ft_strlen(s))
		di = ft_solve_field(p, s, 0);
	return (di);
}

char	*ft_solve_di(t_printf *p)
{
	int		i;
	char	*di;

	di = NULL;
	i = va_arg(p->args, int);
	if (i < 0)
	{
		if (i == INT_MIN)
			di = ft_strdup("2147483648");
		else
			di = ft_itoa(-1 * i);
		if (di)
			di = ft_neg_di(p, di);
	}
	else
	{
		if (i == 0 && p->prec && p->prec_v == 0)
			di = (char *)ft_calloc(1, 1);
		else
			di = ft_itoa(i);
		di = ft_pos_di(p, di);
	}
	return (di);
}
