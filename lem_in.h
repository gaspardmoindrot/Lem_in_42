/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 07:39:34 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/12/02 18:02:11 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define PRINT (1)
# define PRINT_LIST (0)

typedef struct s_params		t_params;

struct	s_params
{
	int		ant_count;
	int		rooms_started;
	int		rooms_count;
	int		rooms_ended;
	int		tunnels_started;
	int		tunnels_ended;
	int		next_is_start;
	int		next_is_end;
	int		has_start;
	int		has_end;
	int		fatal_error;
	int		error_line;
	int		non_fatal_error_line;
	char	*error_type;
	char	*non_fatal_error_type;
	char	*path_start_end;
	int		length_path_start_end;
	char	*map;
};

typedef struct s_node		t_node;

struct	s_node
{
	int		id;
	char	*name;
	long	name_hash;
	int		is_start;
	int		is_end;
	int		x_coord;
	int		y_coord;
	int		passed_flag;
	int		chance_one;
	t_list	*next;
	t_list	*father;
};

typedef struct s_fd_list	t_fd_list;

struct	s_fd_list
{
	char		*str;
	int			fd;
	t_fd_list	*next;
};

int		get_next_line(const int fd, char **line);
int		ft_add_tunnel(t_list **list, char **str, t_params **params);
int		ft_add_room(t_params **params, t_list **list, char **str);
void	ft_print_adjacent_list(t_list **nodes);
int		ft_browse_entry(t_list **nodes, t_params **params);
int		ft_is_comment(char **str);
int		ft_is_modifier(char *str);
void	ft_free_split(int nbr, char **res);
int		ft_get_split_size(char **str);
int		ft_is_room_type(char **str);
int		ft_is_tunnel_type(char **str);
int		ft_mod(t_params **params, t_list **list, char **str, int *i);
int		ft_initialize_adjacent_list(t_list **nodes);
void	ft_free_adjacent_list(t_list **list);
void	ft_free_params(t_params **params);
int		ft_strsplit_get_nb_words(char const *s, char c);
void	ft_free_split(int nbr, char **res);
void	ft_list_sort_asc_by_name(t_list **list);
void	ft_list_sort_adj(t_list **list);
int		ft_initialize_params(t_params **params);
void	ft_print_general_details(t_list **list, t_params **params);
int		ft_check_room_exists(t_list **list, long hash, t_params **params);
int		ft_check_tunnel_rooms_exist(t_list **list, long hash0, long hash1,
		t_params **params);
int		ft_check_coords_exist(t_list **list, int x, int y, t_params **params);
int		ft_check_char_occurences(char *str, char c);
void	ft_print_node(t_node *node);
t_node	*ft_find_t_node_with_id(t_list **list, int id);
t_node	*ft_find_t_node_with_name_hash(t_list **list, long hash);
t_node	*ft_find_t_node_with_start(t_list **list);
t_node	*ft_find_t_node_with_end(t_list **list);
void	ft_print_parsing_error_non_fatal(t_params **params);
void	ft_print_parsing_error_fatal(t_params **params);
int		ft_parse_fatal_errors_check(t_params **params, t_list **list);
int		ft_check_start_connected_to_end_dfs(t_params **params, t_node *start,
		t_node *fixed_start);
int		ft_check_start_connected_to_end_bfs(t_params **params, t_node *start);
t_list	*ft_lstnew_revisited(void *content, size_t content_size);
int		ft_is_neighbor_with_name_hash(t_node *node, long hash);
void	ft_reset_passed_flags(t_list **list);
long	ft_hash(char *str);
int		ft_check_ants(t_params **params);
void	ft_free_fathers(t_list **list);
void	ft_set_has_start_or_end(t_params **params, char *str);
int		ft_lin(t_params **params, int i, char **str);
int		ft_lsharp(t_params **params, char **str, int i);
void	ft_tunnel_add_success(t_params **params, char **str);
void	ft_init_queue(t_node **queue, int size);
int		ft_handle_other_error_cases(char **str, t_params **params, int *i);
int		ft_handle_double_start(t_params **params, int i);
int		ft_handle_double_end(t_params **params, int i);
int		ft_handle_end(t_node **queue, t_params **params, int i);
void	ft_print_father_list(t_node *end, t_params **params);
void	ft_add_return_line(t_params **params);
void	ft_print_map(t_params **params);

void		ft_algo(t_params **params, t_list **list);
void		ft_reset_passed_flags_gasp(t_list **list);
int		ft_bfs_gaspard(t_list **list, t_params **params, t_node *start);
void		ft_put_arcw(t_node *end, t_list **list);
void		ft_put_bibli(t_list **list, t_list ***result, int i);
t_list		***ft_malloc_result(t_params **params, t_list **list);
int		ft_connect_start(t_list **list);
void		ft_test_voisin(t_node *node);

#endif
