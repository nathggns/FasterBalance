#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@interface xyzApp
-(UIButton*)getNotNowButton;
@end

@interface UIButton (HSBCInterstitial)
-(void)HSBCInterstitialNotNowTapped:(id)tapped;
-(void)HSBCInterstitialDownloadTapped:(id)tapped;
@end

%hook xyzApp
 
-(void)applicationDidFinishLaunching:(id)application
{
    %orig;
    
    UIButton* button = [self getNotNowButton];
    [button HSBCInterstitialNotNowTapped:button];
}

%new
-(UIButton*)getNotNowButton
{
    return [[[[[[UIApplication sharedApplication] keyWindow] subviews] objectAtIndex:0] subviews] objectAtIndex:3];
}
 
%end