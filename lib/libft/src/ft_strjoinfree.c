/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:18:35 by jrossign          #+#    #+#             */
/*   Updated: 2022/12/06 15:58:57 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdlib.h>

char	*ft_strjoinfree(const char *s1, const char *s2)
{
	char	*new_line;

	new_line = ft_strjoin(s1, s2);
	free((char *)s1);
	free((char *)s2);
	return (new_line);
}
