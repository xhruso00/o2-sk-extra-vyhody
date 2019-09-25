//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIViewController.h"

#import "UIWebViewDelegate.h"

@class CustomActivityIndicator, NSString, NoPhoneNumberViewController, UIWebView;

@interface LoginViewController : UIViewController <UIWebViewDelegate>
{
    CustomActivityIndicator *loading;
    BOOL loagout;
    NoPhoneNumberViewController *npnvc;
    UIWebView *_content;
}

@property(nonatomic) __weak UIWebView *content; // @synthesize content=_content;
- (void).cxx_destruct;
- (void)clickedBack:(id)arg1;
- (void)sentAgreementsAfterLogin;
- (void)loggedOut;
- (void)codeObtained:(id)arg1;
- (void)showLogout;
- (void)show;
- (void)webView:(id)arg1 didFailLoadWithError:(id)arg2;
- (void)webViewDidFinishLoad:(id)arg1;
- (void)viewDidLoad;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned int hash;
@property(readonly) Class superclass;

@end

