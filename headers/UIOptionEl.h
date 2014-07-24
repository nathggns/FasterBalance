/**
 * This header is generated by class-dump-z 0.2-0.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "Monitise-iPhone-HSBC-EN-GB-Structs.h"
#import "MonitiseBaseTableViewCell.h"

@class UIImageView, NSString, UILabel;

__attribute__((visibility("hidden")))
@interface UIOptionEl : MonitiseBaseTableViewCell {
	UILabel* titleLabel;
	UILabel* subTitleLabel;
	UIImageView* disclosureIconImageView;
	NSString* titleText;
	BOOL myHideImage;
}
@property(retain, nonatomic) UIImageView* disclosureIconImageView;
@property(retain, nonatomic) UILabel* subTitleLabel;
@property(retain, nonatomic) UILabel* titleLabel;
-(void)dealloc;
-(void)touchesBegan:(id)began withEvent:(id)event;
-(void)layoutSubviews;
-(void)setUpDisplayFromElement:(UIElement*)element hideElementImage:(BOOL)image;
-(id)initWithFrameAndDetails:(CGRect)frameAndDetails;
@end
