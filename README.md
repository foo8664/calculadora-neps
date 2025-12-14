# Calculadora de CLI
Realiza operações aritimeticas simples entre dois operandos, projeto feito para
curso da Neps Academy

# Como usar
execute o programa no terminal `./main`, e siga as instruções providenciadas
pelo programa:
```bash
$ ./main
===============================
   Calculadora Simples
===============================
Selecione uma operação:
1. Adição
2. Subtração
3. Multiplicação
4. Divisão
5. Sair
Opção: Digite o primeiro número: Digite o segundo número: Resultado: 2.0000 + 2.0000 = 4.0000
Desjea realizar outra operação (s/n)?: n
```

# Instalação e pré-requisitos
No momento da instalação, é necessario ter instalado:
* `Make` (o programa é testado apenas com o GNU make)
* Um compilador de C, o Make ira usar `cc`, o padrão do seu sistema
* Recomenda-se que instale o codigo com o `git`, mas ele também pode ser baixado pelo github

### Clone o repositorio
```bash
$ git clone git@github.com:foo8664/calculadora-neps.git
(...)
$ git clone https://github.com/foo8664/calculadora-neps.git # Também é possivel
```

### Compile o codigo
```bash
$ cd calculadora-neps
$ make
(...)
```

# Estrutura do projeto
```bash

.
├── Makefile    # Receita para o make
├── README.md   # Arquivo que você esta lendo
└── main.c      # codigo do programa
```
