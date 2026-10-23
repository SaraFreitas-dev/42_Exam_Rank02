#ifndef PRACTICESHELL_H
# define PRACTICESHELL_H

# include "exercises.h"
# include <time.h>

# define RESET   "\033[0m"
# define BOLD    "\033[1m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define CYAN    "\033[36m"
# define GREY    "\033[90m"

# define EXAM_DURATION 10800 /* 3 hours, in seconds */
# define TIMEOUT       2     /* seconds allowed per test run */
# define BUF_SIZE      1024

/* utils.c */
char	*read_line(const char *prompt, char *buf);
void	print_file(const char *path);
void	ensure_dir(const char *path);
void	install_subject(const t_exercise *ex);
void	remove_subject(const t_exercise *ex);
void	print_subject(const t_exercise *ex);
void	prepare_workspace(const t_exercise *ex);

/* grader.c */
int		grade(const t_exercise *ex);

/* session.c */
/* run_exercise() results */
# define EX_PASSED  1
# define EX_BACK    0  /* left the exercise (back) or time over */
# define EX_QUIT    -1 /* user wants to exit the program */

int		run_exercise(const t_exercise *ex, time_t exam_start);
int		is_back(const char *cmd);
int		is_quit(const char *cmd);

/* exam.c / practice.c */
/* What the menu should do after a mode ends */
typedef enum e_action
{
	ACT_PAUSE,  /* show "Press Enter to return to menu" */
	ACT_MENU,   /* go straight back to the menu */
	ACT_QUIT    /* exit the program */
}	t_action;

t_action	exam_mode(void);
t_action	practice_mode(void);
void		list_exercises(void);

#endif
