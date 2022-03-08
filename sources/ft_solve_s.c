/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:29:24 by ajazbuti          #+#    #+#             */
/*   Updated: 2021/11/05 20:42:49 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_null_str(t_printf *p)
{
	char	*str;

	if (p->prec)
		str = ft_substr("(null)", 0, p->prec_v);
	else
		str = ft_strdup("(null)");
	return (str);
}

static char	*ft_form_str(t_printf *p, char *s)
{
	char	*str;
	char	*fill;

	str = NULL;
	fill = (char *)ft_calloc(p->wdth - ft_strlen(s) + 1, sizeof(char));
	if (fill)
	{
		ft_memset(fill, ' ', p->wdth - ft_strlen(s));
		if (p->mnus)
			str = ft_strjoin(s, fill);
		else if (p->zero)
		{
			ft_memset(fill, '0', p->wdth - ft_strlen(s));
			str = ft_strjoin(fill, s);
		}
		else
			str = ft_strjoin(fill, s);
		free(fill);
	}
	free(s);
	return (str);
}

char	*ft_solve_s(t_printf *p)
{
	char	*str;
	char	*s;

	str = va_arg(p->args, char *);
	if (!str)
		s = ft_null_str(p);
	else
	{
		if (p->prec)
			s = ft_substr(str, 0, p->prec_v);
		else
			s = ft_strdup(str);
	}
	if (p->wdth > (int)ft_strlen(s) && s)
		s = ft_form_str(p, s);
	return (s);
}
