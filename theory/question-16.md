# Команда вычисления эффективного адреса

Данная команда имеет следующий вид:

```asm
LEA <приёмник>, <источник>
```

Она вычисляет эффективный адрес `<источника>` и помещает его в `<приёмник>`.
Также эта команда позволяет вычислять сложные адреса, поэтому иногда она
используется для быстрых арифметических вычислений. Например:

```asm
LEA BX, [BX+BX*4]
```