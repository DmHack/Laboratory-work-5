cmake_minimum_required(VERSION 3.10)
project(Laboratory_work_5 C)
set(CMAKE_C_STANDARD 99)
# Укажите все исходные файлы, которые должны быть собраны
add_executable(Laboratory_work_5 main.c func/vvod/vvod.c
        func/randvVod/randVvod.c
        func/goBack/goBack.c
        func/sort/vstavka/vstavka.c
        func/copyMass/copyMass.c
        func/vuvod/vuvod.c
        func/sort/vibor/vibor.c
        func/sort/pyzir/pyzir.c
)