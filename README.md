# cc_edcoder RU
cc_edcoder - Кодек циклических кодов и генератор шума, реализующий процессы кодирования/декодирования исходных данных кодом Хэмминга (7, 4) и внесения ошибок в виде 3-х отдельных независимых приложений, использующих экземпляр класса QSharedMemory в качестве симулятора канала связи с ВРК (TDMA).

## Компоненты:

cc_encoder - Кодер

cc_decoder - Декодер

noise_generator - Генератор шума

tdma_data_link - Симулятор канала связи с ВРК

memory_cleaner - Очиститель QSharedMemory (в Windows реализации не нужен)

## Windows:
Для запуска приложений необходимы библиотеки QtCore и Visual C++ Redistributable.

Скомпилированные исполняемые файлы с библиотекой QtCore находятся в bin/Windows.

Библиотеку Visual C++ Redistributable необходимо установить.

## macOS:
Для запуска приложений необходима библиотека QtCore.

Скомпилированные исполняемые файлы с библиотекой QtCore находятся в bin/macOS. 

Библиотеку QtCore необходимо установить.

# cc_edcoder EN
cc_edcoder - Cyclic code codec and noise generator that implements encoding/decoding of (7, 4) Hamming codes and error insertion processes as 3 separate independent applications that use instance of QSharedMemory class as TDMA data link simulator.

## Windows:
Libraries QtCore and Visual C++ Redistributable are needed to run applications.

Compiled binaries with QtCore library are in bin/Windows.

Visual C++ Redistributable library is needed to be installed.

## macOS:
Library QtCore is needed to run applications.

Compiled binaries with QtCore library are in bin/macOS. Libraries are needed to be installed.

QtCore library is needed to be installed.
