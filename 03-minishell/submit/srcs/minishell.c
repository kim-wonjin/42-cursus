/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-wonjin <kim-wonjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:12:55 by sshin             #+#    #+#             */
/*   Updated: 2022/06/28 16:56:06 by kim-wonjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit_status = 0;

int	first_error_handler(char *line)
{
	if (line[0] == '|' || line[0] == ';')
	{
		if (line[1] == line[0])
			printf("minishell: syntax error near unexpected token `%c%c'\n", \
			 line[0], line[0]);
		else
			printf("minishell: syntax error near unexpected token `%c'\n", \
			 line[0]);
		return (1);
	}
	return (0);
}

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
		if (*line != '\0' && !check_whitespace(line) && \
		!first_error_handler(line))
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
