# Структура программы на языке ассемблера. Модули. Сегменты

Программа на языке ассемблера состоит из **модулей**, каждый из которых
представляется файлом с исходным кодом. В свою очередь, каждый модуль состоит
из **сегментов**, описывающих соответствующие блоки памяти.

Сегменты могут содержать команды, описания структур данных в памяти и
макроопределения. Различают следующие их виды:

- Сегмент кода.
- Сегмент данных.
- Сегмент стека.

Описание модуля может завершаться указанием **точки входа** - объявленной в
сегменте кода метки, с которой должно начинаться исполнение программы. Только
один модуль может содержать точку входа!
