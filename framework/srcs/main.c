/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:17:16 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/24 16:03:05 by samatsum         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/libunit.h"
#include "../../tests/test_includes/test.h"

int	main(void)
{
	int	result;

	result = 0;
	result |= strlen_launcher();
	return (result);
}
