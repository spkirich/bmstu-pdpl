# Обратная разработка

С помощью дизассемблера определить пароль, необходимый для получения
сообщения об успешном взломе данной программы.

## Замечания

Дизассемблируем исполняемый файл:

```bash
$ objdump -d crackme.exe > dump
```

В файле `dump` увидим под две сотни килобайт отборного текста, в котором
придётся разбираться. Найдём метку `_main`:

```asm
00401410 <_main>:
```

Сначала расположен типичный код настройки стека при входе в функцию, затем
под локальные переменные на нём отводится 80 байт:

```asm
  401410:       55                      push   %ebp
  401411:       89 e5                   mov    %esp,%ebp
  401413:       83 e4 f0                and    $0xfffffff0,%esp
  401416:       83 ec 50                sub    $0x50,%esp
```

Самое интересное происходит дальше - локальные переменные инициализируются:

```asm
  40141e:       c7 44 24 38 70 61 73    movl   $0x73736170,0x38(%esp)
  401425:       73
  401426:       c7 44 24 3c 77 6f 72    movl   $0x64726f77,0x3c(%esp)
  40142d:       64
  40142e:       c7 44 24 40 31 32 33    movl   $0x333231,0x40(%esp)
  401435:       00
```

После вывода приглашения ко вводу программа запрашивает пароль:

```asm
  401467:       8d 44 24 1a             lea    0x1a(%esp),%eax
  40146b:       89 44 24 04             mov    %eax,0x4(%esp)
  40146f:       c7 04 24 ab 60 40 00    movl   $0x4060ab,(%esp)
  401476:       e8 31 2a 00 00          call   403eac <_scanf>
```

А затем сравнивает введённую строку по адресу `0x1a(%esp)` со строкой по
адресу`0x38(%esp)`:

```asm
  40147b:       8d 44 24 1a             lea    0x1a(%esp),%eax
  40147f:       89 44 24 04             mov    %eax,0x4(%esp)
  401483:       8d 44 24 38             lea    0x38(%esp),%eax
  401487:       89 04 24                mov    %eax,(%esp)
  40148a:       e8 05 2a 00 00          call   403e94 <_strcmp>
```

Получается, те самые локальные переменные - это и есть пароль! С учётом того,
что младшие байты кладутся на стек первыми, он кодируется следующей строкой:

```c
{ 0x70, 0x61, 0x73, 0x73, 0x77, 0x6f, 0x72, 0x64, 0x31, 0x32, 0x33, 0x00 }
```

Теперь несложно видеть, что пароль - `password123`.
