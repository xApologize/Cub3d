/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:18:39 by jrossign          #+#    #+#             */
/*   Updated: 2023/02/03 11:29:10 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strtrim_free(char *str, const char c)
{
	char	*str_trimmed;

	str_trimmed = ft_strtrim_char(str, c);
	free(str);
	return (str_trimmed);
}
