# Basic test makefile for Housement firmware.

TARGET = test.out

CC = g++

UNITYFILES = Unity/src/unity.c
CPPSRCS = test.cpp ../state_machine.cpp ../events.cpp $(UNITYFILES)
INC = -I../. -IUnity/src

CPPFLAGS = -Wall -O2 $(INC)

all:
	$(CC) $(CPPFLAGS) $(CPPSRCS) -o $(TARGET)
	./$(TARGET)
