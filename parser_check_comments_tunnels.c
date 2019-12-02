/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_comments_tunnels.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:43:42 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/27 18:33:07 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_is_comment(char **str)
{
	if ((*str)[0] && (*str)[0] == '#')
	{
		if ((*str)[1] && (*str)[1] == '#')
			return (0);
		else
		{
			ft_strdel(str);
			return (1);
		}
	}
	return (0);
}

int				ft_is_tunnel_type(char **str)
{
	char	**split;
	int		i;

	if (ft_strsplit_get_nb_words(*str, '-') != 2 ||
			ft_check_char_occurences(*str, '-') != 1)
		return (0);
	else
	{
		split = ft_strsplit(*str, '-');
		i = -1;
		while (split[0][++i])
			if (!ft_isprint(split[0][i]))
				return (0);
		i = -1;
		while (split[1][++i])
			if (!ft_isprint(split[1][i]))
				return (0);
		ft_free_split(1, split);
	}
	return (1);
}
