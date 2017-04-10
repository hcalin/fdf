/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 20:39:22 by chrihorc          #+#    #+#             */
/*   Updated: 2017/01/03 20:41:25 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	j;
	unsigned int	i;
	unsigned int	z;
	char			*ptr;

	i = 0;
	z = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = ft_strlen(s) - 1;
	ptr = (char*)malloc(sizeof(char) * j+2);
	if (!ptr)
		return (0);
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	while (i <= j)
	{
		ptr[z] = s[i];
		z++;
		i++;
	}
	ptr[z] = '\0';
	return (ptr);
}
