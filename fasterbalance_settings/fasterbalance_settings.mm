#import <Preferences/Preferences.h>

@interface fasterbalance_settingsListController: PSListController {
}
@end

@implementation fasterbalance_settingsListController
- (id)specifiers {
	if(_specifiers == nil) {
		_specifiers = [[self loadSpecifiersFromPlistName:@"fasterbalance_settings" target:self] retain];
	}
	return _specifiers;
}
@end

// vim:ft=objc
