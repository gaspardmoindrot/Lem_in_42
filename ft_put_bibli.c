#include "lem-in.h"

static int	ft_connect_start(t_list **list)
{
	t_node	*start;
	t_list	*tmp;
	int	count;

	start = ft_find_t_node_with_start(list);
	tmp = start->next;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void		ft_malloc_result(t_params **params, t_list **list, t_list ***result)
{
	int     size;
	int     i;

	i = 0;
	if ((*params)->ant_count >= ft_connect_start(list))
		size = (*params)->ant_count;
	else
		size = ft_connect_start(list);
	if (!(result = (t_list ***)malloc(sizeof(t_list **) * size)))
		exit(EXIT_SUCCESS);
	while (i++ < size)
		if (!(result[i] = (t_list **)malloc(sizeof(t_list *) * (i + 1))))
			exit(EXIT_SUCCESS);
}

void		ft_put_bibli(t_list **list, t_list ***result, int i)
{
	t_list	*tmp;
	t_list	*tmp_2;
	t_node	*node;
	t_node	*node_2;
	int	j;

	(void)result; //pour pas avoir d'erreur avec le Makefile
	j = 0;
	node = ft_find_t_node_with_start(list);
	tmp = node->next;
	while (tmp && i >= j && node)
	{
		node = (t_node *) tmp->content;
		if (tmp->arcw == 1)
		{
			//ft_printf("%s", ft_find_t_node_with_start(list)->name); //printf
			//ft_printf(" -> %s ", node->name); //printf
			//result[i][j] = put_start_in_bibli;
			//result[i][j] = put_tmp_in_bibli_next;
			tmp_2 = node->next;
			node_2 = (t_node *) tmp_2->content;
			while(node_2 != ft_find_t_node_with_end(list) && tmp_2)
			{
				node_2 = (t_node *) tmp_2->content;
				if (tmp_2->arcw == 1)
				{
					ft_printf("-> %s ", node_2->name); //printf
					; //result[i][j] = put_tmp2_in_bibli_next;
					tmp_2 = node_2->next;
				}
				else
					tmp_2 = tmp_2->next;
			}
			j++;
			//ft_putchar('\n'); //printf
		}
		tmp = tmp->next;
	}
}
