/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 21:29:36 by chrihorc          #+#    #+#             */
/*   Updated: 2017/01/03 21:31:20 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (f) (char))
{

	int		i;
	char	*mappedstr;

	if (s == NULL || f == NULL)
		return (NULL);
	mappedstr = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (mappedstr == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		mappedstr[i] = f(s[i]);
	}
	mappedstr[i] = '\0';
	return (mappedstr);
}
