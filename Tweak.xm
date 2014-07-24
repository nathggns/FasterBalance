#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <hsbc/Monitise-iPhone-HSBC-EN-GB.h>
#import "headers.h"

#define kBundlePath @"/Library/MobileSubstrate/DynamicLibraries/com.nathggns.FasterBalance.bundle"

MyTableView* passwordView;

UIWaitScreenView* waitScreen;
int passwordViewSubviews = 0;

@implementation Util
+(UIView*)getNestedView:(UIView*)parentView tree:(NSArray*)tree {
    
    UIView* currentView = parentView;
    
    for (int i = 0; i < [tree count]; i++) {
        currentView = [[currentView subviews] objectAtIndex:[[tree objectAtIndex:i] intValue]];
    }
    
    return currentView;
}

+(void)listSubviewsOfView:(UIView *)view {
    [Util listSubviewsOfView:(UIView *)view withPrefix:@""];
}

+(void)listSubviewsOfView:(UIView *)view withPrefix:(NSString *)prefix {
    NSArray *subviews = [view subviews];
    for (UIView *subview in subviews) {
        NSLog(@"%@ %@ (%d %d; %d %d)", prefix, subview.class
              , (int)subview.frame.origin.x
              , (int)subview.frame.origin.y
              , (int)subview.frame.size.width
              , (int)subview.frame.size.height);

        [Util listSubviewsOfView:subview withPrefix:[NSString stringWithFormat:@"%@    ", prefix]];
    }
}

+(void)setTimeout:(float)time target:(id)object selector:(SEL)selector {
    [NSTimer scheduledTimerWithTimeInterval:time target:object selector:selector userInfo:nil repeats:NO];
}
@end



@implementation NCUtil
+(void)fire:(NSString*)name {
    [[NSNotificationCenter defaultCenter] postNotificationName:name object:nil];
}

+(void)observe:(NSString*)name target:(id)target selector:(SEL)selector {
    [[NSNotificationCenter defaultCenter] addObserver:target selector:selector name:name object:nil];
}
@end

%hook UIView
-(void)addSubview:(UIView *)view {
    %orig;
    
    if (self == passwordView) {
        if (++passwordViewSubviews == 4) {
            [NCUtil fire:@"passwordViewCreated"];
        }
    }
}
%end

%hook MyTableView
-(int)tableView:(id)view numberOfRowsInSection:(int)section {
    int count = %orig;

    if (count == 3 && floorf([Util getNestedView:self tree:@[@0]].frame.size.width) == 310) {
        passwordView = self;
        passwordViewSubviews = 0;
    }
    
    return count;
}

%new
-(UITextField*)getPasswordField {
    return (UITextField*)[Util getNestedView:self tree:@[@0, @2, @0, @0, @0, @0]];
}

%new
-(BOOL)isPasswordView {
    return self == passwordView;
}
%end

%hook xyzApp
-(void)applicationDidFinishLaunching:(id)application {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    NSDictionary *prefs=[[NSDictionary alloc] initWithContentsOfFile:@"/var/mobile/Library/Preferences/com.nathggns.FasterBalance.plist"];
    
    if (![[prefs objectForKey:@"enabled"] boolValue]){
        [prefs release];
        
        return %orig;
    }
    
    [prefs release];

    
    [NCUtil observe:@"passwordViewCreated" target:self selector:@selector(submitPasswordView:)];

    %orig;

    [[self getNotNowButton] HSBCInterstitialNotNowTapped:nil];
    [pool drain];
}

%new
-(void)pressContinueAnchor:(NSTimer *)timer {
    [[self getContinueAnchor] buttonPressed:nil];
}

%new
-(void)submitPasswordView:(NSNotification*)notification {
    Class UIWaitScreenViewClass = objc_getClass("UIWaitScreenView");
    
    [passwordView setHidden:YES];
    
    waitScreen = [[UIWaitScreenViewClass alloc] initWithTitle];
    [waitScreen setWaitScreenProperties:@"Connecting..." subTitleText:@"Secure Connection"];
    [waitScreen setHidden:NO];
    [waitScreen startWaitAnimation];
    
    [[self getCurrentMyView] addSubview:waitScreen];
    
    UITextField* field = [[self getCurrentTableView] getPasswordField];

    [field resignFirstResponder];
    NSBundle *bundle = [[[NSBundle alloc] initWithPath:kBundlePath] autorelease];
    NSString *filePath = [bundle pathForResource:@"password" ofType:@"txt"];
    NSError *error;
    NSString *fileContents = [NSString stringWithContentsOfFile:filePath encoding:NSUTF8StringEncoding error:&error];
    field.text = [NSString stringWithFormat:@"%@", fileContents];
  
    [Util setTimeout:0.5 target:self selector:@selector(pressContinueAnchor:)];
}

%new
-(UIButton*)getNotNowButton {
    return (UIButton*) [Util getNestedView:[self getCurrentWindow] tree:@[@0, @3]];
}

%new
-(UIApplication*)getCurrentApp {
    return [UIApplication sharedApplication];
}

%new
-(UIWindow*)getCurrentWindow {
    return [[self getCurrentApp] keyWindow];
}
  
%new
-(MyView*)getCurrentMyView {
    return (MyView*) [Util getNestedView:[self getCurrentWindow] tree:@[@0]];
}
  
%new
-(MyTableView*)getCurrentTableView {
    return [[self getCurrentMyView] mainTable];
}

%new
-(UIAnchor*)getContinueAnchor {
    return (UIAnchor*) [Util getNestedView:[self getCurrentTableView] tree:@[@0, @1, @0, @0, @0]];
}

%new
-(UIButton*)getContinueButton {
    return (UIButton*) [Util getNestedView:[self getContinueAnchor] tree:@[@0]];
}
%end