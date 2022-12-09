/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:53:14 by bperron           #+#    #+#             */
/*   Updated: 2022/12/09 09:19:14 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	checkset(const char *set, char c)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (c == set[j++])
			return (1);
	}
	return (0);
}

char	*ft_strtrim_str(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (!s1 || !set)
		return (NULL);
	j = 0;
	k = 0;
	i = ft_strlen(s1);
	while (s1[j] && checkset(set, s1[j]))
		j++;
	while (i > j && checkset(set, s1[i - 1]))
		i--;
	str = ft_calloc((i - j + 1), sizeof(char));
	if (str == NULL)
		return (0);
	while (j < i)
		str[k++] = s1[j++];
	return (str);
}
