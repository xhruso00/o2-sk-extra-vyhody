//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSError, NSObject<OS_dispatch_queue>, NSURLRequest, NSURLResponse;

@interface CLSURLSessionTask : NSObject
{
    id <CLSURLSessionTaskDelegate> _delegate;
    NSURLRequest *_originalRequest;
    NSURLRequest *_currentRequest;
    NSURLResponse *_response;
    NSError *_error;
    NSObject<OS_dispatch_queue> *_queue;
    BOOL _invokesDelegate;
}

+ (id)task;
@property(nonatomic) id <CLSURLSessionTaskDelegate> delegate; // @synthesize delegate=_delegate;
@property(nonatomic) BOOL invokesDelegate; // @synthesize invokesDelegate=_invokesDelegate;
@property(readonly, nonatomic) NSObject<OS_dispatch_queue> *queue; // @synthesize queue=_queue;
@property(copy, nonatomic) NSError *error; // @synthesize error=_error;
@property(copy, nonatomic) NSURLResponse *response; // @synthesize response=_response;
@property(copy, nonatomic) NSURLRequest *originalRequest; // @synthesize originalRequest=_originalRequest;
@property(copy, nonatomic) NSURLRequest *currentRequest; // @synthesize currentRequest=_currentRequest;
- (void).cxx_destruct;
- (void)cleanup;
- (void)resume;
- (void)cancel;
- (void)start;
- (id)init;

@end

