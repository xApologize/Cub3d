/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pp_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:13:06 by jrossign          #+#    #+#             */
/*   Updated: 2022/12/21 17:14:57 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_pp_length(char **pp)
{
	int	i;

	i = 0;
	while (pp[i])
		i++;
	return (i);
}