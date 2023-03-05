cmake_minimum_required(VERSION 3.24)
project(ft_printf C)

set(CMAKE_C_STANDARD 11)
set(FT_PRINTF_SOURCES
        main.c
        src/ft_printf.c
        src/ft_printf_utils.c
        src/ft_printflag.c
        src/libft_utils.c
)

add_executable(ft_printf ${FT_PRINTF_SOURCES})
