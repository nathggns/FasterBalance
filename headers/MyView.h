/**
 * This header is generated by class-dump-z 0.2-0.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Monitise-iPhone-HSBC-EN-GB-Structs.h"
#import "UINavigationBarDelegate.h"
#import <UIKit/UIView.h>

@class MyTableView, UIImageView, UINavigationBar, UINavigationItem;

__attribute__((visibility("hidden")))
@interface MyView : UIView <UINavigationBarDelegate> {
	UINavigationBar* navBar;
	UIElement* navBarLHS;
	UIElement* navBarRHS;
	UINavigationItem* navBarItem;
	MyTableView* mainTable;
	UIImageView* bannerImageView;
}
@property(retain, nonatomic) MyTableView* mainTable;
-(void)dealloc;
-(void)layoutSubviewsOnElements;
-(void)goHelp;
-(void)goRHS;
-(void)goLHS;
-(void)redrawTableView;
-(id)initWithFrame:(CGRect)frame;
@end

