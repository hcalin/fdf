/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 21:24:20 by chrihorc          #+#    #+#             */
/*   Updated: 2017/01/03 21:24:45 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	len1;
	size_t	i;

	i = 0;
	len1 = ft_strlen(dest);
	while (i < n && src[i])
	{
		dest[len1++] = src[i++];
	}
	dest[len1] = '\0';
	return (dest);
}
