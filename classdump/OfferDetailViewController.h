//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIViewController.h"

#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"
#import "UIWebViewDelegate.h"

@class ClaimedDataViewController, CodeViewController, CustomActivityIndicator, LoginPopupViewController, NSIndexPath, NSMutableArray, NSString, NoMoreCodesViewController, Offer, UITableView;

@interface OfferDetailViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, UIWebViewDelegate>
{
    NSIndexPath *expandIndex;
    NSMutableArray *cells;
    CodeViewController *cvc;
    LoginPopupViewController *lpvc;
    NoMoreCodesViewController *nmcvc;
    ClaimedDataViewController *cdvc;
    CustomActivityIndicator *loading;
    float qrCodeDefaultHeigh;
    Offer *_offer;
    UITableView *_table;
}

@property(nonatomic) __weak UITableView *table; // @synthesize table=_table;
@property(retain, nonatomic) Offer *offer; // @synthesize offer=_offer;
- (void).cxx_destruct;
- (void)clickedClaim;
- (void)clickedButton2;
- (void)clickedButton1;
- (void)clickedBack:(id)arg1;
- (id)tableView:(id)arg1 viewForHeaderInSection:(int)arg2;
- (float)tableView:(id)arg1 heightForHeaderInSection:(int)arg2;
- (id)tableView:(id)arg1 viewForFooterInSection:(int)arg2;
- (float)tableView:(id)arg1 heightForFooterInSection:(int)arg2;
- (float)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (int)tableView:(id)arg1 numberOfRowsInSection:(int)arg2;
- (int)numberOfSectionsInTableView:(id)arg1;
- (void)webViewDidFinishLoad:(id)arg1;
- (void)refresh;
- (void)viewWillDisappear:(BOOL)arg1;
- (void)viewWillAppear:(BOOL)arg1;
- (void)viewDidLoad;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned int hash;
@property(readonly) Class superclass;

@end

