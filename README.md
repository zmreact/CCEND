# cc_edcoder [ru]
cc_edcoder - Кодер/декодер циклических кодов и генератор шума, реализующий процессы кодирования/декодирования исходных данных кодом Хэмминга (7, 4) и внесения ошибок в виде 3-х отдельных независимых приложений, использующих экземпляр объекта класса QSharedMemory в качестве канала связи с ВРК (TDMA).

## Компоненты:

cc_encoder - Кодер

cc_decoder - Декодер

noise_generator - Генератор шума

tdma_data_link - Имитация канала связи с ВРК

memory_cleaner - Очиститель QSharedMemory памяти (для Windows не нужен)

Для запуска и компиляции приложений требуется библиотека QtCore.

## Windows:
Скомпилированные исполняемые файлы с необходимыми библиотеками находятся в bin/windows.

## macOS:
Скомпилированные исполняемые файлы с необходимыми библиотеками находятся в bin/macOS. Библиотеки необходимо установить.

# cc_edcoder [en]
cc_edcoder - Cyclic code encoder/decoder and noise generator that implements encoding/decoding of (7, 4) Hamming codes and error insertion processes as 3 separate independent applications that use QSharedMemory instance as data link with TDMA.

Library QtCore is needed to compile and run applications.

## Windows:
Compiled binaries with all needed libraries are in bin/windows.

## macOS:
Compiled binaries with all needed libraries are in bin/macOS. Libraries are needed to be installed.