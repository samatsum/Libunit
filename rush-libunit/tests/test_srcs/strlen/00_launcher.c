/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42.jp   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:21:56 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/24 15:15:23 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test_includes/test.h"
#include "../../../framework/includes/libunit.h"

int	strlen_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	printf("STRLEN:\n");
	load_test(&testlist, "Basic test", &basic_test);
	load_test(&testlist, "NULL test", &null_test);
	load_test(&testlist, "Segmentation fault test", &segfault_test);
	load_test(&testlist, "Bus error test", &bus_error_test);
	return (launch_tests(&testlist));
}