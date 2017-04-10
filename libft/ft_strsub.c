/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 20:44:57 by chrihorc          #+#    #+#             */
/*   Updated: 2017/01/03 20:50:53 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	str = (char *)malloc(sizeof(char) * (len + 5));
	if (!str)
		return (0);
	while (s[i])
	{
		if (i == start)
		{
			while (j < len)
			{
				str[j] = s[i + j];
				j++;
			}
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}
