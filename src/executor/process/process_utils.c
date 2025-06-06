/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:51:59 by gzovkic           #+#    #+#             */
/*   Updated: 2025/05/02 17:52:00 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reset_redirection(int saved_stdin, int saved_stdout)
{
	dup2(saved_stdin, STDIN_FILENO);
	dup2(saved_stdout, STDOUT_FILENO);
}

void	save_stdin_stdout(int *saved_stdin, int *saved_stdout)
{
	*saved_stdin = dup(STDIN_FILENO);
	*saved_stdout = dup(STDOUT_FILENO);
}

void	pipe_creation(int *fd)
{
	if (pipe(fd) == -1)
	{
		ft_putstr_fd("Error: invalid file", 2);
		return ;
	}
}

int	error_check_null(char *str)
{
	if (str == NULL)
		return (-1);
	return (0);
}

void	print_error_message(char *cmd, char *message)
{
	ft_putstr_fd("brother: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(" : ", 2);
	ft_putstr_fd(message, 2);
}
