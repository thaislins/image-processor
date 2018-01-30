#Makefile for "Image Processor" C++ application
#Created by Thais Lins 30/01/2018

PROG = ppmprocessor
CC = g++
CPPFLAGS = -Wall -pedantic -std=c++11
OBJS = ppmreader.o image.o pixel.o

all: ppmprocessor

ppmprocessor: ppmreader.o image.o pixel.o
	$(CC) ppmreader.o image.o pixel.o -o ../bin/ppmprocessor

ppmreader.o:  ppmreader.cpp
	$(CC) $(CPPFLAGS) -c ppmreader.cpp

image.o: image.cpp
	 $(CC) $(CPPFLAGS) -c image.cpp

animal.o: pixel.cpp
	  $(CC) $(CPPFLAGS) -c pixel.cpp

clean:
	rm -rf *o $(OBJS) 	



