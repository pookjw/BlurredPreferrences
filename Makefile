include $(THEOS)/makefiles/common.mk

SUBPROJECTS += modules/BlurredPreferencesHelper
SUBPROJECTS += modules/BlurredPreferencesSpringBoardHelper

include $(THEOS_MAKE_PATH)/aggregate.mk
