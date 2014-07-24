/**
 * This header is generated by class-dump-z 0.2-0.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "MyView.h"
#import "Monitise-iPhone-HSBC-EN-GB-Structs.h"
#import "UITextFieldDelegate.h"
#import "UIPickerViewDelegate.h"

@class UILabel, UIDatePicker, UIPickerView, UIInput;

__attribute__((visibility("hidden")))
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

