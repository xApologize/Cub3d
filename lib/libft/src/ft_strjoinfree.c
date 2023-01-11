/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:18:35 by jrossign          #+#    #+#             */
/*   Updated: 2022/12/09 09:53:55 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoinfree(const char *s1, const char *s2)
{
	char	*new_line;

	if (!s2)
		return (NULL);
	if (!s1)
		new_line = ft_strdup(s2);
	else
		new_line = ft_strjoin(s1, s2);
	if (s1)
		free((char *)s1);
	free((char *)s2);
	return (new_line);
}
