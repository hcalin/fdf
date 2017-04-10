/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 20:56:08 by chrihorc          #+#    #+#             */
/*   Updated: 2017/01/03 20:56:30 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		sz;

	sz = ft_strlen(s);
	while (s[sz] != c && 0 < sz)
		sz--;
	if (s[sz] == (char)c)
		return ((char*)&s[sz]);
	return (NULL);
}
