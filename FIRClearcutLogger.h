//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "GULNetworkReachabilityDelegate.h"

@class GULNetwork, NSMutableArray, NSMutableDictionary, NSObject<OS_dispatch_queue>, NSString, NSURL;

@interface FIRClearcutLogger : NSObject <GULNetworkReachabilityDelegate>
{
    NSObject<OS_dispatch_queue> *_queue;
    // Error parsing type: AI, name: _backgroundTaskId
    NSObject *_pendingRequestsLock;
    BOOL _sendScheduled;
    NSString *_applicationBuild;
    unsigned int _maxRequestNumBytes;
    NSString *_installIdentifier;
    NSURL *_serverURL;
    NSString *_zwiebackCookie;
    int _fetcherCookieStorageMethod;
    Class _delegate;
    NSString *_logDirectory;
    NSMutableDictionary *_accounts;
    int _uploadRetriesRemaining;
    GULNetwork *_network;
    NSMutableArray *_pendingRequests;
    long long _sendDelayMillis;
}

+ (id)sharedInstance;
@property(readonly, copy, nonatomic) NSMutableArray *pendingRequests; // @synthesize pendingRequests=_pendingRequests;
@property(retain, nonatomic) GULNetwork *network; // @synthesize network=_network;
@property(nonatomic) BOOL sendScheduled; // @synthesize sendScheduled=_sendScheduled;
@property(nonatomic) int uploadRetriesRemaining; // @synthesize uploadRetriesRemaining=_uploadRetriesRemaining;
@property(nonatomic) long long sendDelayMillis; // @synthesize sendDelayMillis=_sendDelayMillis;
@property(readonly, copy, nonatomic) NSMutableDictionary *accounts; // @synthesize accounts=_accounts;
@property(copy, nonatomic) NSString *logDirectory; // @synthesize logDirectory=_logDirectory;
@property(nonatomic) __weak Class delegate; // @synthesize delegate=_delegate;
@property(nonatomic) int fetcherCookieStorageMethod; // @synthesize fetcherCookieStorageMethod=_fetcherCookieStorageMethod;
@property(copy) NSString *zwiebackCookie; // @synthesize zwiebackCookie=_zwiebackCookie;
@property(copy) NSURL *serverURL; // @synthesize serverURL=_serverURL;
@property(copy) NSString *installIdentifier; // @synthesize installIdentifier=_installIdentifier;
@property unsigned int maxRequestNumBytes; // @synthesize maxRequestNumBytes=_maxRequestNumBytes;
@property(copy) NSString *applicationBuild; // @synthesize applicationBuild=_applicationBuild;
- (void).cxx_destruct;
@property(nonatomic) unsigned int backgroundTaskId; // @dynamic backgroundTaskId;
- (void)reachabilityDidChange;
- (void)sendNextPendingRequestWithCompletionHandler:(CDUnknownBlockType)arg1;
- (void)scheduleNextSend;
- (id)nextPendingRequest;
- (void)sendLogsWithCompletionHandler:(CDUnknownBlockType)arg1;
- (void)updatePendingRequests;
- (void)flushWriters;
- (id)logRequestFromPath:(id)arg1 logSource:(int)arg2;
- (id)accountDataForAccount:(id)arg1;
- (void)logEvent:(id)arg1 logSource:(int)arg2 account:(id)arg3;
- (void)flushWithCompletionHandler:(CDUnknownBlockType)arg1;
- (void)applicationDidEnterBackground:(id)arg1;
- (void)dealloc;
- (id)init;

@end
