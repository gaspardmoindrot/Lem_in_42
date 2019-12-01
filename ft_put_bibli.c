#include "lem_in.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*list;

	if (new && alst && *alst)
	{
		list = *alst;
		while (list->next)
			list = list->next;
		list->next = new;
	}
}

void		ft_put_bibli(t_list **list, t_list **result, int i)
{
	t_list	*tmp;
	t_list	*tmp_2;
	t_list	*new;
	t_node	*node;
	t_node	*node_2;
	t_node	*end;
	int	j;

	end = ft_find_t_node_with_end(list);
	j = 0;
	node = ft_find_t_node_with_start(list);
	tmp = node->next;
	while (tmp && i >= j && node)
	{
		node = (t_node *) tmp->content;
		if (tmp->arcw == 1 && i >= j)
		{
			result[j] = (t_list *)malloc(sizeof(t_list));
			result[j]->content = ft_find_t_node_with_start(list);
			result[j]->content_size = sizeof(t_node);
			result[j]->next = NULL;
			new = ft_lstnew_revisited(node, sizeof(t_node));
			ft_lstadd_back(&result[j], new);
			tmp_2 = node->next;
			node_2 = (t_node *) tmp_2->content;
			while(node_2 != end && tmp_2)
			{
				node_2 = (t_node *) tmp_2->content;
				if (tmp_2->arcw == 1)
				{
					new = ft_lstnew_revisited(node_2, sizeof(t_node));
					ft_lstadd_back(&result[j], new);
					tmp_2 = node_2->next;
				}
				else
					tmp_2 = tmp_2->next;
			}
			j++;
		}
		tmp = tmp->next;
	}
}
