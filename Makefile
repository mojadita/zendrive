# Makefile --- makefile for the test cases.
# Author: Luis Colorado <luiscoloradourcola@gmail.com>
# Date: Thu Dec  7 09:51:15 EET 2017

targets = pru1 pru2
toclean = $(targets)
RM ?= rm -f 

all: $(targets)
clean:
	$(RM) $(toclean)

pru1_objs = main.o pru1.o
toclean += $(pru1_objs)
pru1: $(pru1_objs)
	$(CC) $(LDFLAGS) -o $@ $($@_objs) $($@_libs)
$(pru1_objs): pru.h

pru2_objs = main.o pru2.o
toclean += $(pru2_objs)
pru2: $(pru2_objs)
	$(CC) $(LDFLAGS) -o $@ $($@_objs) $($@_libs)
$(pru2_objs): pru.h
