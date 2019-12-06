# list/Makefile
#
# Makefile for list implementation and test file.
#
# Amari Jones

list: main.c
  gcc -std=c99 -o list.c main.c -I.
  
