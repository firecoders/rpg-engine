# rpg-engine, An rpg engine written in C++
# Copyright (C) 2014 firecoders
# 
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included
# in all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
# OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
# IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
# DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
# OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

####################################################
#        Constants                                 #
####################################################
CC = g++ -std=c++11 -Wall
SRCDIR = src/
OBJDIR = bin/

EXECUTABLES = executable

# Default target
default: executable

####################################################
#        Other prerequisites / dependencies        #
####################################################

####################################################
#         Application definitions                  #
####################################################
OBJS = main.o
executable: make_dirs $(OBJS)
	$(CC) $(addprefix $(OBJDIR), $(OBJS)) -o $@
	@echo Done linking $@.

####################################################
#        Generated Variables                       #
####################################################
OBJDIRS = $(subst $(SRCDIR),$(OBJDIR),$(shell find $(SRCDIR) -type d))
HEADER = $(subst .o,.h, $@)

####################################################
#          Other targets                           #
####################################################
.PHONY : clean make_dirs all

%.o : %.cpp
	$(CC) -c $(filter %.cpp, $^) -o $(OBJDIR)$@

clean:
	@-rm -r bin $(EXECUTABLES)

make_dirs:
	@mkdir -p $(OBJDIRS)

all: $(EXECUTABLES)


####################################################
#          vpath                                   #
####################################################
vpath %.cpp $(SRCDIR)
vpath %.h   $(SRCDIR)
