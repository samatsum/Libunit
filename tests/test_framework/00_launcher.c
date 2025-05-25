/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:21:56 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/25 16:35:04 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test_includes/test.h"
#include "../../framework/includes/libunit.h"

int	framework_test_launcher(void)
{
	t_unit_test	*testlist;
	char		*test_function_name;

	testlist = NULL;
	test_function_name = "[FRAMEWORK]";
	load_test(&testlist, test_function_name, "[OK test]", &ok_test);
	load_test(&testlist, test_function_name, "[KO test]", &ko_test);
	load_test(&testlist, test_function_name, "[SIGSEGV test]", &sigsegv_test);
	load_test(&testlist, test_function_name, "[SIGBUS test]", &sigbus_test);
	return (launch_tests(&testlist));
}
