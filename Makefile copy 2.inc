mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS +=

APPL_CXXOBJS += \
	util.o \
	PID.o \
	SpeedControl.o \
	LowPassFilter.o \
	Walker.o \
	Judge.o \
	Measure.o \
	Brightness.o \
	HsvHue.o \
	HsvSatu.o \
	MyColorSensor.o \
	TurnAngle.o \
	Length.o \
	Odometry.o \
	XPosition.o\
	YPosition.o\
	TailAngle.o\
	ArmAngle.o\
	Velocity.o \
	LineTracer.o \
	SimpleWalker.o \
	Polling.o 


SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

APPL_DIRS += $(mkfile_path)app $(mkfile_path)unit  $(mkfile_path)device $(mkfile_path)walker $(mkfile_path)section $(mkfile_path)judge $(mkfile_path)bingo

INCLUDES += \
	-I$(mkfile_path)app \
	-I$(mkfile_path)device \
	-I$(mkfile_path)walker \
	-I$(mkfile_path)section \
	-I$(mkfile_path)judge \
	-I$(mkfile_path)bingo \
	-I$(ETROBO_HRP3_WORKSPACE)/etroboc_common

# COPTS += -fno-use-cxa-atexit
COPTS += -std=c++11
