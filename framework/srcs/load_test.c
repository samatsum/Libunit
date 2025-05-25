/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42.jp   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:17:16 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/24 15:17:18 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit.h"

int	load_test(t_unit_test **testlist, char *function_name, char *name, int (*test_func)(void))
{
	t_unit_test	*new;
	t_unit_test	*temp;

	new = (t_unit_test *)malloc(sizeof(t_unit_test));
	if (!new)
		return (-1);
	new->name = name;
	new->function_name = function_name;  // 追加
	new->function = test_func;
	new->next = NULL;
	if (*testlist == NULL)
	{
		*testlist = new;
		return (0);
	}
	temp = *testlist;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return (0);
}