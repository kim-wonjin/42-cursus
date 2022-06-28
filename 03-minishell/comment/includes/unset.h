/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:47:31 by sshin             #+#    #+#             */
/*   Updated: 2022/02/10 21:07:54 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNSET_H
# define UNSET_H

# include "structs.h"
# include "../libft/libft.h"

int	ft_valid_key(char *key);
int ft_unset(t_cmd *cmd_list, char **envp);

#endif
