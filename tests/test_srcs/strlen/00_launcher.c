/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:21:56 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/25 13:57:19 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test_includes/test.h"
#include "../../../framework/includes/libunit.h"

int	strlen_launcher(void)
{
	char		*test_func_name;
	t_unit_test	*testlist;

	testlist = NULL;
	test_func_name = "STRLEN";
	load_test(&testlist, test_func_name, "Basic test", &basic_test);
	load_test(&testlist, test_func_name, "NULL test", &null_test);
	load_test(&testlist, test_func_name, "Segmentation fault test", &segfault_test);
	load_test(&testlist, test_func_name, "Bus error test", &bus_error_test);
	return (launch_tests(&testlist));
}