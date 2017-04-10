/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 21:31:50 by chrihorc          #+#    #+#             */
/*   Updated: 2017/01/03 21:33:26 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	unsigned int	j;
	size_t			dlen;
	size_t			slen;

	i = ft_strlen(dst);
	j = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (size < dlen + 1)
		return (slen + size);
	if (size > dlen + 1)
	{
		while (i < size - 1)
		{
			*(dst + i) = *(src + j);
			i++;
			j++;
		}
		*(dst + i) = '\0';
	}
	return (dlen + slen);
}
