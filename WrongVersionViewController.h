//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIViewController.h"

@class UIButton, UILabel, UIView;

@interface WrongVersionViewController : UIViewController
{
    UILabel *_text;
    UIView *_blurView;
    UIView *_contentView;
    UIButton *_buttonOk;
}

@property(nonatomic) __weak UIButton *buttonOk; // @synthesize buttonOk=_buttonOk;
@property(nonatomic) __weak UIView *contentView; // @synthesize contentView=_contentView;
@property(nonatomic) __weak UIView *blurView; // @synthesize blurView=_blurView;
@property(nonatomic) __weak UILabel *text; // @synthesize text=_text;
- (void).cxx_destruct;
- (void)clickedUpdate:(id)arg1;
- (void)showWithImage:(id)arg1 text:(id)arg2;
- (void)showWithImage:(id)arg1;
- (void)viewDidLoad;

@end

