//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIViewController.h"

#import "UIScrollViewDelegate.h"

@class NSLayoutConstraint, NSString, UIButton, UILabel, UIPageControl, UIScrollView, UIView;

@interface SygicTutorialScrollViewController : UIViewController <UIScrollViewDelegate>
{
    UILabel *_Title;
    int _screenNumber;
    UIScrollView *_tutScrollView;
    UIView *_progressBarView;
    UIPageControl *_pageControl;
    UIView *_arrowCircle;
    UIView *_nextView;
    UIButton *_next;
    UIView *_finishView;
    UIButton *_finish;
    UIScrollView *_scrollView;
    UIView *_transparentBackground;
    NSLayoutConstraint *_bottomCons;
}

@property(nonatomic) __weak NSLayoutConstraint *bottomCons; // @synthesize bottomCons=_bottomCons;
@property(nonatomic) __weak UIView *transparentBackground; // @synthesize transparentBackground=_transparentBackground;
@property(nonatomic) __weak UIScrollView *scrollView; // @synthesize scrollView=_scrollView;
@property(nonatomic) __weak UIButton *finish; // @synthesize finish=_finish;
@property(nonatomic) __weak UIView *finishView; // @synthesize finishView=_finishView;
@property(nonatomic) __weak UIButton *next; // @synthesize next=_next;
@property(nonatomic) __weak UIView *nextView; // @synthesize nextView=_nextView;
@property(nonatomic) __weak UIView *arrowCircle; // @synthesize arrowCircle=_arrowCircle;
@property(nonatomic) __weak UIPageControl *pageControl; // @synthesize pageControl=_pageControl;
@property(nonatomic) __weak UIView *progressBarView; // @synthesize progressBarView=_progressBarView;
@property(nonatomic) __weak UIScrollView *tutScrollView; // @synthesize tutScrollView=_tutScrollView;
@property(nonatomic) int screenNumber; // @synthesize screenNumber=_screenNumber;
@property(nonatomic) __weak UILabel *Title; // @synthesize Title=_Title;
- (void).cxx_destruct;
- (void)scrollViewDidScroll:(id)arg1;
- (void)hide;
- (void)show:(double)arg1;
- (void)changePageControl:(id)arg1;
- (void)clickedFinish:(id)arg1;
- (void)clickedSkip:(id)arg1;
- (void)setupImages;
- (void)setupButtons;
- (void)setupViews;
- (void)viewDidAppear:(BOOL)arg1;
- (void)viewDidLoad;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned int hash;
@property(readonly) Class superclass;

@end

