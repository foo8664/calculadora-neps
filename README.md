# Calculadora de CLI
Realiza operações aritimeticas simples entre dois operandos, projeto feito para
curso da Neps Academy

# Demonstração
![Como usar](./assets/use.jpg)

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

# Como usar
execute o programa no terminal: `./main`, e siga as instruções providenciadas
pelo programa, por exemplo:
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
Opção: 3
Digite o primeiro número: 3
Digite o segundo número: 3
Resultado: 3.0000 * 3.0000 = 9.0000
Desjea realizar outra operação (s/n)?: n
*(clear)*
Obrigado por usar a calculadora! Até a próxima.
$
```

# Estrutura do projeto
```bash

.
├── Makefile    # Receita para o make
├── README.md   # Arquivo que você esta lendo
└── main.c      # codigo do programa
```

# Licensa
[MIT](LICENSE.md):

Copyright \<2025\> \<Diego Oliveira\>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
