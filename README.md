# Computação Gráfica

## Instalação (Fedora)

> sudo dnf install mesa-libGL-devel \
sudo dnf install freeglut-devel

## Compilar (sem makefile)

> gcc -lglut -lGL -lGLU -lm \<file\>.c

## Compilar (com makefile)

> make compile file=\<file path\>.c

## Rodar

> make run
