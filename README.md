# Conversão Romanos
Resolver o problema de conversão de números romanos em números arábicos.
Desenvolver em C++, dividindo o problema em módulos e testando o funcionamento da biblioteca.
Explorar os fundamentos do desenvolvimento orientado a testes com o auxílio da ferramenta **googletest**.

## Compilação
- Comando `make` compila os arquivos, gerando o executável **test.out**.
- Comando `make verify` realiza testes de memória (CPPCHECK e VALGRIND).
- Comando `make clean` remove todos os arquivos gerados pela compilação.

## Documentação dos testes
- **TEST (RomantoArabic, ConvertBasicRoman)**:
Verifica se a função *roman_to_arabic* converte as unidades básicas dos números romanos 
[I, V, X, L, C, D, M].
- **TEST (RomantoArabic, ConvertRoman)**:
Verifica se a função *roman_to_arabic* converte números romanos mais complexos, mostrando que essa função funciona corretamente para números romanos válidos.
- **TEST (ArabictoRoman, ConvertArabic)**:
Verifica se a função *arabic_to_roman* converte números arábicos para romanos corretamente.
- **TEST (ValidateConvertArabic, CorrectCases)**:
Verifica se a função *validate_convert* valida e converte corretamente números romanos válidos.
- **TEST (ValidateConvertArabic, InvalidCases)**:
Verifica se a função *validate_convert* reconhece números romanos inválidos.
    - **"CCXCIVI"**: sequência inválida "**IVI**" detectada.
    - **"XXXX"**: sequência inválida de 4 algarismos iguais detectada.
    - **"MMMI"**: número romano acima de 3000 detectado.
    - **"LL"**: sequência inválida **(VV, LL, DD)** detectada.
    - **"XM"**: sequência entre dois números sem relação detectada.
    - **"xiv"**: caracteres com letras minúsculas detectados.
    - **"IIIIIIIIIIIIIIIIIIIIIIIIIIIIIII"**: número de algarismos romanos maior que 30 detectado.
    - **"ANA"**: caracteres fora do padrão romano detectados.
