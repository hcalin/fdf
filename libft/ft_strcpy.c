/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:32:29 by chrihorc          #+#    #+#             */
/*   Updated: 2017/01/03 22:32:32 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	unsigned int n;

	n = 0;
	while (src[n])
	{
		dest[n] = src[n];
		n++;
	}
	dest[n] = '\0';
	return (dest);
}
