mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS +=

APPL_CXXOBJS += \
	util.o \
	Measure.o \
	Brightness.o \
	MyColorSensor.o \
	Polling.o \
	Length.o \
	TurnAngle.o \
	Odometry.o \
	Velocity.o \
	HsvHue.o \
	HsvSatu.o

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

APPL_DIRS += $(mkfile_path)app $(mkfile_path)unit  $(mkfile_path)device

INCLUDES += \
	-I$(mkfile_path)app \
	-I$(mkfile_path)device \

# COPTS += -fno-use-cxa-atexit
COPTS += -std=c++11
