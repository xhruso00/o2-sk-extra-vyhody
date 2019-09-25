//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "CLSURLSessionDownloadDelegate.h"

@class NSMutableSet, NSObject<OS_dispatch_queue>, NSOperationQueue, NSString, NSURLSessionConfiguration;

@interface CLSURLSession : NSObject <CLSURLSessionDownloadDelegate>
{
    id <NSURLSessionDelegate> _delegate;
    NSOperationQueue *_delegateQueue;
    NSURLSessionConfiguration *_configuration;
    NSMutableSet *_taskSet;
    NSObject<OS_dispatch_queue> *_queue;
    NSString *_sessionDescription;
}

+ (id)newDefaultDelegateQueue;
+ (id)sessionWithConfiguration:(id)arg1 delegate:(id)arg2 delegateQueue:(id)arg3;
+ (id)sessionWithConfiguration:(id)arg1;
+ (BOOL)NSURLSessionShouldBeUsed;
@property(copy, nonatomic) NSString *sessionDescription; // @synthesize sessionDescription=_sessionDescription;
@property(copy, nonatomic) NSURLSessionConfiguration *configuration; // @synthesize configuration=_configuration;
@property(retain, nonatomic) NSOperationQueue *delegateQueue; // @synthesize delegateQueue=_delegateQueue;
@property(retain, nonatomic) id <NSURLSessionDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)downloadTask:(id)arg1 didFinishDownloadingToURL:(id)arg2;
- (void)task:(id)arg1 didReceiveData:(id)arg2;
- (void)task:(id)arg1 didReceiveResponse:(id)arg2;
- (void)task:(id)arg1 didCompleteWithError:(id)arg2;
- (id)task:(id)arg1 willPerformHTTPRedirection:(id)arg2 newRequest:(id)arg3;
- (id)downloadTaskWithRequest:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
- (id)uploadTaskWithRequest:(id)arg1 fromFile:(id)arg2 completionHandler:(CDUnknownBlockType)arg3;
- (id)dataTaskWithRequest:(id)arg1;
- (id)dataTaskWithRequest:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
- (id)downloadTaskWithURL:(id)arg1;
- (id)downloadTaskWithRequest:(id)arg1;
- (id)uploadTaskWithRequest:(id)arg1 fromFile:(id)arg2;
- (BOOL)shouldInvokeDelegateSelector:(SEL)arg1 forTask:(id)arg2;
- (void)configureTask:(id)arg1 withRequest:(id)arg2 block:(CDUnknownBlockType)arg3;
- (void)removeTaskFromSet:(id)arg1;
- (void)getTasksWithCompletionHandler:(CDUnknownBlockType)arg1;
- (void)finishTasksAndInvalidate;
- (void)invalidateAndCancel;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned int hash;
@property(readonly) Class superclass;

@end

