/**
 * This header is generated by class-dump-z 0.2-0.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <Foundation/NSObject.h>

@class NSString;

__attribute__((visibility("hidden")))
@interface MTKKeychain : NSObject {
	NSString* _service;
	NSString* _accessGroup;
}
+(id)keychainWithService:(id)service accessGroup:(id)group;
+(id)shared;
-(BOOL)setData:(id)data forKey:(id)key;
-(id)dataForKey:(id)key;
-(id)accounts;
-(BOOL)setPassword:(id)password forAccount:(id)account;
-(id)passwordForAccount:(id)account;
-(id)initWithService:(id)service accessGroup:(id)group;
@end

