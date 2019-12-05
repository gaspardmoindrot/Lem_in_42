/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:24:36 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/25 21:32:12 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_char_occurences(char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int		ft_strsplit_get_nb_words(char const *s, char c)
{
	int i;
	int nbr;

	i = 0;
	nbr = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] < 32 || s[i] > 126)
			return (0);
		else
		{
			nbr++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (nbr);
}

int		ft_free_split_special(int nbr, char **res)
{
	while (nbr >= 0)
	{
		if (res[nbr] != NULL)
			free(res[nbr]);
		nbr--;
	}
	free(res);
	return (1);
}
