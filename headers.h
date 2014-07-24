@interface NCUtil : NSObject {}
+(void)fire:(NSString*)name;
+(void)observe:(NSString*)name target:(id)target selector:(SEL)selector;
@end


@interface Util : NSObject {}
+(UIView*)getNestedView:(UIView*)parentView tree:(NSArray*)tree;
+(void)listSubviewsOfView:(UIView *)view;
+(void)listSubviewsOfView:(UIView *)view withPrefix:(NSString *)prefix;
+(void)setTimeout:(float)time target:(id)object selector:(SEL)selector;
@end