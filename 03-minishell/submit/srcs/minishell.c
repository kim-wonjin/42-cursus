/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:12:55 by sshin             #+#    #+#             */
/*   Updated: 2022/02/14 10:25:22 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit_status = 0;

int	main(int argc, char *argv[], char *envp[])
{
	char	*line;
	t_cmd	*cmd_list;
	char	**cpenv;

	(void)argc;
	dup2(STDIN, 100);
	dup2(STDOUT, 101);
	cpenv = copy_envp(envp);
	set_signal();
	line = readline("minishell $ ");
	while (line)
	{
		if (*line != '\0' && !check_whitespace(line))
		{
			add_history(line);
			parse(&cmd_list, line, cpenv);
			g_exit_status = exec(cmd_list, argv, &cpenv);
			free_list(cmd_list);
		}
		free(line);
		line = NULL;
		line = readline("minishell $ ");
	}
	return (0);
}
