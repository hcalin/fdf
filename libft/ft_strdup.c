/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:30:20 by chrihorc          #+#    #+#             */
/*   Updated: 2017/01/03 22:31:24 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;
	size_t	n;

	if (!s)
		return (0);
	i = 0;
	n = ft_strlen(s);
	ptr = (char*)malloc(n + 1);
	if (!ptr)
		return (0);
	while (i < n)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
