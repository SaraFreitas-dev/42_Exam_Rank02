#include "practiceshell.h"
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define TMP      ".tmp"
#define BIN      ".tmp/bin"
#define OUT      ".tmp/out"
#define LOG      ".tmp/compile.log"
#define MAX_ARGS 64

/*
** Every exercise has a fixed expected output:
**   src/tests/Level_X/<name>/expected.txt
** The user's output must be exactly the same.
**
** FUNCTION: output of main.c (compiled with the user's file).
** PROGRAM : for each line of args.txt, a header "$ ./<name> args"
**           followed by the program's output.
*/

static int	compile(const char *src, const char *extra, const char *out)
{
	char	cmd[BUF_SIZE * 4];

	snprintf(cmd, sizeof(cmd), "cc -Wall -Wextra -Werror %s %s -o %s 2> %s",
		src, extra ? extra : "", out, LOG);
	return (system(cmd) == 0);
}

/* Runs bin with argv, appending its stdout to outfile. Returns signal or 0. */
static int	run(char **argv, const char *outfile)
{
	pid_t	pid;
	int		status;
	int		fd;

	fflush(stdout);
	pid = fork();
	if (pid == 0)
	{
		fd = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
		dup2(fd, STDOUT_FILENO);
		close(fd);
		alarm(TIMEOUT);
		execv(argv[0], argv);
		exit(127);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	return (0);
}

static void	append_text(const char *path, const char *text)
{
	FILE	*f;

	f = fopen(path, "a");
	if (!f)
		return ;
	fputs(text, f);
	fclose(f);
}

/* Runs every line of args.txt (args separated by '|'). */
static int	run_program(const t_exercise *ex, const char *args_path,
	const char *outfile)
{
	FILE	*f;
	char	line[BUF_SIZE];
	char	header[BUF_SIZE * 2];
	char	*argv[MAX_ARGS];
	char	*tok;
	int		n;
	int		sig;

	f = fopen(args_path, "r");
	if (!f)
		return (printf(RED "Missing %s" RESET "\n", args_path), -1);
	sig = 0;
	while (!sig && fgets(line, sizeof(line), f))
	{
		line[strcspn(line, "\n")] = '\0';
		snprintf(header, sizeof(header), "$ ./%s %s\n", ex->name, line);
		append_text(outfile, header);
		argv[0] = BIN;
		n = 1;
		tok = (line[0] != '\0') ? strtok(line, "|") : NULL;
		while (tok && n < MAX_ARGS - 1)
		{
			argv[n++] = tok;
			tok = strtok(NULL, "|");
		}
		argv[n] = NULL;
		sig = run(argv, outfile);
		append_text(outfile, "\n");
	}
	fclose(f);
	return (sig);
}

/*
** Compiles src for this exercise and writes all its output to outfile.
** Returns 0 if OK, -1 if compilation failed, or the signal that killed it.
*/
static int	produce_output(const t_exercise *ex, const char *src,
	const char *outfile)
{
	char	test_dir[BUF_SIZE];
	char	path[BUF_SIZE * 2];
	char	*argv[2];

	snprintf(test_dir, sizeof(test_dir), TESTS_DIR "/Level_%d/%s",
		ex->level, ex->name);
	ensure_dir(TMP);
	unlink(outfile);
	if (ex->type == FUNCTION)
	{
		snprintf(path, sizeof(path), "%s/main.c", test_dir);
		if (!compile(src, path, BIN))
			return (-1);
		argv[0] = BIN;
		argv[1] = NULL;
		return (run(argv, outfile));
	}
	if (!compile(src, NULL, BIN))
		return (-1);
	snprintf(path, sizeof(path), "%s/args.txt", test_dir);
	return (run_program(ex, path, outfile));
}

static int	files_equal(const char *a, const char *b)
{
	FILE	*fa;
	FILE	*fb;
	int		ca;
	int		cb;

	fa = fopen(a, "r");
	fb = fopen(b, "r");
	if (!fa || !fb)
	{
		if (fa)
			fclose(fa);
		if (fb)
			fclose(fb);
		return (0);
	}
	do
	{
		ca = fgetc(fa);
		cb = fgetc(fb);
	} while (ca == cb && ca != EOF);
	fclose(fa);
	fclose(fb);
	return (ca == cb);
}

static void	print_crash(int sig)
{
	if (sig == SIGALRM)
		printf(RED "[KO] Timeout (infinite loop?)" RESET "\n");
	else
		printf(RED "[KO] Crash: %s" RESET "\n", strsignal(sig));
}

int	grade(const t_exercise *ex)
{
	char	user_src[BUF_SIZE];
	char	expected[BUF_SIZE];
	int		res;

	snprintf(user_src, sizeof(user_src), "rendu/%s/%s.c", ex->name, ex->name);
	snprintf(expected, sizeof(expected), TESTS_DIR "/Level_%d/%s/expected.txt",
		ex->level, ex->name);
	if (access(user_src, F_OK) != 0)
		return (printf(RED "File not found: %s" RESET "\n", user_src), 0);
	if (access(expected, F_OK) != 0)
		return (printf(RED "Missing %s" RESET "\n",
				expected), 0);
	res = produce_output(ex, user_src, OUT);
	if (res == -1)
	{
		printf(RED "[KO] Compilation failed:" RESET "\n");
		print_file(LOG);
		return (0);
	}
	if (res > 0)
		return (print_crash(res), 0);
	if (files_equal(OUT, expected))
		return (1);
	printf(RED "[KO] Wrong output" RESET "\n");
	printf(GREEN "Expected:" RESET "\n");
	print_file(expected);
	printf(RED "Got:" RESET "\n");
	print_file(OUT);
	return (0);
}
