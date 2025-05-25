/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <zunandkun@gmail.com      >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:00:35 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/25 14:00:35 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:17:16 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/24 15:32:34 by samatsum         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/libunit.h"

static void	report_result(char *func_name, char *test_name, int status)
{
	printf("%s:%s:", func_name, test_name);	
	if (status == 0)
		printf("[OK]\n");
	else if (status == 255)
		printf("[KO]\n");
	else if (status == SIGSEGV)
		printf("[SEGV]\n");
	else if (status == SIGBUS)
		printf("[BUS]\n");
}

int	execute_test(t_unit_test *test)
{
	pid_t	pid;
	int		status;
	int		result;

	pid = fork();
	if (pid < 0)
		return (-1);
	else if (pid == 0)
	{
		result = test->function();
		exit(result);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			result = WEXITSTATUS(status);
			report_result(test->function_name, test->name, result);
			return (result);
		}
		else if (WIFSIGNALED(status))
		{
			report_result(test->function_name, test->name, WTERMSIG(status));
			return (-1);
		}
	}
	return (-1);
}