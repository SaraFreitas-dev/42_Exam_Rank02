#ifndef EXERCISES_H
# define EXERCISES_H

# define SOLUTIONS_DIR "solutions"
# define TESTS_DIR     "src/tests"
# define MAX_LEVELS    9
# define NAME_SIZE     256

/*
** Exercises are found automatically at startup:
**   solutions/Level_X/<name>/subject.txt   -> the exercise exists
**   src/tests/Level_X/<name>/main.c        -> FUNCTION (compiled with user file)
**   src/tests/Level_X/<name>/args.txt      -> PROGRAM (one test per line,
**                                             args separated by '|')
**   src/tests/Level_X/<name>/expected.txt  -> the exact expected output
** Solutions in solutions/ are for study only: the grader never uses them.
** To add an exercise, just create these folders. No code to change.
*/
typedef enum e_type
{
	PROGRAM,
	FUNCTION
}	t_type;

typedef struct s_exercise
{
	char	name[NAME_SIZE];
	int		level;
	t_type	type;
}	t_exercise;

extern t_exercise	*g_exercises;
extern int			g_nb_exercises;
extern int			g_max_level;

int		load_exercises(void);
void	free_exercises(void);

#endif
