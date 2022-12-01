TARGET := iphone:clang:latest
INSTALL_TARGET_PROCESSES = Preferences
export ARCHS=arm64 arm64e

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = BlurredPreferencesHelper

$(TWEAK_NAME)_CFLAGS = -fobjc-arc -Wno-unused-variable -Wno-unused-function -I$(THEOS_PROJECT_DIR)/headers
$(TWEAK_NAME)_FRAMEWORKS = UIKit CoreGraphics
$(TWEAK_NAME)_FILES = $(wildcard *.m)

include $(THEOS_MAKE_PATH)/tweak.mk
