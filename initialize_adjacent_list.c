/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_adjacent_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 10:17:14 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/16 18:33:17 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			ft_initialize_adjacent_list(t_list **list)
{
	*list = ft_lstnew(NULL, 0);
	if (!list)
		return (-1);
	return (1);
}
