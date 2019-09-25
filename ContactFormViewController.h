//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIViewController.h"

#import "AnimatedTextfieldDelegate.h"
#import "AnimatedTextviewDelegate.h"

@class AnimatedTextfield, AnimatedTextview, CustomActivityIndicator, NSString, UIButton, UILabel, UIScrollView;

@interface ContactFormViewController : UIViewController <AnimatedTextfieldDelegate, AnimatedTextviewDelegate>
{
    CustomActivityIndicator *loading;
    UILabel *_navigationTitle;
    UIScrollView *_scroll;
    AnimatedTextfield *_email;
    AnimatedTextfield *_subject;
    AnimatedTextview *_text;
    UIButton *_buttonConfirm;
}

@property(nonatomic) __weak UIButton *buttonConfirm; // @synthesize buttonConfirm=_buttonConfirm;
@property(nonatomic) __weak AnimatedTextview *text; // @synthesize text=_text;
@property(nonatomic) __weak AnimatedTextfield *subject; // @synthesize subject=_subject;
@property(nonatomic) __weak AnimatedTextfield *email; // @synthesize email=_email;
@property(nonatomic) __weak UIScrollView *scroll; // @synthesize scroll=_scroll;
@property(nonatomic) __weak UILabel *navigationTitle; // @synthesize navigationTitle=_navigationTitle;
- (void).cxx_destruct;
- (void)beginWrite;
- (void)sizeChanged2;
- (void)sizeChanged;
- (void)clickConfirm:(id)arg1;
- (void)clickBack:(id)arg1;
- (void)viewWillAppear:(BOOL)arg1;
- (void)viewDidLoad;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned int hash;
@property(readonly) Class superclass;

@end

