/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_field.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:04:38 by ajazbuti          #+#    #+#             */
/*   Updated: 2021/11/05 16:05:24 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_put_field(t_printf *p, char *s)
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
		else
			str = ft_strjoin(fill, s);
		free(fill);
	}
	free(s);
	return (str);
}
