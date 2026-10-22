#include "practiceshell.h"
#include <stdio.h>
#include <stdlib.h>

/* Picks a random exercise of the given level, or NULL if there is none. */
static const t_exercise	*pick_random(int level)
{
	int	count;
	int	choice;
	int	i;

	count = 0;
	for (i = 0; i < g_nb_exercises; i++)
		if (g_exercises[i].level == level)
			count++;
	if (count == 0)
		return (NULL);
	choice = rand() % count;
	for (i = 0; i < g_nb_exercises; i++)
		if (g_exercises[i].level == level && choice-- == 0)
			return (&g_exercises[i]);
	return (NULL);
}

void	exam_mode(void)
{
	const t_exercise	*ex;
	time_t				start;
	int					level;
	int					passed;
	int					total;

	start = time(NULL);
	passed = 0;
	total = 0;
	printf(YELLOW BOLD "\nExam started! You have 3 hours." RESET "\n");
	for (level = 1; level <= g_max_level; level++)
	{
		ex = pick_random(level);
		if (!ex)
			continue ;
		total++;
		printf(CYAN BOLD "\n=== Level %d / %d ===" RESET "\n", level,
			g_max_level);
		if (!run_exercise(ex, start))
			break ;
		passed++;
	}
	printf(BOLD "\nResult: %d exercise(s) passed" RESET "\n", passed);
	if (passed == total)
		printf(GREEN BOLD "🏆 Exam passed!" RESET "\n");
}
