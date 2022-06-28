/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:41:14 by sshin             #+#    #+#             */
/*   Updated: 2022/06/28 11:30:31 by kim-wonjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_env(t_cmd *cmd_list, char **envp, int fd)
{
	int	i;

	i = 0;
	// env 뒤에 추가적인 문자가 있으면 에러 문구 발생 리다리렉트 는 가능    ex) env > t.txt
	if (cmd_list->cmdline[1].cmd != 0 && cmd_list->cmdline[i].redir_flag == 0)
	{
		// errcode 3 -> error_write("minishell: %s: No such file or directory\n",
		cmd_list->err_manage.errcode = 3;
		cmd_list->err_manage.errindex = 1;
		return (-1);
	}
	while (envp[i])
	{
		//haveequal 는 export_util.c에 있다. envp[i] 에 '=' 가 있는 것만 출력
		if (haveequal(envp[i]))
		{
			ft_putstr_fd(envp[i], fd);
			ft_putchar_fd('\n', fd);
		}
		i++;
	}
	return (1);
}

// envp의 구성
// 키=항목
// 맨 마지막 항목 뒤는 NULL
char	**copy_envp(char **envs)
{
	char	**new;
	int		i;

	i = 0;
	while (envs[i])
		i++;
	if (!(new = malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = -1;
	while (envs[++i])
		new[i] = ft_strdup(envs[i]);
	new[i] = NULL;
	return (new);
}
