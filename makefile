##****************************************************************************
## Program Name: makefile
## Author: Ren Demeis-Ortiz
## Description: Makefile that builds, cleans, debugs, and zips project files.
## Credit: Code used from CS162 Module one makefile lecture unless otherwise
##         noted.
## Source: https://oregonstate.instructure.com/courses/1738874/files/76040054
##****************************************************************************

#----------#
# Complier #
#----------#
CXX = g++

#------------------------------------------------#
# CXX Flags                                      #
# Credit: Harlan James                           #
# Source: https://oregonstate.instructure.com/   # 
# courses/1738874/files/76040124/download?wrap=1 #
#------------------------------------------------#
CFLAGS = -std=gnu++11 -pedantic -Wall

#----------------------#
# Executable File Name #
#----------------------#
PROJ = chaos 

#-------------#
# Main  File  #
#-------------#
MAIN = chaosMain.cpp

#---------------#
# Source  Files #
#---------------#
SRCS = Menu.cpp
SRCS += Game.cpp
SRCS += Animal.cpp
SRCS += Dog.cpp
SRCS += Cat.cpp
SRCS += Space.cpp
SRCS += UseSpace.cpp
SRCS += OpenSpace.cpp
SRCS += BreakSpace.cpp


#---------------#
# Header  Files #
#---------------#
HDRS = Menu.hpp
HDRS += Game.hpp
HDRS += Animal.hpp
HDRS += Dog.hpp
HDRS += Cat.hpp
HDRS += Space.hpp
HDRS += UseSpace.hpp
HDRS += OpenSpace.hpp
HDRS += BreakSpace.hpp

#------------------------------------#
# Additional Files to Include in Zip #
#------------------------------------#
ADD = makefile
ADD += Final_Project_Demeis-Ortiz_Reflection.pdf
ADD += Foyer
ADD += Living_and_Dining_Room
ADD += Kitchen
ADD += Bathroom
ADD += Bedroom
ADD += Garden
ADD += Instructions

#------------------#
# Name of Zip File #
#------------------#
ZNAME = Final_Project_Demeis-Ortiz_Lauren.zip

#------------------------------------------------#
# Valgrind Options                               #
# Credit: Harlan James                           #
# Source: https://oregonstate.instructure.com/   # 
# courses/1738874/files/76040124/download?wrap=1 #
#------------------------------------------------#
VALOPT = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes 

#------------------------------------------------#
# Object Files                                   #         
# Credit: Harlan James                           #
# Source: https://oregonstate.instructure.com/   # 
# courses/1738874/files/76040124/download?wrap=1 #
#------------------------------------------------#
OBJS = $(SRCS:.cpp=.o)

#------------------------------------------------#
# Compile Object Files                           #         
# Credit: Harlan James                           #
# Source: https://oregonstate.instructure.com/   # 
# courses/1738874/files/76040124/download?wrap=1 #
#------------------------------------------------#
%.o: %.cpp %.hpp
	${CXX} ${CFLAGS} -c $(@:.o=.cpp)

#-------------------#
# Link Object Files #
#-------------------#
${PROJ}: ${OBJS} ${HDRS} ${MAIN}
	${CXX} ${CFLAGS} ${MAIN} ${OBJS} -lncurses -o ${PROJ}

#------------------------------------------------#
# Debug                                          #
# Credit: Harlan James                           #
# Source: https://oregonstate.instructure.com/   # 
# courses/1738874/files/76040124/download?wrap=1 #
#------------------------------------------------#
.PHONY: clean debug zip

debug: 
	valgrind ${VALOPT} ./${PROJ}  

#------------------------------------------------------#
# Remove Object Files and Executable                   #
# Credit: Code used from https://ftp.gnu.org/          #
# old-gnu/Manuals/make-3.79.1/html_chapter/make_2.html #
#------------------------------------------------------#
clean:
	-rm ${OBJS} ${PROJ}

#------------------------------------------------------#
# Zip Project Files                                    #
#------------------------------------------------------#
zip:
	zip -D ${ZNAME} ${SRCS} ${MAIN} ${HDRS} ${ADD}

