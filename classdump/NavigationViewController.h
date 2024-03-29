//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIViewController.h"

#import "SYDriversBehaviorLogDelegate.h"
#import "SYDrivingDelegate.h"
#import "SYMapViewDelegate.h"
#import "SYNavigationDelegate.h"
#import "SYPositioningDelegate.h"
#import "SYRoutingDelegate.h"
#import "UIGestureRecognizerDelegate.h"
#import "UITextFieldDelegate.h"

@class NSDictionary, NSMutableArray, NSString, SYGeoCoordinate, SYLaneAssistView, SYMapView, SYReverseSearch, SYRoute, SYRouting, SYSearch, SYSearchResult, UIButton, UILabel, UITableView, UITextField, UIView;

@interface NavigationViewController : UIViewController <UITextFieldDelegate, SYMapViewDelegate, SYNavigationDelegate, SYDriversBehaviorLogDelegate, SYDrivingDelegate, SYPositioningDelegate, SYRoutingDelegate, UIGestureRecognizerDelegate>
{
    NSMutableArray *tableData;
    NSMutableArray *searchHistoryData;
    SYMapView *mapView;
    SYRouting *routing;
    SYSearch *search;
    SYSearchResult *searchResult;
    SYRoute *route;
    NSMutableArray *routes;
    SYLaneAssistView *laneAssistView;
    unsigned int step;
    BOOL routingEnabled;
    BOOL routingFromHistory;
    SYGeoCoordinate *coordinatesFromHistory;
    NSDictionary *historyDictionary;
    BOOL distractionFlag;
    double locationTimestamp;
    SYReverseSearch *reverseSearch;
    BOOL freeRide;
    UIView *_navigationHeaderSearch;
    UIView *_searchView;
    UITextField *_searchInput;
    UIButton *_buttonCancelSearch;
    UIView *_navigationHeaderSelectRoute;
    UIView *_content;
    UIView *_laneAssistContainer;
    UITableView *_searchResultTable;
    UILabel *_tripStartLabel;
    UIButton *_buttonRecenter;
    UIButton *_buttonEndTrip;
    UIView *_getDirectionsView;
    UIButton *_buttonGetDirections;
    UILabel *_getDirectionsLine1;
    UILabel *_getDirectionsLine2;
    UIView *_selectRouteView;
    UIButton *_buttonNavigate;
    UILabel *_selectRouteLine1;
    UILabel *_selectRouteLine2;
    UIView *_navigationHeaderNavigation;
    UIView *_navigationInfoView;
    UILabel *_arrivalTime;
    UILabel *_distanceValue;
    UILabel *_duration;
    UILabel *_distanceUnit;
    UIView *_speedView;
    UILabel *_speedValue;
    UIView *_speedLimitView;
    UILabel *_speedLimitValue;
    UILabel *_directionDistance;
    UILabel *_primaryManeuverBackground;
    UILabel *_primaryManeuverForeground;
    UILabel *_primaryManeuverName;
    UIView *_secondaryManeuverView;
    UILabel *_secondaryManeuverBackground;
    UILabel *_secondaryManeuverForeground;
    UIButton *_buttomResume;
    UIButton *_buttonCancelNavigation;
    UILabel *_findingRouteLabel;
    UIView *_sygicLogoView;
    UIView *_sygicLogo;
    UIButton *_buttonStartTrip;
    UIView *_arrivalTimeDistanceLeftView;
    UIView *_freeRideButtonView;
    UIView *_routingRideButtonView;
    UIButton *_buttonCancelNavigationBigger;
}

