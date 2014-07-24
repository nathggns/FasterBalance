#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <headers/Monitise-iPhone-HSBC-EN-GB.h>

#define kBundlePath @"/Library/MobileSubstrate/DynamicLibraries/com.nathggns.FasterBalance.bundle"

MyTableView* passwordView;

UIWaitScreenView* waitScreen;
int passwordViewSubviews = 0;

@interface Util : NSObject {}
+(UIView*)getNestedView:(UIView*)parentView tree:(NSArray*)tree;
@end

@implementation Util
    +(UIView*)getNestedView:(UIView*)parentView tree:(NSArray*)tree{
        
        UIView* currentView = parentView;
        
        for (int i = 0; i < [tree count]; i++) {
            currentView = [[currentView subviews] objectAtIndex:[[tree objectAtIndex:i] intValue]];
        }
        
        return currentView;
    }
@end

%hook UIWaitScreenView

%new
-(UIView*)getWaitTitle {
    return self;
    return [Util getNestedView:self tree:@[@0]];
}
%end

%hook UIView

-(void)addSubview:(UIView *)view {
    %orig;
    
    if (self == passwordView) {
        passwordViewSubviews = passwordViewSubviews + 1;
        
        if (passwordViewSubviews == 4) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"passwordViewCreated" object:nil];
        }
    }
}

%end

%hook MyTableView

-(int)tableView:(id)view numberOfRowsInSection:(int)section {
    int count = %orig;
    
    // @todo This is a bit of a finiky way of detecting if it's the password view....
    // will probably cause problems.
    if (count == 3) {
        passwordView = self;
        passwordViewSubviews = 0;
    }
    
    return count;
}

%new
- (UITextField*)getPasswordField {
    return (UITextField*)[Util getNestedView:self tree:@[@0, @2, @0, @0, @0, @0]];
}

%new
- (BOOL)isPasswordView {
    return self == passwordView;
}

%end

%hook xyzApp
-(void)applicationDidFinishLaunching:(id)application {
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(submitPasswordView:) name:@"passwordViewCreated" object:nil];

    %orig;

    UIButton* button = [self getNotNowButton];
    [button HSBCInterstitialNotNowTapped:button];
}


%new
-(void)pressContinueAnchor:(NSTimer *)timer {
    UIAnchor* anchor = [self getContinueAnchor];
    
    [anchor buttonPressed:anchor];
}

%new
-(void)hideWaitscreen:(NSNotification*)notification {
    [waitScreen setHidden:YES];
}


%new
-(void)submitPasswordView:(NSNotification*)notification {
    [passwordView setHidden:YES];
    
    Class clazz = objc_getClass("UIWaitScreenView");
    waitScreen = [[clazz alloc] initWithTitle];
    
    [waitScreen setWaitScreenProperties:@"Connecting..." subTitleText:@"Secure Connection"];
    
    NSLog(@"%@", [waitScreen getWaitTitle]);
    
    [[self getCurrentMyView] addSubview:waitScreen];
    
    [waitScreen setHidden:NO];
    [waitScreen startWaitAnimation];
    
    UITextField* field = [[self getCurrentTableView] getPasswordField];

    [field resignFirstResponder];
    NSBundle *bundle = [[[NSBundle alloc] initWithPath:kBundlePath] autorelease];
    NSString *filePath = [bundle pathForResource:@"password" ofType:@"txt"];
    NSError *error;
    NSString *fileContents = [NSString stringWithContentsOfFile:filePath encoding:NSUTF8StringEncoding error:&error];
    field.text = [NSString stringWithFormat:@"%@", fileContents];
    
//    
//    if (error)
//        NSLog(@"Error reading file: %@", error.localizedDescription);
//    else
//        field.text = fileContents;
//    
    [NSTimer scheduledTimerWithTimeInterval:0.5f
                                      target:self
                                    selector: @selector(pressContinueAnchor:)
                                    userInfo:nil
                                     repeats:NO];
    
}

%new
-(UIButton*)getNotNowButton {
    return (UIButton*) [Util getNestedView:[self getCurrentWindow] tree:@[@0, @3]];
}

%new
-(UIApplication*)getCurrentApp     { return [UIApplication sharedApplication]; }

%new
-(UIWindow*)getCurrentWindow       { return [[self getCurrentApp] keyWindow]; }
  
%new
-(MyView*)getCurrentMyView         { return (MyView*) [Util getNestedView:[self getCurrentWindow] tree:@[@0]]; }
  
%new
-(MyTableView*)getCurrentTableView { return [[self getCurrentMyView] mainTable]; }

%new
-(UIAnchor*)getContinueAnchor     { return (UIAnchor*) [Util getNestedView:[self getCurrentTableView] tree:@[@0, @1, @0, @0, @0]]; }

%new
-(UIButton*)getContinueButton      { return (UIButton*) [Util getNestedView:[self getContinueAnchor] tree:@[@0]]; }
%end