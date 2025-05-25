/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:34:01 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/25 14:22:03 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

#include <string.h>
#include <stdio.h>

int ok_test(void);
int ko_test(void);
int sigsegv_test(void);
int sigbus_test(void);
int framework_test_launcher(void);

#endif