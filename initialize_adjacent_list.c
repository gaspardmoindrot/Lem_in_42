/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_adjacent_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 10:17:14 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/24 20:32:50 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_initialize_adjacent_list(t_list **list)
{
	*list = ft_lstnew(NULL, 0);
	if (!list)
		return (-1);
	return (1);
}
