# Makefile --- makefile for the test cases.
# Author: Luis Colorado <luiscoloradourcola@gmail.com>
# Date: Thu Dec  7 09:51:15 EET 2017

targets = pru1 pru2 pru3
toclean = $(targets)
RM ?= rm -f 

all: $(targets)
clean:
	$(RM) $(toclean)

common_objs=main.o
toclean += $(common_objs)
main.o: pru.h

pru1_objs = pru1.o
toclean += $(pru1_objs)
pru1: $(pru1_objs) $(common_objs)
	$(CC) $(LDFLAGS) -o $@ $($@_objs) $(common_objs) $($@_libs)
$(pru1_objs): pru.h

pru2_objs = pru2.o
toclean += $(pru2_objs)
pru2: $(pru2_objs) $(common_objs)
	$(CC) $(LDFLAGS) -o $@ $($@_objs) $(common_objs) $($@_libs)
$(pru2_objs): pru.h

pru3_objs = pru3.o
toclean += $(pru3_objs)
pru3: $(pru3_objs) $(common_objs)
	$(CC) $(LDFLAGS) -o $@ $($@_objs) $(common_objs) $($@_libs)
$(pru3_objs): pru.h
