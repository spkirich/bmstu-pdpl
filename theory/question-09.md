# Команда сравнения

Единственная и неповторимая:

```asm
CMP <приёмник>, <источник>
```

Здесь `<приёмник>` - регистр или ячейка памяти, `<источник>` -
непосредственный операнд, регистр или ячейка памяти.

Однако стоит отметить, что оба операнда не могут одновременно быть ячейками
памяти.

Команда вычитает `<источник>` из `<приёмника>`, не сохраняя результат, но
выставляя флаги `CF`, `PF`, `AF`, `ZF`, `SF` и `OF`.
