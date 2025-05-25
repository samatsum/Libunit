/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:17:16 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/24 15:50:37 by samatsum         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_unit_test
{
	char				*name;
	char				*function_name;  // 追加
	int					(*function)(void);
	struct s_unit_test	*next;
}	t_unit_test;

/* テスト管理関数 */
int		load_test(t_unit_test **testlist, char *function_name, char *name, int (*test_func)(void));
int		launch_tests(t_unit_test **testlist);

/* テスト実行関数 */
int		execute_test(t_unit_test *test);

/* ユーティリティ関数 */
void	free_test_list(t_unit_test **testlist);


#endif