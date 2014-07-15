#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <headers.h>

%hook UIButton
-(void)HSBCInterstitialNotNowTapped:(id)tapped {
    %orig;
    
    NSLog(@"Button tapped");
}
%end

%hook MyView
-(id)initWithFrame:(CGRect)frame {
    NSLog(@"Created a MyView");

    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleToRHS:) name:@"toRHS" object:nil];
    
    return %orig;
}

%new
-(void)handleToRHS:(NSNotification*)notification{
    [self goRHS];
}
%end

%hook UIInput
-(id)initWithFrame:(CGRect)frame{
    id result = %orig;    
    self.textInputField.text = @"02151";

    [[NSNotificationCenter defaultCenter] postNotificationName:@"passwordInputCreated" object:nil];
    
    return result;
}
%end

%hook UITextField
-(id)initWithFrame:(CGRect)aRect{
    id result = %orig;
    
    self.text = @"02151";
    
    return result;
}
%end


%hook xyzApp
-(void)applicationDidFinishLaunching:(id)application {
    %orig;

    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(submitPasswordView:) name:@"passwordInputCreated" object:nil];
    
   UIButton* button = [self getNotNowButton];
   [button HSBCInterstitialNotNowTapped:button];
}

%new
-(void)submitPasswordView:(NSNotification*)notification {
    UIButton* cont = [self getContinueButton];
    [cont sendActionsForControlEvents:UIControlEventTouchUpInside];
}

%new
-(UIButton*)getNotNowButton {
    return [[[[[self getCurrentWindow] subviews] objectAtIndex:0] subviews] objectAtIndex:3];
}

%new
-(UIApplication*)getCurrentApp     { return [UIApplication sharedApplication]; }

%new
-(UIWindow*)getCurrentWindow       { return [[self getCurrentApp] keyWindow]; }
  
%new
-(MyView*)getCurrentMyView         { return [[[self getCurrentWindow] subviews] objectAtIndex:0]; }
  
%new
-(MyTableView*)getCurrentTableView { return [[self getCurrentMyView] mainTable]; }

%new
-(UIButton*)getContinueButton      { return [[[[[[[[[[[[[self getCurrentTableView] subviews] objectAtIndex:0] subviews] objectAtIndex:1] subviews] objectAtIndex:0] subviews] objectAtIndex:0] subviews] objectAtIndex:0] subviews] objectAtIndex:0]; }
%end