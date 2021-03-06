#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Form1.o \
	${OBJECTDIR}/TApplication.o \
	${OBJECTDIR}/TButton.o \
	${OBJECTDIR}/TEvent.o \
	${OBJECTDIR}/TFont.o \
	${OBJECTDIR}/TForm.o \
	${OBJECTDIR}/TFormDefinition.o \
	${OBJECTDIR}/TFormDefinitionSection.o \
	${OBJECTDIR}/TObject.o \
	${OBJECTDIR}/TPosition.o \
	${OBJECTDIR}/TSize.o \
	${OBJECTDIR}/TTextBox.o \
	${OBJECTDIR}/TVisibleObject.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=$$(pkg-config --libs --cflags gtkmm-3.0)
CXXFLAGS=$$(pkg-config --libs --cflags gtkmm-3.0)

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Form1.o: Form1.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I/usr/local/boost_1_72_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Form1.o Form1.cpp

${OBJECTDIR}/TApplication.o: TApplication.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I/usr/local/boost_1_72_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TApplication.o TApplication.cpp

${OBJECTDIR}/TButton.o: TButton.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I/usr/local/boost_1_72_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TButton.o TButton.cpp

${OBJECTDIR}/TEvent.o: TEvent.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I/usr/local/boost_1_72_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TEvent.o TEvent.cpp

${OBJECTDIR}/TFont.o: TFont.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I/usr/local/boost_1_72_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TFont.o TFont.cpp

${OBJECTDIR}/TForm.o: TForm.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I/usr/local/boost_1_72_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TForm.o TForm.cpp

${OBJECTDIR}/TFormDefinition.o: TFormDefinition.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I/usr/local/boost_1_72_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TFormDefinition.o TFormDefinition.cpp

${OBJECTDIR}/TFormDefinitionSection.o: TFormDefinitionSection.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I/usr/local/boost_1_72_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TFormDefinitionSection.o TFormDefinitionSection.cpp

${OBJECTDIR}/TObject.o: TObject.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I/usr/local/boost_1_72_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TObject.o TObject.cpp

${OBJECTDIR}/TPosition.o: TPosition.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I/usr/local/boost_1_72_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TPosition.o TPosition.cpp

${OBJECTDIR}/TSize.o: TSize.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I/usr/local/boost_1_72_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TSize.o TSize.cpp

${OBJECTDIR}/TTextBox.o: TTextBox.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I/usr/local/boost_1_72_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TTextBox.o TTextBox.cpp

${OBJECTDIR}/TVisibleObject.o: TVisibleObject.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I/usr/local/boost_1_72_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TVisibleObject.o TVisibleObject.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I/usr/local/boost_1_72_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
