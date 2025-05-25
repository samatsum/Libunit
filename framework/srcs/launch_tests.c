/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <zunandkun@gmail.com      >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:00:35 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/25 14:00:35 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42.jp   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:17:16 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/24 12:29:57 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit.h"

static void	print_summary(int success, int total)
{
	ft_putnbr(success);
	ft_putstr("/");
	ft_putnbr(total);
	ft_putstr(" tests checked\n");
}

int	launch_tests(t_unit_test **testlist)
{
	t_unit_test	*current;
	int			total;
	int			success;
	int			result;

	total = 0;
	success = 0;
	current = *testlist;
	while (current)
	{
		result = execute_test(current);
		if (result == OK)
			success++;
		total++;
		current = current->next;
	}
	print_summary(success, total);
	free_test_list(testlist);
	if (success == total)
		return (OK);
	return (KO);
}
