#include <stdio.h>
#include <stdlib.h>

struct op {
	double n1;
	double n2;
	char op;
};

enum act {ACT_ERR, ACT_ADD=1, ACT_SUB, ACT_MUL, ACT_DIV, ACT_EXIT};

void banner(void) __attribute__((nothrow, cold));
enum act getact(void) __attribute__((nothrow));
struct op *getop(enum act act) __attribute__((nothrow, malloc(free, 1)));
void result(struct op *op) __attribute__((nothrow, nonnull));
void zerodiv(struct op *op) __attribute__((nothrow, nonnull));
int again(void) __attribute__((nothrow));
void exit_program(void) __attribute__((nothrow, noreturn));
void clearscr(void) __attribute__((nothrow));

int main(void)
{
	struct op *op;
	enum act act;

	banner();
	while ((act = getact()) != ACT_EXIT) {
		if (act == ACT_ERR) {
			fputs(	"Essa opção é invalida, insira uma nova opção\n",
				stdout);
			continue;
		}

		if (!(op = getop(act)))
			exit(EXIT_FAILURE);

		if (op->op == '/' && !op->n2) {
			fputs(	"Erro: Divisão por zero não é permitida.\n",
				stdout);
			if (again()) {
				free(op);
				continue;
			} else {
				free(op);
				exit_program();
			}
		}

		result(op);
		free(op);

		if (!again())
			exit_program();
	}

	exit_program();
}

void banner(void)
{
	fputs("===============================\n", stdout);
	fputs("   Calculadora Simples\n", stdout);
	fputs("===============================\n", stdout);
}

enum act getact(void)
{
	enum act act;
	fputs("Selecione uma operação:\n", stdout);
	fputs("1. Adição\n", stdout);
	fputs("2. Subtração\n", stdout);
	fputs("3. Multiplicação\n", stdout);
	fputs("4. Divisão\n", stdout);
	fputs("5. Sair\n", stdout);
	fputs("Opção: ", stdout);
	if (scanf("%d", (int *)&act) != 1 || act < 1 || act > 5)
		return ACT_ERR;
	return act;
}

struct op *getop(enum act act)
{
	struct op *op;
	if (!(op = malloc(sizeof(op))))
		return NULL;

	fputs("Digite o primeiro número: ", stdout);
	if (scanf("%lf", &op->n1) != 1) {
		free(op);
		return NULL;
	}
	getchar();

	fputs("Digite o segundo número: ", stdout);
	if (scanf("%lf", &op->n2) != 1) {
		free(op);
		return NULL;
	}
	getchar();

	switch (act) {
	case ACT_ADD:
		op->op = '+';
		break;
	case ACT_SUB:
		op->op = '-';
		break;
	case ACT_MUL:
		op->op = '*';
		break;
	case ACT_DIV:
		op->op = '/';
		break;
	}

	return op;
}

void result(struct op *op)
{
	double ret;

	switch (op->op) {
	case '+':
		ret = op->n1 + op->n2;
		break;
	case '-':
		ret = op->n1 - op->n2;
		break;
	case '*':
		ret = op->n1 * op->n2;
		break;
	case '/':
		ret = op->n1 / op->n2;
		break;
	}

	printf("Resultado: %.4lf %c %.4lf = %.4lf\n", op->n1, op->op, op->n2, ret);
}

int again(void)
{
	char ret;
	while (1) {
		fputs("Desjea realizar outra operação (s/n)?: ", stdout);
		scanf("%c", &ret);
		if (ret != 's' && ret != 'S' && ret != 'n' && ret != 'N') {
			fputs(	"Resposta inválida. Por favor, digite 's' para"
				" sim ou 'n' para não.\n", stdout);
		} else {
			clearscr();
			return ret == 's' || ret == 'S';
		}
	}
}

void exit_program(void)
{
	fputs("Obrigado por usar a calculadora! Até a próxima.\n", stdout);
	exit(EXIT_SUCCESS);
}

void clearscr(void)
{
#if defined(__WIN32__) || defined(__WIN64__)
	int i;
	for (i = 0; i < 100; ++i)
		putchar('\n'); /* N tem suporte p nada, vai essa bomba msm */
#else /* Assumindo que suporta ANSI pq só a microsoft tem preguiça de suportar */
	fputs("\e[2J\e[H", stdout);
	fflush(stdout);
#endif
}
