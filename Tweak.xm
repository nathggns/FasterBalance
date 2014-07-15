#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>


@interface MyTableView : UITableView
@end

@interface MyView : UIView
{
    MyTableView* mainTable;
}
@property(retain, nonatomic) MyTableView* mainTable;
@end

@interface xyzApp
-(UIButton*)getNotNowButton;
-(UIApplication*)getCurrentApp;
-(UIWindow*)getCurrentWindow;
-(UIButton*)getContinueButton;
-(MyTableView*)getCurrentTableView;
-(MyView*)getCurrentMyView;
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
    return [[[[[self getCurrentWindow] subviews] objectAtIndex:0] subviews] objectAtIndex:3];
}

%new
-(UIApplication*)getCurrentApp
{
    return [UIApplication sharedApplication];
}

%new
-(UIWindow*)getCurrentWindow
{
    return [[self getCurrentApp] keyWindow];
}
  
%new
-(MyView*)getCurrentMyView
{
    return [[[self getCurrentWindow] subviews] objectAtIndex:0];
}
  
%new
-(MyTableView*)getCurrentTableView
{
    return [[self getCurrentMyView] mainTable];
}

%new
-(UIButton*)getContinueButton
{
    return [[[[[[[[[[[[[self getCurrentTableView] subviews] objectAtIndex:0] subviews] objectAtIndex:1] subviews] objectAtIndex:0] subviews] objectAtIndex:0] subviews] objectAtIndex:0] subviews] objectAtIndex:0];
}
 
%end