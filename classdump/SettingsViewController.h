//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIViewController.h"

@class UIImageView;

@interface SettingsViewController : UIViewController
{
    UIImageView *_indicatorPush;
    UIImageView *_indicatorGeo;
}

@property(nonatomic) __weak UIImageView *indicatorGeo; // @synthesize indicatorGeo=_indicatorGeo;
@property(nonatomic) __weak UIImageView *indicatorPush; // @synthesize indicatorPush=_indicatorPush;
- (void).cxx_destruct;
- (void)clickedGeo:(id)arg1;
- (void)clickedPush:(id)arg1;
- (void)clickedBack:(id)arg1;
- (void)notificationsChanged;
- (void)refresh;
- (void)viewWillAppear:(BOOL)arg1;
- (void)viewDidLoad;

@end

