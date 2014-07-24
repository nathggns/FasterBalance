ARCHS=armv7 arm64

include theos/makefiles/common.mk

TWEAK_NAME = FasterBalance
FasterBalance_FILES = Tweak.xm
FasterBalance_FRAMEWORKS = UIKit Foundation

BUNDLE_NAME = com.nathggns.FasterBalance
com.nathggns.FasterBalance_INSTALL_PATH = /Library/MobileSubstrate/DynamicLibraries
include $(THEOS)/makefiles/bundle.mk

include $(THEOS_MAKE_PATH)/tweak.mk

after-install::
	install.exec "killall -9 Monitise-iPhone-HSBC-EN-GB; killall -9 Preferences;"
SUBPROJECTS += fasterbalance_settings
include $(THEOS_MAKE_PATH)/aggregate.mk
