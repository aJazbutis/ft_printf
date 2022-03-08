/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_field.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:46:14 by ajazbuti          #+#    #+#             */
/*   Updated: 2021/11/05 23:07:40 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_solve_field(t_printf *p, char *s, int l)
{
	char	*str;
	char	*fill;

	str = NULL;
	fill = (char *)ft_calloc(p->wdth - (int)ft_strlen(s) + 1 - l, 1);
	if (fill)
	{
		if (p->mnus)
			ft_memset(fill, ' ', p->wdth - (int)ft_strlen(s) - l);
		if (p->mnus)
			str = ft_strjoin(s, fill);
		else if (p->zero)
		{
			ft_memset(fill, '0', p->wdth - (int)ft_strlen(s) - l);
			str = ft_strjoin(fill, s);
		}
		else
		{
			ft_memset(fill, ' ', p->wdth - (int)ft_strlen(s) - l);
			str = ft_strjoin(fill, s);
		}
		free(fill);
	}
	free(s);
	return (str);
}
