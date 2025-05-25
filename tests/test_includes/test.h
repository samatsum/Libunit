/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:34:01 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/24 15:51:38 by samatsum         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef TEST_H
# define TEST_H

#include <string.h>
#include <stdio.h>

int	strlen_launcher(void);
int	basic_test(void);
int	null_test(void);
int	segfault_test(void);
int	bus_error_test(void);

#endif