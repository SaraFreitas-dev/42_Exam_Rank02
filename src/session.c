#include "practiceshell.h"
#include <stdio.h>
#include <string.h>

static void	print_help(void)
{
	printf("Commands:\n");
	printf("  " CYAN "grademe" RESET "  grade your solution\n");
	printf("  " CYAN "subject" RESET "  show the subject again\n");
	printf("  " CYAN "status" RESET "   show exercise and time left\n");
	printf("  " CYAN "quit" RESET "     leave this exercise\n");
}

static void	print_status(const t_exercise *ex, time_t exam_start)
{
	long	left;

	printf("Exercise: " BOLD "%s" RESET " (level %d)\n", ex->name, ex->level);
	if (exam_start)
	{
		left = EXAM_DURATION - (long)(time(NULL) - exam_start);
		printf("Time left: %ldh %02ldm\n", left / 3600, (left % 3600) / 60);
	}
}

/* Main loop for one exercise. Returns 1 if passed, 0 otherwise. */
static int	exercise_loop(const t_exercise *ex, time_t exam_start)
{
	char	buf[BUF_SIZE];

	while (read_line(CYAN "\npracticeshell> " RESET, buf))
	{
		if (exam_start && time(NULL) - exam_start > EXAM_DURATION)
			return (printf(RED "Time is over!" RESET "\n"), 0);
		if (!strcmp(buf, "grademe"))
		{
			if (grade(ex))
				return (printf(GREEN BOLD "[OK] All tests passed!" RESET "\n"),
					1);
		}
		else if (!strcmp(buf, "subject"))
			print_subject(ex);
		else if (!strcmp(buf, "status"))
			print_status(ex, exam_start);
		else if (!strcmp(buf, "quit"))
			return (0);
		else if (buf[0])
			print_help();
	}
	return (0);
}

/*
** Shows the subject, runs the loop, then removes the subject.
** exam_start == 0 means practice mode (no timer).
*/
int	run_exercise(const t_exercise *ex, time_t exam_start)
{
	int	result;

	install_subject(ex);
	print_subject(ex);
	prepare_workspace(ex);
	print_help();
	result = exercise_loop(ex, exam_start);
	remove_subject(ex);
	return (result);
}
