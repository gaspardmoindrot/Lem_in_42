#include "lem-in.h"

void	ft_put_arcw(t_node *end, t_list **list)
{
	t_list	*tmp;
	t_node	*node;
	t_node	*start;

	tmp = end->father;
	end->passed_flag = 2;
	while (tmp)
	{
		node = (t_node *)tmp->content;
		node->passed_flag = 2;
		tmp = node->father;
	}
	start = ft_find_t_node_with_start(list);
	tmp = start->next;
	start->passed_flag = 3;
	while (tmp)
	{
		node = (t_node *)tmp->content;
		if (node->passed_flag == 2 && tmp->arcw <= 0)
		{
			node->passed_flag = 3;
			if (tmp->arcw == -1)
				tmp->arcw = 0;
			else
				tmp->arcw = 1;
			tmp = node->next;
		}
		else
			tmp = tmp->next;
	}
	tmp = end->next;
	end->passed_flag = 0;
	while (tmp)
	{
		node = (t_node *)tmp->content;
                if (node->passed_flag == 3 && tmp->arcw >= 0)
                {
                        node->passed_flag = 0;
                        if (tmp->arcw == 1)
                                tmp->arcw = 0;
                        else
                                tmp->arcw = -1;
                        tmp = node->next;
                }
                else
                        tmp = tmp->next;
	}
}

void	fonction_test(t_list **list)
{
	t_list *tmp;
	t_list *tmp_2;
	t_node *node;

	tmp = *list;
	ft_putchar('\n');
	while (tmp && tmp->content && ((t_node *) tmp->content)->name)
	{
		node = (t_node *) tmp->content;
		tmp_2 = node->next;
		ft_printf("%s ||", node->name);
		while (tmp_2)
		{
			node = (t_node *) tmp_2->content;
			ft_printf("-> %s:%d ", node->name, tmp_2->arcw);
			tmp_2 = tmp_2 -> next;
		}
		ft_printf("\n");
		tmp = tmp->next;
	}
}

void	ft_algo(t_params **params, t_list **list, t_list ***result)
{
	t_node	*node;
	int	index;

	(void)result;
	index = 0;
	node = ft_find_t_node_with_start(list);
	//ft_malloc_result(params, list, result);
	while (index < (*params)->ant_count && ft_bfs_gaspard(list, params, node) > 0)
	{
		ft_reset_passed_flags(list);
		//fonction_test(list);
		ft_put_bibli(list, result, index);
		index++;
	}
}
