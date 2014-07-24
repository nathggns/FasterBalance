include theos/makefiles/common.mk

BUNDLE_NAME = fasterbalance_settings
fasterbalance_settings_FILES = fasterbalance_settings.mm
fasterbalance_settings_INSTALL_PATH = /Library/PreferenceBundles
fasterbalance_settings_FRAMEWORKS = UIKit
fasterbalance_settings_PRIVATE_FRAMEWORKS = Preferences

include $(THEOS_MAKE_PATH)/bundle.mk

internal-stage::
	$(ECHO_NOTHING)mkdir -p $(THEOS_STAGING_DIR)/Library/PreferenceLoader/Preferences$(ECHO_END)
	$(ECHO_NOTHING)cp entry.plist $(THEOS_STAGING_DIR)/Library/PreferenceLoader/Preferences/fasterbalance_settings.plist$(ECHO_END)
