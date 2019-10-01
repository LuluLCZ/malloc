/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:19:44 by llacaze           #+#    #+#             */
/*   Updated: 2019/10/01 15:07:24 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# include <sys/mman.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"

# define TYPE_TINY 0
# define TYPE_SMALL 1
# define TYPE_LARGE 2

# define TINY 4096
# define SMALL 4096+4096+4096+4096+4096+4096

# define HOUSE_SIZE sizeof(struct s_house)
# define FIELD_SIZE sizeof(struct s_field)

typedef struct		s_house
{
	size_t			size;
	bool			free;
	struct s_house	*next;
}					t_house;

typedef struct		s_field
{
	int				type;
	size_t			remain_size;
	t_house			*base;
	struct s_field	*next;
}					t_field;


/*
Functions to implement
*/

void				*ft_malloc(size_t size);
void				ft_free(void *ptr);
void				*ft_realloc(void *ptr, size_t size);


/*
create_new_field.c
*/

size_t				get_proper_size(size_t size, int *type, size_t *space_left);
t_field				*create_new_field(size_t size);


/*
get_set_base_last.c
*/

void				*get_first_in_list();
void				set_field_base(void *new_base);
t_field				*get_last_field();
void				link_fields();
t_house				*get_last_house(t_field *field);

/*
search_available_house.c
*/

t_house				*create_new_house(t_field *field, t_house *last_house, size_t size);
t_house				*find_type_and_place_in_field(t_field *field, size_t size, int type);


#endif