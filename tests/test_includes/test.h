/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:34:01 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/25 16:36:50 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <string.h>
# include <stdio.h>

# define OK 0
# define KO -1

int ok_test(void);
int ko_test(void);
int sigsegv_test(void);
int sigbus_test(void);
int framework_test_launcher(void);

#endif