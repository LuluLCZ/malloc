/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:19:44 by llacaze           #+#    #+#             */
/*   Updated: 2019/10/08 18:01:52 by llacaze          ###   ########.fr       */
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

# define TINY (2 * getpagesize())
# define SMALL (4 * getpagesize())

# define HOUSE_SIZE sizeof(struct s_house)
# define FIELD_SIZE sizeof(struct s_field)

# define multiple_4(x) ((((x-1)>>2)<<4)+4)

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
The free structure is usefull when i'm looking for the house and the field,
it contains the field and the house where the ptr to free is located
*/
typedef struct		s_free
{
	t_field			*field;
	t_house			*house;
}					t_free;


/*
Functions to implement
*/

void				*ft_malloc(size_t size);
void				ft_free(void *ptr);
void				*ft_realloc(void *ptr, size_t size);
void				*ft_calloc(size_t count, size_t size);


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

/*
free.c
*/
t_free				find_field_house_according_ptr(void *ptr, bool need_to_free);

/*
realloc.c
*/




#endif