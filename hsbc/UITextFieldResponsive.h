/**
 * This header is generated by class-dump-z 0.2-0.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Monitise-iPhone-HSBC-EN-GB-Structs.h"
#import <UIKit/UITextField.h>

@class NSString;

__attribute__((visibility("hidden")))
@interface UITextFieldResponsive : UITextField {
	UIElement* myElement;
	NSString* lastString;
}
-(void)dealloc;
-(void)setMaskText:(BOOL)text;
-(void)layoutSubviews;
-(void)setUpDisplayFromElement:(UIElement*)element;
@end

