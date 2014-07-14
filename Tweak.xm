%hook xyzApp
 
-(void)applicationDidFinishLaunching:(id)application
{
    %orig;
    UIButton *button = [[[[[[UIApplication sharedApplication] keyWindow] subviews] objectAtIndex:0] subviews] objectAtIndex:3];
    [button sendActionsForControlEvents:64];
}
 
%end