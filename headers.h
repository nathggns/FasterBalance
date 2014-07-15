/**
 * This header is generated by class-dump-z 0.2-0.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

typedef struct Smart Smart;
typedef struct UIElement {} UIElement;
typedef struct String String;
typedef struct StyleSheetElement StyleSheetElement;
typedef struct DataElement DataElement;
typedef struct UIImageElement* UIImageElementRef;
typedef struct MATMAlgorithm* MATMAlgorithmRef;
typedef struct UIInputElement {} UIInputElement;
typedef struct UIParagraphElement* UIParagraphElementRef;
typedef struct CGContext* CGContextRef;
typedef struct __SCNetworkReachability* SCNetworkReachabilityRef;
typedef struct in_addr {
    unsigned _field1;
} in_addr;

typedef struct sockaddr_in {
    unsigned char _field1;
    unsigned char _field2;
    unsigned short _field3;
    in_addr _field4;
    BOOL _field5[8];
} sockaddr_in;

typedef struct sqlite3 sqlite3;

typedef struct CommsManager CommsManager;

@protocol __ARCLiteKeyedSubscripting__
-(void)setObject:(id)object forKeyedSubscript:(id)keyedSubscript;
-(id)objectForKeyedSubscript:(id)keyedSubscript;
@end

@protocol __ARCLiteIndexedSubscripting__
-(void)setObject:(id)object atIndexedSubscript:(unsigned)indexedSubscript;
-(id)objectAtIndexedSubscript:(unsigned)indexedSubscript;
@end

@interface MonitiseBaseTableViewCell : UIView {
    float height;
    float width;
    int myRowId;
    UIElement* myElement;
    BOOL supportRoundedCorners;
    BOOL gradient;
    UIImage* image;
    int format;
    void* parentView;
    UIColor* UIFontColor;
    BOOL selectable;
    BOOL selectChangesColor;
    float unselBGColorR;
    float unselBGColorG;
    float unselBGColorB;
    float selBGColorR;
    float selBGColorG;
    float selBGColorB;
    UIImageView* imageView;
    UITableViewCell* windowTableViewCell;
}
@property(retain, nonatomic) UITableViewCell* windowTableViewCell;
@property(retain, nonatomic) UIImageView* imageView;
@property(retain, nonatomic) UIImage* image;
@property(assign, nonatomic) BOOL supportRoundedCorners;
@property(assign, nonatomic) BOOL selectChangesColor;
@property(assign, nonatomic) BOOL selectable;
@property(assign, nonatomic) BOOL gradient;
@property(readonly, assign, nonatomic) int myRowId;
@property(assign, nonatomic) float height;
-(void)touchesBegan:(id)began withEvent:(id)event;
-(void)layoutSubviews;
-(void)addToViewTable;
-(UIElement*)findParentTableElement;
-(void)setUpDisplayFromElement:(UIElement*)element BGgradient:(BOOL)ggradient;
-(void)setWidth:(float)width;
-(float)getWidth;
-(float)getHeight;
-(id)initWithFrame:(CGRect)frame;
-(void)setBackgroundColourAsTransparent;
-(void)drawRect:(CGRect)rect;
-(void)CGContextAddRoundedRect:(CGContextRef)rect rect:(CGRect)rect2 corner_radius:(int)radius;
-(void)dealloc;
@end


@interface UIAnchor : MonitiseBaseTableViewCell {
    UILabel* titleLabel;
    UILabel* subTitleLabel;
    UIButton* button;
    UIImageView* disclosureIconImageView;
}
@property(retain, nonatomic) UIImageView* disclosureIconImageView;
@property(retain, nonatomic) UIButton* button;
@property(retain, nonatomic) UILabel* subTitleLabel;
@property(retain, nonatomic) UILabel* titleLabel;
-(void)dealloc;
-(void)buttonPressed:(id)pressed;
-(void)layoutSubviews;
-(BOOL)doesRectContainNAN:(CGRect)nan;
-(void)setUpDisplayFromElement:(UIElement*)element;
-(id)initWithFrame:(CGRect)frame;
-(void)handleFirePressedFontColorChanges:(id)changes;
@end

@interface UIImageEl : MonitiseBaseTableViewCell {
    UIImageView* theImageView;
    int xPosition;
}
@property(retain, nonatomic) UIImageView* theImageView;
-(void)dealloc;
-(void)setUpDisplayFromElement:(UIElement*)element;
-(void)layoutSubviews;
-(id)initWithFrame:(CGRect)frame;
@end

@interface UITextFieldResponsive : UITextField {
    UIElement* myElement;
    NSString* lastString;
}
-(void)dealloc;
-(void)setMaskText:(BOOL)text;
-(void)layoutSubviews;
-(void)setUpDisplayFromElement:(UIElement*)element;
@end

@interface UIInput : MonitiseBaseTableViewCell <UITextFieldDelegate> {
    UITextFieldResponsive* textInputField;
    UILabel* titleLabel;
    UILabel* subTitleLabel;
    UILabel* textFieldCurrencyLabel;
}
@property(retain, nonatomic) UILabel* textFieldCurrencyLabel;
@property(retain, nonatomic) UILabel* subTitleLabel;
@property(retain, nonatomic) UILabel* titleLabel;
@property(retain, nonatomic) UITextFieldResponsive* textInputField;
-(BOOL)textField:(id)field shouldChangeCharactersInRange:(NSRange)range replacementString:(id)string;
-(BOOL)textFieldShouldBeginEditing:(id)textField;
-(BOOL)textFieldShouldEndEditing:(id)textField;
-(void)setUpDisplayFromElement:(UIElement*)element;
-(void)dealloc;
-(void)layoutSubviews;
-(void)setHint:(id)hint;
-(void)updateText;
-(id)initWithFrame:(CGRect)frame;
@end

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

@interface UIParagraph : MonitiseBaseTableViewCell {
    UILabel* titleLabel;
}
@property(retain, nonatomic) UILabel* titleLabel;
-(void)layoutSubviews;
-(float)getHeight;
-(void)dealloc;
-(void)setUpDisplayFromElement:(UIElement*)element;
-(id)initWithFrame:(CGRect)frame;
@end

@interface UISelectEl : MonitiseBaseTableViewCell {
    UILabel* titleLabel;
    UILabel* subTitleLabel;
    UIImageView* disclosureIconImageView;
}
@property(retain, nonatomic) UIImageView* disclosureIconImageView;
@property(retain, nonatomic) UILabel* subTitleLabel;
@property(retain, nonatomic) UILabel* titleLabel;
-(void)dealloc;
-(void)layoutSubviews;
-(BOOL)showOptions;
-(void)setUpDisplayFromElement:(UIElement*)element;
-(id)initWithFrame:(CGRect)frame;
@end

@interface TimerEl : NSObject {
    NSTimer* timerTimer;
    UIElement* myElement;
    BOOL ignoreTimerResponse;
}
-(void)killTimer;
-(void)timerFired;
-(void)setUpFromElement:(UIElement*)element timoutPeriod:(int)period repeats:(BOOL)repeats;
@end

@interface RoundedRectView : UIView {
    UIColor* strokeColor;
    UIColor* rectColor;
    float strokeWidth;
    float cornerRadius;
}
@property(assign) float cornerRadius;
@property(assign) float strokeWidth;
@property(retain, nonatomic) UIColor* rectColor;
@property(retain, nonatomic) UIColor* strokeColor;
-(void)dealloc;
-(void)drawRect:(CGRect)rect;
-(void)setOpaque:(BOOL)opaque;
-(void)setBackgroundColor:(id)color;
-(id)initWithFrame:(CGRect)frame;
-(id)initWithCoder:(id)coder;
@end

@interface MyTableView : UITableView <UITableViewDelegate, UITableViewDataSource> {
    int myRowCount;
    id* myTableCells;
    UIElement** myTableCellsElements;
    DataElement* myDataElement;
    unsigned lastRowId;
    NSTimer* timer;
}
@property(assign, nonatomic) unsigned lastRowId;
-(void)dealloc;
-(void)layoutSubviewsOnElements;
-(void)rowClickTimerFired;
-(float)tableView:(id)view heightForRowAtIndexPath:(id)indexPath;
-(void)tableView:(id)view didSelectRowAtIndexPath:(id)indexPath;
-(id)tableView:(id)view willSelectRowAtIndexPath:(id)indexPath;
-(id)tableView:(id)view cellForRowAtIndexPath:(id)indexPath;
-(int)tableView:(id)view numberOfRowsInSection:(int)section;
-(int)numberOfSectionsInTableView:(id)tableView;
-(void)setupElementData:(int)data;
-(id)initWithFrameAndDetails:(CGRect)frameAndDetails style:(int)style;
@end

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

-(void)handleToRHS:(NSNotification*)notification;
@end

@interface OptionElementView : MyView {
    UILabel* titleLabel;
    UISelectEl* mySelectEl;
}
@property(retain, nonatomic) UILabel* titleLabel;
-(void)dealloc;
-(void)goBack;
-(id)initWithFrameAndDetails:(CGRect)frameAndDetails sourceElement:(id)element;
@end

@interface TextInputView : MyView <UITextFieldDelegate, UIPickerViewDelegate> {
    UILabel* textFieldTitle;
    UILabel* textFieldSubTitle;
    UILabel* textFieldCurrencyLabel;
    UIInputElement* mySourceElement;
    UIInput* mySourceCell;
    int myInputType;
    UIDatePicker* datePicker;
    UIPickerView* pickerView;
}
@property(retain, nonatomic) UILabel* textFieldSubTitle;
@property(retain, nonatomic) UILabel* textFieldTitle;
-(void)dealloc;
-(void)layoutSubviews;
-(void)goSave;
-(void)goCancel;
-(BOOL)textField:(id)field shouldChangeCharactersInRange:(NSRange)range replacementString:(id)string;
-(BOOL)textFieldShouldReturn:(id)textField;
-(BOOL)textFieldShouldBeginEditing:(id)textField;
-(BOOL)textFieldShouldEndEditing:(id)textField;
-(id)stringFormatRequiredByServer;
-(void)updateTextField;
-(id)twoDigitNumber:(int)number;
-(void)pickerView:(id)view didSelectRow:(int)row inComponent:(int)component;
-(float)pickerView:(id)view widthForComponent:(int)component;
-(id)pickerView:(id)view viewForRow:(int)row forComponent:(int)component reusingView:(id)view4;
-(int)pickerView:(id)view numberOfRowsInComponent:(int)component;
-(int)numberOfComponentsInPickerView:(id)pickerView;
-(void)changedDate:(id)date;
-(id)initWithFrameAndDetails:(CGRect)frameAndDetails sourceElement:(UIInputElement*)element sourceCell:(id)cell inputType:(int)type;
@end

@interface MyAlertView : UIAlertView <UIAlertViewDelegate> {
    int myParagraphCount;
    UIParagraphElementRef* myParagraphElements;
    int myButtonCount;
    UIElement** myButtonElements;
}
-(void)dealloc;
-(void)alertView:(id)view clickedButtonAtIndex:(int)index;
-(void)populateLabels;
@end

@interface UIWaitScreenView : MyView {
    UIActivityIndicatorView* activityView;
    UIView* contentView;
    UILabel* waitTitle;
    UILabel* waitSubTitle;
    UIImageView* backgroundImageView;
    UIColor* textColor;
}
-(void)layoutSubviews;
-(void)setWaitScreenProperties:(id)properties subTitleText:(id)text;
-(void)stopWaitAnimation;
-(void)startWaitAnimation;
-(id)initWithTitle;
@end

@interface xyzApp : NSObject {
    UIImage* frameBuffer;
    UIImageView* imageView;
    UIWindow* window;
}
-(void)hideOverlayedWaitScreenInApp;
-(void)showOverlayedWaitScreenInApp;
-(void)displayFullScreenWaitScreen;
-(void)createFullScreenWaitScreen;
-(void)pseudoResponseReceived_B_Hook;
-(void)pseudoResponseReceived_I_S_Hook;
-(void)pseudoResponseReceived_AB_I_Hook;
-(void)setFirstViewHook;
-(void)animationDidStop:(id)animation finished:(BOOL)finished;
-(void)animationDidStopFlip:(id)animation;
-(void)removeKeyboard:(id)keyboard;
-(void)viewTransitionHook;
-(void)dealloc;
-(void)applicationWillEnterForeground:(id)application;
-(void)applicationDidEnterBackground:(id)application;
-(void)applicationWillResignActive:(id)application;
-(void)applicationDidBecomeActive:(id)application;
-(void)applicationWillTerminate:(id)application;
-(void)applicationDidFinishLaunching:(id)application;

-(UIButton*)getNotNowButton;
-(UIApplication*)getCurrentApp;
-(UIWindow*)getCurrentWindow;
-(UIButton*)getContinueButton;
-(MyTableView*)getCurrentTableView;
-(MyView*)getCurrentMyView;
@end

@interface UITableCellEl : MonitiseBaseTableViewCell {
    int myRowCount;
    id* myTableCells;
    UIElement** myTableCellsElements;
}
-(void)dealloc;
-(void)layoutSubviews;
-(void)setUpDisplayFromElement:(UIElement*)element;
-(id)initWithFrame:(CGRect)frame;
@end

@interface UITableRowEl : MonitiseBaseTableViewCell {
    int myColCount;
    id* myTableCells;
    UIElement** myTableCellsElements;
}
-(void)dealloc;
-(void)layoutSubviews;
-(void)setUpDisplayFromElement:(UIElement*)element;
-(id)initWithFrame:(CGRect)frame;
@end

@interface Reachability : NSObject {
    BOOL _networkStatusNotificationsEnabled;
    NSString* _hostName;
    NSString* _address;
    NSMutableDictionary* _reachabilityQueries;
}
@property(assign, nonatomic) NSMutableDictionary* reachabilityQueries;
@property(retain, nonatomic) NSString* address;
@property(retain, nonatomic) NSString* hostName;
@property(assign) BOOL networkStatusNotificationsEnabled;
+(id)sharedReachability;
-(BOOL)addressFromString:(id)string address:(sockaddr_in*)address;
-(int)localWiFiConnectionStatus;
-(int)internetConnectionStatus;
-(int)remoteHostStatus;
-(SCNetworkReachabilityRef)reachabilityRefForAddress:(id)address;
-(SCNetworkReachabilityRef)reachabilityRefForHostName:(id)hostName;
-(void)stopListeningForReachabilityChanges;
-(BOOL)isNetworkAvailableFlags:(unsigned*)flags;
-(BOOL)isAdHocWiFiNetworkAvailableFlags:(unsigned*)flags;
-(BOOL)isHostReachable:(id)reachable;
-(BOOL)isReachableWithoutRequiringConnection:(unsigned)connection;
-(void)dealloc;
@end

@interface ReachabilityQuery : NSObject {
    SCNetworkReachabilityRef _reachabilityRef;
    CFArrayRef _runLoops;
    NSString* _hostNameOrAddress;
}
@property(assign, nonatomic) CFArrayRef runLoops;
@property(retain, nonatomic) NSString* hostNameOrAddress;
@property(assign, nonatomic) SCNetworkReachabilityRef reachabilityRef;
-(CFRunLoopRef)startListeningForReachabilityChanges:(SCNetworkReachabilityRef)reachabilityChanges onRunLoop:(CFRunLoopRef)loop;
-(void)scheduleOnRunLoop:(id)loop;
-(BOOL)isScheduledOnRunLoop:(CFRunLoopRef)loop;
-(void)dealloc;
-(id)init;
@end

@interface PermanentCache : NSObject {
    NSString* dbPath;
    NSMutableArray* cacheItems;
    sqlite3* database;
}
@property(retain, nonatomic) NSMutableArray* cacheItems;
+(id)allocWithZone:(NSZone*)zone;
+(id)getPermanentCache;
-(void)writeCacheManagerContentsToStore;
-(void)loadStoredContentIntoCacheManager;
-(id)getDBPath;
-(void)copyDBToDeviceIfRequired;
-(id)init;
-(id)autorelease;
-(void)release;
-(unsigned)retainCount;
-(id)retain;
-(id)copyWithZone:(NSZone*)zone;
-(void)dealloc;
@end

@interface MTKKeychain : NSObject {
    NSString* _service;
    NSString* _accessGroup;
}
+(id)keychainWithService:(id)service accessGroup:(id)group;
+(id)shared;
-(BOOL)setData:(id)data forKey:(id)key;
-(id)dataForKey:(id)key;
-(id)accounts;
-(BOOL)setPassword:(id)password forAccount:(id)account;
-(id)passwordForAccount:(id)account;
-(id)initWithService:(id)service accessGroup:(id)group;
@end

@interface MonitiseKeyChain : NSObject {
    NSString* _keyChainMigrationUID;
    MTKKeychain* _MTKKeychain;
}
+(id)sharedInstance;
-(id)stringForKey:(id)key;
-(BOOL)setString:(id)string forKey:(id)key;
-(BOOL)migrateFromUserDefaultsForKeys:(id)keys;
-(id)keyChainKeyFor:(id)aFor;
-(id)serviceId;
-(void)generateKeyChainMigrationUID;
-(id)generateUID;
-(void)dealloc;
-(id)init;
@end

@interface ExtensionLoader : NSObject {
}
@end

@interface ExtensionManager : NSObject <UIAlertViewDelegate> {
    UIView* _oldView;
    UIView* _extensionView;
    BOOL _viewTransitionSkip;
    NSString* telephoneToDialForClickToCallExtension;
    NSURL* urlToOpenInBrowser;
}
@property(retain, nonatomic) NSURL* urlToOpenInBrowser;
@property(retain, nonatomic) NSString* telephoneToDialForClickToCallExtension;
@property(readonly, assign, nonatomic) UIView* extensionView;
@property(assign, nonatomic) BOOL viewTransitionSkip;
+(id)sharedManager;
-(void)didCloseExtension;
-(void)hideExtension;
-(BOOL)handleClickToOpenBrowserExtensionWithURL:(NSString*)url;
-(BOOL)handleClickToCallExtensionWithURLAsString:(id)urlasString;
-(id)parametersFromParamsAsString:(id)paramsAsString;
-(void)showTermsAndConditionsWithURL:(id)url;
-(void)showExtensionView:(id)view;
-(void)setCommsManager:(CommsManager*)manager;
-(void)dealloc;
-(id)init;
-(void)alertView:(id)view didDismissWithButtonIndex:(int)buttonIndex;
-(void)openPhoneAppForTelephone:(id)telephone;
-(void)openSafariBrowserWithURL:(id)url;
@end

@interface UIButton (HSBCInterstitial)
-(void)HSBCInterstitialNotNowTapped:(id)tapped;
-(void)HSBCInterstitialDownloadTapped:(id)tapped;
@end

@interface UINavigationBar (MTKitAdditions)
-(void)drawRect:(CGRect)rect;
-(void)setBackgroundImage:(id)image;
@end