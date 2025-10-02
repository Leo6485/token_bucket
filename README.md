## Integrantes
Leonardo Guimarães de Oliveira

## Compilar
```bash
    make
```

## Execução
```bash
    ./x
```

## Respostas

### 1
Uma estrutura para o bucket foi alocada dinamicamente com malloc, é liberada manualmente no final do programa, se as variáveis usadas para armazenar o númerod e tokens disponíveis e o timestamp do último update fossem armazenadas de forma errada, os valores poderiam ser reinicializados a cada requisição, tendo um comportamento monótono.

### 2
Se a biblioteca for usada via cabeçalho ou com ligação estática (.a), o comportamento é congelado no binário do cliente.
Com ligação dinâmica (.so), o comportamento pode ser alterado sem recompilar, permitindo corrigir bugs, etc.

Para configurar o limitador em tempo de execução, a ligação dinâmica deve ser usada.