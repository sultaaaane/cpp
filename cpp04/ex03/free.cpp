/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:47:55 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/15 14:48:01 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.hpp"

t_data	*init_data(void *content)
{
	t_data	*new_data;

	if (!content)
		return (NULL);
	new_data = (t_data *)malloc(sizeof(t_data));
	if (!new_data)
		return (NULL);
	new_data->ptr = content;
	new_data->next = NULL;
	return (new_data);
}

t_data	*ft_lstlast_data(t_data *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next == NULL)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_free(t_data **lst, t_data *new_data)
{
	t_data	*tmp;

	if (lst != NULL && new_data != NULL)
	{
		if (*lst == NULL)
		{
			*lst = new_data;
			new_data->next = NULL;
		}
		else
		{
			tmp = ft_lstlast_data(*lst);
			ft_lstlast_data(*lst)->next = new_data;
		}
	}
}

void	ft_lstclear_free(t_data **lst)
{
	t_data	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->ptr);
		free(tmp);
	}
	*lst = NULL;
}

t_data *global_data()
{
	static t_data data;
	return (&data);
}