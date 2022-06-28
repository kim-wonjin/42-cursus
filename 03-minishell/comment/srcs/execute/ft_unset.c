/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:41:33 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 19:49:29 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/unset.h"

int	ft_find_envkey(char *key, char **envp)
{
	int		i;
	size_t	key_len;

	i = 0;
	key_len = ft_strlen(key);
	while (envp[i])
	{
		if (ft_strncmp(key, envp[i], key_len) == 0 &&
				(envp[i][key_len] == '=' || envp[i][key_len] == 0))
			return (i);
		i++;
	}
	return (-1);
}

void	ft_delete_env(int tgt_idx, char **envp)
{
	free(envp[tgt_idx]);
	while (envp[tgt_idx])
	{
		envp[tgt_idx] = envp[tgt_idx + 1];
		tgt_idx++;
	}
}

int	ft_valid_key(char *key)
{
	int	i;

	i = 0;
	if (ft_strlen(key) == 0)
		return (0);
	while (key[i])
	{
		if (ft_isdigit(key[0]))
			return (0);
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	ft_unset(t_cmd *cmd_list, char **envp)
{
	int	i;
	int	tgt_idx;

	i = 1;
	while (cmd_list->cmdline[i].cmd && cmd_list->cmdline[i].redir_flag == 0)
	{
		// 키 첫글자가 숫자인 경우 제외 /  (영문이 아니고 _ 도 아닌경우 제외)
		if (ft_valid_key(cmd_list->cmdline[i].cmd))
		{
			// 키값이 같은 환경변수 찾기 , null 이 아니고 마지막이 = 이거나 0 일 경우 key 단어를 가지고 있는 환경변수를 제외하기 위해
			tgt_idx = ft_find_envkey(cmd_list->cmdline[i].cmd, envp);
			// 등록되어있는 변수가 있는 경우
			if (tgt_idx > -1)
				ft_delete_env(tgt_idx, envp);
		}
		else
			cmd_list->err_manage.errcode = 6;
		i++;
	}
	if (cmd_list->err_manage.errcode == 6)
		return (-1);
	return (1);
}
