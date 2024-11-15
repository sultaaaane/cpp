/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:40:05 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/15 14:48:39 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FREE_HPP
# define FREE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <limits>
# include <cctype>
# include <cstdlib>
# include <iomanip>
# include <fcntl.h>

typedef struct s_data
{
	void *ptr;
	struct s_data *next;
}				t_data;

t_data	*init_data(void *content);
t_data	*ft_lstlast_data(t_data *lst);
void	ft_lstadd_back_free(t_data **lst, t_data *new_data);
void	ft_lstclear_free(t_data **lst);
t_data *global_data();

#endif