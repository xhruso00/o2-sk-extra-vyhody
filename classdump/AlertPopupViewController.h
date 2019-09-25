//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIViewController.h"

@class NSString, UIButton, UILabel, UIView;

@interface AlertPopupViewController : UIViewController
{
    NSString *_message;
    UIView *_blurView;
    UIView *_contentView;
    UIButton *_buttonOk;
    UILabel *_label1;
    UIView *_shadowView;
    UIView *_roundedView;
    UIView *_claimButtonView;
}

@property(nonatomic) __weak UIView *claimButtonView; // @synthesize claimButtonView=_claimButtonView;
@property(nonatomic) __weak UIView *roundedView; // @synthesize roundedView=_roundedView;
@property(nonatomic) __weak UIView *shadowView; // @synthesize shadowView=_shadowView;
@property(nonatomic) __weak UILabel *label1; // @synthesize label1=_label1;
@property(nonatomic) __weak UIButton *buttonOk; // @synthesize buttonOk=_buttonOk;
@property(nonatomic) __weak UIView *contentView; // @synthesize contentView=_contentView;
@property(nonatomic) __weak UIView *blurView; // @synthesize blurView=_blurView;
@property(retain) NSString *message; // @synthesize message=_message;
- (void).cxx_destruct;
- (void)clickedBack:(id)arg1;
- (void)showWithImage:(id)arg1;
- (void)setupButtons;
- (void)setupLabels;
- (void)viewDidLoad;

@end

