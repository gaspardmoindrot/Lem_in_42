#include "lem-in.h"

/*static int	ft_connect_start(t_list **list)
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
		ft_connect_start(list);
	if (!(result = (t_list ***)malloc(sizeof(t_list **) * size)))
		exit(EXIT_SUCCESS);
	while (i++ < size)
		if (!(result[i] = (t_list **)malloc(sizeof(t_list *) * (i + 1))))
			exit(EXIT_SUCCESS);
}*/

void		ft_put_bibli(t_params **params, t_list **list, t_list ***result, int i)
{
	(void)params;
	(void)list;
	(void)result;
	i = 1;
	/*t_list	*tmp;
	t_list	*adj;
	t_node	*node;
	int	j;

	j = 0;
	node = ft_find_t_node_with_start(list);
	tmp = node->next;
	while (tmp && j++ <= i)
	{
		result[i][j] = (t_list *)malloc(sizeof(t_list));
		result[i][j] = ft_lstnew_revisited(node, sizeof(t_node));
		//adj = ft_lstnew_revisited(node, sizeof(t_node));
		//ft_lstadd(&(node->next), adj);
		while (tmp && tmp->content)
		{
			if (tmp->arcw == 1)
			{
				node = (t_node *)tmp->content;
				while (node != ft_find_t_node_with_end(list))
				{
					..

					tmp = tmp->next;
					node = (t_node *)tmp->content;
				}
				break;
			}
			tmp = tmp->next;
		}
	}*/
}