@property(nonatomic) __weak UIButton *buttonCancelNavigationBigger; // @synthesize buttonCancelNavigationBigger=_buttonCancelNavigationBigger;
@property(nonatomic) __weak UIView *routingRideButtonView; // @synthesize routingRideButtonView=_routingRideButtonView;
@property(nonatomic) __weak UIView *freeRideButtonView; // @synthesize freeRideButtonView=_freeRideButtonView;
@property(nonatomic) __weak UIView *arrivalTimeDistanceLeftView; // @synthesize arrivalTimeDistanceLeftView=_arrivalTimeDistanceLeftView;
@property(nonatomic) __weak UIButton *buttonStartTrip; // @synthesize buttonStartTrip=_buttonStartTrip;
@property(nonatomic) __weak UIView *sygicLogo; // @synthesize sygicLogo=_sygicLogo;
@property(nonatomic) __weak UIView *sygicLogoView; // @synthesize sygicLogoView=_sygicLogoView;
@property(nonatomic) __weak UILabel *findingRouteLabel; // @synthesize findingRouteLabel=_findingRouteLabel;
@property(nonatomic) __weak UIButton *buttonCancelNavigation; // @synthesize buttonCancelNavigation=_buttonCancelNavigation;
@property(nonatomic) __weak UIButton *buttomResume; // @synthesize buttomResume=_buttomResume;
@property(nonatomic) __weak UILabel *secondaryManeuverForeground; // @synthesize secondaryManeuverForeground=_secondaryManeuverForeground;
@property(nonatomic) __weak UILabel *secondaryManeuverBackground; // @synthesize secondaryManeuverBackground=_secondaryManeuverBackground;
@property(nonatomic) __weak UIView *secondaryManeuverView; // @synthesize secondaryManeuverView=_secondaryManeuverView;
@property(nonatomic) __weak UILabel *primaryManeuverName; // @synthesize primaryManeuverName=_primaryManeuverName;
@property(nonatomic) __weak UILabel *primaryManeuverForeground; // @synthesize primaryManeuverForeground=_primaryManeuverForeground;
@property(nonatomic) __weak UILabel *primaryManeuverBackground; // @synthesize primaryManeuverBackground=_primaryManeuverBackground;
@property(nonatomic) __weak UILabel *directionDistance; // @synthesize directionDistance=_directionDistance;
@property(nonatomic) __weak UILabel *speedLimitValue; // @synthesize speedLimitValue=_speedLimitValue;
@property(nonatomic) __weak UIView *speedLimitView; // @synthesize speedLimitView=_speedLimitView;
@property(nonatomic) __weak UILabel *speedValue; // @synthesize speedValue=_speedValue;
@property(nonatomic) __weak UIView *speedView; // @synthesize speedView=_speedView;
@property(nonatomic) __weak UILabel *distanceUnit; // @synthesize distanceUnit=_distanceUnit;
@property(nonatomic) __weak UILabel *duration; // @synthesize duration=_duration;
@property(nonatomic) __weak UILabel *distanceValue; // @synthesize distanceValue=_distanceValue;
@property(nonatomic) __weak UILabel *arrivalTime; // @synthesize arrivalTime=_arrivalTime;
@property(nonatomic) __weak UIView *navigationInfoView; // @synthesize navigationInfoView=_navigationInfoView;
@property(nonatomic) __weak UIView *navigationHeaderNavigation; // @synthesize navigationHeaderNavigation=_navigationHeaderNavigation;
@property(nonatomic) __weak UILabel *selectRouteLine2; // @synthesize selectRouteLine2=_selectRouteLine2;
@property(nonatomic) __weak UILabel *selectRouteLine1; // @synthesize selectRouteLine1=_selectRouteLine1;
@property(nonatomic) __weak UIButton *buttonNavigate; // @synthesize buttonNavigate=_buttonNavigate;
@property(nonatomic) __weak UIView *selectRouteView; // @synthesize selectRouteView=_selectRouteView;
@property(nonatomic) __weak UILabel *getDirectionsLine2; // @synthesize getDirectionsLine2=_getDirectionsLine2;
@property(nonatomic) __weak UILabel *getDirectionsLine1; // @synthesize getDirectionsLine1=_getDirectionsLine1;
@property(nonatomic) __weak UIButton *buttonGetDirections; // @synthesize buttonGetDirections=_buttonGetDirections;
@property(nonatomic) __weak UIView *getDirectionsView; // @synthesize getDirectionsView=_getDirectionsView;
@property(nonatomic) __weak UIButton *buttonEndTrip; // @synthesize buttonEndTrip=_buttonEndTrip;
@property(nonatomic) __weak UIButton *buttonRecenter; // @synthesize buttonRecenter=_buttonRecenter;
@property(nonatomic) __weak UILabel *tripStartLabel; // @synthesize tripStartLabel=_tripStartLabel;
@property(nonatomic) __weak UITableView *searchResultTable; // @synthesize searchResultTable=_searchResultTable;
@property(nonatomic) __weak UIView *laneAssistContainer; // @synthesize laneAssistContainer=_laneAssistContainer;
@property(nonatomic) __weak UIView *content; // @synthesize content=_content;
@property(nonatomic) __weak UIView *navigationHeaderSelectRoute; // @synthesize navigationHeaderSelectRoute=_navigationHeaderSelectRoute;
@property(nonatomic) __weak UIButton *buttonCancelSearch; // @synthesize buttonCancelSearch=_buttonCancelSearch;
@property(nonatomic) __weak UITextField *searchInput; // @synthesize searchInput=_searchInput;
@property(nonatomic) __weak UIView *searchView; // @synthesize searchView=_searchView;
@property(nonatomic) __weak UIView *navigationHeaderSearch; // @synthesize navigationHeaderSearch=_navigationHeaderSearch;
- (void).cxx_destruct;
- (int)preferredStatusBarStyle;
- (BOOL)prefersStatusBarHidden;
- (id)formattedDistanceUnit:(unsigned int)arg1;
- (id)formattedDistanceValue:(unsigned int)arg1;
- (id)formattedDuration:(double)arg1;
- (id)formattedDistance:(unsigned int)arg1;
- (id)arrivalTimeFromDuration:(double)arg1;
- (id)line2ForSelectRoute:(id)arg1;
- (id)line1ForSelectRoute:(id)arg1;
- (id)line2ForGetDirectionsFromSearchResult:(id)arg1;
- (id)line1ForGetDirectionsFromSearchResult:(id)arg1;
- (id)colorForSearchFromSearchResult:(id)arg1;
- (id)line2ForSearchFromSearchResultHistory:(int)arg1 country:(id)arg2 street:(id)arg3 addressPoint:(id)arg4 city:(id)arg5;
- (id)line2ForSearchFromSearchResult:(id)arg1;
- (id)line1ForSearchFromSearchResultHistory:(int)arg1 poi:(id)arg2 street:(id)arg3 addressPoint:(id)arg4 city:(id)arg5;
- (id)line1ForSearchFromSearchResult:(id)arg1;
- (void)saveLastSearchedResult:(id)arg1;
- (void)checkForSearchHistory;
- (void)hide;
- (void)show;
- (void)makeDistractionEvent;
- (BOOL)gestureRecognizer:(id)arg1 shouldReceiveTouch:(id)arg2;
- (id)tableView:(id)arg1 viewForHeaderInSection:(int)arg2;
- (float)tableView:(id)arg1 heightForHeaderInSection:(int)arg2;
- (id)tableView:(id)arg1 viewForFooterInSection:(int)arg2;
- (float)tableView:(id)arg1 heightForFooterInSection:(int)arg2;
- (float)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (int)tableView:(id)arg1 numberOfRowsInSection:(int)arg2;
- (int)numberOfSectionsInTableView:(id)arg1;
- (void)valueChanged:(id)arg1;
- (void)textFieldDidEndEditing:(id)arg1;
- (void)textFieldDidBeginEditing:(id)arg1;
- (void)clickedCancelNavigation:(id)arg1;
- (void)clickedNavigate:(id)arg1;
- (void)clickedGetDirections:(id)arg1;
- (void)clickedEndTrip:(id)arg1;
- (void)clickedStartTrip:(id)arg1;
- (void)clickedContinue:(id)arg1;
- (void)clickedRecenter:(id)arg1;
- (void)clickedCancelSearch:(id)arg1;
- (void)clickedBack:(id)arg1;
- (void)log:(id)arg1 didEndTrip:(id)arg2;
- (void)log:(id)arg1 didStartTrip:(id)arg2;
- (void)hideStartTripLabel;
- (void)navigationManagerDidReachFinish:(id)arg1;
- (void)navigation:(id)arg1 didUpdateDirection:(id)arg2;
- (void)navigation:(id)arg1 didUpdateOnRouteInfo:(id)arg2;
- (void)navigation:(id)arg1 didUpdateSpeedLimit:(id)arg2;
- (void)positioning:(id)arg1 didUpdatePosition:(id)arg2;
- (void)routing:(id)arg1 didFinishRouteRecompute:(id)arg2;
- (void)mapView:(id)arg1 didSelectObjects:(id)arg2;
- (void)routing:(id)arg1 computingFailedWithError:(int)arg2;
- (void)routing:(id)arg1 didComputeAlternativeRoute:(id)arg2;
- (void)routing:(id)arg1 didComputePrimaryRoute:(id)arg2;
- (void)computeRoute;
- (void)mapView:(id)arg1 didChangeCameraMovementMode:(int)arg2;
- (void)resizeForX;
- (void)initStepMap;
- (void)setPenalties;
- (void)initSygic;
- (void)viewWillDisappear:(BOOL)arg1;
- (void)viewWillAppear:(BOOL)arg1;
- (void)viewDidLoad;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned int hash;
@property(readonly) Class superclass;

@end

