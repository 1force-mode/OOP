cmake_minimum_required(VERSION 3.8)

# Включение горячей перезагрузки для MSVC, если поддерживается
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Название проекта
project(CMakeProject_lab_5)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Список исходных файлов
set(SOURCES
    CMakeProject_lab_5.cpp
    LightBulb.cpp
    PowerStrip.cpp
    KeroseneLamp.cpp
    Garland.cpp
    ElectricIron.cpp
    Flashlight.cpp
    ElectroFlashlight.cpp
    Candle.cpp
)

# Создание исполняемого файла
add_executable(${PROJECT_NAME} ${SOURCES})

# Указание директорий с заголовочными файлами
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# TODO: Добавьте тесты или дополнительные зависимости, если необходимо