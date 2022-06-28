/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:47:10 by sshin             #+#    #+#             */
/*   Updated: 2022/02/10 21:05:23 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETENV_H
# define FT_GETENV_H

# include "../libft/libft.h"

char	*get_env_value(char *key, char **envp);

#endif
