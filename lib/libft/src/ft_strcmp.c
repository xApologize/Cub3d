/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:14:31 by jrossign          #+#    #+#             */
/*   Updated: 2022/12/21 14:14:34 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (ft_strlen(s1) - ft_strlen(s2) != 0)
		return (-1);
	return (ft_strncmp(s1, s2, ft_strlen(s1)));
}
